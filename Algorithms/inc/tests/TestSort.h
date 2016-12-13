#ifndef __TEST_SORT_H__
#define __TEST_SORT_H__
#include <algorithm>
#include <chrono>
#include <random>
#include "util/pprinter.h"
#include "algo/mergesort.h"
#include "algo/mergesort_async.h"
#include "algo/qsort.h"
#include "algo/qsort_async.h"
//https://github.com/itabhijitb/UnitTestFramework
#include "OOTest/OOtest.h"

namespace Sort {
	namespace MergeSort {
		struct Sample : public OOTestNS::Pledge
		{
			Sample() {
				arr.resize(10000);
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::minstd_rand0 generator(seed);
				std::generate(arr.begin(), arr.end(), generator);
			};
			virtual void Honour() {
				output = Sort::MergeSort::MergeSort<int>(arr.begin(), arr.end())();
			}
			bool IsCommitted()
			{
				return true;
			}
			std::vector<int> arr;
			std::vector<int> output;
		};
	}
	namespace MergeSortAsync {
		struct Sample : public OOTestNS::Pledge
		{
			Sample() {
				arr.resize(10000);
				auto seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::minstd_rand0 generator(seed);
				std::generate(arr.begin(), arr.end(), generator);
			};
			virtual void Honour() {
				output = Sort::MergeSortAsync::MergeSortAsync<int>(arr.begin(), arr.end())();
			}
			bool IsCommitted()
			{
				return true;
			}
			std::vector<int> arr;
			std::vector<int> output;
		};
	}
	namespace QuickSort {
		struct Sample : public OOTestNS::Pledge
		{
			Sample() {
				arr.resize(10000);
				auto seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::minstd_rand0 generator(seed);
				std::generate(arr.begin(), arr.end(), generator);
			};
			virtual void Honour() {
				output = Sort::QuickSort::QuickSort<int>(arr.begin(), arr.end())();
			}
			bool IsCommitted()
			{
				return true;
			}
			std::vector<int> arr;
			std::vector<int> output;
		};
	}
	namespace QuickSortAsync {
		struct Sample : public OOTestNS::Pledge
		{
			Sample() {
				arr.resize(10000);
				const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::minstd_rand0 generator(seed);
				std::generate(arr.begin(), arr.end(), generator);
			};
			virtual void Honour() {
				output = Sort::QuickSortAsync::QuickSortAsync<int>(arr.begin(), arr.end())();
			}
			bool IsCommitted()
			{
				return true;
			}
			std::vector<int> arr;
			std::vector<int> output;
		};
	}
	auto UnitTest() {
		BEGIN_TEST("test_cases_sort.csv")
			ADD_TEST(Sort::QuickSort, Sample);
			ADD_TEST(Sort::QuickSortAsync, Sample);
			ADD_TEST(Sort::MergeSort, Sample);
			ADD_TEST(Sort::MergeSortAsync, Sample);
		END_TEST(ALL, FORMATTED, std::cout)

	}
}


#endif

