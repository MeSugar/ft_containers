#ifndef TREE_H
# define TREE_H

#include "utility.hpp"

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
			pointer get_root() { return _root; }
			int		get_size() { return _size; }

			void	add(value_type& val = value_type())
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
					add(_root, new_node);
					_size++;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
					throw ;
				}
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
				if (!ptr->parent->parent->left || ptr->parent->parent->left->is_black)
					return rotate(ptr);
				 // color flip
				if (ptr->parent->parent->left)
					ptr->parent->parent->left->is_black = true;
				ptr->parent->parent->is_black = false;
				ptr->parent->is_black = true;
			}

			void	check_color(pointer ptr)
			{
				if (ptr == _root)
					return ;
				if (!ptr->is_black && !ptr->parent->is_black)
					correct_tree(ptr);
				check_color(ptr->parent);
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

			size_type	black_nodes(pointer ptr)
			{
				if (!ptr)
					return 1;
				size_type right_black_nodes = black_nodes(ptr->right);
				size_type left_black_nodes = black_nodes(ptr->left);
				if (left_black_nodes != right_black_nodes)
					correct_tree(ptr);
				if (ptr->is_black)
					left_black_nodes++;
				return left_black_nodes;
			}

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
						return ;
					}
					return add(parent->right, new_node);
				}
				if (!parent->left)
				{
					parent->left = new_node;
					new_node->parent = parent;
					new_node->is_leftchild = true;
					return ;
				}
				return add(parent->left, new_node);
				check_color(new_node);
			}
	};
}

#endif