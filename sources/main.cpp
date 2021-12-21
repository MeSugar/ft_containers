#include "../includes/test.hpp"

std::vector<int> random_numbers_generator(unsigned int elements)
{
	std::vector<int> myvect;
	srand((unsigned)time(NULL));

    for(unsigned i =0; i < elements; i++)
    {
        int b = rand() % 1000;
        if ( !(std::find(myvect.begin(), myvect.end(), b) != myvect.end()))
        {
           myvect.push_back(b);
        }
    }
	return myvect;
}

int main()
{
    vector_test();
    map_test();
    stack_test();
}