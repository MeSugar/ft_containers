#include "../includes/test.hpp"

void    stack_constructor_test()
{
	{
		std::ofstream ofs("./stack_tests/ft_constructor_test");
		std::deque<int> mydeque(3,100);          // deque with 3 elements
		std::vector<int> myvector(2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int> second (mydeque);         // stack initialized to copy of deque

		ft::stack<int,std::vector<int> > third;  // empty stack using vector
		ft::stack<int,std::vector<int> > fourth (myvector);
		ft::stack<int, std::list<int> > fifth;	// empty stack using list

		ofs << "size of first: " << first.size() << '\n';
		ofs << "size of second: " << second.size() << '\n';
		ofs << "size of third: " << third.size() << '\n';
		ofs << "size of fourth: " << fourth.size() << '\n';
		ofs << "size of fifth: " << fifth.size() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./stack_tests/stl_constructor_test");
		std::deque<int> mydeque(3,100);          // deque with 3 elements
		std::vector<int> myvector(2,200);        // vector with 2 elements

		std::stack<int> first;                    // empty stack
		std::stack<int> second (mydeque);         // stack initialized to copy of deque

		std::stack<int,std::vector<int> > third;  // empty stack using vector
		std::stack<int,std::vector<int> > fourth (myvector);
		std::stack<int, std::list<int> > fifth;	// empty stack using list

		ofs << "size of first: " << first.size() << '\n';
		ofs << "size of second: " << second.size() << '\n';
		ofs << "size of third: " << third.size() << '\n';
		ofs << "size of fourth: " << fourth.size() << '\n';
		ofs << "size of fifth: " << fifth.size() << '\n';
		ofs.close();
	}
}

void    stack_empty_test()
{
	{
		std::ofstream ofs("./stack_tests/ft_empty_test");
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		ofs << "total: " << sum << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./stack_tests/stl_empty_test");
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		ofs << "total: " << sum << '\n';
		ofs.close();
	}
}

void    stack_size_test()
{
	{
		std::ofstream ofs("./stack_tests/ft_size_test");
		ft::stack<int> myints;
		ofs << "0. size: " << myints.size() << '\n';
		for (int i=0; i<5; i++) myints.push(i);
			ofs << "1. size: " << myints.size() << '\n';
		myints.pop();
		ofs << "2. size: " << myints.size() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./stack_tests/stl_size_test");
		ft::stack<int> myints;
		ofs << "0. size: " << myints.size() << '\n';
		for (int i=0; i<5; i++) myints.push(i);
			ofs << "1. size: " << myints.size() << '\n';
		myints.pop();
		ofs << "2. size: " << myints.size() << '\n';
		ofs.close();
	}
}

void    stack_top_test()
{
	{
		std::ofstream ofs("./stack_tests/ft_top_test");
		ft::stack<int> mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
		ofs << "mystack.top() is now " << mystack.top() << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./stack_tests/stl_top_test");
		std::stack<int> mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
		ofs << "mystack.top() is now " << mystack.top() << '\n';
		ofs.close();
	}
}

void    stack_push_pop_test()
{
	{
		std::ofstream ofs("./stack_tests/ft_push_pop_test");
		ft::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		ofs << "Popping out elements...";
		while (!mystack.empty())
		{
			ofs << ' ' << mystack.top();
			mystack.pop();
		}
		ofs << '\n';
		ofs.close();
	}
	{
		std::ofstream ofs("./stack_tests/stl_push_pop_test");
		std::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		ofs << "Popping out elements...";
		while (!mystack.empty())
		{
			ofs << ' ' << mystack.top();
			mystack.pop();
		}
		ofs << '\n';
		ofs.close();
	}
}

void	stack_relational_operators_test()
{
	{
		std::ofstream ofs("./stack_tests/ft_relational_operators_test");
		ft::stack<int> mystack1;
		ft::stack<int> mystack2;

		for (int i=0; i<5; ++i) mystack1.push(i);
		for (int i=3; i<8; ++i) mystack2.push(i);
		if (mystack1 == mystack2)
			ofs << "stack1 == stack2" << std::endl;
		if (mystack1 < mystack2)
			ofs << "stack1 < stack2" << std::endl;
		if (mystack1 > mystack2)
			ofs << "stack1 > stack2" << std::endl;
		if (mystack1 >= mystack2)
			ofs << "stack1 >= stack2" << std::endl;
		if (mystack1 <= mystack2)
			ofs << "stack1 <= stack2" << std::endl;
		ofs.close();
	}
	{
		std::ofstream ofs("./stack_tests/stl_relational_operators_test");
		std::stack<int> mystack1;
		std::stack<int> mystack2;

		for (int i=0; i<5; ++i) mystack1.push(i);
		for (int i=3; i<8; ++i) mystack2.push(i);
		if (mystack1 == mystack2)
			ofs << "stack1 == stack2" << std::endl;
		if (mystack1 < mystack2)
			ofs << "stack1 < stack2" << std::endl;
		if (mystack1 > mystack2)
			ofs << "stack1 > stack2" << std::endl;
		if (mystack1 >= mystack2)
			ofs << "stack1 >= stack2" << std::endl;
		if (mystack1 <= mystack2)
			ofs << "stack1 <= stack2" << std::endl;
		ofs.close();
	}
}

void    stack_test()
{
	mkdir("./stack_tests", 0777);
	stack_constructor_test();
    stack_empty_test();
	stack_size_test();
	stack_top_test();
	stack_push_pop_test();
	stack_relational_operators_test();
}