#ifndef __ARRAY_H__
#define __ARRAY_H__
#undef min
#undef max
#include <algorithm>
/*
Majority Element
Majority Element: A majority element in an array A[] of size n is an element
that appears more than n/2 times (and hence there is at most one such element).

Write a function which takes an array and emits the majority element (if it exists),
otherwise prints NONE as follows:

I/P : 3 3 4 2 4 4 2 4 4
O/P : 4

I/P : 3 3 4 2 4 4 2 4
O/P : NONE
*/
namespace Array {
	template<typename Ty, std::size_t N>
	auto majority(Ty(&arr)[N]) {
		std::size_t maj_ix = 0, count = 1;
		for (std::size_t i = 1; i < N; i++) {
			if (arr[i] != arr[maj_ix]) {
				count--;
				if (count == 1) {
					maj_ix = i;
				}
			}
			count++;

		}
		count = 0;
		for (std::size_t i = 1; i < N; i++) {
			if (arr[i] == arr[maj_ix]) {
				count++;
			}
		}
		return (count > N / 2) ? std::unique_ptr<Ty>(new int{ arr[maj_ix] }) : std::unique_ptr<Ty>(nullptr);
	}
	/*
	Largest Sum Contiguous Subarray
	Write an efficient C program to find the sum of contiguous subarray within a
	one-dimensional array of numbers which has the largest sum.

	{-2, -3, 4, -1, -2, 1, 5, -3}

	*/

	template<typename Ty, std::size_t N>
	auto LargestSumContiguousSubarray(Ty(&arr)[N]) {
		Ty _max = 0, _runmax = 0;
		for (auto& elem : arr) {
			_runmax = elem + _runmax;
			if (_runmax < 0) {
				_runmax = 0;
			}
			_max = std::max(_max, _runmax);
		}
		return _max;
	}
	/*
	Search an element in a sorted and rotated array
	An element in a sorted array can be found in O(log n) time via binary search.
	But suppose we rotate an ascending order sorted array at some pivot unknown to
	you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
	Devise a way to find an element in the rotated array in O(log n) time.
	*/
	template<typename Ty, std::size_t N>
	auto SearchSortedAndRotatedArray(Ty(&arr)[N], Ty key) {
		std::function<std::unique_ptr<std::size_t>(std::size_t, std::size_t)> bsearch = [&](std::size_t lo, std::size_t hi) {
			auto mid = (hi + lo) / 2;
			if (key == arr[mid]) {
				return std::make_unique<std::size_t>(mid);
			}
			if (lo >= hi) {
				return std::unique_ptr<std::size_t>(nullptr);
			}

			if (arr[mid] < arr[hi]) {	// Right is Increasing Seq
				if (arr[mid] <= key && key <= arr[hi]) {	// Right Seq has Key
					return bsearch(mid + 1, hi);
				}
				else { // Left Seq has Key
					return bsearch(lo, mid);
				}
			}
			else { // Left is Increasing Seq
				if (arr[lo] <= key && key <= arr[mid]) {	// Left Seq has Key
					return bsearch(lo, mid);
				}
				else { // Right Seq has Key
					return bsearch(mid, hi);
				}
			}
		};
		return bsearch(0, N - 1);
	};
	/*
	Program for array rotation
	Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.
	*/

	template<typename Ty, std::size_t N>
	auto rotate(Ty(&arr)[N], std::size_t d) {
		auto invert = [&](std::size_t lo, std::size_t hi) {
			for (hi--; lo < hi; lo++, hi--) {
				std::swap(arr[lo], arr[hi]);
			}
		};
		invert(0, d);
		invert(d, N);
		invert(0, N);
		return;
	};


	template<typename Ty, std::size_t N>
	auto inversion_count(Ty(&arr)[N]) {
		Ty temp[N] = {};
		size_t count = 0;
		auto merge = [&](
			std::size_t left_lo,
			std::size_t left_hi,
			std::size_t right_lo,
			std::size_t right_hi
			) {
			auto left = left_lo, right = right_lo, i = left_lo;
			for (; left < left_hi && right < right_hi; i++) {
				if (arr[left] < arr[right]) {
					temp[i] = arr[left];
					left++;
				}
				else {
					temp[i] = arr[right];
					right++;
					count += (right_lo - left);
				}
			}
			for (; left < left_hi; left++, i++) {
				temp[i] = arr[left];
			}
			for (; right < right_hi; right++, i++) {
				temp[i] = arr[right];
			}
			for (auto i = left_lo; i < right_hi; i++) {
				arr[i] = temp[i];
			}
		};
		std::function<void(std::size_t, std::size_t)> mergeSort = [&](std::size_t lo, std::size_t hi) {
			if (hi <= lo + 1) {
				return;
			}
			auto mid = (lo + hi) / 2;
			mergeSort(lo, mid);
			mergeSort(mid, hi);
			merge(lo, mid, mid, hi);

		};
		mergeSort(0, N);
		return count;
	};
	/*
	Maximum difference between two elements such that larger element appears after the smaller number
	Given an array arr[] of integers, find out the difference between any two elements such that larger
	element appears after the smaller number in arr[].

	Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2).
	If array is [ 7, 9, 5, 6, 3, 2 ] then returned value should be 2 (Diff between 7 and 9)

	*/
	template<typename Ty, std::size_t N>
	auto maxDifference(Ty(&arr)[N]) {
		Ty runMin, runMax = arr[0], 0;
		std::advance(arr, 1);
		for (auto& elem : arr) {
			if (elem < runMin) {
				runMin = elem;
			}
			else if (elem > runMin) {
				runMax = std::max(elem, elem - runMin);
			}
		}
	}
	/*
	Segregate Even and Odd numbers
	Given an array A[], write a function that segregates even and odd numbers.
	The functions should put all even numbers first, and then odd numbers.

	Example

	Input  = {12, 34, 45, 9, 8, 90, 3}
	Output = {12, 34, 8, 90, 45, 9, 3} 
	In the output, order of numbers can be changed, i.e., in the above example
	34 can come before 12 and 3 can come before 9.
	*/
	template<typename Ty, std::size_t N>
	auto SegregateOddEven(Ty(&arr)[N]) {
		for (std::size_t even = 0, odd = N - 1; even < odd;) {
			while (even < odd && arr[even] % 2 == 0) {
				even++;
			}
			while (even < odd && arr[odd] % 2 != 0) {
				odd--;
			}
			std::swap(arr[even], arr[odd]);
		}
	}
	/*
	Union and Intersection of two sorted arrays
	Given two sorted arrays, find their union and intersection.

	For example, if the input arrays are: 
	arr1[] = {1, 3, 4, 5, 7}
	arr2[] = {2, 3, 5, 6}
	Then your program should print Union as {1, 2, 3, 4, 5, 6, 7} and Intersection as {3, 5}. 

	*/
	template<typename Ty, std::size_t N, std::size_t M>
	auto UnionAndIntersection(Ty(&larr)[N], Ty(&rarr)[M], Ty(&output)[N + M]) {
		std::size_t left = 0, right = 0, iUnion = 0, iInt = N + M;
		Ty intUnion[std::min(N, M)] = {};
		for (; left < N && right < M;) {
			if (larr[left] < rarr[right]) {
				output[iUnion] = larr[left];
				iUnion++;
				left++;
			}
			else if (larr[left] > rarr[right]) {
				output[iUnion] = rarr[right];
				iUnion++;
				right++;
			}
			else {
				output[--iInt] = larr[left];
				right++;
				left++;
			}
		}
		for (; left < N; iUnion++, left++) {
			output[iUnion] = larr[left];			
		}
		for (; right < M; iUnion++, right++) {
			output[iUnion] = larr[right];
		}
		for (std::size_t i = 0; i < N + M - iInt; i++) {
			output[iInt - i - 1] = output[iInt + i];
			output[iInt + i] = 0;
		}
		return std::make_pair(2 * iInt - N - M, iInt);
	}
	/*
	Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
	Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e]
	such that sorting this subarray makes the whole array sorted.

	Examples:
	1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should
	be able to find that the subarray lies between the indexes 3 and 8.

	2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], your program should be able to
	find that the subarray lies between the indexes 2 and 5.

	*/
	template<typename Ty, std::size_t N>
	auto MinLenUnsortedSubarray(Ty(&arr)[N]) {
		std::size_t start = 0, end = N - 1, 
			maxLeft = std::numeric_limits<Ty>::min(), minRight = std::numeric_limits<Ty>::max();
		for (; start < N - 2 && arr[start] < arr[start + 1]; start++);
		for (; end >= 0 && arr[end] > arr[end - 1]; end--);
		for (std::size_t left = 0; left < start; left++) {
			if (arr[left] > arr[minLeft]) {
				maxLeft = left;
			}
		}
		for (std::size_t right = N - 1; right > end; right--) {
			if (arr[right] > arr[minRight]) {
				minRight = right;
			}
		}
		if (arr[start] < arr[minLeft]) {
			start = minLeft;
		}
		if (arr[end] > arr[minRight]) {
			end = minRight;
		}
		return std::make_pair(start, end);
	}
	/*
	Check if array elements are consecutive | Added Method 3
	Given an unsorted array of numbers, write a function that returns true
	if array consists of consecutive numbers. 

	Examples:
	a) If array is {5, 2, 3, 1, 4}, then the function should return true
	because the array has consecutive numbers from 1 to 5.

	b) If array is {83, 78, 80, 81, 79, 82}, then the function should return
	true because the array has consecutive numbers from 78 to 83.

	c) If the array is {34, 23, 52, 12, 3 }, then the function should return
	false because the elements are not consecutive.

	d) If the array is {7, 6, 5, 5, 3, 4}, then the function should return
	false because 5 and 5 are not consecutive.
	*/
	template<typename Ty, std::size_t N>
	auto checkConsecutive(Ty(&arr)[N]) {
		Ty _min = std::numeric_limits<Ty>::max(), _max = std::numeric_limits<Ty>::max(), _sum = 0;
		for (auto& elem : arr) {
			if (elem < _min) {
				_min = elem;
			}
			if (elem > _max) {
				_max = elem;
			}
			_sum += elem;
		}
		return (_min + _max)* N / 2 == _sum;
	}
	/*
	Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
	Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

	Examples:

	  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
	  Output: 6  (j = 7, i = 1)

	  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
	  Output: 8 ( j = 8, i = 0)

	  Input:  {1, 2, 3, 4, 5, 6}
	  Output: 5  (j = 5, i = 0)

	  Input:  {6, 5, 4, 3, 2, 1}
	  Output: -1 
	*/
	template<typename Ty, std::size_t N>
	int MaxIndexDiff(Ty(&arr)[N]) {
		Ty leftarr[N] = {arr[0]}, rightarr[N] = {};
		rightarr[N - 1] = arr[N - 1];
		for (std::size_t i = 1; i < N;i++) {
			leftarr[i] = std::min(leftarr[i - 1], arr[i]);
			rightarr[N - i - 1] = std::max(rightarr[N - i], arr[N - i - 1]);
		}
		std::size_t maxDiff = std::numeric_limits<std::size_t>::min();
for (std::size_t left = 0, right = 0; left < N && right < N;) {
	if (leftarr[left] >= rightarr[right]) {
		left++;
	}
	else {
		right++;
		maxDiff = std::max(maxDiff, right - left - 1);
	}
}
return maxDiff;
	}
	/*
	Count the number of occurrences in a sorted array
	Given a sorted array arr[] and a number x, write a function that counts
	the occurrences of x in arr[]. Expected time complexity is O(Logn)

	Examples:

	  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
	  Output: 4 // x (or 2) occurs 4 times in arr[]

	  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
	  Output: 1

	  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 1
	  Output: 2

	  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 4
	  Output: -1 // 4 doesn't occur in arr[]
	*/
	template<typename Ty, std::size_t N>
	std::size_t OccurCount(Ty(&arr)[N], Ty num) {
		auto lo = std::lower_bound(std::begin(arr), std::end(arr), num);
		auto hi = std::upper_bound(std::begin(arr), std::end(arr), num);
		if (lo == std::end(arr) || *lo != num) {
			return -1;
		}
		return std::distance(lo, hi);
	}
	/*
	Maximum of all subarrays of size k (Added a O(n) method)
	Given an array and an integer k, find the maximum for each and every
	contiguous subarray of size k.

	Examples:

	Input :
	arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
	k = 3
	Output :
	3 3 4 5 5 5 6

	Input :
	arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}
	k = 4
	Output :
	10 10 10 15 15 90 90
	*/
	template<typename Ty, std::size_t N, std::size_t M>
	auto MaxOfKSubArray(Ty(&arr)[N], std::size_t k, Ty (&out)[M]) {
		std::deque<Ty> Q(k);

		for (std::size_t i = 0; i < k; i++) {
			while (!Q.empty() && arr[Q.back()] <= arr[i]) {
				Q.pop_back();
			}
			Q.push_back(i);
		}
		for (std::size_t i = k; i < N; i++) {
			out[i - k] = Q.back();
			while (!Q.empty() && Q.front() <= i - k) {
				Q.pop_front();
			}
			while (!Q.empty() && arr[Q.back()] <= arr[i]) {
				Q.pop_back();
			}
			Q.push_back(i);
		}
	}
	/*
	Find a Fixed Point in a given array
	Given an array of n distinct integers sorted in ascending order,
	write a function that returns a Fixed Point in the array, if there
	is any Fixed Point present in array, else returns -1.
	Fixed Point in an array is an index i such that arr[i] is equal to i.
	Note that integers in array can be negative.

	Examples:

	  Input: arr[] = {-10, -5, 0, 3, 7}
	  Output: 3  // arr[3] == 3

	  Input: arr[] = {0, 2, 5, 8, 17}
	  Output: 0  // arr[0] == 0


	  Input: arr[] = {-10, -5, 3, 4, 7, 9}
	  Output: -1  // No Fixed Point
	*/

	template<typename Ty, std::size_t N>
	auto FixedPoint(Ty(&arr)[N]) {
		std::size_t indexes[N];
		for (std::size_t i = 0; i < N; i++) {
			indexes[i] = i;
		}
		auto index = std::lower_bound(
			std::begin(indexes),
			std::end(indexes),
			0,
			[&](std::size_t index, std::size_t) {
			return index < arr[index];
		});
		return *index;
	}
	/*
	Minimum number of jumps to reach end
	Given an array of integers where each element represents the max number of
	steps that can be made forward from that element. Write a function to return
	the minimum number of jumps to reach the end of the array (starting from the first element).
	If an element is 0, then cannot move through that element.

	Example:

	Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
	Output: 3 (1-> 3 -> 8 ->9)
	First element is 1, so can only go to 3. Second element is 3,
	so can make at most 3 steps eg to 5 or 8 or 9.
	*/
	template<typename Ty, std::size_t N>
	auto Jumps(Ty(&arr)[N]) {
		std::function<Ty(Ty)> recur = [&](Ty idx) {
			if (idx >= N) {
				return 0;
			}
			Ty _min = std::numeric_limits<Ty>::max();
			for (auto jump = 1; jump <= arr[idx]; jump++) {
				if (idx + jump < N) {
					_min = std::min(_min, 1 + recur(idx + jump));
				}
			}
			
			return _min == std::numeric_limits<Ty>::min()? 0 : _min;
		};
		auto _min=  recur(0);
		return _min;
	}
}

#endif
