#ifndef ITERATOR_H
# define ITERATOR_H

#include <stddef.h>

namespace ft
{
	//Iterator category tag
	struct random_access_iterator_tag {};

	//Iterator base class
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		protected:
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
		// iterator() { std::cout << "base_iterator created" << std::endl; }
	};

	//Iterator traits class
	template <class Iterator>
	class iterator_traits
	{
		public:
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
		// iterator_traits()
		// {
		// 	std::cout << "iterator_traits created" << std::endl;
		// 	std::cout << sizeof(value_type) << std::endl;
		// }

	};

	template <class T>
	class iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
		// iterator_traits() { std::cout << "iterator_traits * created" << std::endl; }

	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
		// iterator_traits() { std::cout << "const iterator_traits * created" << std::endl; }

	};

	//Vector itarator
	template <class T>
	class Vector_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			//Aliases
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;


			//Constructors && destructor
			Vector_iterator() {}
			Vector_iterator(pointer x) : ptr(x) {}
			Vector_iterator(Vector_iterator const &other) : ptr(other.ptr) {}
			~Vector_iterator() {}
			
			//Overloads
			// Vector_iterator &operator=(const Vector_iterator& other)
			// {
			// 	ptr = other.ptr;
			// 	return (*this);
			// }
			
			reference operator*(void) const { return (*ptr); }
			
			Vector_iterator& operator++(void)
			{
				ptr++;
				return (*this);
			}

			Vector_iterator operator++(int)
			{
				Vector_iterator tmp = *this;
				ptr++;
				return (tmp);
			}

			Vector_iterator& operator--(void)
			{
				ptr--;
				return (*this);
			}

			Vector_iterator operator--(int)
			{
				Vector_iterator tmp = *this;
				ptr--;
				return (tmp);
			}

			Vector_iterator operator+(difference_type n) const
			{
				Vector_iterator tmp(ptr + n);
				return tmp;
			}
			
			Vector_iterator operator+(difference_type n) const
			{
				Vector_iterator tmp(ptr + n);
				return tmp;
			}

			bool operator!=(Vector_iterator const &other) const { return !(ptr == other.ptr); }
			bool operator==(Vector_iterator const &other) const { return (ptr == other.ptr); }
			bool operator>(Vector_iterator const &other) const { return (ptr > other.ptr); }
			bool operator<(Vector_iterator const &other) const { return (ptr < other.ptr); }
			bool operator>=(Vector_iterator const &other) const { return (ptr >= other.ptr); }
			bool operator<=(Vector_iterator const &other) const { return (ptr <= other.ptr); }

		protected:
			pointer ptr;
	};
}

	
#endif