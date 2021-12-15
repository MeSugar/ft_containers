#ifndef TREE_H
# define TREE_H

#include "utility.hpp"
#include <fstream>


namespace ft
{
	template <class T>
	class node
	{
		public:
			typedef T					value_type;
			// typedef const T				const_value_type;
			typedef	node<value_type>*	pointer;
			typedef	node<value_type>&	reference;

			value_type					value;
			pointer						parent;
			pointer						right;
			pointer						left;	
			bool						is_black;

			// constructors & destructor
			node() : value(NULL), parent(NULL), right(NULL), left(NULL), is_black(false) {}
			
			node(const value_type &val) : value(val), parent(NULL), right(NULL),
					left(NULL), is_black(false) {}
			
			node(const node &other): value(other.value), parent(other.parent), right(other.right),
					left(other.left), is_black(other.is_black) {}

			~node() {}

			node	&operator=(const node &other)
			{
				value = other.value;
				parent = other.parent;
				right = other.right;
				left = other.left;
				is_black = other.is_black;
			}

			bool	operator==(const node &other) { return (value.first == other.value.first); }
			// bool	operator<(const node &other) { return (value.first < other.value.first); }
	};

	template <class Key, class T, class Compare = ft::less<Key>, class node_t = node<T>, class Alloc = std::allocator<node_t> >
	class RBTree
	{
		public:
			// type aliases
			typedef	Key										key_type;
			typedef T										value_type;
			typedef Compare									key_compare;
			typedef	node_t									node_type;
			typedef	Alloc									allocator_type;
			typedef typename allocator_type::pointer		pointer;
			typedef size_t									size_type;
			typedef ft::RBTree_iterator<node_type>			iterator;
			typedef ft::RBTree_const_iterator<node_type>	const_iterator;

			// constructors & destructor
			RBTree()
			{
				_NIL = _allocator.allocate(1);
				_allocator.construct(_NIL, value_type());
				_NIL->is_black = true;
				_NIL->parent = _NIL;
				_NIL->right = _NIL;
				_NIL->left = _NIL;
				_root = _NIL;
				_size = 0; 
			}
			~RBTree() {}

			// methods
			pointer		get_root() const { return _root; }
			pointer		get_nil() const { return _NIL; }
			size_type	get_size() const { return _size; }

			void	add(const value_type &val)
			{
				try
				{
					pointer new_node = _allocator.allocate(1);
					_allocator.construct(new_node, val);
					new_node->parent = NULL;
					new_node->right = _NIL;
					new_node->left = _NIL;
					add(new_node);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
					throw ;
				}
			}

			void	remove(value_type &val)
			{
				pointer ptr = contains(val);
				if (ptr != _NIL)
					remove(ptr);
			}

			// size_type	height()
			// {
			// 	if (!_root)
			// 		return 0;
			// 	return (height(_root) - 1);
			// }

			// size_type	height(pointer ptr)
			// {
			// 	if (ptr == _NIL)
			// 		return 0;
			// 	size_type left_height = height(ptr->left) + 1;
			// 	size_type right_height = height(ptr->right) + 1;
			// 	if (left_height > right_height)
			// 		return left_height;
			// 	return right_height;
			// }

			pointer		minimum(pointer ptr)
			{
				while (ptr->left != _NIL)
					ptr = ptr->left;
				return ptr;
			}

			pointer		maximum(pointer ptr)
			{
				while (ptr->right != _NIL)
					ptr = ptr->right;
				return ptr;
			}

			pointer		predecessor(pointer ptr)
			{
				if (ptr->left != _NIL)
					return (maximum(ptr->left));
				pointer tmp = ptr->parent;
				while (tmp != _NIL && ptr == tmp->left)
				{
					ptr = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}

			pointer		successor(const pointer ptr)
			{
				if (ptr->right != _NIL)
					return (minimum(ptr->right));
				pointer tmp = ptr->parent;
				while (tmp != _NIL && ptr == tmp->right)
				{
					ptr = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}

			size_type	black_nodes(pointer ptr)
			{
				if (ptr == _NIL)
					return 1;
				size_type right_black_nodes = black_nodes(ptr->right);
				size_type left_black_nodes = black_nodes(ptr->left);
				if (left_black_nodes != right_black_nodes)
				{
					std::cout << "error: tree contains wrong number of black nodes" << std::endl;
				}
				if (ptr->is_black == true)
					left_black_nodes++;
				return left_black_nodes;
			}

			void inOrderHelper(pointer ptr, std::ostream &ofs)
			{				
				if (ptr != _NIL)
				{
					inOrderHelper(ptr->left, ofs);
					ofs << ptr->value.first << " => " << ptr->value.second << " => " << ptr->is_black << '\n';
					inOrderHelper(ptr->right, ofs);
				} 
			}

			pointer	contains(const value_type &val) { return contains(val, _root); }
			pointer	contains(const key_type &key) { return contains(key, _root); }
			pointer	contains(pointer position, const value_type &val) { return contains(val, position); }

		protected:
			allocator_type		_allocator;
			pointer				_root;
			pointer				_NIL;
			size_type			_size;
			key_compare			_comp;

			void	left_rotate(pointer ptr)
			{
				pointer	tmp = ptr->right;
				ptr->right = tmp->left;
				if (tmp->left != _NIL)
					tmp->left->parent = ptr;
				tmp->parent = ptr->parent;
				if (ptr->parent == _NIL)
					_root = tmp;
				else if (ptr == ptr->parent->left)
					ptr->parent->left = tmp;
				else
					ptr->parent->right = tmp;
				tmp->left = ptr;
				ptr->parent = tmp;
			}

			void	right_rotate(pointer ptr)
			{
				pointer	tmp = ptr->left;
				ptr->left = tmp->right;
				if (tmp->right != _NIL)
					tmp->right->parent = ptr;
				tmp->parent = ptr->parent;
				if (ptr->parent == _NIL)
					_root = tmp;
				else if (ptr == ptr->parent->left)
					ptr->parent->left = tmp;
				else
					ptr->parent->right = tmp;
				tmp->right = ptr;
				ptr->parent = tmp;
			}

			void	transplant(pointer ptr1, pointer ptr2)
			{
				if (ptr1->parent == _NIL)
					_root = ptr2;
				else if (ptr1 == ptr1->parent->left)
					ptr1->parent->left = ptr2;
				else
					ptr1->parent->right = ptr2;
				ptr2->parent = ptr1->parent;
			}

			void	add(pointer ptr)
			{
				pointer	entry = _root;
				pointer	new_parent = _NIL;
				while (entry != _NIL)
				{
					new_parent = entry;
					if (_comp(ptr->value.first, entry->value.first))
						entry = entry->left;
					else
						entry = entry->right;
				}
				ptr->parent = new_parent;
				if (ptr->parent == _NIL)
					_root = ptr;
				else if (_comp(ptr->value.first, new_parent->value.first))
					new_parent->left = ptr;
				else
					new_parent->right = ptr;
				ptr->left = _NIL;
				ptr->right = _NIL;
				_size++;
				add_color_fix(ptr);
				_NIL->parent = maximum(_root);
			}

			void	add_color_fix(pointer ptr)
			{
				pointer	aunt = _NIL;
				while (ptr->parent->is_black == false)
				{
					if (ptr->parent == ptr->parent->parent->left)	//ptr is in the left subtree
					{
						aunt = ptr->parent->parent->right;
						if (aunt->is_black == false)	// aunt is red – color_flip
						{
							ptr->parent->is_black = true;
							aunt->is_black = true;
							ptr->parent->parent->is_black = false;
							ptr = ptr->parent->parent;
						}
						else	// aunt is black – rotate
						{
							if (ptr == ptr->parent->right)
							{
								ptr = ptr->parent;
								left_rotate(ptr);
							}
							ptr->parent->is_black = true;
							ptr->parent->parent->is_black = false;
							right_rotate(ptr->parent->parent);
						}
					}
					else // ptr is in the right subtree
					{
						aunt = ptr->parent->parent->left;
						if (aunt->is_black == false)	// aunt is red – color_flip
						{
							ptr->parent->is_black = true;
							aunt->is_black = true;
							ptr->parent->parent->is_black = false;
							ptr = ptr->parent->parent;
						}
						else	// aunt is black – rotate
						{
							if (ptr == ptr->parent->left)
							{
								ptr = ptr->parent;
								right_rotate(ptr);
							}
							ptr->parent->is_black = true;
							ptr->parent->parent->is_black = false;
							left_rotate(ptr->parent->parent);
						}
					}
					if (ptr == _root)
						break ;
				}
				_root->is_black = true;
				black_nodes(_root);
			}

			void	remove(pointer ptr)
			{
				pointer	min, tmp;
				min = ptr;
				tmp = NULL; 
				bool	min_original_color = min->is_black;
				if (ptr->left == _NIL)
				{
					tmp = ptr->right;
					transplant(ptr, ptr->right);
				}
				else if (ptr->right == _NIL)
				{
					tmp = ptr->left;
					transplant(ptr, ptr->left);
				}
				else
				{
					min = minimum(ptr->right);
					min_original_color = min->is_black;
					tmp = min->right;
					if (min->parent == ptr)
						tmp->parent = min;
					else
					{
						transplant(min, min->right);
						min->right = ptr->right;
						min->right->parent = min;
					}
					transplant(ptr, min);
					min->left = ptr->left;
					min->left->parent = min;
					min->is_black = ptr->is_black;
				}
				if (min_original_color == true)
					remove_color_fix(tmp);
				destroy_n_dealloc(ptr);
				_size--;
				_NIL->parent = maximum(_root);
			}

			void	remove_color_fix(pointer ptr)
			{
				pointer	tmp = _NIL;
				while (ptr != _root && ptr->is_black == true)
				{
					if (ptr == ptr->parent->left)
					{
						tmp = ptr->parent->right;
						if (tmp->is_black == false)
						{
							tmp->is_black = true;
							ptr->parent->is_black = false;
							left_rotate(ptr->parent);
							tmp = ptr->parent->right;
						}
						if (tmp->left->is_black == true && tmp->right->is_black == true)
						{
							tmp->is_black = false;
							ptr = ptr->parent;
						}
						else
						{ 
							if (tmp->right->is_black == true)
							{
								tmp->left->is_black = true;
								tmp->is_black = false;
								right_rotate(tmp);
								tmp = ptr->parent->right;
							}
							tmp->is_black = ptr->parent->is_black;
							ptr->parent->is_black = true;
							tmp->right->is_black = true;
							left_rotate(ptr->parent);
							ptr = _root;
						}
					}
					else
					{
						tmp = ptr->parent->left;
						if (tmp->is_black == false)
						{
							tmp->is_black = true;
							ptr->parent->is_black = false;
							right_rotate(ptr->parent);
							tmp = ptr->parent->left;
						}
						if (tmp->left->is_black == true && tmp->right->is_black == true)
						{
							tmp->is_black = false;
							ptr = ptr->parent;
						}
						else
						{ 
							if (tmp->left->is_black)
							{
								tmp->right->is_black = true;
								tmp->is_black = false;
								left_rotate(tmp);
								tmp = ptr->parent->left;
							}
							tmp->is_black = ptr->parent->is_black;
							ptr->parent->is_black = true;
							tmp->left->is_black = true;
							right_rotate(ptr->parent);
							ptr = _root;
						}
					}
				}
				ptr->is_black = true;
				black_nodes(_root);
			}

			pointer	contains(const value_type &val, pointer ptr)
			{
				if (ptr == _NIL)
					return _NIL;
				if (ptr->value.first == val.first)
					return ptr;
				if (_comp(val.first, ptr->value.first))
					return contains(val, ptr->left);
				return contains(val, ptr->right);
			}

			pointer	contains(const key_type &key, pointer ptr)
			{
				if (ptr == _NIL)
					return _NIL;
				if (ptr->value.first == key)
					return ptr;
				if (_comp(key, ptr->value.first))
					return contains(key, ptr->left);
				return contains(key, ptr->right);
			}

			void	destroy_n_dealloc(pointer ptr)
			{
				_allocator.destroy(ptr);
				_allocator.deallocate(ptr, 1);
			}
	};
}

#endif