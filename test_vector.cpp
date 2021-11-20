// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <vector>

   
    
//   typedef std::iterator_traits<int*> traits;
int main()
{
    // if (typeid(std::vector<char>::iterator::iterator_category)==typeid(std::random_access_iterator_tag))
    // //     std::cout << "int* is a random-access iterator" << std::endl;
    // std::vector<int> v(3, 222);
    std::vector<int> b(5, 111);
    std::vector<int> c(5, 222);
    std::vector<int>::iterator it = c.begin();
    b.assign(it + 1, c.end() - 1);
    for (int i = 0; i < 5; i++)
        std::cout << b[i] << std::endl;
    // std::vector<int >::iterator it1 = v.begin();
    // // std::vector<int >::iterator it2 = v.end();
    
    // // std::vector<int >::iterator it2 = v.begin();
    // std::cout << it1[4] << std::endl;
    
    // std::vector<int> v4(it1, it2);


    return 0;
}
