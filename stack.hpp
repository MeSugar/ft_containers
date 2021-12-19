#ifndef STACK_H
# define STACK_H

#include <deque>
namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{
		public:
			// type aliases
			typedef T			value_type;
			typedef Container	container_type;
			typedef	size_t		size_type;

			explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {}
			~stack() {}

			//member functions
			bool				empty() const { return _ctnr.empty(); }
			size_type			size() const { return _ctnr.size(); }
			value_type&			top() { return _ctnr.back(); }
			const value_type&	top() const { return _ctnr.back(); }
			void				push (const value_type& val) { _ctnr.push_back(val); }
			void				pop() { _ctnr.pop_back(); }

			template <class Value, class Ctnr>
			friend bool operator== (const ft::stack<Value, Ctnr>& lhs, const ft::stack<Value, Ctnr>& rhs);

			template <class Value, class Ctnr>
			friend bool operator!= (const ft::stack<Value, Ctnr>& lhs, const ft::stack<Value, Ctnr>& rhs);
			
			template <class Value, class Ctnr>
			friend bool operator< (const ft::stack<Value, Ctnr>& lhs, const ft::stack<Value, Ctnr>& rhs);

			template <class Value, class Ctnr>
			friend bool operator<= (const ft::stack<Value, Ctnr>& lhs, const ft::stack<Value, Ctnr>& rhs);

			template <class Value, class Ctnr>
			friend bool operator> (const ft::stack<Value, Ctnr>& lhs, const ft::stack<Value, Ctnr>& rhs);

			template <class Value, class Ctnr>
			friend bool operator>= (const ft::stack<Value, Ctnr>& lhs, const ft::stack<Value, Ctnr>& rhs);
		protected:
			container_type	_ctnr;
	};

	//non-member function overloads
	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return lhs._ctnr == rhs._ctnr; }

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return !(lhs._ctnr == rhs._ctnr); }

	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return lhs._ctnr < rhs._ctnr; }

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return lhs._ctnr <= rhs._ctnr; }

	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return lhs._ctnr > rhs._ctnr; }

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return lhs._ctnr >= rhs._ctnr; }
}

#endif 