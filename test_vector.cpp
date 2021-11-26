// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <vector>

   
    
//   typedef std::iterator_traits<int*> traits;
// int main ()
// {
// 	std::vector<int> myvector(10,10);
// 	std::vector<int>::iterator it;
// 	myvector.reserve(10);


// 	it = myvector.begin();
// 	it = myvector.insert ( it , 2200 );

// 	myvector.insert (it + 2,5,300);
// 	myvector.insert (myvector.end() - 1,0,900);
	

// 	// "it" no longer valid, get a new one:
// 	it = myvector.begin();

// 	std::vector<int> anothervector (2,400);
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

// int main ()
// {
//   std::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=20; i++) myvector.push_back(i);

//   // erase the 6th element
//  	myvector.erase (myvector.begin()+5);
// 	myvector.erase (myvector.end() - 1);
// 	std::vector<int>::iterator iter = myvector.erase (myvector.begin());
// 	std::cout << *iter << std:: endl;


//   // erase the first 3 elements:
//   iter = myvector.erase (myvector.begin(),myvector.begin()+3);
// 	// myvector.erase (myvector.begin() + 4,myvector.begin()+3);
// 	myvector.erase (myvector.begin(),myvector.end());

// 	std::cout << *iter << std:: endl;



//   std::cout << "their vector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
// std::cout << myvector.size() << std::endl;

//   return 0;
// }

int main ()
{
	std::vector<int>::size_type sz;
	std::vector<int> foo(10);
	std::vector<int>::iterator it = foo.begin();

	sz = foo.capacity();
	// std::cout << "making foo grow:\n";
	for (unsigned long i = 0; i < foo.size(); i++)
	{
		it[i] = i;
	}
	for (unsigned long i = 0; i < foo.size(); i++)
	{
		std::cout << it[i] << " ";	
	}
	std::cout << std::endl;
	foo.reserve(20);
	if (sz != foo.capacity())
	{
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
	}
	it = foo.begin();
	for (unsigned long i = 0; i < foo.size(); i++)
	{
		it[i] = i;
	}
	for (unsigned long i = 0; i < foo.size(); i++)
	{
		std::cout << it[i] << " ";	
	}
	std::cout << std::endl;
	foo.reserve(10);
	for (unsigned long i = 0; i < foo.size(); i++)
	{
		std::cout << it[i] << " ";	
	}
	std::cout << std::endl;
	std::cout << "size: "<< foo.size() << std::endl;
	std::cout << "capacity: " << foo.capacity() << std::endl;

	return 0;
}