#pragma once
#include "priority_queue/priority_queue_list.h"
#include "priority_queue/heap.h"
#include <fstream>
#include <chrono>

namespace structures
{
	class PriorityQueueTest
	{
	public:
		PriorityQueueTest(PriorityQueueList<int>& queue);
		
		void Script(int o1, int o2);

		~PriorityQueueTest();

	private:
		PriorityQueueList<int>* queue_;
		std::ofstream file;
	};

	inline PriorityQueueTest::PriorityQueueTest(PriorityQueueList<int>& queue)
	{
		queue_ = &queue;
		file.open("PriorityQueueOutput.csv");
	}

	inline void PriorityQueueTest::Script(int o1, int o2)
	{
		int a;
		int randomChance = rand() % 100 + 1;
		int randomData = rand() % 100 + 1;
		int randomPriority = rand() % 10000 + 1;

		if (queue_->isEmpty())
		{
			auto start = std::chrono::steady_clock::now();
			queue_->push(randomPriority, randomData);
			auto end = std::chrono::steady_clock::now();
			file << "push" << "," << queue_->size() << "," << randomPriority << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
			return;
		}
		if (randomChance <= o1)
		{
			auto start = std::chrono::steady_clock::now();
			queue_->push(randomPriority, randomData);
			auto end = std::chrono::steady_clock::now();
			file << "push" << "," << queue_->size() << "," << randomPriority << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;

		}
		else if (randomChance > o1 && randomChance <= o1 + o2)
		{			
			a = queue_->peekPriority();
			auto start = std::chrono::steady_clock::now();
			queue_->pop();
			auto end = std::chrono::steady_clock::now();
			file << "pop" << "," << queue_->size() << "," << a << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;

		}
		else
		{
			a = queue_->peekPriority();
			auto start = std::chrono::steady_clock::now();
			a = queue_->peek();
			auto end = std::chrono::steady_clock::now();
			file << "peek" << "," << queue_->size() << "," << a << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
		}
	}
	inline PriorityQueueTest::~PriorityQueueTest()
	{
		delete queue_;
		queue_ = nullptr;
	}
}