#include "vector.hpp"

// int main()
// {
//     // ft::vector<int> a;
   
//     // ft::vector<int> b(5, 111);
//     // ft::vector<int> c(b.begin(), b.end() - 1);
//     // ft::vector<int> d(c);
//     // ft::vector<int>::iterator it = d.begin();
  
//     // ft::vector<int>::iterator it1;
//     // it1 = it;

//     // for ( ; it1 != d.end(); it1++ )
//     //     std::cout << *it1 << std::endl;
//     // std::cout << b[1] << std::endl;
    
//     // ft::vector<std::string> c(41, "hello");
//     // ft::vector<int>::iterator *it2 = &b.begin();


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

int main () {
    ft::vector<int> myvector(10);
    ft::vector<int>::iterator it = myvector.begin();

    for (int i = 0; i < 10; i++)
    {
        it[i] = i;
    }

  typedef ft::vector<int>::iterator iter_type;

  ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

  std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';

  return 0;
}
