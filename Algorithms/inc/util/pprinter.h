/*****************************************************************************/
/*                              STL Libraries                                */
/*****************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <set>
#include <sstream>
#include <array>
#include <type_traits>
#include "c11_type_traits.h"
#ifndef __PPRINTSTL_H__
#define __PPRINTSTL_H__

namespace pprint
{

	template<
		typename Ty,
		bool as_type = std_c11::is_associative<Ty>::value,
		bool it_type = std_c11::is_iterable<Ty>::value,
		bool pr_type = std_c11::is_pair<Ty>::value
	>
	struct brackets
	{
		static const char open = '|';
		static const char close = '|';
	};
	template<typename Ty>
	struct brackets<
		Ty,
		true,  //Associative
		true,  //Iterable
		false  //But not a Pair
	>
	{
		static const char open = '{';
		static const char close = '}';
	};
	template<typename Ty>
	struct brackets<
		Ty,
		false, //Not Associative
		true,  //But Iterable
		false  //But not a Pair
	>
	{
		static const char open = '[';
		static const char close = ']';
	};
	template<typename Ty>
	struct brackets<
		Ty,
		false, //Neither Associative
		false, //Nor Iterable
		false  //Nor a Pair
	>
	{
		static const char open = '<';
		static const char close = '>';
	};
	template<typename Ty>
	struct brackets<
		Ty,
		false, //Neither Associative (actually don't care)
		false, //Nor Iterable
		true   //But a Pair
	>
	{
		static const char open = '(';
		static const char close = ')';
	};
	template<
		typename Ty,
		bool is_iterable = std_c11::is_iterable<typename std_c11::remove_cv<typename std_c11::remove_reference<Ty>::type>::type>::value,
		bool is_fundamental = std::is_fundamental<typename std_c11::remove_cv<typename std_c11::remove_reference<Ty>::type>::type>::value,
		bool is_string = std_c11::is_convertible<Ty, std::string>::value,
		bool is_ptr = std_c11::is_pointer<Ty>::value
	>
	struct pprint {
		std::string   operator()(const Ty& data, size_t depth = 0)
		{
			std::string strm;
			strm += "\n";
			strm += std::string(depth, ' ');
			strm += std::string(1, brackets<Ty>::open);
			for (Ty::const_iterator it = data.begin();
				it != data.end();
				it++)
			{
				strm += pprint<typename Ty::value_type>()(*it, depth + 1);
				if (std::distance(it, data.end()) > 1)
				{
					strm += ",";

				}
			}
			strm += std::string(1, brackets<Ty>::close);
			return strm;
		}
	};
	//Smart Pointer
	template<typename Ty>
	struct pprint<
		Ty,
		false,	//Is Neither Iterable 
		false,  //Nor Fundamental
		false,   //Nor a String Convetable
		true    //Not a Pointer
	> {
		std::string   operator()(const Ty& data, size_t depth = 0)
		{
			std::string strm;
			strm = std::string(1, brackets<Ty>::open)
				+ pprint<typename Ty::element_type>()(*data, depth + 1)
				+ std::string(1, brackets<Ty>::close);
			return strm;
		}
	};
	//std::string / C Type String
	template<typename Ty>
	struct pprint<
		Ty,
		true, //Is Iterable 
		false, //But not Fundamental
		true,   //Yet a String Convetable
		false   //Not a Pointer
	> {
		const std::string   operator()(const std::string& data, size_t depth = 0)
		{
			std::string strm = "\"" + data + "\"";
			return strm;
		}
	};
	// Fundamental Data Types
	template<typename Ty>
	struct pprint<
		Ty,
		false,   //Is Neither Iterable 
		true,    //But Fundamental
		false,   //Nor a String Convetable
		false   //Not a Pointer
	> {
		std::string  operator()(const Ty& data, size_t depth = 0)
		{
			std::stringstream st;
			st << data;
			return st.str();
		}
	};
	template<
		typename TyK,
		typename TyV>
	struct pprint<
		std::pair<TyK, TyV>,
		false,
		false,
		false,   //Nor a String Convetable
		false    //Not a Pointer
	> {
		std::string   operator()(const std::pair<TyK, TyV>& data, size_t depth = 0)
		{
			std::string strm = std::string("\n");
			strm += std::string(depth, ' ')
				+ std::string("(")
				+ pprint<TyK>()(data.first, depth)
				+ " :";
			strm += pprint<TyV>()(data.second, strm.size())
				+ ")";
			return strm;
		}
	};
	template<typename Ty, int size>
	struct pprint<
		Ty[size], 
		false, 
		false, 
		false,   //Nor a String Convetable
		false    //Not a Pointer
	> {
		std::string   operator()(const Ty data[size], size_t depth = 0)
		{
			std::string strm;
			strm += "\n";
			strm += std::string(depth, ' ');
			strm += std::string(1, brackets<Ty>::open);
			for (size_t i = 0; i < size; i++)
			{
				strm += std::string(depth + 1, ' ');
				strm += pprint<Ty>()(data[i], depth + 1);
				if ((size - i) > 1)
				{
					strm += ", ";

				}
			}
			strm += std::string(1, brackets<Ty>::close);
			return strm;
		}
	};
	//template<typename ... Ty>
	//struct pprint<
	//	std::tuple<Ty...>,
	//	false,
	//	false,
	//	false,   //Nor a String Convetable
	//	false    //Not a Pointer
	//> {
	//	std::string   operator()(std::tuple<Ty...> data, size_t depth = 0)
	//	{
	//		std::stringstream st;
	//		st << std::string(1, brackets<std::tuple<Ty...>>::open);
	//		print_tuple<0>(st, data);
	//		st << std::string(1, brackets<std::tuple<Ty...>>::close);
	//		return st.str();
	//	}
	//private:
	//	template <size_t n, typename... T>
	//	typename std::enable_if<(n >= sizeof...(T))>::type
	//		print_tuple(std::stringstream&, const std::tuple<T...>&)
	//	{}

	//	template <size_t n, typename... T>
	//	typename std::enable_if<(n < sizeof...(T))>::type
	//		print_tuple(std::stringstream& os, const std::tuple<T...>& tup)
	//	{
	//		if (n != 0)
	//			os << ", ";
	//		os << pprint<decltype(std::get<n>(tup))>()(std::get<n>(tup));
	//		print_tuple<n + 1>(os, tup);
	//	}
	//};

};
#endif
