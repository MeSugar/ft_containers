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
				public:
					key_compare	comp;
					value_compare(key_compare c) : comp(c) {}
					bool operator() (const value_type& x, const value_type& y) const
					{ return comp(x.first, y.first); }
			};

			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename ft::RBTree<key_type, value_type>::iterator 				iterator;
			typedef typename ft::RBTree<key_type, value_type>::const_iterator			const_iterator;
			typedef typename ft::RBTree<key_type, value_type>::reverse_iterator			reverse_iterator;
			typedef typename ft::RBTree<key_type, value_type>::const_reverse_iterator	const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type				difference_type;
			typedef size_t																size_type;

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

			map(const map& x) { *this = x; }

			~map() { clear(); }

			map&	operator=(const map& x)
			{
				_allocator = x._allocator;
				_comp = x._comp;
				clear();
				insert(x.begin(), x.end());
				return *this;
			}

			// iterators
			iterator				begin() { return (iterator(_tree.minimum(_tree.get_root()), _tree.get_nil())); }
			const_iterator			begin() const { return (const_iterator(_tree.minimum(_tree.get_root()), _tree.get_nil())); }
			iterator				end() { return (iterator(_tree.get_nil(), _tree.get_nil())); }
			const_iterator			end() const { return (const_iterator(_tree.get_nil(), _tree.get_nil())); }
			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			reverse_iterator		rend() { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			// capacity
			bool		empty() const { return (_tree.get_size() == 0); }
			size_type	size() const { return _tree.get_size(); }
			size_type 	max_size() const { return _allocator.max_size(); }
			

			// element access
			mapped_type&	operator[](const key_type& k)
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
			void 					insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*first++);
			}

			void					erase(iterator position) { _tree.remove(*position); }
			size_type				erase(const key_type& k)
			{
				_tree.remove(k);
				return (1);
			}

			void					erase(iterator first, iterator last)
			{
				while (first != last)
					_tree.remove(*first++);
			}

			void					swap(map& x) { _tree.swap(x._tree); }
			void					clear() { erase(begin(), end()); }
			
			// observers
			key_compare		key_comp() const { return (key_compare()); }
			value_compare	value_comp() const { return (value_compare(key_compare())); }

			// operations
			iterator 		find(const key_type& k)
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(k);
				if (ptr != _tree.get_nil())
					return iterator(ptr, _tree.get_nil());
				return end();
			}

			size_type		count(const key_type& k) const
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(k);
				if (ptr != _tree.get_nil())
					return 1;
				return 0;
			}
			
			iterator		lower_bound(const key_type& k)
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(k);
				if (ptr != _tree.get_nil())
					return (--(iterator(_tree.successor(ptr), _tree.get_nil())));
				return end();

			}

			const_iterator	lower_bound(const key_type& k) const { return const_iterator(lower_bound(k)); }

			iterator								upper_bound(const key_type& k)
			{
				typename RBTree<Key, value_type>::pointer ptr = _tree.contains(k);
				if (ptr != _tree.get_nil())
					return iterator(_tree.successor(ptr), _tree.get_nil());
				return end();
			}

			const_iterator	upper_bound(const key_type& k) const { return const_iterator(upper_bound(k)); }
			
			pair<iterator, iterator>	equal_range(const key_type& k)
			{ return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{ return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			// allocator
			allocator_type			get_allocator() const { return _allocator; }

		protected:
			allocator_type					_allocator;
			key_compare						_comp;
			RBTree<key_type, value_type>	_tree;


	};
}


#endif