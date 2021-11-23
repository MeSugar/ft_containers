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

// 	return 0;
// }

//insert test
int main ()
{
	ft::vector<int> myvector (10,10);
	ft::vector<int>::iterator it;
	myvector.reserve(10);

	it = myvector.begin();
	it = myvector.insert ( it , 2200 );

	myvector.insert (it + 2,5,300);
	myvector.insert (myvector.end() - 1,0,900);
	

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "last: " << *(myvector.end() - 1) << std::endl;
	

	return 0;
}