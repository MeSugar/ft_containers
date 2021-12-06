#include "map.hpp"
// #include "vector.hpp"
#include <map>

// template <class T>
// class node
// {
// 	public:
// 		T data;
// 		node *parent;
// 		node *right;
// 		node *left;
// 		node(T new_data) : data(new_data), parent(0), right(0), left(0) {}
// };


// template <class T, class U>
// void add(T data, U object)
// {
// 	if (object && object->data && data >= object->data)
// 	{
// 		if (!object->right)
// 		{
// 			object->right = new node<T>(data);
// 			object->right->parent = object;
// 			return ;
// 		}
// 		return add(data, object->right);
// 	}
// 	if (!object->left)
// 	{
// 		object->left = new node<T>(data);
// 		object->left->parent = object;
// 		return ;
// 	}
// 	return add(data, object->left);
// }

// t_node *create_tree(int *arr)
// {
// 	t_node *head;
// 	t_node *tmp;
// 	head = new t_node();

// 	head->data = arr[0];
// 	head->parent = 0;
// 	head->right = 0;
// 	head->left = 0;
// 	int i = 1;
// 	tmp = head;

// 	while (i < 8)
// 	{
// 		if (tmp->left && arr[i] < tmp->data)
// 			tmp = tmp->left;
// 		else if (tmp->right && arr[i] >= tmp->data)
// 			tmp = tmp->right;
// 		else if (!tmp->left && arr[i] < tmp->data)
// 		{
// 			tmp->left = new t_node();
// 			tmp->left->left = 0;
// 			tmp->left->right = 0;
// 			tmp->left->data = arr[i];
// 			tmp->left->parent = tmp;
// 			i++;
// 			tmp = head;
// 		}
// 		else if (!tmp->right && arr[i] >= tmp->data)
// 		{
// 			tmp->right = new t_node();
// 			tmp->right->left = 0;
// 			tmp->right->right = 0;
// 			tmp->right->data = arr[i];
// 			tmp->right->parent = tmp;
// 			i++;
// 			tmp = head;
// 		}
// 	}
// 	return head;
// }

// template <class T>
// void preorder_traversal(node<T> *tree)
// {
// 	// bool	is_printed = false;
// 	node<T>	*tmp;
// 	node<T>	*to_go_right;

// 	tmp = tree;
// 	to_go_right = tree;
// 	while (tmp)
// 	{
// 		std::cout << tmp->data << std::endl;
// 		if (tmp->right)
// 			to_go_right = tmp;
// 		if (tmp->left)
// 			tmp = tmp->left;
// 		else if (!tmp->left)
// 		{
// 			while (tmp != to_go_right)
// 				tmp = tmp->parent;
// 		}
// 		if (tmp == to_go_right)
// 		{
// 			to_go_right = tmp->parent;			
// 			tmp = tmp->right;
// 			std::cout << tmp->data << std::endl;
// 			if (tmp->right)
// 				to_go_right = tmp;
// 			if (tmp->left)
// 				tmp = tmp->left;
// 		}
// 	}
// }

// template <typename T>
// node<T> *right_rotate(node<T> *ptr)
// {
// 	node<T> *tmp = ptr->left;
// 	ptr->left = tmp->right;
// 	ptr->left->parent = ptr;
// 	tmp->right = ptr;
// 	ptr->parent = tmp;
// 	tmp->parent = NULL;
// 	return (tmp);
// }

int main()
{
	// int arr[] = { 1, 24, -11,-10, 13, 1, -33, -44};
	// // node<int> *tree = create_tree(arr);
	// node<int> *tree = new node<int>(arr[0]);
	// for (int i = 1; i < 8; i++)
	// 	add(arr[i], tree);
	// tree = right_rotate(tree);
	// preorder_traversal(tree);
	// std::cout << tree->data << std::endl;
	// std::cout << tree->left->data << std::endl;
	// std::cout << tree->left->right->data << std::endl;
	// std::cout << tree->left->left->data << std::endl;
	// std::cout << tree->left->left->left->data << std::endl;
	// std::cout << tree->right->data << std::endl;
	// std::cout << tree->right->left->data << std::endl;
	// std::cout << tree->right->left->left->data << std::endl;

	// ft::node<int, int> nd(1, 2);
	// ft::RBTree<int, int>* tree = new ft::RBTree<int, int>;
	// std::cout << nd.value.first << " " << nd.value.second << std::endl;
	// tree->add(nd.value);
	// std::cout << tree->get_root()->value.first << ' ' << tree->get_root()->value.second << std::endl;
	// std::cout << tree->get_size() << std::endl;

	ft::node<std::string, int> nd1("ehe", 121);
	ft::node<std::string, int> nd2("ehu", 122);
	ft::node<std::string, int> nd3("www", 123);
	ft::node<std::string, int> nd4("bba", 124);
	ft::RBTree<std::string, int>* tree = new ft::RBTree<std::string, int>;
	tree->add(nd1.value);
	tree->add(nd2.value);
	tree->add(nd3.value);
	tree->add(nd4.value);
	std::cout << tree->height() << std::endl;
	std::cout << tree->black_nodes(tree->get_root()) << std::endl;
	// if (nd1.value.first > nd2.value.first)
	// 	std::cout << nd1.value.first << " is greater than " << nd2.value.first << std::endl;
	// else
	// 	std::cout << nd1.value.first << " is less than " << nd2.value.first << std::endl;
	
	
}
