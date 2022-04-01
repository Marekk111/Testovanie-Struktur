#pragma once
#include "Matrix.h"
#include <fstream>
#include <iostream>

namespace structures
{

	class MatrixTest
	{
	public:
		MatrixTest();

		void ScriptAddition(Matrix<int>& matrix1, Matrix<int>& matrix2, Matrix<int>& matrix);
		void ScriptMultiplication(Matrix<int>& matrix1, Matrix<int>& matrix2, Matrix<int>& matrix);

		~MatrixTest();

	private:
		std::ofstream file;
	};

	inline MatrixTest::MatrixTest()
	{
		file.open("MatrixOutput.csv");
	}

	inline void MatrixTest::ScriptAddition(Matrix<int>& matrix1, Matrix<int>& matrix2, Matrix<int>& matrix)
	{
		Matrix<int>* matrix1_ = &matrix1;
		Matrix<int>* matrix2_ = &matrix2;
		Matrix<int>* matrix_ = &matrix;

		auto start = std::chrono::steady_clock::now();
		for (int i = 0; i < matrix1_->rowSize(); i++)
		{
			for (int j = 0; j < matrix1_->columnSize(); j++)
			{
				matrix1_->set(i, j, 5);
				matrix2_->set(i, j, 1);
				matrix_->set(i, j, matrix1_->access(i, j) + matrix2_->access(i, j));
			}
		}
		auto end = std::chrono::steady_clock::now();
		//std::cout << matrix_->access(0, 1);
		file << "Scitanie" << "," << matrix1_->rowSize() << "," << matrix1_->columnSize() << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
		delete matrix1_;
		delete matrix2_;
		delete matrix_;
	}

	inline void MatrixTest::ScriptMultiplication(Matrix<int>& matrix1, Matrix<int>& matrix2, Matrix<int>& matrix)
	{
		Matrix<int>* matrix1_ = &matrix1;
		Matrix<int>* matrix2_ = &matrix2;
		Matrix<int>* matrix_ = &matrix;

		int auxNumber = 0;
		for (int i = 0; i < matrix1_->rowSize(); i++)
		{
			for (int j = 0; j < matrix1_->columnSize(); j++)
			{
				matrix1_->set(i, j, 10);
				
			}
		}
		
		for (int i = 0; i < matrix2_->rowSize(); i++)
		{
			for (int j = 0; j < matrix2_->columnSize(); j++)
			{
				matrix2_->set(i, j, 20);
			}
		}
		auto start = std::chrono::steady_clock::now();
		for (int i = 0; i < matrix1_->rowSize(); i++)
		{
			
			for (int j = 0; j < matrix2_->columnSize(); j++)
			{
				for (int k = 0; k < matrix1_->columnSize(); k++)
				{
					auxNumber += matrix1_->access(i, k) * matrix2_->access(k, j);
					matrix_->set(i, j, auxNumber);
				}
				auxNumber = 0;
			}
		}
		auto end = std::chrono::steady_clock::now();
		//std::cout << matrix_->access(1, 1);
		file << "Nasobenie" << "," << matrix1_->rowSize() << "," << matrix1_->columnSize() << "," << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
		delete matrix1_;
		delete matrix2_;
		delete matrix_;
	}

	MatrixTest::~MatrixTest()
	{
		file.close();
	}
}