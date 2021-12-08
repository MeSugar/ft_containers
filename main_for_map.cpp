#include "map.hpp"
// #include "vector.hpp"
#include <map>
// #include <algorithm>
// #include <chrono>
// #include <iostream>
// #include <random>
// #include <vector>



int main()
{
	ft::node<std::string, int> nd1("ehe", 121);
	ft::node<std::string, int> nd2("ehu", 122);
	ft::node<std::string, int> nd3("bbag", 123);
	ft::node<std::string, int> nd4("www", 124);
	ft::node<std::string, int> nd5("bba", 125);
	ft::node<std::string, int> nd6("aaa", 126);
	ft::node<std::string, int> nd7("bhaa", 127);
	ft::node<std::string, int> nd8("bbsasda", 128);
	ft::node<std::string, int> nd9("ddzag", 129);
	ft::node<std::string, int> nd10("dag", 130);
	ft::node<std::string, int> nd11("czg", 131);
	ft::node<std::string, int> nd12("ea", 132);
	ft::node<std::string, int> nd13("qqa", 133);
	ft::node<std::string, int> nd14("her", 134);
	ft::node<std::string, int> nd15("wery", 135);
	ft::node<std::string, int> nd16("aadtr", 136);
	ft::node<std::string, int> nd17("utdf", 137);

	ft::RBTree<std::string, int>* tree = new ft::RBTree<std::string, int>;
	tree->add(nd1.value);
	tree->add(nd2.value);
	tree->add(nd3.value);
	tree->add(nd4.value);
	tree->add(nd5.value);
	tree->add(nd6.value);
	tree->add(nd7.value);
	tree->add(nd8.value);
	tree->add(nd9.value);
	tree->add(nd10.value);
	tree->add(nd11.value);
	tree->add(nd12.value);
	tree->add(nd13.value);
	tree->add(nd14.value);
	tree->add(nd15.value);
	tree->add(nd16.value);
	tree->add(nd17.value);

	std::cout << "my fukin' tree:" << std::endl;
	tree->inOrderHelper(tree->get_root());
	std::cout << std::endl;

	//original map
	std::map<std::string, int>* mapTree = new std::map<std::string, int>;
	mapTree->insert(std::pair<std::string, int>("ehe", 121));
	mapTree->insert(std::pair<std::string, int>("ehu", 122));
	mapTree->insert(std::pair<std::string, int>("bbag", 123));
	mapTree->insert(std::pair<std::string, int>("www", 124));
	mapTree->insert(std::pair<std::string, int>("bba", 125));
	mapTree->insert(std::pair<std::string, int>("aaa", 126));
	mapTree->insert(std::pair<std::string, int>("bhaa", 127));
	mapTree->insert(std::pair<std::string, int>("bbsasda", 128));
	mapTree->insert(std::pair<std::string, int>("ddzag", 129));
	mapTree->insert(std::pair<std::string, int>("dag", 130));
	mapTree->insert(std::pair<std::string, int>("czg", 131));
	mapTree->insert(std::pair<std::string, int>("ea", 132));
	mapTree->insert(std::pair<std::string, int>("qqa", 133));
	mapTree->insert(std::pair<std::string, int>("her", 134));
	mapTree->insert(std::pair<std::string, int>("wery", 135));
	mapTree->insert(std::pair<std::string, int>("aadtr", 136));
	mapTree->insert(std::pair<std::string, int>("utdf", 137));

	std::map<std::string, int>::iterator it = mapTree->begin();
	std::cout << "their fukin' tree:" << std::endl;
	for (it = mapTree->begin(); it != mapTree->end(); ++it)
    	std::cout << it->first << " => " << it->second << " => " << it._M_node->_M_color << '\n';
	
	// ft::node<std::string, int> nd18("utd", 138);
	tree->remove(nd17.value);

	// contains check
	// ft::node<std::string, int> nd18("utd", 138);
	// if (tree->contains(nd18.value))
	// 	std::cout << "YEAH" << std::endl;
	// else
	// 	std::cout << "NOPE" << std::endl;


	// std::cout << tree->height() << std::endl;
	// std::cout << tree->black_nodes(tree->get_root()) << std::endl;
}


// tree test
// int main()
// {
// 	std::vector<int> numbers;

//     for(int i=0; i<100; i++)       // add 0-99 to the vector
//         numbers.push_back(i);
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
//     for(int i=0; i<100; i++)        // print the first 40 randomly sorted numbers
//         std::cout << numbers[i] << std::endl;
// 	std::map<int, int> *mapTree = new std::map<int, int>;
// 	ft::RBTree<int, int> *tree = new ft::RBTree<int, int>;
// 	ft::node<int, int> *nodes[100];
	
// 	for(int i=0; i<100; i++)
// 	{
// 		nodes[i] = new ft::node<int, int>(numbers[i], numbers[i]);
// 	}
// 	for (int i = 0; i < 100; i++)
// 		mapTree->insert(std::pair<int, int>(numbers[i], numbers[i]));
	
	
// 	std::map<int, int>::iterator it = mapTree->begin();
// 	std::ofstream ofs1("test1");
// 	for (it = mapTree->begin(); it != mapTree->end(); ++it)
//     	ofs1 << it->first << " => " << it->second << " => " << it._M_node->_M_color << '\n';
//     for(int i=0; i<100; i++)
// 	{
// 		tree->add(nodes[i]->value);
// 	}
// 	std::ofstream ofs("test2");
// 	tree->inOrderHelper(tree->get_root());
// 	std::cout << std::endl;

// }


