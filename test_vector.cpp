// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <vector>

template <class T>
class A
{
    public:
        A(T x) { std::cout << x << " is not a char"<< std::endl; }
};

template <>
class A<char>
{
    public:
        A(char x) { std::cout << x << " is a char"<< std::endl; }
};

int main()

{
   
    
//   typedef std::iterator_traits<int*> traits;
  
    // if (typeid(std::vector<char>::iterator::iterator_category)==typeid(std::random_access_iterator_tag))
    // //     std::cout << "int* is a random-access iterator" << std::endl;
    // std::vector<int> v(3, 222);

    A<int> a(5);
    A<float> b(4.11);
    A<char> n('4');
    // std::vector<int >::iterator it1 = v.begin();
    // // std::vector<int >::iterator it2 = v.end();
    
    // // std::vector<int >::iterator it2 = v.begin();
    // std::cout << it1[4] << std::endl;
    
    // std::vector<int> v4(it1, it2);


    return 0;
}
