#include <iostream>
#include "PriorityQueueTest.h"
#include "list/linked_list.h"
#include "list/array_list.h"
#include "priority_queue/priority_queue_sorted_array_list.h"
#include "priority_queue/heap.h"
#include "ListTest.h"
#include "MatrixTest.h"
#include "MatrixContinuous.h"
#include "MatrixDiscontinuous.h"

#define _CRT_SECURE_NO_DEPRECATE

using namespace structures;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));

	//Priority Queue Testing
	/*PriorityQueueTest queueTest(*(new PriorityQueueSortedArrayList<int>));
	for (int i = 0; i < 100000; i++)
	{
		queueTest.Script(70,25);
	}*/

	//List Testing
	/*ListTest listT(*(new ArrayList<int>));
	for (int i = 0; i < 100000; i++)
	{
		listT.Script(45, 45, 5);
	}*/
	
	//Matrix Testing
	//MatrixTest matrixT;
	//for (int i = 10; i < 201; i++)
	//{
	//	//matrixT.ScriptAddition(*(new MatrixContinuous<int>(10, 10*i)), *(new MatrixContinuous<int>(10, 10*i)), *(new MatrixContinuous<int>(10, 10 * i)));
	//	//matrixT.ScriptMultiplication(*(new MatrixContinuous<int>(10, 10 * i)), *(new MatrixContinuous<int>(10 * i, 10)), *(new MatrixContinuous<int>(10, 10)));
	//	matrixT.ScriptMultiplication(*(new MatrixDiscontinuous<int>(10, 10 * i)), *(new MatrixDiscontinuous<int>(10 * i, 10)), *(new MatrixDiscontinuous<int>(10, 10)));
	//}
//	matrixT.ScriptAddition(*(new MatrixContinuous<int>(10,1000)), *(new MatrixContinuous<int>(10, 1000)), *(new MatrixContinuous<int>(10,1000)));
//	matrixT.ScriptMultiplication(*(new MatrixContinuous<int>(2000, 300)), *(new MatrixContinuous<int>(300, 2000)), *(new MatrixContinuous<int>(2000, 2000)));
//	matrixT.ScriptMultiplication(*(new MatrixDiscontinuous<int>(300, 2000)), *(new MatrixDiscontinuous<int>(2000, 300)), *(new MatrixDiscontinuous<int>(300, 300)));
	
	std::string TestName;
	std::string TypeName;
	int op1;
	int op2;
	int op3;
	int OpAmount;
	std::cout << "Input name of the test you want to run" << std::endl;
	std::cout << "Available tests: 'List', 'Matrix', 'PriorityQueue'." << std::endl;
	std::cin >> TestName;
	if (TestName == "List")
	{
		std::cout << "Input ratios of the first 3 operations (must not be more than 100 in total, the 4th operation will be calculated automatically)." << std::endl;
		std::cin >> op1;
		std::cin >> op2;
		std::cin >> op3;

		std::cout << "Choose how many operations you want carried out." << std::endl;
		std::cin >> OpAmount;

		std::cout << "Choose type of List" << std::endl;
		std::cout << "Available types: 'ArrayList', 'LinkedList'" << std::endl;
		std::cin >> TypeName;
		if (TypeName == "ArrayList")
		{
			ListTest listTest(*(new ArrayList<int>));
			for (int i = 0; i < OpAmount; i++)
			{
				listTest.Script(op1, op2, op3);
			}
		}
		else if (TypeName == "LinkedList")
		{
			ListTest listTest(*(new LinkedList<int>));
			for (int i = 0; i < OpAmount; i++)
			{
				listTest.Script(op1, op2, op3);
			}
		}
		else
		{
			std::cout << "Wrong input!" << std::endl;
		}
	}
	else if (TestName == "Matrix")
	{
		std::cout << "Choose dimensions of matrix." << std::endl;
		std::cin >> op1;
		std::cin >> op2;
		std::cout << "Choose 'Addition' or 'Multiplication'." << std::endl;
		std::string MatrixOperation;
		std::cin >> MatrixOperation;

		MatrixTest matrixTest;
		std::cout << "Choose 'Continuous' or 'Discontinous' matrix type." << std::endl;
		std::cin >> TypeName;
		if (TypeName == "Continuous")
		{
			if (MatrixOperation == "Addition")
			{
				matrixTest.ScriptAddition(*(new MatrixContinuous<int>(op1, op2)), *(new MatrixContinuous<int>(op1, op2)), *(new MatrixContinuous<int>(op1, op2)));
				return 0;
			}
			if (MatrixOperation == "Multiplication")
			{
				matrixTest.ScriptMultiplication(*(new MatrixContinuous<int>(op1, op2)), *(new MatrixContinuous<int>(op2, op1)), *(new MatrixContinuous<int>(op1, op1)));
				return 0;
			}
		}
		if (TypeName == "Discontinuous")
		{
			if (MatrixOperation == "Addition")
			{
				matrixTest.ScriptAddition(*(new MatrixDiscontinuous<int>(op1, op2)), *(new MatrixDiscontinuous<int>(op1, op2)), *(new MatrixDiscontinuous<int>(op1, op2)));
				return 0;
			}
			if (MatrixOperation == "Multiplication")
			{
				matrixTest.ScriptMultiplication(*(new MatrixDiscontinuous<int>(op1, op2)), *(new MatrixDiscontinuous<int>(op2, op1)), *(new MatrixDiscontinuous<int>(op1, op1)));
				return 0;
			}
			else
			{
				std::cout << "Wrong input!" << std::endl;
			}
		}
		else
		{
			std::cout << "Wrong input!" << std::endl;
		}
	}
	else if (TestName == "PriorityQueue")
	{
		std::cout << "Input ratios of the first 2 operations (must not be more than 100 in total, the 3rd operation will be calculated automatically)." << std::endl;
		std::cin >> op1;
		std::cin >> op2;

		std::cout << "Choose how many operations you want carried out." << std::endl;
		std::cin >> OpAmount;

		std::cout << "Choose type of Priority Queue" << std::endl;
		std::cout << "Available types: 'Heap', 'SortedArrayList'" << std::endl;
		std::cin >> TypeName;
		if (TypeName == "Heap")
		{
			PriorityQueueTest queueTest(*(new PriorityQueueSortedArrayList<int>));
			for (int i = 0; i < OpAmount; i++)
			{
				queueTest.Script(op1, op2);
				return 0;
			}
		}
		else if (TypeName == "SortedArrayList")
		{
			PriorityQueueTest queueTest(*(new PriorityQueueSortedArrayList<int>));
			for (int i = 0; i < OpAmount; i++)
			{
				queueTest.Script(op1, op2);
				return 0;
			}
		}
		else
		{
			std::cout << "Wrong input!" << std::endl;
		}
	}
	else
	{
		//std::cout << "Wrong input!" << std::endl;			
	}
	return 0;
}


