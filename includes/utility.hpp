#ifndef UTILITY_H
# define UTILITY_H

#include <iostream>
#include <memory>
#include <exception>
#include <stdexcept>
#include <string>
#include <typeinfo>

namespace ft
{
	// pair
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		// constructors
		pair() : first(), second() {}

		template<class U, class V> pair (const pair<U, V>& pr)
		: first(pr.first), second(pr.second) {}

		pair(const first_type& a, const second_type& b)
		: first(a), second(b) {}
		~pair() {};

		pair& operator=(const pair& pr)
		{ 
			first = pr.first, second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair (T1 x, T2 y) { return (ft::pair<T1, T2> (x, y)); }

	// enable_if
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	// is_integral
	template<typename B, B val>
	struct integral_constant
	{
		static const bool value = val;
		typedef B							value_type;
		typedef integral_constant<B, val>	type;
	};

	typedef integral_constant<bool, true>     true_type;
	typedef integral_constant<bool, false>    false_type;

	template<typename>
	struct is_integral_helper : public false_type {};
	
	template <>
	struct is_integral_helper<bool> : public true_type {};

	template <>
	struct is_integral_helper<char> : public true_type {};
	
	template <>
	struct is_integral_helper<signed char> : public true_type {};

	template <>
	struct is_integral_helper<unsigned char> : public true_type {};
	
	template <>
	struct is_integral_helper<short int> : public true_type {};

	template <>
	struct is_integral_helper<unsigned short int> : public true_type {};
	
	template <>
	struct is_integral_helper<int> : public true_type {};

	template <>
	struct is_integral_helper<long int> : public true_type {};

	template <>
	struct is_integral_helper<long long int> : public true_type {};

	template <>
	struct is_integral_helper<unsigned int> : public true_type {};

	template <>	
	struct is_integral_helper<unsigned long int> : public true_type {};
	
	template <>
	struct is_integral_helper<unsigned long long int> : public true_type {};

	template<typename T>
	struct	is_integral : public is_integral_helper<T> {};

	// equal
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	// lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template<typename T, typename U, typename Result>
	struct binary_function
	{
		typedef T		first_argument_type; 
		typedef U		second_argument_type;
		typedef Result	result_type;
	};

	template <class T>
	struct less : binary_function <T, T, bool>
	{ bool operator() (const T& x, const T& y) const { return x < y; } };
}

#endif