// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <vector>

   
    
//   typedef std::iterator_traits<int*> traits;
int main ()
{
	std::vector<int> myvector(10,10);
	std::vector<int>::iterator it;
	myvector.reserve(10);


	it = myvector.begin();
	it = myvector.insert ( it , 2200 );

	myvector.insert (it + 2,5,300);
	myvector.insert (myvector.end() - 1,0,900);
	

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
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