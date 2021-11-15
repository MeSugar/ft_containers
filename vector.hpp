#ifndef VECTOR_H
# define VECTOR_H

#include <iostream>
#include <memory>
#include <exception>
#include "iterator.hpp"
#include "utility.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
		//Aliases
			typedef	T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename ft::Vector_iterator<value_type>			iterator;
			typedef size_t												size_type;
		//Constructors && destructor
			explicit Vector(const allocator_type& alloc = allocator_type())
			: _allocator(alloc)
			{
				init(0);
			}
			explicit Vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			: _allocator(alloc)
			{
				try {
					init(n); }
				catch(const std::exception& e) {
					throw ; }
				for (unsigned int i = 0; i < n; i++)
				{
					_allocator.construct(_last, val);
					_last++;
				}
			}
			~Vector<T>() { clear(); }
		//Methods
		iterator begin() { return iterator(_first); }
		iterator last() { return iterator(_last); }

		protected:	
		//Objects instatiation
			allocator_type	_allocator;
			pointer			_first, _last, _end;

			void	init(size_type n)
			{
				if (!n) {
					_first = NULL, _last = NULL, _end = NULL; }
				else
				{
					try
					{
						_first = _allocator.allocate(n);
						_last = _first;
						_end = _first + n;
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << std::endl;
						throw ;
					}
				}
			}
			void	destroy(pointer first, pointer last)
			{
				for ( ; first != last; first++)
					_allocator.destroy(first);
			}
			void	clear()
			{
				if (_first)
					destroy(_first, _last);
				_allocator.deallocate(_first, _end - _first);
				_first = 0, _last = 0, _end = 0;
			}
		
	};
	// std::ostream	&operator<<(std::ostream &o, Vector const &src);
}

#endif