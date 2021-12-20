#include "../includes/test.hpp"

void	constructor_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_constructor_test");
		// constructors used in the same order as described above:
		ft::vector<int> first;                                // empty vector of ints
		ft::vector<int> second (40,100);                       // four ints with value 100
		ft::vector<int> third (second.begin(),second.end());  // iterating through second
		ft::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		if (ofs.is_open())
		{
			ofs << "The contents of first are:";
			for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of second are:";
			for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of third are:";
			for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of fourth are:";
			for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of fifth are:";
			for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
		}
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_constructor_test");
		// constructors used in the same order as described above:
		std::vector<int> first;                                // empty vector of ints
		std::vector<int> second (40,100);                       // four ints with value 100
		std::vector<int> third (second.begin(),second.end());  // iterating through second
		std::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		if (ofs.is_open())
		{
			ofs << "The contents of first are:";
			for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of second are:";
			for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of third are:";
			for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of fourth are:";
			for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
			ofs << "The contents of fifth are:";
			for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
				ofs << ' ' << *it;
			ofs << '\n';
		}
		ofs.close();
	}
}

void	operator_equals_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_operator_equals_test");
		ft::vector<int> foo (3,0);
		ft::vector<int> bar (5,0);

		bar = foo;
		foo = ft::vector<int>();

		ofs << "Size of foo: " << int(foo.size()) << '\n';
		ofs << "Size of bar: " << int(bar.size()) << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_operator_equals_test");
		std::vector<int> foo (3,0);
		std::vector<int> bar (5,0);

		bar = foo;
		foo = std::vector<int>();

		ofs << "Size of foo: " << int(foo.size()) << '\n';
		ofs << "Size of bar: " << int(bar.size()) << '\n';
		ofs.close();
	}
}

void	begin_end_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_begin_end_test");
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);
		ofs << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			ofs << ' ' << *it;
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_begin_end_test");
		std::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);
		ofs << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			ofs << ' ' << *it;
		ofs << '\n';
		ofs.close();
	}
}

void	rbegin_rend_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_rbegin_rend_test");
		ft::vector<int> myvector (5);  // 5 default-constructed ints
		ft::vector<int>::reverse_iterator rit = myvector.rbegin();
		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;
		ofs << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		ofs << ' ' << *it;
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_rbegin_rend_test");
		std::vector<int> myvector (5);  // 5 default-constructed ints
		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;
		ofs << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			ofs << ' ' << *it;
		ofs << '\n';
		ofs.close();
	}
}

void	size_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_size_test");
		ft::vector<int> myints;
		ofs << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
			ofs << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		ofs << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		ofs << "3. size: " << myints.size() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_size_test");
		std::vector<int> myints;
		ofs << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
			ofs << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		ofs << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		ofs << "3. size: " << myints.size() << '\n';
		ofs.close();
	}
}

void	max_size_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_max_size_test");
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		ofs << "size: " << myvector.size() << "\n";
		ofs << "capacity: " << myvector.capacity() << "\n";
		ofs << "max_size: " << myvector.max_size() << "\n";
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_max_size_test");
		std::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		ofs << "size: " << myvector.size() << "\n";
		ofs << "capacity: " << myvector.capacity() << "\n";
		ofs << "max_size: " << myvector.max_size() << "\n";
		ofs.close();
	}
}

void	resize_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_resize_test");
		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		ofs << "myvector contains:";
		for (unsigned int i=0;i<myvector.size();i++)
		ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_resize_test");
		std::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		ofs << "myvector contains:";
		for (unsigned int i=0;i<myvector.size();i++)
		ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
}

void	capacity_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_capacity_test");
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		ofs << "size: " << (int) myvector.size() << '\n';
		ofs << "capacity: " << (int) myvector.capacity() << '\n';
		ofs << "max_size: " << (int) myvector.max_size() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_capacity_test");
		std::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		ofs << "size: " << (int) myvector.size() << '\n';
		ofs << "capacity: " << (int) myvector.capacity() << '\n';
		ofs << "max_size: " << (int) myvector.max_size() << '\n';
		ofs.close();
	}
}

void	vector_test()
{
    mkdir("./vector_tests", 0777);
	constructor_test();
	operator_equals_test();
	begin_end_test();
	rbegin_rend_test();
	size_test();
	max_size_test();
	resize_test();
	capacity_test();

}
