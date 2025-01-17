#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

namespace myContainer
{
	template<class valueType>
	class vector
	{
	public:
		typedef valueType* iterator;
		typedef const valueType* const_iterator;

		vector()
		{
			_start = _finish = _end_storage = nullptr;
		}

		vector(const vector<valueType>& instance)
		{
			reserve(instance.capacity());
			for (auto& e : instance)
			{
				push_back(e);
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}

			_start = _finish = _end_storage = nullptr;
		}

		iterator begin()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator end() const
		{
			return _finish;
		}

		size_t capacity()
		{
			return _end_storage - _start;
		}

		const size_t capacity() const
		{
			return _end_storage - _start;
		}

		size_t size()
		{
			return _finish - _start;
		}

		const size_t size() const
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
				iterator new_start = new valueType[allocateSpace];
				memcpy(new_start, _start, size() * sizeof(valueType));
				delete[] _start;

				_start = new_start;
				_finish = new_start + old_size;
				_end_storage = new_start + allocateSpace;
			}
		}

		void resize(size_t n, valueType value = valueType())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish++ = value;
				}
			}
		}

		void push_back(const valueType& instance)
		{
			if (_finish == _end_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish++ = instance;
		}

		void pop_back()
		{
			if (empty())
			{
				throw std::out_of_range("Index out of range");
			}

			--_finish;
		}

		void insert(iterator pos, const valueType& instance)
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

		void erase(iterator pos)
		{
			if ((pos < _start) || (pos >= _finish))
			{
				throw std::out_of_range("Index out of range");
			}

			iterator i = pos;
			while (i < _finish - 1)
			{
				*i = *(i + 1);
				++i;
			}

			--_finish;
		}

		void clear()
		{
			_finish = _start;
		}

		vector<valueType>& operator=(const vector<valueType>& instance)
		{
			if (this != &instance)
			{
				clear();

				reserve(instance.capacity());
				for (auto e : instance)
				{
					push_back(e);
				}

				return *this;
			}
		}

		vector<valueType>& operator=(vector<valueType> instance)
		{
			std::swap(_start, instance._start);
			std::swap(_finish, instance._finish);
			std::swap(_end_storage, instance._end_storage);

			return *this;
		}

		valueType& operator[](size_t num)
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
	void display_vector(const vector<T>& instance)
	{
		typename vector<T>::const_iterator it = instance.begin();
		//The compiler does not know const_iterator in "vector<valueType>"
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

	template<class Container>
	void display_Container(const Container& instance)
	{
		typename Container::const_iterator it = instance.begin();
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