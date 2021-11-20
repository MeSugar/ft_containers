#ifndef VECTOR_H
# define VECTOR_H

#include "iterator.hpp"
#include "utility.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			// aliases
			typedef	T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::random_access_iterator<value_type>			iterator;
			typedef typename ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type; 
			typedef size_t													size_type;
		
			// constructors && destructor
			explicit vector(const allocator_type& alloc = allocator_type())
			: _allocator(alloc)
			{
				init(0);
			}
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			: _allocator(alloc)
			{
				try
				{
					init(n);
					while (n--)
					{
						_allocator.construct(_last, val);
						_last++;
					}
				}
				catch(const std::exception& e) {
					throw ; }
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
					
			: _allocator(alloc)
			{
				if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(ft::random_access_iterator_tag))
				{
					try
					{
            			difference_type n = ft::distance(first, last);
						init(n);
						for (unsigned int i = 0; i < n; i++)
						{
							_allocator.construct(_last, first[i]);
							_last++;
						}
					}
					catch(const std::exception& e) {
						throw ; }
				}
				else
				{
					std::cout << "Error : invalid input iterator" << std:: endl;
					throw ;
				}
			}

			vector(const vector& x)
			{
				try
					{
						const_iterator itBegin(x.begin());
						const_iterator itEnd(x.end());
            			difference_type n = ft::distance(itBegin, itEnd);
						init(n);
						for (unsigned int i = 0; i < n; i++)
						{
							_allocator.construct(_last, itBegin[i]);
							_last++;
						}
					}
					catch(const std::exception& e) {
						throw ; }
			}
			~vector<T>() { clear(); }
		
			// iterators
			iterator				begin() { return iterator(_first); }
			iterator				end() { return iterator(_last); }
			const_iterator			begin() const { return const_iterator(_first); }
			const_iterator			end() const { return const_iterator(_last); }
			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			reverse_iterator		rend() { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			// capacity
			size_type				size() const { return (_last - _first); }
			size_type				max_size() const { return (_allocator.max_size()); }
			size_type				capacity() const { return (_end - _first); }
			bool					empty() const { return (!_first); }

			// element access
			reference 				operator[](size_type n) { return *(_first + n); }
			const_reference			operator[](size_type n) const { return *(_first + n); }
			reference				at(size_type n)
			{
				if (n >= size())
					throw (std::out_of_range("vector::at() access denied at position >= vector::size()"));
				return operator[](n);
			}
			const_reference			at(size_type n) const
			{
				if (n >= size())
					throw (std::out_of_range("vector::at() access denied at position >= vector::size()"));
				return operator[](n);
			}
			reference				front() { return *_first; }
			const_reference			front() const { return *_first; }
			reference				back() { return *(_last - 1); }
			const_reference			back() const { return *(_last - 1); }

			// modifiers
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last)
			{
				difference_type n = ft::distance(first, last);
				// if (n > capacity())
				// {
				// 	clear();
				// 	init(dist);
				// }
				// else
				// 	destroy(_first, _first + dist);
				while (first != last)
				{
					_first = first->();
				}
			}
			// void	push_back(const value_type& val)
			// {

			// }

		protected:
			allocator_type	_allocator;
			pointer			_first, _last, _end;

			// private methods
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
	//  std::ostream	&operator<<(std::ostream &o, vector const &src);
}

#endif