#include "map.hpp"
// #include "vector.hpp"
#include <map>
#include <string>
#include <vector>

// #include <algorithm>
// #include <chrono>
// #include <iostream>
// #include <random>



// int main()
// {
// 	ft::node<std::string, int> nd1("ehe", 121);
// 	ft::node<std::string, int> nd2("ehu", 122);
// 	ft::node<std::string, int> nd3("bbag", 123);
// 	ft::node<std::string, int> nd4("www", 124);
// 	ft::node<std::string, int> nd5("bba", 125);
// 	ft::node<std::string, int> nd6("aaa", 126);
// 	ft::node<std::string, int> nd7("bhaa", 127);
// 	ft::node<std::string, int> nd8("bbsasda", 128);
// 	ft::node<std::string, int> nd9("ddzag", 129);
// 	ft::node<std::string, int> nd10("dag", 130);
// 	ft::node<std::string, int> nd11("czg", 131);
// 	ft::node<std::string, int> nd12("ea", 132);
// 	ft::node<std::string, int> nd13("qqa", 133);
// 	ft::node<std::string, int> nd14("her", 134);
// 	ft::node<std::string, int> nd15("wery", 135);
// 	ft::node<std::string, int> nd16("aadtr", 136);
// 	ft::node<std::string, int> nd17("utdf", 137);

// 	ft::RBTree<std::string, int>* tree = new ft::RBTree<std::string, int>;
// 	tree->add(nd1.value);
// 	tree->add(nd2.value);
// 	tree->add(nd3.value);
// 	tree->add(nd4.value);
// 	tree->add(nd5.value);
// 	tree->add(nd6.value);
// 	tree->add(nd7.value);
// 	tree->add(nd8.value);
// 	tree->add(nd9.value);
// 	tree->add(nd10.value);
// 	tree->add(nd11.value);
// 	tree->add(nd12.value);
// 	tree->add(nd13.value);
// 	tree->add(nd14.value);
// 	tree->add(nd15.value);
// 	tree->add(nd16.value);
// 	tree->add(nd17.value);

// 	//original map
// 	std::map<std::string, int>* mapTree = new std::map<std::string, int>;
// 	mapTree->insert(std::pair<std::string, int>("ehe", 121));
// 	mapTree->insert(std::pair<std::string, int>("ehu", 122));
// 	mapTree->insert(std::pair<std::string, int>("bbag", 123));
// 	mapTree->insert(std::pair<std::string, int>("www", 124));
// 	mapTree->insert(std::pair<std::string, int>("bba", 125));
// 	mapTree->insert(std::pair<std::string, int>("aaa", 126));
// 	mapTree->insert(std::pair<std::string, int>("bhaa", 127));
// 	mapTree->insert(std::pair<std::string, int>("bbsasda", 128));
// 	mapTree->insert(std::pair<std::string, int>("ddzag", 129));
// 	mapTree->insert(std::pair<std::string, int>("dag", 130));
// 	mapTree->insert(std::pair<std::string, int>("czg", 131));
// 	mapTree->insert(std::pair<std::string, int>("ea", 132));
// 	mapTree->insert(std::pair<std::string, int>("qqa", 133));
// 	mapTree->insert(std::pair<std::string, int>("her", 134));
// 	mapTree->insert(std::pair<std::string, int>("wery", 135));
// 	mapTree->insert(std::pair<std::string, int>("aadtr", 136));
// 	mapTree->insert(std::pair<std::string, int>("utdf", 137));

// 	std::map<std::string, int>::iterator it = mapTree->begin();
// 	mapTree->erase("qqa");
// 	mapTree->erase("ehe");
// 	std::cout << "their fukin' tree:" << std::endl;
// 	for (it = mapTree->begin(); it != mapTree->end(); ++it)
//     	std::cout << it->first << " => " << it->second << " => " << it._M_node->_M_color << '\n';
// 	std::cout << mapTree->size() << std::endl;

// 	std::cout << std::endl;

// 	//original map end
	
	
// 	// ft::node<std::string, int> nd18("utd", 138);
// 	tree->remove(nd13.value);
// 	tree->remove(nd1.value);

// 	std::cout << "my fukin' tree:" << std::endl;
// 	tree->inOrderHelper(tree->get_root());
// 	std::cout << tree->get_size() << std::endl;
// 	// std::cout << tree->height() << std::endl;
// 	std::cout << std::endl;

// 	// contains check
// 	// ft::node<std::string, int> nd18("utd", 138);
// 	// if (tree->contains(nd18.value))
// 	// 	std::cout << "YEAH" << std::endl;
// 	// else
// 	// 	std::cout << "NOPE" << std::endl;


// 	// std::cout << tree->height() << std::endl;
// 	// std::cout << tree->black_nodes(tree->get_root()) << std::endl;
// }


// tree test
// int main()
// {
// 	std::vector<int> numbers;

//     for(int i=0; i<100; i++)       // add 0-99 to the vector
// 	{
//         numbers.push_back(i);
// 	}
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
//     // for(int i=0; i<100; i++)        // print the first 40 randomly sorted numbers
// 	// {
//     //     std::cout << numbers[i] << std::endl;
// 	// }
// 	std::map<int, int> *mapTree = new std::map<int, int>;
// 	ft::RBTree<int, ft::pair<int, int> > *tree = new ft::RBTree<int, ft::pair<int, int> >;
// 	ft::node<ft::pair<int, int> > *nodes[100];
	
// 	for(int i=0; i<100; i++)
// 	{
// 		nodes[i] = new ft::node<ft::pair<int, int> >(ft::pair<int, int>(numbers[i], numbers[i] * 10));
// 	}
// 	for (int i = 0; i < 100; i++)
// 	{
// 		mapTree->insert(std::pair<int, int>(numbers[i], numbers[i] * 10));
// 	}
// 	mapTree->erase(numbers[15]);
// 	mapTree->erase(numbers[99]);
// 	mapTree->erase(numbers[10]);
// 	mapTree->erase(numbers[12]);
// 	mapTree->erase(numbers[55]);
// 	mapTree->erase(numbers[16]);
// 	mapTree->erase(numbers[77]);
// 	mapTree->erase(numbers[32]);
// 	// std::pair<std::map<int, int>::iterator, int> ppair = mapTree->insert(std::pair<int, int>(numbers[15], numbers[15] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[15], numbers[15] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[99], numbers[99] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[10], numbers[10] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[12], numbers[12] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[55], numbers[55] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[16], numbers[16] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[77], numbers[77] * 10));
// 	mapTree->insert(std::pair<int, int>(numbers[32], numbers[32] * 10));
	
// 	std::map<int, int>::iterator it = mapTree->begin();
// 	std::ofstream ofs1("test1");
// 	for (it = mapTree->begin(); it != mapTree->end(); ++it)
// 	{
//     	ofs1 << it->first << " => " << it->second << " => " << it._M_node->_M_color << '\n';
// 	}
// 	// it--;
// 	// std::cout << it._M_node->_M_color << ' ' << std::endl;
// 	// std::cout << (*it).first << ' ' << std::endl;

//     for(int i=0; i<100; i++)
// 	{
// 		tree->add(nodes[i]->value);
// 	}
// 	tree->remove(nodes[15]->value);
// 	tree->remove(nodes[99]->value);
// 	tree->remove(nodes[10]->value);
// 	tree->remove(nodes[12]->value);
// 	tree->remove(nodes[55]->value);
// 	tree->remove(nodes[16]->value);
// 	tree->remove(nodes[77]->value);
// 	tree->remove(nodes[32]->value);
// 	tree->add(nodes[15]->value);
// 	tree->add(nodes[99]->value);
// 	tree->add(nodes[10]->value);
// 	tree->add(nodes[12]->value);
// 	tree->add(nodes[55]->value);
// 	tree->add(nodes[16]->value);
// 	tree->add(nodes[77]->value);
// 	tree->add(nodes[32]->value);
// 	ofs1.close();
// 	std::ofstream ofs("test2");
// 	tree->inOrderHelper(tree->get_root(), ofs);
// 	std::cout << std::endl;
// 	ofs.close();

// 	// std::cout << tree->get_size() << std::endl;
// 	// std::cout << mapTree->size() << std::endl;
	// ft::map<int, int> mymap;
// 	// mymap.insert(nodes[15]->value);
// 	// mymap.insert(nodes[15]->value);
// 	// ft::map<int, int>::iterator myit;
// 	// myit = mymap.begin();
// 	// std::cout << myit->first << std::endl;
// 	// ft::map<int, int>::iterator it;

// 	// std::cout << ppair.first->first << ' ' << ppair.first->second << ' ' << ppair.second << std::endl;
// 	delete tree;
// 	delete mapTree;
// }



//insert tests
// int main ()
// {
// 	ft::map<char,int> mymap;

// 	// first insert function version (single parameter):
// 	mymap.insert ( ft::pair<char,int>('a',100) );
// 	mymap.insert ( ft::pair<char,int>('z',200) );

// 	ft::pair<ft::map<char,int>::iterator,bool> ret;
// 	ret = mymap.insert ( ft::pair<char,int>('z',500) );
// 	if (ret.second==false) {
// 		std::cout << "element 'z' already existed";
// 		std::cout << " with a value of " << ret.first->second << '\n';
// 	}

// 	// second insert function version (with hint position):
// 	ft::map<char,int>::iterator it = mymap.begin();
// 	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
// 	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

// 	// third insert function version (range insertion):
// 	ft::map<char,int> anothermap;
// 	anothermap.insert(mymap.begin(),mymap.find('c'));

// 	 // showing contents:
// 	std::cout << "mymap contains:\n";
// 	for (it=mymap.begin(); it!=mymap.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';
	
// 	std::cout << "anothermap contains:\n";
//  	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
// 	std::cout << it->first << " => " << it->second << '\n';
// 	return 0;
// }

// operator[] test
// int main ()
// {
//   ft::map<char,std::string> mymap;

//   mymap['a']="an element";
//   mymap['b']="another element";
//   mymap['c']=mymap['b'];

//   std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//   std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//   std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//   std::cout << "mymap['d'] is " << mymap['d'] << '\n';

//   std::cout << "mymap now contains " << mymap.size() << " elements.\n";

//   return 0;
// }

// constructors test
// bool fncomp (char lhs, char rhs) {return lhs<rhs;}

// struct classcomp {
//   bool operator() (const char& lhs, const char& rhs) const
//   {return lhs<rhs;}
// };

// int main ()
// {
//   ft::map<char,int> first;

//   first['a']=10;
//   first['b']=30;
//   first['c']=50;
//   first['d']=70;

//   ft::map<char,int> second (first.begin(),first.end());

//   ft::map<char,int> third (second);

//   ft::map<char,int,classcomp> fourth;                 // class as Compare

//   bool(*fn_pt)(char,char) = fncomp;
//   ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

//   return 0;
// }


// // operator= test
// int main ()
// {
//   ft::map<char,int> first;
//   ft::map<char,int> second;

//   first['x']=8;
//   first['y']=16;
//   first['z']=32;

//   second=first;                // second now contains 3 ints
//   first=ft::map<char,int>();  // and first is now empty

//   std::cout << "Size of first: " << first.size() << '\n';
//   std::cout << "Size of second: " << second.size() << '\n';
//   return 0;
// }


//begin test && const_iterator test
// int main ()
// {
//   ft::map<char,int> mymap;

//   mymap['b'] = 100;
//   mymap['a'] = 200;
//   mymap['c'] = 300;

//   // show content:
//   ft::map<char,int>::iterator it=mymap.begin();
//   it->second = 333;
// 	ft::map<char,int>::const_iterator itt = it;
// //   itt->second = 333;
//   for (; itt!=mymap.end(); ++itt)
//     std::cout << itt->first << " => " << itt->second << '\n';
// 	// ft::map<char,int>::iterator ittt = itt;

//   return 0;
// }

//rbegin && rend test
// int main ()
// {
//   ft::map<char,int> mymap;

//   mymap['x'] = 100;
//   mymap['y'] = 200;
//   mymap['z'] = 300;

//   // show content:
//   ft::map<char,int>::reverse_iterator rit = mymap.rbegin();
// //   ft::map<char,int>::iterator it = mymap.begin();
// //   std::map<char,int>::reverse_iterator ritt = theirmap.rbegin();
//   for (; rit!=mymap.rend(); ++rit)
//     std::cout << rit->first << " => " << rit->second << '\n';

// {
// 		const int range_int[] = {1458, -985, 58, 632, 65};
// 		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

// 		std::map<int, std::string> stl_map;
// 		ft::map<int, std::string> ft_map;

// 		for (int i = 0; i < 5; i++)
// 		{
// 			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
// 			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
// 		}


// 		std::map<int, std::string>::reverse_iterator stl_it = stl_map.rbegin();
// 		ft::map<int, std::string>::reverse_iterator ft_it = ft_map.rbegin();
	
// 		std::cout << stl_it->first << ' ' << stl_it->second << std::endl;
// 		std::cout << ft_it->first << ' ' << ft_it->second << std::endl;
// }

//   return 0;
// }

//empty test
// int main ()
// {
//   ft::map<char,int> mymap;

// 	std::cout << mymap.size() << std::endl;

//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;

// //   while (!mymap.empty())
// //   {
// //     std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
// //     mymap.erase(mymap.begin());
// //   }
// 	std::cout << mymap.size() << std::endl;
//   return 0;
// }

//max_size test
// int main ()
// {
//   int i;
//   ft::map<int,int> mymap;

//   if (mymap.max_size()>1000)
//   {
//     for (i=0; i<1000; i++) mymap[i]=0;
//     std::cout << "The map contains 1000 elements.\n";
//   }
//   else std::cout << "The map could not hold 1000 elements.\n";

//   return 0;
// }

//erase test
// int main ()
// {
//   ft::map<char,int> mymap;
//   ft::map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');                  // erasing by key

//   it=mymap.find ('e');
//   mymap.erase ( it, mymap.end() );    // erasing by range

// //   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
//   return 0;
// }

//swap test
// int main ()
// {
// 	ft::map<char,int> foo,bar;

// 	foo['x']=100;
// 	foo['y']=200;

// 	bar['a']=11;
// 	bar['b']=22;
// 	bar['c']=33;

// 	foo.swap(bar);

// 	std::cout << "foo size: " << foo.size() << std::endl;
// 	std::cout << "foo contains:\n";
// 	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';

// 	std::cout << "bar size: " << bar.size() << std::endl;
// 	std::cout << "bar contains:\n";
// 	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

//clear test
// int main ()
// {
//   ft::map<char,int> mymap;

//   mymap['x']=100;
//   mymap['y']=200;
//   mymap['z']=300;

//   std::cout << "mymap contains:\n";
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   mymap.clear();
//   mymap['a']=1101;
//   mymap['b']=2202;

//   std::cout << "mymap contains:\n";
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }


// // count test
// int main ()
// {
//   ft::map<char,int> mymap;
//   char c;

//   mymap ['a']=101;
//   mymap ['c']=202;
//   mymap ['f']=303;

//   for (c='a'; c<'h'; c++)
//   {
//     std::cout << c;
//     if (mymap.count(c)>0)
//       std::cout << " is an element of mymap.\n";
//     else 
//       std::cout << " is not an element of mymap.\n";
//   }

//   return 0;
// }

// //lower bound test
// int main ()
// {
//   ft::map<char,int> mymap;
//   ft::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   mymap['b']=40;
//   mymap['c']=60;
//   mymap['d']=80;
//   mymap['e']=100;

//   itlow=mymap.lower_bound ('b');  // itlow points to b
//   std::cout << "itlow points to: " << itlow->first << " => " << itlow->second << '\n';

//   itup=mymap.upper_bound ('d');   // itup points to e (not d!)
//   std::cout << "itup points to: " << itup->first << " => " << itup->second << '\n';


//   mymap.erase(itlow,itup);        // erases [itlow,itup)

//   // print content:
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

// // equal_range test
// int main ()
// {
//   ft::map<char,int> mymap;

//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;

//   ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
//   ret = mymap.equal_range('b');

//   std::cout << "lower bound points to: ";
//   std::cout << ret.first->first << " => " << ret.first->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << ret.second->first << " => " << ret.second->second << '\n';

//   return 0;
// }


//get_allocator test
// int main ()
// {
//   int psize;
//   ft::map<char,int> mymap;
//   ft::pair<const char,int>* p;

//   // allocate an array of 5 elements using mymap's allocator:
//   p=mymap.get_allocator().allocate(5);

//   // assign some values to array
//   psize = sizeof(std::map<char,int>::value_type)*5;

//   std::cout << "The allocated array has a size of " << psize << " bytes.\n";

//   mymap.get_allocator().deallocate(p,5);

//   return 0;
// }