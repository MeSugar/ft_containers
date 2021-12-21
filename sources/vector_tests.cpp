#include "../includes/test.hpp"

void	vector_constructor_test()
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

void	vector_operator_equals_test()
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

void	vector_begin_end_test()
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

void	vector_rbegin_rend_test()
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

void	vector_size_test()
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

void	vector_max_size_test()
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

void	vector_resize_test()
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

void	vector_capacity_test()
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

void	vector_empty_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_empty_test");
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		ofs << "total: " << sum << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_empty_test");
		std::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		ofs << "total: " << sum << '\n';
		ofs.close();
	}
}

void	vector_reserve_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_reserve_test");
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		ofs << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			ofs << "capacity changed: " << sz << '\n';
			}
		}

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		ofs << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			ofs << "capacity changed: " << sz << '\n';
			}
		}
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_reserve_test");
				ft::vector<int>::size_type sz;

		std::vector<int> foo;
		sz = foo.capacity();
		ofs << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			ofs << "capacity changed: " << sz << '\n';
			}
		}

		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		ofs << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			ofs << "capacity changed: " << sz << '\n';
			}
		}
		ofs.close();
	}
}

void	vector_sq_brackets_operator_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_sq_brackets_operator_test");
		ft::vector<int> myvector (10);   // 10 zero-initialized elements

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		ofs << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_sq_brackets_operator_test");
		std::vector<int> myvector (10);   // 10 zero-initialized elements

		std::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		ofs << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
}

void	vector_at_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_at_test");
		ft::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			ofs << ' ' << myvector.at(i);
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_at_test");
		std::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			ofs << ' ' << myvector.at(i);
		ofs << '\n';
		ofs.close();
	}
}

void	vector_front_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_front_test");
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		ofs << "myvector.front() is now " << myvector.front() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_front_test");
		std::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		ofs << "myvector.front() is now " << myvector.front() << '\n';
		ofs.close();
	}
}

void	vector_back_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_back_test");
		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_back_test");
		std::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
}

void	vector_assign_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_assign_test");
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		ft::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.
		ofs << "first contains:";
		for (unsigned i=0; i<first.size() ; i++)
			ofs << ' ' << first[i];
		ofs << '\n';
		ofs << "second contains:";
		for (unsigned i=0; i<second.size() ; i++)
			ofs << ' ' << second[i];
		ofs << '\n';
		ofs << "third contains:";
		for (unsigned i=0; i<third.size() ; i++)
			ofs << ' ' << third[i];
		ofs << '\n';
		ofs << "Size of first: " << int (first.size()) << '\n';
		ofs << "Size of second: " << int (second.size()) << '\n';
		ofs << "Size of third: " << int (third.size()) << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_assign_test");
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		std::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.
		ofs << "first contains:";
		for (unsigned i=0; i<first.size() ; i++)
			ofs << ' ' << first[i];
		ofs << '\n';
		ofs << "second contains:";
		for (unsigned i=0; i<second.size() ; i++)
			ofs << ' ' << second[i];
		ofs << '\n';
		ofs << "third contains:";
		for (unsigned i=0; i<third.size() ; i++)
			ofs << ' ' << third[i];
		ofs << '\n';
		ofs << "Size of first: " << int (first.size()) << '\n';
		ofs << "Size of second: " << int (second.size()) << '\n';
		ofs << "Size of third: " << int (third.size()) << '\n';
		ofs.close();
	}
}

void	vector_push_back_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_push_back_test");
		ft::vector<int> myvector;
		int myint[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };

		for (unsigned i = 0; i < 9; i++)
			myvector.push_back(myint[i]);
		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs << "myvector stores " << int(myvector.size()) << " numbers.\n";
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_push_back_test");
		std::vector<int> myvector;
		int myint[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
		
		for (unsigned i = 0; i < 9; i++)
			myvector.push_back(myint[i]);
		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs << "myvector stores " << int(myvector.size()) << " numbers.\n";
		ofs.close();
	}
}

void	vector_pop_back_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_pop_back_test");
		ft::vector<int> myvector;
		int myint[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
		int sum (0);
		for (unsigned i = 0; i < 9; i++)
			myvector.push_back(myint[i]);
		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}
		ofs << "The elements of myvector add up to " << sum << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_pop_back_test");
		std::vector<int> myvector;
		int myint[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
		int sum (0);
		for (unsigned i = 0; i < 9; i++)
			myvector.push_back(myint[i]);
		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}
		ofs << "The elements of myvector add up to " << sum << '\n';
		ofs.close();
	}
}

void	vector_insert_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_insert_test");
		ft::vector<int> myvector (3,100);
		ft::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		ft::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		ofs << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			ofs << ' ' << *it;
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_insert_test");
		std::vector<int> myvector (3,100);
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		ofs << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			ofs << ' ' << *it;
		ofs << '\n';
		ofs.close();
	}
}

void	vector_erase_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_erase_test");
		ft::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_erase_test");
		std::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
}

void	vector_swap_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_swap_test");
		ft::vector<int> foo (9,100);   // three ints with a value of 100
		ft::vector<int> bar (15,200);   // five ints with a value of 200
		ft::vector<int>::iterator foo_it = foo.begin();
		ft::vector<int>::iterator bar_it = bar.begin();

		foo.swap(bar);

		ofs << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			ofs << ' ' << foo[i];
		ofs << '\n';

		ofs << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			ofs << ' ' << bar[i];
		ofs << '\n';
		if (foo_it == bar.begin())
			ofs << "iterators remain valid: foo_it == bar.begin()" << std::endl;
		if (++foo_it == ++bar.begin())
			ofs << "++foo_it value == ++bar.begin(), value: " << *foo_it << std::endl;
		if (bar_it == foo.begin())
			ofs << "iterators remain valid: bar_it == foo.begin()" << std::endl;
		if (++bar_it == ++foo.begin())
			ofs << "++bar_it value == ++foo.begin(), value: "  << *bar_it << std::endl;
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_swap_test");
		std::vector<int> foo (9,100);   // three ints with a value of 100
		std::vector<int> bar (15,200);   // five ints with a value of 200
		std::vector<int>::iterator foo_it = foo.begin();
		std::vector<int>::iterator bar_it = bar.begin();

		foo.swap(bar);

		ofs << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			ofs << ' ' << foo[i];
		ofs << '\n';

		ofs << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			ofs << ' ' << bar[i];
		ofs << '\n';
		if (foo_it == bar.begin())
			ofs << "iterators remain valid: foo_it == bar.begin()" << std::endl;
		if (++foo_it == ++bar.begin())
			ofs << "++foo_it value == ++bar.begin(), value: " << *foo_it << std::endl;
		if (bar_it == foo.begin())
			ofs << "iterators remain valid: bar_it == foo.begin()" << std::endl;
		if (++bar_it == ++foo.begin())
			ofs << "++bar_it value == ++foo.begin(), value: "  << *bar_it << std::endl;
		ofs.close();
	}
}

void	vector_clear_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_clear_test");
		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_clear_test");
		std::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		ofs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			ofs << ' ' << myvector[i];
		ofs << '\n';
		ofs.close();
	}
}

void	vector_get_allocator_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_get_allocator_test");
		ft::vector<int> myvector;
		int *p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		ofs << "The allocated array contains:";
		for (i=0; i<5; i++) ofs << ' ' << p[i];
		ofs << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
			myvector.get_allocator().deallocate(p,5);
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_get_allocator_test");
		std::vector<int> myvector;
		int *p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		ofs << "The allocated array contains:";
		for (i=0; i<5; i++) ofs << ' ' << p[i];
		ofs << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
			myvector.get_allocator().deallocate(p,5);
		ofs.close();
	}
}

void	vector_relational_operators_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_relational_operators_test");
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) ofs << "foo and bar are equal\n";
		if (foo!=bar) ofs << "foo and bar are not equal\n";
		if (foo< bar) ofs << "foo is less than bar\n";
		if (foo> bar) ofs << "foo is greater than bar\n";
		if (foo<=bar) ofs << "foo is less than or equal to bar\n";
		if (foo>=bar) ofs << "foo is greater than or equal to bar\n";
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_relational_operators_test");
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) ofs << "foo and bar are equal\n";
		if (foo!=bar) ofs << "foo and bar are not equal\n";
		if (foo< bar) ofs << "foo is less than bar\n";
		if (foo> bar) ofs << "foo is greater than bar\n";
		if (foo<=bar) ofs << "foo is less than or equal to bar\n";
		if (foo>=bar) ofs << "foo is greater than or equal to bar\n";
		ofs.close();
	}
}

void	vector_const_iterators_compare_test()
{
	{
		std::ofstream ofs("./vector_tests/ft_const_iterators_compare_test");
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int>::iterator it = foo.begin();
		ft::vector<int>::const_iterator const_it = foo.end();
		if (it == const_it) ofs << "it == cont_it" << std::endl;
		if (it != const_it) ofs << "it != cont_it" << std::endl;
		if (it < const_it) ofs << "it < cont_it" << std::endl;
		if (it > const_it) ofs << "it > cont_it" << std::endl;
		if (it <= const_it) ofs << "it <= cont_it" << std::endl;
		if (it >= const_it) ofs << "it >= cont_it" << std::endl;
		ofs.close();
	}
	{
		std::ofstream ofs("./vector_tests/stl_const_iterators_compare_test");
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int>::iterator it = foo.begin();
		std::vector<int>::const_iterator const_it = foo.end();
		if (it == const_it) ofs << "it == cont_it" << std::endl;
		if (it != const_it) ofs << "it != cont_it" << std::endl;
		if (it < const_it) ofs << "it < cont_it" << std::endl;
		if (it > const_it) ofs << "it > cont_it" << std::endl;
		if (it <= const_it) ofs << "it <= cont_it" << std::endl;
		if (it >= const_it) ofs << "it >= cont_it" << std::endl;
		ofs.close();
	}
}

void	vector_test()
{
    mkdir("./vector_tests", 0777);
	vector_constructor_test();
	vector_operator_equals_test();
	vector_begin_end_test();
	vector_rbegin_rend_test();
	vector_size_test();
	vector_max_size_test();
	vector_resize_test();
	vector_capacity_test();
	vector_empty_test();
	vector_reserve_test();
	vector_sq_brackets_operator_test();
	vector_at_test();
	vector_front_test();
	vector_back_test();
	vector_assign_test();
	vector_push_back_test();
	vector_pop_back_test();
	vector_insert_test();
	vector_erase_test();
	vector_swap_test();
	vector_clear_test();
	vector_get_allocator_test();
	vector_relational_operators_test();
	vector_const_iterators_compare_test();
}
