#ifndef __TEST_ARRAY_H__
#define __TEST_ARRAY_H__
#include <algorithm>
#include "util/pprinter.h"
#include "ds/Array.h"
//https://github.com/itabhijitb/UnitTestFramework
#include "OOTest/OOtest.h"

namespace Array {
	namespace MajElem {
		struct SamplePositive : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
				output = Array::majority(arr);
			}
			bool IsCommitted()
			{
				return *output == 4;
			}
			std::unique_ptr<int> output;
		};
		struct SampleNeg : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 3, 3, 4, 2, 4, 4, 2, 4 };
				output = Array::majority(arr);
			}
			bool IsCommitted()
			{
				return output == nullptr;
			}
			std::unique_ptr<int> output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::MajElem, SamplePositive);
			ADD_TEST(Array::MajElem, SampleNeg);
			END_TEST(ALL, FORMATTED, std::cout)
		}

	}
	namespace TestLargestSumContiguousSubarray {
		struct Sample : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
				output = Array::LargestSumContiguousSubarray(arr);
			}
			bool IsCommitted()
			{
				return output == 7;
			}
			int output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestLargestSumContiguousSubarray, Sample);
			END_TEST(ALL, FORMATTED, std::cout)
		}

	}

	namespace TestSearchSortedAndRotatedArray {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 7, 8, 9, 1, 2, 3, 4, 5, 6 };
				output = Array::SearchSortedAndRotatedArray(arr, 1);
			}
			bool IsCommitted()
			{
				return *output == 3;
			}
			std::unique_ptr<std::size_t> output;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
				output = Array::SearchSortedAndRotatedArray(arr, 6);
			}
			bool IsCommitted()
			{
				return *output == 2;
			}
			std::unique_ptr<std::size_t> output;
		};
		struct Sample3 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 5, 6, 7, 8, 9, 10, 1, 2 };
				output = Array::SearchSortedAndRotatedArray(arr, 3);
			}
			bool IsCommitted()
			{
				return *output == 8;
			}
			std::unique_ptr<std::size_t> output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestSearchSortedAndRotatedArray, Sample1);
			ADD_TEST(Array::TestSearchSortedAndRotatedArray, Sample2);
			ADD_TEST(Array::TestSearchSortedAndRotatedArray, Sample3);
			END_TEST(ALL, FORMATTED, std::cout)
		}

	}
	namespace TestRotate {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::rotate(arr, 3);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(arr),
					std::end(arr),
					std::begin({ 4, 5, 6, 7, 1, 2, 3 }));
			}
			int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::rotate(arr, 3);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(arr),
					std::end(arr),
					std::begin({ 4, 5, 6, 7, 8, 1, 2, 3 }));
			}
			int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		};
		struct Sample3 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::rotate(arr, 2);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(arr),
					std::end(arr),
					std::begin({ 3, 4, 5, 6, 7, 8, 9, 1, 2 }));
			}
			int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		};
		struct Sample4 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::rotate(arr, 2);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(arr),
					std::end(arr),
					std::begin({ 3, 4, 5, 6, 1, 2 }));
			}
			int arr[6] = { 1, 2, 3, 4, 5, 6 };
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestRotate, Sample1);
			ADD_TEST(Array::TestRotate, Sample2);
			ADD_TEST(Array::TestRotate, Sample3);
			ADD_TEST(Array::TestRotate, Sample4);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestInvCount {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 1, 20, 6, 4, 5 };
				output = Array::inversion_count(arr);
			}
			bool IsCommitted()
			{
				return output == 5;
			}
			std::size_t output;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 2, 4, 1, 3, 5 };
				output = Array::inversion_count(arr);
			}
			bool IsCommitted()
			{
				return output == 3;
			}
			std::size_t output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestInvCount, Sample1);
			ADD_TEST(Array::TestInvCount, Sample2);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestmaxDiff {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 1, 2, 90, 10, 110 };
				output = Array::inversion_count(arr);
			}
			bool IsCommitted()
			{
				return output == 109;
			}
			std::size_t output;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 2, 3, 10, 6, 4, 8, 1 };
				output = Array::inversion_count(arr);
			}
			bool IsCommitted()
			{
				return output == 8;
			}
			std::size_t output;
		};
		struct Sample3 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { 7, 9, 5, 6, 3, 2 };
				output = Array::inversion_count(arr);
			}
			bool IsCommitted()
			{
				return output == 2;
			}
			std::size_t output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestmaxDiff, Sample1);
			ADD_TEST(Array::TestmaxDiff, Sample2);
			ADD_TEST(Array::TestmaxDiff, Sample3);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestSegregateOddEven {
		struct Sample : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::SegregateOddEven(arr);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(arr),
					std::end(arr),
					std::begin({ 12, 34, 90, 8, 9, 45, 3 }));
			}
			int arr[7] = { 12, 34, 45, 9, 8, 90, 3 };
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestSegregateOddEven, Sample);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestUnionAndIntersection {
		struct Sample : public OOTestNS::Pledge
		{
			virtual void Honour() {
				result = Array::UnionAndIntersection(arr1, arr2, output);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(output),
					std::begin(output) + result.second,
					std::begin({ 1, 2, 4, 6, 7 , 3, 5 }))
					&& std::equal(
						std::begin(output) + result.first,
						std::begin(output) + result.second,
						std::begin({ 3, 5 }));
			}
			int arr1[5] = { 1, 3, 4, 5, 7 };
			int arr2[4] = { 2, 3, 5, 6 };
			int output[9] = {};
			std::pair<std::size_t, std::size_t> result;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestUnionAndIntersection, Sample);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestMaxIndexDiff {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::MaxIndexDiff(arr);
			}
			bool IsCommitted()
			{
				return output == 6;
			}
			int arr[9] = { 34, 8, 10, 3, 2, 80, 30, 33, 1 };
			std::size_t output = 0;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::MaxIndexDiff(arr);
			}
			bool IsCommitted()
			{
				return output == 8;
			}
			int arr[10] = { 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };
			std::size_t output = 0;
		};
		struct Sample3 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::MaxIndexDiff(arr);
			}
			bool IsCommitted()
			{
				return output == 5;
			}
			int arr[6] = { 1, 2, 3, 4, 5, 6 };
			std::size_t output = 0;
		};
		struct Sample4 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::MaxIndexDiff(arr);
			}
			bool IsCommitted()
			{
				return output == 3;
			}
			int arr[6] = { 7, 8, 1, 9, 5, 6 };
			std::size_t output = 0;
		};
		struct Edge1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::MaxIndexDiff(arr);
			}
			bool IsCommitted()
			{
				return output == -1;
			}
			int arr[6] = { 6, 5, 4, 3, 2, 1 };
			int output = 0;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestMaxIndexDiff, Sample1);
				ADD_TEST(Array::TestMaxIndexDiff, Sample2);
				ADD_TEST(Array::TestMaxIndexDiff, Sample3);
				ADD_TEST(Array::TestMaxIndexDiff, Sample4);
				ADD_TEST(Array::TestMaxIndexDiff, Edge1);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestOccurCount {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::OccurCount(arr, 2);
			}
			bool IsCommitted()
			{
				return output == 4;
			}
			int arr[7] = { 1, 1, 2, 2, 2, 2, 3 };
			std::size_t output = 0;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::OccurCount(arr, 3);
			}
			bool IsCommitted()
			{
				return output == 1;
			}
			int arr[7] = { 1, 1, 2, 2, 2, 2, 3 };
			std::size_t output = 0;
		};
		struct Sample3 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::OccurCount(arr, 1);
			}
			bool IsCommitted()
			{
				return output == 2;
			}
			int arr[7] = { 1, 1, 2, 2, 2, 2, 3 };
			std::size_t output = 0;
		};
		struct Edge1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::OccurCount(arr, 4);
			}
			bool IsCommitted()
			{
				return output == -1;
			}
			int arr[7] = { 1, 1, 2, 2, 2, 2, 3 };
			int output = 0;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestOccurCount, Sample1);
				ADD_TEST(Array::TestOccurCount, Sample2);
				ADD_TEST(Array::TestOccurCount, Sample3);
				ADD_TEST(Array::TestOccurCount, Edge1);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestMaxOfKSubArray {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::MaxOfKSubArray(arr, 3, out);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(out),
					std::end(out),
					std::begin({ 3, 3, 4, 5, 5, 5, 6 }));
			}
			int arr[9] = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
			int out[7] = {};
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::MaxOfKSubArray(arr, 4, out);
			}
			bool IsCommitted()
			{
				return std::equal(
					std::begin(out),
					std::end(out),
					std::begin({ 10, 10, 10, 15, 15, 90, 90 }));
			}
			int arr[10] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
			int out[7] = {};
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestMaxOfKSubArray, Sample1);
			ADD_TEST(Array::TestMaxOfKSubArray, Sample2);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestFixedPoint {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::FixedPoint(arr);
			}
			bool IsCommitted()
			{
				return index == 3;
			}
			int arr[5] = { -10, -5, 0, 3, 7 };
			std::size_t index = 0;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::FixedPoint(arr);
			}
			bool IsCommitted()
			{
				return index == 0;
			}
			int arr[5] = { 0, 2, 5, 8, 17 };
			std::size_t index = 0;
		};
		struct Sample3 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				Array::FixedPoint(arr);
			}
			bool IsCommitted()
			{
				return index == -1;
			}
			int arr[6] = { -10, -5, 3, 4, 7, 9 };
			std::size_t index = 0;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestFixedPoint, Sample1);
			ADD_TEST(Array::TestFixedPoint, Sample2);
			ADD_TEST(Array::TestFixedPoint, Sample3);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace TestJumps {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = Array::Jumps(arr);
			}
			bool IsCommitted()
			{
				return output == 3;
			}
			int arr[11] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
			std::size_t output = 0;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_array.csv")
				ADD_TEST(Array::TestJumps, Sample1);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	auto UnitTest() {
		Array::MajElem::UnitTest();
		Array::TestLargestSumContiguousSubarray::UnitTest();
		Array::TestSearchSortedAndRotatedArray::UnitTest();
		Array::TestRotate::UnitTest();
		Array::TestInvCount::UnitTest();
		Array::TestmaxDiff::UnitTest();
		Array::TestSegregateOddEven::UnitTest();
		Array::TestUnionAndIntersection::UnitTest();
		Array::TestMaxIndexDiff::UnitTest();
		Array::TestOccurCount::UnitTest();
		Array::TestMaxOfKSubArray::UnitTest();
		Array::TestFixedPoint::UnitTest();
		Array::TestJumps::UnitTest();
	}
}


#endif

