#include "vector.hpp"



int main()
{
    // ft::Vector<int> a;
   
    ft::Vector<int> b(5, 111);
    //  std::vector<int *> v;
    ft::Vector<int>::iterator it = b.begin();
    //  typedef ft::iterator_traits<ft::Vector_iterator<int> > traits;

    // std::cout << traits::pointer() << std::endl;
    // ++it;
    // it++;
    // *it = 333;
    ft::Vector<int>::iterator it1;
    it1 = it;
    for ( ; it1 != b.last(); it1++ )
        std::cout << *it1 << std::endl;
    // ft::Vector<std::string> c(41, "hello");
    // ft::Vector<int>::iterator *it2 = &b.begin();


    //Some syntax tests
    // int x(2);
    // std::cout << x << std::endl;


//     // pair tests
//     // ft::pair<std::string, int> pair2("price", 22);
//     // ft::pair<std::string, int> pair3 = pair2;
//     // ft::pair<std::string, int> pair1;
//     // std::cout << pair1.first << " " << pair1.second << std::endl;

//     // ft::pair<std::string, int> pair4 = ft::make_pair("hello", 232);

//     // std::cout << pair4.first << " " << pair4.second << std::endl;
}

