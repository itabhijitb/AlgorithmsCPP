#ifndef __QSORT_H__
#define __QSORT_H__
#include <vector>
#include <algorithm>
#include <functional>

namespace Sort
{
	namespace QuickSort
	{
		template<typename Ty>
		class QuickSort
		{
		public:
			template<size_t SIZE>
			QuickSort(Ty(&arr)[SIZE]) :arr(std::begin(arr), std::end(arr)){}
			template<typename Iter>
			QuickSort(Iter begin, Iter end) : arr(begin, end){}
			std::vector<Ty> operator()()
			{
				recurse(0, arr.size());
				return arr;
			}
		private:
			size_t partition(
				size_t i, 
				size_t j, 
				std::function<size_t(size_t, size_t)> pred = [](size_t a, size_t b){return a < b; },
				std::function<size_t(size_t, size_t)> find_pivot = [](size_t a, size_t b){return (a + b) / 2; })
			{
				int pivot = find_pivot(i, j );
				std::swap(arr[j - 1], arr[pivot]);
				size_t lo = i, hi = j - 2;
				for (; hi - lo >= 1;)
				{
					for (; lo < hi && pred(arr[lo],arr[j-1]); lo++);
					for (; hi > lo && !pred(arr[hi] , arr[j-1]); hi--);
					if (hi - lo >= 1)
					{ 
						std::swap(arr[lo], arr[hi]); 
					}
				}
				if (!pred(arr[lo], arr[j - 1]))
					std::swap(arr[lo], arr[j-1]);
				return hi;
			}
			void recurse(size_t lo, size_t hi)
			{
				if (hi - lo <= 2)
				{
					return;
				}
				size_t pivot = partition(lo, hi);
				recurse(0, pivot);
				recurse(pivot, hi);

			}
			std::vector<Ty> arr;
			std::vector<Ty> temp;
		};
	}
}
#endif