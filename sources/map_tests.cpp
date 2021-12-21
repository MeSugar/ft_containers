#include "../includes/test.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


void    map_constructor_test()
{
	{
		std::ofstream ofs("./map_tests/ft_constructor_test");
		ft::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		ft::map<char,int> second (first.begin(),first.end());
		ft::map<char,int> third (second);
		ft::map<char,int,classcomp> fourth;                 // class as Compare
		bool(*fn_pt)(char,char) = fncomp;
		ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		ofs << "first contains:";
		for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); it++)
			ofs << ' ' << it->first << ' ' << it->second;
		ofs << std::endl;
		ofs << "second contains:";
		for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); it++)
			ofs << ' ' << it->first << ' ' << it->second;
		ofs << std::endl;
		ofs << "third contains:";
		for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); it++)
			ofs << ' ' << it->first << ' ' << it->second;
		ofs << std::endl;
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_constructor_test");
		std::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::map<char,int> second (first.begin(),first.end());
		std::map<char,int> third (second);
		std::map<char,int,classcomp> fourth;                 // class as Compare
		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		ofs << "first contains:";
		for (std::map<char, int>::iterator it = first.begin(); it != first.end(); it++)
			ofs << ' ' << it->first << ' ' << it->second;
		ofs << std::endl;
		ofs << "second contains:";
		for (std::map<char, int>::iterator it = second.begin(); it != second.end(); it++)
			ofs << ' ' << it->first << ' ' << it->second;
		ofs << std::endl;
		ofs << "third contains:";
		for (std::map<char, int>::iterator it = third.begin(); it != third.end(); it++)
			ofs << ' ' << it->first << ' ' << it->second;
		ofs << std::endl;
		ofs.close();
	}
}

void    map_operator_equals_test()
{
	{
		std::ofstream ofs("./map_tests/ft_operator_equals_test");
		ft::map<char,int> first;
		ft::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=ft::map<char,int>();  // and first is now empty

		ofs << "Size of first: " << first.size() << '\n';
		ofs << "Size of second: " << second.size() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_operator_equals_test");
		std::map<char,int> first;
		std::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=std::map<char,int>();  // and first is now empty

		ofs << "Size of first: " << first.size() << '\n';
		ofs << "Size of second: " << second.size() << '\n';
		ofs.close();
	}
}

void	map_begin_end_test()
{
	{
		std::ofstream ofs("./map_tests/ft_begin_end_test");
		ft::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_begin_end_test");
		std::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
}

void	map_rbegin_rend_test()
{
	{
		std::ofstream ofs("./map_tests/ft_rbegin_rend_test");
		ft::map<char,int> mymap;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		// show content:
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			ofs << rit->first << " => " << rit->second << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_rbegin_rend_test");
		std::map<char,int> mymap;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		// show content:
		std::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			ofs << rit->first << " => " << rit->second << '\n';
		ofs.close();
	}
}

void	map_empty_test()
{
	{
		std::ofstream ofs("./map_tests/ft_empty_test");
		ft::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		while (!mymap.empty())
		{
			ofs << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_empty_test");
		std::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		while (!mymap.empty())
		{
			ofs << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
		ofs.close();
	}
}

void	map_size_test()
{
	{
		std::ofstream ofs("./map_tests/ft_size_test");
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		ofs << "mymap.size() is " << mymap.size() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_size_test");
		std::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		ofs << "mymap.size() is " << mymap.size() << '\n';
		ofs.close();

	}
}

void	map_max_size_test()
{
	{
		std::ofstream ofs("./map_tests/ft_max_size_test");
		int i;
		ft::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
		for (i=0; i<1000; i++) mymap[i]=0;
		ofs << "The map contains 1000 elements.\n";
		}
		else ofs << "The map could not hold 1000 elements.\n";
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_max_size_test");
		int i;
		std::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
		for (i=0; i<1000; i++) mymap[i]=0;
		ofs << "The map contains 1000 elements.\n";
		}
		else ofs << "The map could not hold 1000 elements.\n";
		ofs.close();
	}
}

void	map_sq_brackets_operator_test()
{
	{
		std::ofstream ofs("./map_tests/ft_sq_brackets_operator_test");
		ft::map<char,std::string> mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];
		ofs << "mymap['a'] is " << mymap['a'] << '\n';
		ofs << "mymap['b'] is " << mymap['b'] << '\n';
		ofs << "mymap['c'] is " << mymap['c'] << '\n';
		ofs << "mymap['d'] is " << mymap['d'] << '\n';
		ofs << "mymap now contains " << mymap.size() << " elements.\n";
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_sq_brackets_operator_test");
		std::map<char,std::string> mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];
		ofs << "mymap['a'] is " << mymap['a'] << '\n';
		ofs << "mymap['b'] is " << mymap['b'] << '\n';
		ofs << "mymap['c'] is " << mymap['c'] << '\n';
		ofs << "mymap['d'] is " << mymap['d'] << '\n';
		ofs << "mymap now contains " << mymap.size() << " elements.\n";
		ofs.close();
	}
}

void	map_insert_test()
{
	{
		std::ofstream ofs("./map_tests/ft_insert_test");
		ft::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		// iterator invalidation check
		ft::map<char,int>::iterator it_inv = mymap.begin();
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second==false) {
			ofs << "element 'z' already existed";
		ofs << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
		if (mymap.begin() == it_inv)
			ofs << "it_inv is not invalidated" << std::endl; 

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		ofs << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		ofs << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_insert_test");
		std::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		// iterator invalidation check
		std::map<char,int>::iterator it_inv = mymap.begin();
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
			ofs << "element 'z' already existed";
		ofs << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

		if (mymap.begin() == it_inv)
			ofs << "it_inv is not invalidated" << std::endl; 

		// third insert function version (range insertion):
		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		ofs << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		ofs << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
}

void	map_erase_test()
{
	{
		std::ofstream ofs("./map_tests/ft_erase_test");
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;
		// insert some values:
		mymap['a']=10;
		ft::map<char,int>::iterator it_inv = mymap.begin();
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		mymap.erase ('c');                  // erasing by key
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		if (mymap.begin() == it_inv)
			ofs << "it_inv is not invalidated" << std::endl; 
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_erase_test");
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;
		// insert some values:
		mymap['a']=10;
		std::map<char,int>::iterator it_inv = mymap.begin();
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		mymap.erase ('c');                  // erasing by key
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		if (mymap.begin() == it_inv)
			ofs << "it_inv is not invalidated" << std::endl; 
		ofs.close();
	}
}

void	map_swap_test()
{
	{
		std::ofstream ofs("./map_tests/ft_swap_test");
		ft::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		ft::map<char,int>::iterator foo_it = foo.begin();
		ft::map<char,int>::iterator bar_it = bar.begin();
		foo.swap(bar);

		ofs << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		ofs << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		if (foo_it == bar.begin())
			ofs << "iterators remain valid: foo_it == bar.begin()" << std::endl;
		if (++foo_it == ++bar.begin())
			ofs << "++foo_it value == ++bar.begin(), value: " << foo_it->first << ' ' << foo_it->second << std::endl;
		if (bar_it == foo.begin())
			ofs << "iterators remain valid: bar_it == foo.begin()" << std::endl;
		if (++bar_it == ++foo.begin())
			ofs << "++bar_it value == ++foo.begin(), value: "  << bar_it->first << ' ' << bar_it->second << std::endl;
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_swap_test");
		std::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		std::map<char,int>::iterator foo_it = foo.begin();
		std::map<char,int>::iterator bar_it = bar.begin();
		foo.swap(bar);

		ofs << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		ofs << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		if (foo_it == bar.begin())
			ofs << "iterators remain valid: foo_it == bar.begin()" << std::endl;
		if (++foo_it == ++bar.begin())
			ofs << "++foo_it value == ++bar.begin(), value: " << foo_it->first << ' ' << foo_it->second << std::endl;
		if (bar_it == foo.begin())
			ofs << "iterators remain valid: bar_it == foo.begin()" << std::endl;
		if (++bar_it == ++foo.begin())
			ofs << "++bar_it value == ++foo.begin(), value: "  << bar_it->first << ' ' << bar_it->second << std::endl;
		ofs.close();
	}
}

void	map_clear_test()
{
	{
		std::ofstream ofs("./map_tests/ft_clear_test");
		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		ofs << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		ofs << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_clear_test");
		std::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		ofs << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		ofs << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
}

void	map_key_compare_test()
{
	{
		std::ofstream ofs("./map_tests/ft_key_compare_test");
		ft::map<char,int> mymap;
		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=10011;
		mymap['b']=20022;
		mymap['c']=30033;

		ofs << "mymap contains:\n";
		char highest = mymap.rbegin()->first;     // key value of last element
		ft::map<char,int>::iterator it = mymap.begin();
		do {
		ofs << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_key_compare_test");
		std::map<char,int> mymap;
		std::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=10011;
		mymap['b']=20022;
		mymap['c']=30033;

		ofs << "mymap contains:\n";
		char highest = mymap.rbegin()->first;     // key value of last element
		std::map<char,int>::iterator it = mymap.begin();
		do {
		ofs << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		ofs << '\n';
		ofs.close();
	}
}

void	map_value_compare_test()
{
	{
		std::ofstream ofs("./map_tests/ft_value_compare_test");
		ft::map<char,int> mymap;

		mymap['x']=10021;
		mymap['y']=20032;
		mymap['z']=30043;

		ofs << "mymap contains:\n";
		ft::pair<char,int> highest = *mymap.rbegin();          // last element
		ft::map<char,int>::iterator it = mymap.begin();
		do {
		ofs << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_value_compare_test");
		std::map<char,int> mymap;

		mymap['x']=10021;
		mymap['y']=20032;
		mymap['z']=30043;

		ofs << "mymap contains:\n";
		std::pair<char,int> highest = *mymap.rbegin();          // last element
		std::map<char,int>::iterator it = mymap.begin();
		do {
		ofs << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
		ofs.close();
	}
}

void	map_find_test()
{
	{
		std::ofstream ofs("./map_tests/ft_find_test");
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);
		// print content:
		ofs << "elements in mymap:" << '\n';
		ofs << "a => " << mymap.find('a')->second << '\n';
		ofs << "c => " << mymap.find('c')->second << '\n';
		ofs << "d => " << mymap.find('d')->second << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_find_test");
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);
		// print content:
		ofs << "elements in mymap:" << '\n';
		ofs << "a => " << mymap.find('a')->second << '\n';
		ofs << "c => " << mymap.find('c')->second << '\n';
		ofs << "d => " << mymap.find('d')->second << '\n';
		ofs.close();
	}
}

void	map_count_test()
{
	{
		std::ofstream ofs("./map_tests/ft_count_test");
		ft::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			ofs << c;
			if (mymap.count(c)>0)
				ofs << " is an element of mymap.\n";
			else 
				ofs << " is not an element of mymap.\n";
		}
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_count_test");
		std::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			ofs << c;
			if (mymap.count(c)>0)
				ofs << " is an element of mymap.\n";
			else 
				ofs << " is not an element of mymap.\n";
		}
		ofs.close();
	}
}

void	map_lower_upper_test()
{
	{
		std::ofstream ofs("./map_tests/ft_lower_upper_bound_test");
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_lower_upper_bound_test");
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ofs << it->first << " => " << it->second << '\n';
		ofs.close();
	}
}

void	map_equal_range_test()
{
	{
		std::ofstream ofs("./map_tests/ft_equal_range_test");
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		ofs << "lower bound points to: ";
		ofs << ret.first->first << " => " << ret.first->second << '\n';

		ofs << "upper bound points to: ";
		ofs << ret.second->first << " => " << ret.second->second << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_equal_range_test");
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		ofs << "lower bound points to: ";
		ofs << ret.first->first << " => " << ret.first->second << '\n';

		ofs << "upper bound points to: ";
		ofs << ret.second->first << " => " << ret.second->second << '\n';
		ofs.close();
	}
}

void	map_get_allocator_test()
{
	{
		std::ofstream ofs("./map_tests/ft_get_allocator_test");
		int psize;
		ft::map<char,int> mymap;
		ft::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(ft::map<char,int>::value_type)*5;

		ofs << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_get_allocator_test");
		int psize;
		std::map<char,int> mymap;
		std::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(std::map<char,int>::value_type)*5;

		ofs << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
		ofs.close();
	}
}

void	map_elements_order_test()
{
	{
		std::ofstream ofs("./map_tests/ft_elements_order_test");
		ft::map<std::string, int> mymap;
		mymap.insert(ft::pair<std::string, int>("ehe", 121));
		mymap.insert(ft::pair<std::string, int>("ehu", 122));
		mymap.insert(ft::pair<std::string, int>("bbag", 123));
		mymap.insert(ft::pair<std::string, int>("www", 124));
		mymap.insert(ft::pair<std::string, int>("bba", 125));
		mymap.insert(ft::pair<std::string, int>("aaa", 126));
		mymap.insert(ft::pair<std::string, int>("bhaa", 127));
		mymap.insert(ft::pair<std::string, int>("bbsasda", 128));
		mymap.insert(ft::pair<std::string, int>("ddzag", 129));
		mymap.insert(ft::pair<std::string, int>("dag", 130));
		mymap.insert(ft::pair<std::string, int>("czg", 131));
		mymap.insert(ft::pair<std::string, int>("ea", 132));
		mymap.insert(ft::pair<std::string, int>("qqa", 133));
		mymap.insert(ft::pair<std::string, int>("her", 134));
		mymap.insert(ft::pair<std::string, int>("wery", 135));
		mymap.insert(ft::pair<std::string, int>("aadtr", 136));
		mymap.insert(ft::pair<std::string, int>("utdf", 137));
		ofs << "mymap contains:\n";
		for (ft::map<std::string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			ofs << it->first << ' ' << it->second << std::endl;
		ofs.close();
	}
	{
		std::ofstream ofs("./map_tests/stl_elements_order_test");
		std::map<std::string, int> mymap;
		mymap.insert(std::pair<std::string, int>("ehe", 121));
		mymap.insert(std::pair<std::string, int>("ehu", 122));
		mymap.insert(std::pair<std::string, int>("bbag", 123));
		mymap.insert(std::pair<std::string, int>("www", 124));
		mymap.insert(std::pair<std::string, int>("bba", 125));
		mymap.insert(std::pair<std::string, int>("aaa", 126));
		mymap.insert(std::pair<std::string, int>("bhaa", 127));
		mymap.insert(std::pair<std::string, int>("bbsasda", 128));
		mymap.insert(std::pair<std::string, int>("ddzag", 129));
		mymap.insert(std::pair<std::string, int>("dag", 130));
		mymap.insert(std::pair<std::string, int>("czg", 131));
		mymap.insert(std::pair<std::string, int>("ea", 132));
		mymap.insert(std::pair<std::string, int>("qqa", 133));
		mymap.insert(std::pair<std::string, int>("her", 134));
		mymap.insert(std::pair<std::string, int>("wery", 135));
		mymap.insert(std::pair<std::string, int>("aadtr", 136));
		mymap.insert(std::pair<std::string, int>("utdf", 137));
		ofs << "mymap contains:\n";
		for (std::map<std::string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			ofs << it->first << ' ' << it->second << std::endl;
		ofs.close();
	}
}

void	map_execution_time_test(unsigned elements)
{
	std::vector<int> myvect = random_numbers_generator(elements);
	{
		struct timeval start, end;
		std::ofstream ofs("./map_tests/ft_execution_time_test");
		gettimeofday(&start, NULL);
		ft::map<int, int> mymap;
		for (unsigned i = 0; i < myvect.size(); i++)
			mymap.insert(ft::pair<int, int>(myvect[i], myvect[i]));
		gettimeofday(&end, NULL);
		double time_taken;
    	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
		ofs << "time taken by ft_map is : " << std::fixed << time_taken << std::setprecision(6);
		ofs << "sec" << std::endl;
		ofs.close();
	}
	{
		struct timeval start, end;
		std::ofstream ofs("./map_tests/stl_execution_time_test");
		gettimeofday(&start, NULL);
		std::map<int, int> mymap;
		for (unsigned i = 0; i < myvect.size(); i++)
			mymap.insert(std::pair<int, int>(myvect[i], myvect[i]));
		gettimeofday(&end, NULL);
		double time_taken;
    	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
		ofs << "time taken by stl_map is : " << std::fixed << time_taken << std::setprecision(6);
		ofs << "sec" << std::endl;
		ofs.close();
	}
}


void    map_test()
{
	mkdir("./map_tests", 0777);
	map_constructor_test();
	map_operator_equals_test();
	map_begin_end_test();
	map_rbegin_rend_test();
	map_empty_test();
	map_size_test();
	map_max_size_test();
	map_sq_brackets_operator_test();
	map_insert_test();
	map_erase_test();
	map_swap_test();
	map_clear_test();
	map_key_compare_test();
	map_value_compare_test();
	map_find_test();
	map_count_test();
	map_lower_upper_test();
	map_equal_range_test();
	map_get_allocator_test();
	map_elements_order_test();
	map_execution_time_test(10000);
}