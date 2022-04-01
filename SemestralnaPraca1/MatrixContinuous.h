#pragma once
#include "Matrix.h"
#include "array/array.h"


namespace structures
{
	template <typename T>
	class MatrixContinuous : public Matrix<T>
	{
	private:
		Array<T>* array_;
		size_t rowSize_;
		size_t columnSize_;
	public:
		MatrixContinuous(const int rowSize, const int columnSize);
		MatrixContinuous(const MatrixContinuous<T>& other);
		size_t rowSize() override;
		size_t columnSize() override;
		Structure* clone() const override;
		Matrix<T>& operator=(const Matrix<T>& other) override;
		MatrixContinuous<T>& operator=(const MatrixContinuous<T>& other);
		T& access(const int rowIndex, const int columnIndex) override;
		void set(const int rowIndex, const int columnIndex, const T& data) override;
		size_t size() const override;
		~MatrixContinuous();
	};

	template<typename T>
	inline MatrixContinuous<T>::MatrixContinuous(const int rowSize, const int columnSize)
	{
		rowSize_ = rowSize;
		columnSize_ = columnSize;
		array_ = new Array<T>(rowSize_ * columnSize_);
	}

	template<typename T>
	inline MatrixContinuous<T>::MatrixContinuous(const MatrixContinuous<T>& other)
	{
		rowSize_ = other.rowSize_;
		columnSize_ = other.columnSize_;
		array_ = new Array<T>(*(other.array_));
	}

	template<typename T>
	inline size_t MatrixContinuous<T>::rowSize()
	{
		return rowSize_;
	}

	template<typename T>
	inline size_t MatrixContinuous<T>::columnSize()
	{
		return columnSize_;
	}

	template<typename T>
	inline Structure* MatrixContinuous<T>::clone() const
	{
		return new MatrixContinuous(*this);
	}

	template<typename T>
	inline Matrix<T>& MatrixContinuous<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const MatrixContinuous<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline MatrixContinuous<T>& MatrixContinuous<T>::operator=(const MatrixContinuous<T>& other)
	{
		if (this != &other)
		{
			rowSize_ = other.rowSize_;
			columnSize_ = other.columnSize_;
			delete array_;
			array_ = new Array<T>(*(other.array_));

		}
		return *this;
	}

	template<typename T>
	inline T& MatrixContinuous<T>::access(const int rowIndex, const int columnIndex)
	{
		return (*array_)[columnSize_ * rowIndex + columnIndex];
	}

	template<typename T>
	inline void MatrixContinuous<T>::set(const int rowIndex, const int columnIndex, const T& data)
	{
		(*array_)[columnSize_ * rowIndex + columnIndex] = data;
	}

	template<typename T>
	inline size_t MatrixContinuous<T>::size() const
	{
		return array_->size();
	}

	template<typename T>
	inline MatrixContinuous<T>::~MatrixContinuous()
	{
		delete array_;
		array_ = nullptr;
		rowSize_ = 0;
		columnSize_ = 0;
	}
}


