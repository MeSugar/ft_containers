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
			~vector<T>() { clean(); }
		
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
			void					resize(size_type n, value_type val = value_type())
			{
				if (size() > n)
					erase(begin() + n, end());
				else if (size() < n)
					insert(end(), n - size(), val);
			}

			size_type				capacity() const { return (_end - _first); }
			bool					empty() const { return (size() == 0); }
			void					reserve(size_type n)
			{
				if (max_size() < n)
					throw (std::length_error("size requested by vector::reserve > vector::max_size()"));
				else if (capacity() < n)
				{
					pointer		_old_first = _first;
					pointer		_old_last = _last;
					size_type	_old_size = size();
					size_type	_old_capacity = capacity();
					try
					{
						init(n);
						for (size_type i = 0; i < _old_size; i++)
						{
							_allocator.construct(_last, *(_old_first + i));
							_last++;
						}
					}
					catch(const std::exception& e) {
						throw ; }
					if (_old_first)
						destroy(_old_first, _old_last);
					_allocator.deallocate(_old_first, _old_capacity);
				}
			}

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
			void	assign(InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(ft::random_access_iterator_tag))
				{
            		difference_type n = ft::distance(first, last);
					try
					{
						if (n > static_cast<difference_type>(capacity()))
						{
							clean();
							init(n);
						}
						else
							destroy(_first, _first + n);
					}
					catch(const std::exception& e) {
						throw ; }
					_last = _first;
					for (unsigned int i = 0; i < n; i++)
					{
						_allocator.construct(_last, first[i]);
						_last++;
					}
				}
				else
				{
					std::cout << "Error : invalid input iterator" << std:: endl;
					throw ;
				}
			}

			void	assign(size_type n, const value_type& val)
			{
				if (n > capacity())
				{
					clean();
					init(n);
				}
				else
					destroy(_first, _first + n);
				_last = _first;
				while (n--)
				{
					_allocator.construct(_last, val);
					_last++;
				}
			}

			void	push_back(const value_type& val) { insert(end(), val); }
			void	pop_back() { erase(end() - 1); }
			iterator	insert(iterator position, const value_type& val)
			{
				difference_type n = position - begin();
				insert(position, 1, val);
				return (begin() + n);
			}

			void	insert(iterator position, size_type n, const value_type& val)
			{
				difference_type dist_to_pos = ft::distance(begin(), position);
				difference_type dist_to_end = ft::distance(position, end());
				if (n == 0)
					return ;
				else if (max_size() - size() < n)
					throw (std::length_error("size requested by vector::insert > vector::max_size()"));
				else if (size() + n > capacity())
					reserve(size() + capacity() > 0 ? size() * 2 : 1);
				pointer pos = _first + dist_to_pos;
				_last = pos + n + dist_to_end;
				for ( ; dist_to_end; dist_to_end--)
				{
					_allocator.construct(pos + n + dist_to_end - 1, pos[dist_to_end - 1]);
					_allocator.destroy(pos + dist_to_end - 1);
				}
				for (size_type i = 0; i < n; i++)
					*(pos + i) = val;
			}

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(ft::random_access_iterator_tag))
				{
					difference_type dist_to_pos = ft::distance(begin(), position);
					difference_type dist_to_end = ft::distance(position, end());
					size_type		n = ft::distance(first, last);
					if (n == 0)
						return ;
					else if (max_size() - size() < n)
						throw (std::length_error("size requested by vector::insert > vector::max_size()"));
					else if (size() + n > capacity())
						reserve(size() + capacity() > 0 ? size() * 2 : 1);
					pointer pos = _first + dist_to_pos;
					_last = pos + n + dist_to_end;
					for ( ; dist_to_end; dist_to_end--)
					{
						_allocator.construct(pos + n + dist_to_end - 1, pos[dist_to_end - 1]);
						_allocator.destroy(pos + dist_to_end - 1);
					}
					for (size_type i = 0; i < n; i++)
						*(pos + i) = first[i];
				}	
			}

			iterator	erase(iterator position) { return (erase(position, position + 1)); }
			iterator	erase(iterator first, iterator last)
			{
				if (last < first)
					return (first);
				size_type dist_to_first = ft::distance(begin(), first);
				size_type dist_to_end = ft::distance(last, end());
				size_type diff = ft::distance(first, last);
				// std::cout << diff << std::endl;
				destroy(first.base(), last.base());
				_last = _first + dist_to_first;
				for (size_type i = 0; i < dist_to_end; i++)
				{
				
					_allocator.construct(_last, *(_first + dist_to_first + diff + i));
					_last++;
				}
				return (begin() + dist_to_first);
			}

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

			void	clean()
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