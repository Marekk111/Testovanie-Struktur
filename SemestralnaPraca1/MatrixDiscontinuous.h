#pragma once
#include "Matrix.h"
#include "array/array.h"

namespace structures 
{
	template<typename T>
	class MatrixDiscontinuous : public Matrix<T>
	{
	public:
		MatrixDiscontinuous() = default;
		MatrixDiscontinuous(const int rowSize, const int columnSize);
		~MatrixDiscontinuous();
		MatrixDiscontinuous(const MatrixDiscontinuous<T>& other);
		Structure* clone() const override;
		Matrix<T>& operator=(const Matrix<T>& other) override;
		MatrixDiscontinuous<T>& operator=(const MatrixDiscontinuous<T>& other);
		size_t rowSize() override { return array_->size(); }
		size_t columnSize() override { return (*array_)[0]->size(); }
		T& access(const int rowIndex, const int columnIndex) override;
		void set(const int rowIndex, const int columnIndex, const T& data) override;
		size_t size() const override;
	private:
		Array<Array<T>*>* array_;
	};

	template <typename T>
	inline MatrixDiscontinuous<T>::MatrixDiscontinuous(const int rowSize, const int columnSize)
	{
		array_ = new Array<Array<T>*>(rowSize);
		for (int i = 0; i < rowSize; i++)
		{
			(*array_)[i] = new Array<T>(columnSize);
		}
	}

	template <typename T>
	inline MatrixDiscontinuous<T>::~MatrixDiscontinuous()
	{
		for (int i = 0; i < array_->size(); i++)
		{
			delete (*array_)[i];
		}
		delete array_;
		array_ = nullptr;
	}
	template<typename T>
	inline MatrixDiscontinuous<T>::MatrixDiscontinuous(const MatrixDiscontinuous<T>& other)
	{
		array_ = new Array<Array<T>*>(*(other.array_));

		for (int i = 0; i < array_->size(); i++)
		{
			(*array_)[i] = new Array<T>(*((*other.array_)[i]));
		}
	}

	template<typename T>
	inline Structure* MatrixDiscontinuous<T>::clone() const
	{
		return new MatrixDiscontinuous(*this);
	}
	template<typename T>
	inline Matrix<T>& MatrixDiscontinuous<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const MatrixDiscontinuous<T>&>(other);
		}
		return *this;
	}
	template<typename T>
	inline MatrixDiscontinuous<T>& MatrixDiscontinuous<T>::operator=(const MatrixDiscontinuous<T>& other)
	{
		if (this != &other)
		{
			for (int i = 0; i < array_->size(); i++)
			{
				delete (*array_)[i];
			}
			delete array_;
			array_ = new Array<Array<T>*>(*(other.array_));

			for (int i = 0; i < array_->size(); i++)
			{
				(*array_)[i] = new Array<T>(*((*other.array_)[i]));
			}
		}
		return *this;
		
	}
	template<typename T>
	inline T& MatrixDiscontinuous<T>::access(const int rowIndex, const int columnIndex)
	{
		DSRoutines::rangeCheck(rowIndex, array_->size());
		DSRoutines::rangeCheck(columnIndex, (*array_)[0]->size());
		return (*(*array_)[rowIndex])[columnIndex];
	}
	template<typename T>
	inline void MatrixDiscontinuous<T>::set(const int rowIndex, const int columnIndex, const T& data)
	{
		DSRoutines::rangeCheck(rowIndex, array_->size());
		DSRoutines::rangeCheck(columnIndex, (*array_)[0]->size());
		(*(*array_)[rowIndex])[columnIndex] = data;
	}
	template<typename T>
	inline size_t MatrixDiscontinuous<T>::size() const
	{
		return array_->size() * (*array_)[0]->size();
	}
}

