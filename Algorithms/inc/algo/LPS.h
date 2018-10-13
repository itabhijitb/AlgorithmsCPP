#include <vector>
#include <algorithm>
#undef max
#include <functional>
#include "util/Memorize.h"

namespace DP
{
	namespace LPS /* Longest Palindrom Subsequence*/
	{
		/*
		LPS(i, j) = 1                                 if i == j
		          = 2                                 if arr[i] == arr[j] and i + 1 == j 
		          = 2 + LPS(i + 1, j - 1)             if arr[i] == arr[j]
		          = max(LPS(i, j - 1), LPS(i + 1, j)) otherwise
		*/
		template<typename Ty>
		class LPS : public Memorization::Memorize
		{
		public:
			template<size_t size>
			LPS(Ty(&arr)[size]) :m_arr(std::begin(arr), std::end(arr)) {}
			LPS(std::vector<Ty> arr) : m_arr(arr){}
			size_t operator()()
			{
				size_t len = m_arr.size() - 1;
				return len - Memoize(&LPS::recurse, this)(0, len - 1);
				//return recurse(0, m_arr.size() - 1 - (m_arr.back() == '\0'));
			}
		private:
			Ty recurse(int i, int j)
			{
				if (i == j) return 1;
				if (m_arr[i] == m_arr[j] && i + 1 == j) return 2;
				if (m_arr[i] == m_arr[j]) return 2 + Memoize(&LPS::recurse, this)(i + 1, j - 1);
				return std::max(Memoize(&LPS::recurse, this)(i, j - 1), Memoize(&LPS::recurse, this)(i + 1, j));
			}
			std::vector<Ty> m_arr;
		};
	}
}