#ifndef TREE_H
# define TREE_H

#include "utility.hpp"
#include <fstream>


namespace ft
{
	template <class Key, class T>
	class node
	{
		public:
			typedef	Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;

			value_type					value;
			node<key_type, mapped_type>	*parent;
			node<key_type, mapped_type>	*right;
			node<key_type, mapped_type>	*left;	
			bool						is_leftchild;
			bool						is_black;

			// constructors & destructor
			node() : value(NULL), parent(NULL), right(NULL), left(NULL),
					is_leftchild(false), is_black(false) {}

			node(key_type key, mapped_type val) : value(ft::pair<key_type, mapped_type>(key, val)), parent(NULL), right(NULL), left(NULL),
									is_leftchild(false), is_black(false) {}
			
			node(value_type& val = value_type()) : value(val), parent(NULL), right(NULL), left(NULL),
									is_leftchild(false), is_black(false) {}

			node(const node &other): value(other.value), parent(other.parent), right(other.right), left(other.left),
								is_leftchild(other.is_leftchild), is_black(other.is_black) {}

			~node() {}

			node	&operator=(const node &other)
			{
				value = other.value;
				parent = other.parent;
				right = other.right;
				left = other.left;
				is_leftchild = other.is_leftchild;
				is_black = other.is_black;
			}

			bool	operator==(const node &other) { return (value.first == other.value.first); }
			// bool	operator<(const node &other) { return (value.first < other.value.first); }
	};

	template <class Key, class T, class Compare = ft::less<Key>, class node = node<Key, T>, class Alloc = std::allocator<node> >
	class RBTree
	{
		public:
			// type aliases
			typedef	Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef	node									node_type;
			typedef	Alloc									allocator_type;
			typedef typename allocator_type::pointer		pointer;
			typedef size_t									size_type;

			// constructors & destructor
			RBTree() : _root(NULL), _size(0) {}
			~RBTree() {}

			// methods
			pointer		get_root() { return _root; }
			size_type	get_size() { return _size; }

			void	add(value_type &val)
			{
				try
				{
					pointer new_node = _allocator.allocate(1);
					_allocator.construct(new_node, val);
					if (!_root)
					{
						_root = new_node;
						_root->is_black = true;
						_size++;
						return ;
					}
					else
						add(_root, new_node);
					_size++;
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
				if (ptr)
					remove(ptr);
			}

			void	left_rotate(pointer ptr)
			{
				pointer	tmp = ptr->right;
				ptr->right = tmp->left;
				if (ptr->right)
				{
					ptr->right->parent = ptr;
					ptr->right->is_leftchild = false;
				}
				if (!ptr->parent)
				{
					_root = tmp;
					tmp->parent = NULL;
				}
				else
				{
					tmp->parent = ptr->parent;
					if (ptr->is_leftchild)
					{
						tmp->is_leftchild = true;
						tmp->parent->left = tmp;
					}
					else
					{
						tmp->is_leftchild = false;
						tmp->parent->right = tmp;
					}
				}
				ptr->parent = tmp;
				ptr->is_leftchild = true;
				tmp->left = ptr;
			}

			void	right_rotate(pointer ptr)
			{
				pointer	tmp = ptr->left;
				ptr->left = tmp->right;
				if (ptr->left)
				{
					ptr->left->parent = ptr;
					ptr->left->is_leftchild = true;
				}
				if (!ptr->parent)
				{
					_root = tmp;
					tmp->parent = NULL;
				}
				else
				{
					tmp->parent = ptr->parent;
					if (ptr->is_leftchild)
					{
						tmp->is_leftchild = true;
						tmp->parent->left = tmp;
					}
					else
					{
						tmp->is_leftchild = false;
						tmp->parent->right = tmp;
					}
				}
				ptr->parent = tmp;
				ptr->is_leftchild = false;
				tmp->right = ptr;
			}

			void	left_right_rotate(pointer ptr)
			{
				left_rotate(ptr->left);
				right_rotate(ptr);
			}

			void	right_left_rotate(pointer ptr)
			{
				right_rotate(ptr->right);
				left_rotate(ptr);
			}

			void	rotate(pointer ptr)
			{
				if (ptr->is_leftchild)
				{
					if (ptr->parent->is_leftchild)
					{
						right_rotate(ptr->parent->parent);
						ptr->is_black = false;
						ptr->parent->is_black = true;
						if (ptr->parent->right)
							ptr->parent->right->is_black = false;
						return ;
					}
					right_left_rotate(ptr->parent->parent);
					ptr->is_black = true;
					ptr->right->is_black = false;
					ptr->left->is_black = false;
					return ;
				}
				if (!ptr->parent->is_leftchild)
				{
					left_rotate(ptr->parent->parent);
					ptr->is_black = false;
					ptr->parent->is_black = true;
					if (ptr->parent->left)
						ptr->parent->left->is_black = false;
					return ;
				}
				left_right_rotate(ptr->parent->parent);
				ptr->is_black = true;
				ptr->right->is_black = false;
				ptr->left->is_black = false;
			}

			void	correct_tree(pointer ptr)
			{
				if (ptr->parent->is_leftchild) // aunt is node->parent->parent->right
				{
					if (!ptr->parent->parent->right || ptr->parent->parent->right->is_black)
						return rotate(ptr);
					// color flip
					if (ptr->parent->parent->right) 
						ptr->parent->parent->right->is_black = true;
					ptr->parent->parent->is_black = false;
					ptr->parent->is_black = true;
					return ;
				}
				// aunt is node->parent->parent->left
				if (ptr->parent->parent && (!ptr->parent->parent->left || ptr->parent->parent->left->is_black))
					return rotate(ptr);
				 // color flip
				if (ptr->parent->parent->left)
					ptr->parent->parent->left->is_black = true;
				ptr->parent->parent->is_black = false;
				ptr->parent->is_black = true;
			}

			void	add_fix_color(pointer ptr)
			{
				if (ptr == _root)
				{
					ptr->is_black = true;
					black_nodes(_root);
					return ;
				}
				if (ptr->parent->parent && !ptr->is_black && !ptr->parent->is_black)
					correct_tree(ptr);
				if (ptr->parent)
					add_fix_color(ptr->parent);
			}

			size_type	height()
			{
				if (!_root)
					return 0;
				return (height(_root) - 1);
			}

			size_type	height(pointer ptr)
			{
				if (!ptr)
					return 0;
				size_type left_height = height(ptr->left) + 1;
				size_type right_height = height(ptr->right) + 1;
				if (left_height > right_height)
					return left_height;
				return right_height;
			}

			pointer		minimum(pointer ptr)
			{
				while (ptr->left)
					ptr = ptr->left;
				return ptr;
			}

			pointer		maximum(pointer ptr)
			{
				while (ptr->right)
					ptr = ptr->right;
				return ptr;
			}

			pointer		predecessor(pointer ptr)
			{
				if (ptr->left)
					return (maximum(ptr->left));
				pointer tmp = ptr->parent;
				while (tmp && ptr == tmp->left)
				{
					ptr = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}

			pointer		successor(pointer ptr)
			{
				if (ptr->right)
					return (minimum(ptr->right));
				pointer tmp = ptr->parent;
				while (tmp && ptr == tmp->right)
				{
					ptr = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}

			size_type	black_nodes(pointer ptr)
			{
				if (!ptr)
					return 1;
				size_type right_black_nodes = black_nodes(ptr->right);
				size_type left_black_nodes = black_nodes(ptr->left);
				if (left_black_nodes != right_black_nodes)
				{
					std::cout << "error: tree contains wrong number of black nodes" << std::endl;
				}
				if (ptr->is_black)
					left_black_nodes++;
				return left_black_nodes;
			}

			void preOrderHelper(pointer ptr) 
			{
				if (ptr)
				{
					std::cout << ptr->value.first << " ";
					preOrderHelper(ptr->left);
					preOrderHelper(ptr->right);
				} 
			}

			void inOrderHelper(pointer ptr, std::ostream &ofs)
			{				
				if (ptr)
				{
					inOrderHelper(ptr->left, ofs);
					ofs << ptr->value.first << " => " << ptr->value.second << " => " << ptr->is_black << '\n';
					inOrderHelper(ptr->right, ofs);
				} 
			}

			pointer	contains(value_type &val) { return contains(val, _root); }

		protected:
			allocator_type		_allocator;
			pointer				_root;
			size_type			_size;
			key_compare			_comp;

			void	add(pointer parent, pointer new_node)
			{
				if (_comp(parent->value.first, new_node->value.first))
				{
					if (!parent->right)
					{
						parent->right = new_node;
						new_node->parent = parent;
						new_node->is_leftchild = false;
						add_fix_color(new_node);
					}
					else
						add(parent->right, new_node);
				}
				else
				{
					if (!parent->left)
					{
						parent->left = new_node;
						new_node->parent = parent;
						new_node->is_leftchild = true;
						add_fix_color(new_node);
					}
					else
						add(parent->left, new_node);
				}
			}

			void	transplant(pointer ptr1, pointer ptr2)
			{
				if (!ptr1->parent)
					_root = ptr2;
				else if (ptr1 == ptr1->parent->left)
				{
					ptr1->parent->left = ptr2;
					if (ptr2)
						ptr2->is_leftchild = true;
				}
				else
				{
					ptr1->parent->right = ptr2;
					if (ptr2)
						ptr2->is_leftchild = false;
				}
				if (ptr2)
					ptr2->parent = ptr1->parent;
			}

			void	remove_fix_color(pointer ptr)
			{
				pointer	tmp = NULL;
				while (ptr && ptr != _root && ptr->is_black)
				{
					if (ptr == ptr->parent->left)
					{
						tmp = ptr->parent->right;
						if (!tmp->is_black)
						{
							tmp->is_black = true;
							ptr->parent->is_black = false;
							left_rotate(ptr->parent);
							tmp = ptr->parent->right;
						}
						if (tmp->left->is_black && tmp->right->is_black)
						{
							tmp->is_black = false;
							ptr = ptr->parent;
						}
						else
						{ 
							if (tmp->right->is_black)
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
						if (!tmp->is_black)
						{
							tmp->is_black = true;
							ptr->parent->is_black = false;
							right_rotate(ptr->parent);
							tmp = ptr->parent->left;
						}
						if (tmp->right->is_black && tmp->right->is_black)
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
				if (ptr)
					ptr->is_black = true;
			}

			void	remove(pointer ptr)
			{
				pointer	min, tmp;
				min = ptr;
				tmp = NULL; 
				bool	min_original_color = min->is_black;
				if (!ptr->left)
				{
					tmp = ptr->right;
					transplant(ptr, ptr->right);
				}
				else if (!ptr->right)
				{
					tmp = ptr->left;
					transplant(ptr, ptr->left);
				}
				else
				{
					min = minimum(ptr->right);
					min_original_color = min->is_black;
					tmp = min->right;
					if (min->parent == ptr && tmp)
						tmp->parent = min;
					else
					{
						transplant(min, min->right);
						min->right = ptr->right;
						if (min->right)
							min->right->parent = min;
					}
					transplant(ptr, min);
					min->left = ptr->left;
					min->left->parent = min;
					min->is_black = ptr->is_black;
				}
				if (min_original_color == true)
					remove_fix_color(tmp);
				destroy_n_dealloc(ptr);
				_size--;
			}
			
			pointer	contains(value_type &val, pointer ptr)
			{
				if (!ptr)
					return NULL;
				if (ptr->value.first == val.first)
					return ptr;
				if (_comp(val.first, ptr->value.first))
					return contains(val, ptr->left);
				return contains(val, ptr->right);
			}

			void	destroy_n_dealloc(pointer ptr)
			{
				_allocator.destroy(ptr);
				_allocator.deallocate(ptr, 1);
			}
	};
}

#endif