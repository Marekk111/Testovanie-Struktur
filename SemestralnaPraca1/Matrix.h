#pragma once
#include "structure.h"
#include "ds_structure_types.h"
namespace structures 
{
	template<typename T>
	class Matrix : public Structure
	{
	protected:
		Matrix();
	public:
		virtual Structure* clone() const = 0;
		virtual Matrix<T>& operator=(const Matrix<T>& other) = 0;
		virtual T& access(const int rowIndex, const int columnIndex) = 0;
		virtual void set(const int rowIndex, const int columnIndex, const T& data) = 0;
		virtual size_t rowSize() = 0;
		virtual size_t columnSize() = 0;
		Structure& operator=(const Structure& other) override;
		virtual size_t size() const = 0;
	
	};

	template<typename T>
	inline Matrix<T>::Matrix() :
		Structure()
	{
	}

	template<typename T>
	inline Structure& Matrix<T>::operator=(const Structure& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Matrix<T>&>(other);
		}
		return *this;
	}
}

