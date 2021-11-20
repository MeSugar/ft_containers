#include "vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector (10);   // 10 zero-initialized elements

//   ft::vector<int>::size_type sz = myvector.size();

//   // assign some values:
//   for (unsigned i=0; i<sz; i++) myvector[i]=i;

//   // reverse vector using operator[]:
//   for (unsigned i=0; i<sz/2; i++)
//   {
//     int temp;
//     temp = myvector[sz-1-i];
//     myvector[sz-1-i]=myvector[i];
//     myvector[i]=temp;
//   }

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<sz; i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   std::cout << myvector.at(9) << std::endl;
//   std::cout << myvector.front() << std::endl;
//   std::cout << myvector.back() << std::endl;
//   return 0;
// }

int main ()
{
  ft::vector<int> first;
  ft::vector<int> second;
  // ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  // int myints[] = {1776,7,4};
  // third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  // std::cout << "Size of third: " << int (third.size()) << '\n';
  return 0;
}


//     //Some syntax tests
//     // int x(2);
//     // std::cout << x << std::endl;


// //     // pair tests
// //     // ft::pair<std::string, int> pair2("price", 22);
// //     // ft::pair<std::string, int> pair3 = pair2;
// //     // ft::pair<std::string, int> pair1;
// //     // std::cout << pair1.first << " " << pair1.second << std::endl;

// //     // ft::pair<std::string, int> pair4 = ft::make_pair("hello", 232);

// //     // std::cout << pair4.first << " " << pair4.second << std::endl;

// }

// int main () {
//     ft::vector<int> myvector(10);
//     ft::vector<int>::iterator it = myvector.begin();

//     for (int i = 0; i < 10; i++)
//     {
//         it[i] = i;
//     }

//   typedef ft::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

//   std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';

//   return 0;
// }