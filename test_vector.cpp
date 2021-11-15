// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <vector>

int main()

{
   
    
//   typedef std::iterator_traits<int*> traits;
  
    // if (typeid(std::vector<char>::iterator::iterator_category)==typeid(std::random_access_iterator_tag))
    //     std::cout << "int* is a random-access iterator" << std::endl;
    std::vector<int> v(2, 222);
    std::vector<int >::iterator it = v.begin();
    *it = 333;
    std::cout << *it << std::endl;
    return 0;
}
