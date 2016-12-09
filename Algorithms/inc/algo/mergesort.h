#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__
#include <vector>
#include <algorithm>
namespace Sort
{
	namespace MergeSort
	{
		template<typename Ty>
		class MergeSort
		{
		public:
			template<size_t SIZE>
			MergeSort(Ty(&arr)[SIZE]) :arr(std::begin(arr), std::end(arr)) 
			{
				temp.resize(SIZE);
			}
			template<typename Iter>
			MergeSort(Iter begin, Iter end) : arr(begin, end) 
			{
				temp.resize(arr.size());
			}
			std::vector<Ty> operator()()
			{
				recurse(0, arr.size() - 1);
				return arr;
			}
		private:
			void recurse(size_t lo, size_t hi)
			{
				if (hi - lo < 2)
				{
					if (arr[lo] > arr[hi])
						std::swap(arr[lo], arr[hi]);
					return;
				}
				size_t mid = (lo + hi) / 2;
				recurse(lo, mid);
				recurse(mid + 1, hi);
				size_t i_lo = lo, i_hi = mid, i = 0;
				for (;
					i_lo < mid && i_hi < hi;
					i++)
				{
					if (arr[i_lo] < arr[i_hi])
					{
						temp[i] = arr[i_lo];
						i_lo++;
					}
					else
					{
						temp[i] = arr[i_hi];
						i_hi++;
					}

				}
				for (; i_lo < mid; i_lo++, i++)
				{
					temp[i] = arr[i_lo];
				}
				for (; i_hi < hi; i_hi++, i++)
				{
					temp[i] = arr[i_hi];
				}
				for (size_t i = lo; i < hi; i++) arr[i] = temp[i - lo];

			}
			std::vector<Ty> arr;
			std::vector<Ty> temp;
		};
	}
}
#endif