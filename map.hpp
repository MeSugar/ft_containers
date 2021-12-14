#ifndef MAP_H
# define MAP_H

#include "iterator.hpp"
#include "utility.hpp"
#include "tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
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
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename ft::RBTree<key_type, value_type>::iterator 			iterator;
			typedef typename ft::RBTree<key_type, value_type>::const_iterator		const_iterator;
			typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type			difference_type; 
			typedef size_t															size_type;

			// constructors & destructor
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _comp(comp), _tree() {}


			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _comp(comp), _tree()
			{
				try {
					insert(first, last); }
				catch (const std::exception& e) {
					throw ; }
			}

			map(const map& x) : _allocator(x._allocator), _comp(x._comp), _tree(x._tree) {}

			// map&	operator=(const map& x)
			// {
			// 	clear();
			// 	_allocator = x._allocator;
			// 	_comp = x._comp;
			// 	_tree = x._tree;
			// }

			// iterators
			iterator				begin() { return (iterator(_tree.minimum(_tree.get_root()), _tree.get_nil())); }
			const_iterator			begin() const { return (const_iterator(_tree.minimum(_tree.get_root()), _tree.get_nil())); }
			iterator				end() { return (iterator(_tree.get_nil(), _tree.get_nil())); }

			// capacity
			size_type				size() const { return _tree.get_size(); }

			// element access
			mapped_type&			operator[](const key_type& k)
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(k);
				if (ptr == _tree.get_nil())
					_tree.add(ft::make_pair(k, mapped_type()));
				return (_tree.contains(k))->value.second;
			}

			// modifiers
			pair<iterator, bool>	insert(const value_type& val)
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(val);
				if (ptr == _tree.get_nil())
				{
					_tree.add(val);
					return ft::make_pair(iterator(ptr, _tree.get_nil()), true);
				}
				return ft::make_pair(iterator(ptr, _tree.get_nil()), false);
			}

			iterator				insert(iterator position, const value_type& val)
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(position.get_value_pointer(), val);
				if (ptr != _tree.get_nil())
					return iterator(ptr, _tree.get_nil());
				_tree.add(val);
				return iterator(ptr, _tree.get_nil());
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*first++);
			}
			
			// observers
			key_compare				key_comp() const { return (key_compare()); }
			value_compare			value_comp() const { return (value_compare(key_compare())); }

			// operations
			iterator 				find(const key_type& k)
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(k);
				if (ptr != _tree.get_nil())
					return iterator(ptr, _tree.get_nil());
				return end();
			}
 




		protected:
			allocator_type					_allocator;
			key_compare						_comp;
			RBTree<key_type, value_type>	_tree;


	};
}


#endif