#ifndef MAP_H
# define MAP_H

#include "iterator.hpp"
#include "utility.hpp"
#include "tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
			// type aliases
			typedef	Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef Compare													key_compare;
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					key_compare	comp;
					value_compare(key_compare c) : comp(c) {}

				public:
					bool operator() (const value_type& x, const value_type& y) const
					{ return comp(x.first, y.first); }
			};
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

			// observers
			key_compare		key_comp() const { return (key_compare()); }
			value_compare	value_comp() const { return (value_compare(key_compare())); }
		protected:
			allocator_type _allocator;


	};
}


#endif