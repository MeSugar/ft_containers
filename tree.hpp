#ifndef TREE_H
# define TREE_H

template <typename value_type>
class node
{
	public:
		value_type			value;
		node<value_type>	*parent;
		node<value_type>	*right;
		node<value_type>	*left;
		bool				is_leftchild;
		bool				is_black;

		node() : value(NULL), parent(NULL), right(NULL), left(NULL),
				is_leftchild(false), is_black(false) {}

		node(value_type &val) : value(val), parent(NULL), right(NULL), left(NULL),
								is_leftchild(false), is_black(false) {}

		node(node &other): value(other.val), parent(other.parent), right(other.right), left(other.left),
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

		bool	operator==(const node &other) { return (value == other.value); }
};

template <typename T>
class RBTree
{
	public:
		typedef T	value_type;
		node<value_type>	*root;
		int					size;



};

#endif