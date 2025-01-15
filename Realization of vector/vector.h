#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

namespace I
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
		{
			_start = _finish = _end_storage = nullptr;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		size_t capacity()
		{
			return _end_storage - _start;
		}

		size_t size()
		{
			return _finish - _start;
		}

		bool empty()
		{
			return _start == _finish;
		}

		void reserve(size_t allocateSpace)
		{
			if (allocateSpace > capacity())
			{
				size_t old_size = size();
				iterator new_start = new T[allocateSpace];
				memcpy(new_start, _start, size() * sizeof(T));
				delete[] _start;

				_start = new_start;
				_finish = new_start + old_size;
				_end_storage = new_start + allocateSpace;
			}
		}

		void pushback(const T& instance)
		{
			if (_finish == _end_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish++ = instance;
		}

		void popback()
		{
			if (empty())
			{
				throw std::out_of_range("Index out of range");
			}

			--_finish;
		}

		void insert(iterator pos, const T& instance)
		{
			if (_finish == _end_storage)
			{
				size_t i = pos - _start;

				reserve(capacity() == 0 ? 4 : 2 * capacity());

				pos = _start + i;
			}

			iterator end = _finish - 1;

			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = instance;

			++_finish;
		}

		T& operator[](size_t num)
		{
			if (num >= size())
				throw std::out_of_range("Index out of range");

			return _start[num];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_storage;
	};

	template<class T>
	void display_int(const vector<T>& instance)
	{
		typename vector<T>::const_iterator it = instance.begin();
		//The compiler does not know const_iterator in "vector<T>"
		//use typename to declare vector<int> is a type
		//or auto to determine automatically
		auto it_ = instance.begin();

		while (it != instance.end())
		{
			std::cout << *it << " ";
			++it;
		}

		std::cout << std::endl;

		for (auto e : instance)
		{
			std::cout << e << " ";
		}

		std::cout << std::endl;

	}
}