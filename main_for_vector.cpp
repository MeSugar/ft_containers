#include "vector.hpp"


// assign test
// int main ()
// {
// 		ft::vector<int> first(10);
// 		ft::vector<int> second;
// 		ft::vector<int> third;
// 		ft::vector<int>::iterator it = first.begin();
// 		ft::vector<int>::iterator it2;

// 		for (int i = 0; i < 10; i++)
// 		{
// 				it[i] = i;
// 		}
// 		for (int i = 0; i < 10; i++)
// 		{
// 				std::cout << it[i] << " ";
// 		}
// 		std::cout << std::endl;


// 		first.assign (11,100);           // 7 ints with a value of 100
// 		it = first.begin();

// 		for (int i = 0; i < 11; i++)
// 		{
// 				std::cout << it[i] << " ";
// 		}
// 		std::cout << std::endl;

// 		it=first.begin()+1;

// 		second.assign (it,first.end()-1); // the 5 central values of first
// 		it2 = second.begin();
// 		for (unsigned long i = 0; i < 11; i++)
// 		{
// 				std::cout << it2[i] << " ";
// 		}
// 		std::cout << std::endl;

// 		int myints[] = {1776,7,4};
// 		third.assign (myints,myints+3);   // assigning from array.
		
// 		it2 = third.begin();
// 		for (unsigned long i = 0; i < 11; i++)
// 		{
// 				std::cout << it2[i] << " ";
// 		}
// 		std::cout << std::endl;
// 		third.assign(99, 1010);


// 		std::cout << "Size of first: " << int (first.size()) << '\n';
// 		std::cout << "Size of second: " << int (second.size()) << '\n';
// 		std::cout << "Size of third: " << int (third.size()) << '\n';
// 		std::cout << "Capacity of first: " << int (first.capacity()) << '\n';
// 		std::cout << "Capacity of second: " << int (second.capacity()) << '\n';
// 		std::cout << "Capacity of third: " << int (third.capacity()) << '\n';
// 		return 0;
// }

// reserve test
// int main ()
// {
// 	ft::vector<int>::size_type sz;
// 	ft::vector<int> foo(10);
// 	ft::vector<int>::iterator it = foo.begin();

// 	sz = foo.capacity();
// 	// std::cout << "making foo grow:\n";
// 	for (unsigned long i = 0; i < foo.size(); i++)
// 	{
// 		it[i] = i;
// 	}
// 	for (unsigned long i = 0; i < foo.size(); i++)
// 	{
// 		std::cout << it[i] << " ";	
// 	}
// 	std::cout << std::endl;
// 	foo.reserve(20);
// 	if (sz != foo.capacity())
// 	{
// 		sz = foo.capacity();
// 		std::cout << "capacity changed: " << sz << '\n';
// 	}
// 	it = foo.begin();
// 	for (unsigned long i = 0; i < foo.size(); i++)
// 	{
// 		it[i] = i;
// 	}
// 	for (unsigned long i = 0; i < foo.size(); i++)
// 	{
// 		std::cout << it[i] << " ";	
// 	}
// 	std::cout << std::endl;
// 	foo.reserve(10);
// 	for (unsigned long i = 0; i < foo.size(); i++)
// 	{
// 		std::cout << it[i] << " ";	
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size: "<< foo.size() << std::endl;
// 	std::cout << "capacity: " << foo.capacity() << std::endl;

// 	return 0;
// }

// resize test
// int main()
// {
// 	ft::vector<int> foo(10);
// 	ft::vector<int>::iterator it = foo.begin();

// 	for (unsigned long i = 0; i < foo.size(); i++)
// 	{
// 		it[i] = i;
// 	}
// 	for (unsigned long i = 0; i < foo.size(); i++)
// 	{
// 		std::cout << it[i] << " ";	
// 	}
// 	std::cout << std::endl;

// 	foo.resize(5);
// 	foo.resize(8,100);
// 	foo.resize(12);

// 	std::cout << "myvector contains:";
// 	for (unsigned long i=0;i<foo.size();i++)
// 	std::cout << ' ' << foo[i];
// 	std::cout << '\n';
// 	std::cout << "size: "<< foo.size() << std::endl;
// 	std::cout << "capacity: " << foo.capacity() << std::endl;

// 	return 0;
// }

//insert test
// int main ()
// {
// 	ft::vector<int> myvector (10,10);
// 	ft::vector<int>::iterator it;
// 	myvector.reserve(10);

// 	it = myvector.begin();
// 	it = myvector.insert ( it , 2200 );

// 	myvector.insert (it + 2,5,300);
// 	myvector.insert (myvector.end() - 1,0,900);
	

// 	// "it" no longer valid, get a new one:
// 	it = myvector.begin();

// 	ft::vector<int> anothervector (2,400);
// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

// 	int myarray [] = { 501,502,503 };
// 	myvector.insert (myvector.begin(), myarray, myarray+3);

// 	std::cout << "myvector contains:";
// 	for (it=myvector.begin(); it<myvector.end(); it++)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// 	std::cout << "size: " << myvector.size() << std::endl;
// 	std::cout << "capacity: " << myvector.capacity() << std::endl;
// 	std::cout << "last: " << *(myvector.end() - 1) << std::endl;
	

// 	return 0;
// }


//push_back test
// int main ()
// {
//   ft::vector<int> myvector;
//   int myint;

//   std::cout << "Please enter some integers (enter 0 to end):\n";

//   do {
//     std::cin >> myint;
//     myvector.push_back (myint);
//   } while (myint);

//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

//   return 0;
// }

//pop_back test
// int main ()
// {
//   ft::vector<int> myvector;
//   int sum (0);
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   while (!myvector.empty())
//   {
//     sum+=myvector.back();
//     myvector.pop_back();
//   }

//   std::cout << "The elements of myvector add up to " << sum << '\n';

//   return 0;
// }

//erase_test
// int main ()
// {
// 	ft::vector<int> myvector;

// 	// set some values (from 1 to 10)
// 	for (int i=1; i<=20; i++) myvector.push_back(i);
// 	// for (unsigned long i=0; i<myvector.size(); i++) std::cout << ' ' << myvector[i];
// 	// std::cout << std::endl;
// 	// erase the 6th element
// 	myvector.erase (myvector.begin()+5);
// 	myvector.erase (myvector.end() - 1);
// 	ft::vector<int>::iterator iter = myvector.erase (myvector.begin());
// 	// std::cout << *iter << std:: endl;

// 	// erase the first 3 elements:
// 	iter = myvector.erase (myvector.begin(),myvector.begin()+3);
// 	// myvector.erase (myvector.begin() + 4,myvector.begin()+3);
// 	myvector.erase (myvector.begin(),myvector.end());


// 	// std::cout << *iter << std:: endl;

// 	std::cout << "myvector contains:    ";
// 	for (unsigned i=0; i<myvector.size(); ++i)
// 	std::cout << ' ' << myvector[i];
// 	std::cout << '\n';
// 	std::cout << myvector.size() << std::endl;

// 	return 0;
// }

//resize test
// int main ()
// {
//   ft::vector<int> myvector;

// //   set some initial content:
//   for (int i=1;i<10;i++) myvector.push_back(i);

//   myvector.resize(5);
//   myvector.resize(8,100);
//   myvector.resize(12);

//   std::cout << "myvector contains:";
//   for (unsigned int i=0;i<myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//   std::cout << myvector.size() << std::endl;
//   std::cout << myvector.capacity() << std::endl;

//   return 0;
// }

//swap test
// int main ()
// {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';

//   return 0;
// }

//clear test
// int main ()
// {
//   ft::vector<int> myvector;
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   myvector.clear();
//   std::cout << myvector.size() << std::endl;

//   myvector.push_back (1101);
//   myvector.push_back (2202);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//   std::cout << myvector.size() << std::endl;
//   std::cout << myvector.capacity() << std::endl;

//   return 0;
// }

//get_allocator test
// int main ()
// {
//   ft::vector<int> myvector;
//   int * p;
//   unsigned int i;

//   // allocate an array with space for 5 elements using vector's allocator:
//   p = myvector.get_allocator().allocate(5);

//   // construct values in-place on the array:
//   for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

//   std::cout << "The allocated array contains:";
//   for (i=0; i<5; i++) std::cout << ' ' << p[i];
//   std::cout << '\n';

//   // destroy and deallocate:
//   for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
//   myvector.get_allocator().deallocate(p,5);

//   return 0;
// }

//relational operators test
// int main ()
// {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (2,200);   // two ints with a value of 200

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }

//operator= overload
// int main ()
// {
//   ft::vector<int> foo (3,0);
//   ft::vector<int> bar;

// 	// std::cout << "Capacity of foo: " << int(foo.capacity()) << '\n';
//   	// std::cout << "Capacity of bar: " << int(bar.capacity()) << '\n';
// //   std::cout << "bar:" << std::endl;
//   bar = foo;
// //   std::cout << "foo:" << std::endl;
//   foo = ft::vector<int>();

//   std::cout << "Size of foo: " << int(foo.size()) << '\n';
//   std::cout << "Size of bar: " << int(bar.size()) << '\n';
//   std::cout << std::endl;
//   std::cout << "Capacity of foo: " << int(foo.capacity()) << '\n';
//   std::cout << "Capacity of bar: " << int(bar.capacity()) << '\n';
//   return 0;
// }