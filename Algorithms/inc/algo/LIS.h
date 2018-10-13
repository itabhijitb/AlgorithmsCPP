#include <vector>
#include <algorithm>
#include <functional>
#include "util/Memorize.h"

namespace DP
{
	namespace LIS /* Longest Increasing Subsequence*/
	{
		template<typename Ty>
		class LIS : public Memorization::Memorize
		{
			/*
			LIS(n) = max(LIS_recur(j) for j in 0..n)
			LIS_recur(j) = max(LIS_recur(i) + 1 for i in 0..j if arr[i] < arr[j])
			*/
		public:
			template<size_t size>
			LIS(Ty(&arr)[size]) :m_arr(std::begin(arr), std::end(arr)) {}
			LIS(std::vector<Ty> arr) : m_arr(arr){}
			size_t operator()()
			{
				size_t max = 0;
				for (size_t j = 0; j < m_arr.size(); j++)
				{
					max = std::max(Memoize(&LIS::recurse, this)(j), max);
				}
				return max;
			}
		private:
			size_t recurse(size_t j)
			{
				size_t max = 1;
				for (size_t i = 0; i < j; i++)
				{
					if (m_arr[i] < m_arr[j])
					{
						max = std::max(Memoize(&LIS::recurse, this)(i) + 1, max);
					}
					
				}
				return max;
			}
			std::vector<Ty> m_arr;
		};
	}
}