#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <map>
#include <string>
#include <vector>

//constructors test
// int main ()
// {
//   std::deque<int> mydeque (3,100);          // deque with 3 elements
//   std::vector<int> myvector (2,200);        // vector with 2 elements

//   ft::stack<int> first;                    // empty stack
//   ft::stack<int> second (mydeque);         // stack initialized to copy of deque

//   ft::stack<int,std::vector<int> > third;  // empty stack using vector
//   ft::stack<int,std::vector<int> > fourth (myvector);

//   std::cout << "size of first: " << first.size() << '\n';
//   std::cout << "size of second: " << second.size() << '\n';
//   std::cout << "size of third: " << third.size() << '\n';
//   std::cout << "size of fourth: " << fourth.size() << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::stack<int> myints;
//   std::cout << "0. size: " << myints.size() << '\n';

//   for (int i=0; i<5; i++) myints.push(i);
//   std::cout << "1. size: " << myints.size() << '\n';

//   myints.pop();
//   std::cout << "2. size: " << myints.size() << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::stack<int> mystack;

//   mystack.push(10);
//   mystack.push(20);

//   mystack.top() -= 5;

//   std::cout << "mystack.top() is now " << mystack.top() << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::stack<int> mystack;

//   for (int i=0; i<5; ++i) mystack.push(i);

//   std::cout << "Popping out elements...";
//   while (!mystack.empty())
//   {
//      std::cout << ' ' << mystack.top();
//      mystack.pop();
//   }
//   std::cout << '\n';

//   return 0;
// }

// // relational operators test
// int main ()
// {
// 	ft::stack<int> mystack1;
// 	ft::stack<int> mystack2;

// 	for (int i=0; i<5; ++i) mystack1.push(i);
// 	for (int i=3; i<8; ++i) mystack2.push(i);
// 	if (mystack1 == mystack2)
// 		std::cout << "stack1 == stack2" << std::endl;
// 	if (mystack1 < mystack2)
// 		std::cout << "stack1 < stack2" << std::endl;
// 	if (mystack1 > mystack2)
// 		std::cout << "stack1 > stack2" << std::endl;
// 	if (mystack1 >= mystack2)
// 		std::cout << "stack1 >= stack2" << std::endl;
// 	if (mystack1 <= mystack2)
// 		std::cout << "stack1 <= stack2" << std::endl;
// }

