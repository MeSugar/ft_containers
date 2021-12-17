#ifndef ITERATOR_H
# define ITERATOR_H

#include <stddef.h>
#include <typeinfo>

namespace ft
{
	// iterator category tag
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};

	// base iterator template
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		protected:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

	// iterator traits
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};

	// random_access_iterator
	template <class T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			// aliases
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

			// constructors && destructor
			random_access_iterator() {}
			random_access_iterator(pointer x) : ptr(x) {}
			random_access_iterator(random_access_iterator const &other) : ptr(other.ptr) {}
			~random_access_iterator() {}
			
			// overloads
			//  random_access_iterator &operator=(const random_access_iterator& other)
			//  {
			//  	ptr = other.ptr;
			//  	return (*this);
			//  }
			
			reference				operator*(void) const { return (*ptr); }
			reference				operator[](difference_type n) { return (*(ptr + n)); }
			
			random_access_iterator&	operator++(void)
			{
				ptr++;
				return (*this);
			}

			random_access_iterator	operator++(int)
			{
				random_access_iterator tmp = *this;
				ptr++;
				return (tmp);
			}

			random_access_iterator&	operator--(void)
			{
				ptr--;
				return (*this);
			}

			random_access_iterator	operator--(int)
			{
				random_access_iterator tmp = *this;
				ptr--;
				return (tmp);
			}

			random_access_iterator	operator+(difference_type n) const
			{
				random_access_iterator tmp(ptr + n);
				return tmp;
			}

			random_access_iterator	operator-(difference_type n) const
			{
				random_access_iterator tmp(ptr - n);
				return tmp;
			}

			difference_type			operator-(const random_access_iterator other) { return (ptr - other.ptr); }

			random_access_iterator	&operator+=(difference_type n)
			{
				ptr += n;
				return (*this);
			}

			random_access_iterator	&operator-=(difference_type n)
			{
				ptr -= n;
				return (*this);
			}

			pointer					operator->() { return &(operator*()); }
			bool					operator!=(random_access_iterator const &other) const { return (!(ptr == other.ptr)); }
			bool					operator==(random_access_iterator const &other) const { return (ptr == other.ptr); }
			bool					operator>(random_access_iterator const &other) const { return (ptr > other.ptr); }
			bool					operator<(random_access_iterator const &other) const { return (ptr < other.ptr); }
			bool					operator>=(random_access_iterator const &other) const { return (ptr >= other.ptr); }
			bool					operator<=(random_access_iterator const &other) const { return (ptr <= other.ptr); }
			pointer					base() const { return (ptr); }

		protected:
			pointer ptr;
	};

	// RBTree_iterator
	template <class T>
	class RBTree_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			// aliases
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		node_value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			node_pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			node_reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename T::value_type														value_type;
			typedef value_type*																	pointer;
			typedef value_type&																	reference;

			// constructors && destructor
			RBTree_iterator() {}
			RBTree_iterator(node_pointer x, node_pointer nil) : ptr(x), NIL(nil) {}
			RBTree_iterator(const RBTree_iterator &other) : ptr(other.ptr), NIL(other.NIL) {}
			virtual ~RBTree_iterator() {}
			
			node_pointer			get_value_pointer() const { return ptr; }
			node_pointer			get_nil_pointer() const { return NIL; }

			// overloads
			RBTree_iterator &operator=(const RBTree_iterator& other)
			{
				ptr = other.ptr;
				NIL = other.NIL;
				return (*this);
			}
			
			reference			operator*() const { return ptr->value; }
			pointer				operator->() const { return &ptr->value; }
			bool				operator==(const RBTree_iterator &other) { return (ptr == other.ptr); }
			bool				operator!=(const RBTree_iterator &other) { return (ptr != other.ptr); }

			RBTree_iterator&	operator++(void)
			{
				if (ptr->right != NIL) 
				{
					ptr = ptr->right;
					while (ptr->left != NIL)
						ptr = ptr->left;
				}
				else if (ptr->right->parent == ptr)
					ptr = ptr->right;
				else 
				{
					node_pointer tmp = ptr->parent;
					while (ptr == tmp->right)
					{
						ptr = tmp;
						tmp = tmp->parent;
					}
					if (ptr->right != tmp)
						ptr = tmp;
				}
				return (*this);
			}

			RBTree_iterator		operator++(int)
			{
				RBTree_iterator tmp = *this;
				operator++();
				return (tmp);
			}

			RBTree_iterator&	operator--(void)
			{
				if (ptr->is_black == false && ptr->parent->parent == ptr)
					ptr = ptr->right;
				else if (ptr->left != NIL)
				{
					node_pointer tmp = ptr->left;
					while (tmp->right != NIL)
					tmp = tmp->right;
					ptr = tmp;
				}
				else if (ptr == NIL)
					ptr = ptr->parent;
				else
				{
					node_pointer tmp = ptr->parent;
					while (ptr == tmp->left)
					{
						ptr = tmp;
						tmp = tmp->parent;
					}
					ptr = tmp;
				}
				return (*this);
			}

			RBTree_iterator	operator--(int)
			{
				RBTree_iterator tmp = *this;
				operator--();
				return (tmp);
			}

		protected:
			node_pointer ptr;
			node_pointer NIL;
	};

	// RBTree_const_iterator
	template <class T>
	class RBTree_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			// aliases
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		node_value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename T::value_type const												value_type;
			typedef value_type const*															data_pointer;
			typedef value_type const&															data_reference;

			// constructors && destructor
			RBTree_const_iterator() {}
			RBTree_const_iterator(pointer x, pointer nil) : ptr(x), NIL(nil) {}
			RBTree_const_iterator(const RBTree_const_iterator &other) : ptr(other.ptr), NIL(other.NIL) {}
			RBTree_const_iterator(const RBTree_iterator<T> &other) : ptr(other.get_value_pointer()), NIL(other.get_nil_pointer()) {}
			~RBTree_const_iterator() {}
			
			pointer	get_value_pointer() { return ptr; }
			pointer get_nil_pointer() { return NIL; }

			// overloads
			RBTree_const_iterator &operator=(const RBTree_const_iterator& other)
			{
				ptr = other.ptr;
				NIL = other.NIL;
				return (*this);
			}
			

			data_reference			operator*() const { return ptr->value; }
			data_pointer			operator->() const { return &ptr->value; }
			bool					operator==(const RBTree_const_iterator &other) { return (ptr == other.ptr); }
			bool					operator!=(const RBTree_const_iterator &other) { return (ptr != other.ptr); }

			RBTree_const_iterator&	operator++(void)
			{
				if (ptr->right != NIL) 
				{
					ptr = ptr->right;
					while (ptr->left != NIL)
						ptr = ptr->left;
				}
				else 
				{
					pointer tmp = ptr->parent;
					while (ptr == tmp->right)
					{
						ptr = tmp;
						tmp = tmp->parent;
					}
					if (ptr->right != tmp)
						ptr = tmp;
				}
				return (*this);
			}

			RBTree_const_iterator		operator++(int)
			{
				RBTree_const_iterator tmp = *this;
				operator++();
				return (tmp);
			}

			RBTree_const_iterator&	operator--(void)
			{
				if (ptr->is_black == false && ptr->parent->parent == ptr)
					ptr = ptr->right;
				else if (ptr->left != NIL)
				{
					pointer tmp = ptr->left;
					while (tmp->right != NIL)
					tmp = tmp->right;
					ptr = tmp;
				}
				else
				{
					pointer tmp = ptr->parent;
					while (ptr == tmp->left)
					{
						ptr = tmp;
						tmp = tmp->parent;
					}
					ptr = tmp;
				}
				return (*this);
			}

			RBTree_const_iterator	operator--(int)
			{
				RBTree_const_iterator tmp = *this;
				operator--();
				return (tmp);
			}

		protected:
			pointer ptr;
			pointer NIL;
	};

	// reverse_iterator
	template <class Iterator>
	class reverse_iterator
	{
		public:
			// aliases
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			// constructors && destructor
			reverse_iterator() : revIt() {}
			explicit reverse_iterator(iterator_type const &it) : revIt(it) {}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : revIt(rev_it.revIt) {}
			~reverse_iterator() {}
			
			// overloads
			reverse_iterator &operator=(reverse_iterator const &other)
			{
				revIt = other.revIt;
				return (*this);
			}
			
			reference operator*(void) const
			{ 
				iterator_type tmp = revIt;
				return (*(--tmp));
			}
			
			reference operator[](difference_type n) const { return (base()[-n - 1]); }
			
			reverse_iterator& operator++(void)
			{
				--revIt;
				return (*this);
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--revIt;
				return (tmp);
			}

			reverse_iterator& operator--(void)
			{
				++revIt;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++revIt;
				return (tmp);
			}
			
			reverse_iterator operator+(difference_type n) const
			{
				reverse_iterator tmp(revIt - n);
				return tmp;
			}

			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator tmp(revIt + n);
				return tmp;
			}

			reverse_iterator &operator+=(difference_type n)
			{
				revIt -= n;
				return (*this);
			}

			reverse_iterator &operator-=(difference_type n)
			{
				revIt += n;
				return (*this);
			}

			pointer operator->() const { return &(operator*()); }
			iterator_type base() const { return (revIt); }

		protected:
			iterator_type revIt;
	};

	// reverse_iterator overloads
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (!(lhs.base() == rhs.base())); }

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); }

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
											const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
    																const reverse_iterator<Iterator>& rhs) { return (lhs.base() - rhs.base()); }

	// basic methods
	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			++first;
			++n;
		}
		return n;
	};
}
	
#endif