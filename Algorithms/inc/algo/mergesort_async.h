#ifndef __MERGE_SORT_ASYNC_H__
#define __MERGE_SORT_ASYNC_H__
#include <vector>
#include <algorithm>
#include <future>

namespace Sort
{
	namespace MergeSortAsync
	{
		template<typename Ty>
		class MergeSortAsync
		{
		public:
			template<size_t SIZE>
			MergeSortAsync(Ty(&arr)[SIZE]) :arr(std::begin(arr), std::end(arr))
			{
				temp.resize(SIZE);
			}
			template<typename Iter>
			MergeSortAsync(Iter begin, Iter end) : arr(begin, end)
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
				if (hi - lo < 1000)
				{
					recurse(lo, mid);
					recurse(mid + 1, hi);
				}
				else
				{
					auto handle1 = std::async(&MergeSortAsync::recurse, this, lo, mid);
					auto handle2 = std::async(&MergeSortAsync::recurse, this, mid + 1, hi);
					handle1.get();
					handle2.get();
				}
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