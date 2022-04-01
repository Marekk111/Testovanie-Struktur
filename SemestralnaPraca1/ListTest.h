#pragma once
#include "list/list.h"
#include <chrono>
#include <fstream>
namespace structures 
{
	class ListTest
	{
	public:
		ListTest(List<int>& list);
		
		void Script(int op1, int op2, int op3);

		~ListTest();

	private:
		List<int>* list_;
		std::ofstream file;
	};

	inline ListTest::ListTest(List<int>& list)
	{
		list_ = &list;
		file.open("ListOutput.csv");
	}

	inline void ListTest::Script(int op1, int op2, int op3)
	{
		int element;
		int randomChance1 = rand() % 100;
		int randomChance2 = rand() % 3 + 1;
		int randomData = rand() % 100 + 1;
		int randomIndex = 0;
		int index = 0;

		auto start = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();

		if (list_->size() == 0)
		{
			start = std::chrono::steady_clock::now();
			list_->add(randomData);
			end = std::chrono::steady_clock::now();
			file << "add" << "," << list_->size() << "," << list_->size() - 1 << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
			return;
		}
		randomIndex = rand() % list_->size();

		if (randomChance1 <= op1)
		{
			switch (randomChance2)
			{
			case 1:
				start = std::chrono::steady_clock::now();
				list_->insert(randomData, 0);
				end = std::chrono::steady_clock::now();
				file << "insert at start" << "," << list_->size() << "," << 0 << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			case 2:
				start = std::chrono::steady_clock::now();
				list_->add(randomData);
				end = std::chrono::steady_clock::now();
				file << "add" << "," << list_->size() << "," << list_->size() - 1 << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			case 3:
				start = std::chrono::steady_clock::now();
				list_->insert(randomData, randomIndex);
				end = std::chrono::steady_clock::now();
				file << "insert at random index" << "," << list_->size() << "," << randomIndex << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			default:
				break;
			}
		}
		else if (randomChance1 > op1 && randomChance1 <= (op1 + op2))
		{
			switch (randomChance2)
			{
			case 1:
				start = std::chrono::steady_clock::now();
				element = list_->removeAt(0);
				end = std::chrono::steady_clock::now();
				file << "remove from start" << "," << list_->size() << "," << 0 << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			case 2:
				index = list_->size() - 1;
				start = std::chrono::steady_clock::now();
				element = list_->removeAt(list_->size() - 1);
				end = std::chrono::steady_clock::now();
				file << "remove from end" << "," << list_->size() << "," << index << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			case 3:
				start = std::chrono::steady_clock::now();
				element = list_->removeAt(randomIndex);
				end = std::chrono::steady_clock::now();
				file << "remove from random index" << "," << list_->size() << "," << randomIndex << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			default:
				break;
			}
		}
		else if (randomChance1 > (op1 + op2) && randomChance1 <= (op1 + op2 + op3))
		{
			randomChance2 = rand() % 2 + 1;
			switch (randomChance2)
			{
			case 1:
				start = std::chrono::steady_clock::now();
				element = (*list_)[randomIndex];
				end = std::chrono::steady_clock::now();
				file << "access at random index" << "," << list_->size() << "," << randomIndex << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			case 2:
				start = std::chrono::steady_clock::now();
				(*list_)[randomIndex] = randomData;
				end = std::chrono::steady_clock::now();
				file << "set value at random index" << "," << list_->size() << "," << randomIndex << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
				break;
			default:
				break;
			}
		}
		else
		{
			start = std::chrono::steady_clock::now();
			element = list_->getIndexOf(randomData);
			end = std::chrono::steady_clock::now();
			file << "get Index of" << "," << list_->size() << "," << element << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
		}
		
	}

	inline ListTest::~ListTest()
	{
		delete list_;
		list_ = nullptr;
		file.close();
	}
}
