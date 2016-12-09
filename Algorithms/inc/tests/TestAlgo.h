#ifndef __TEST_ALGO_H__
#define __TEST_ALGO_H__
#include <algorithm>
#include "util/pprinter.h"
#include "algo/LPS.h"
#include "algo/MVCS.h"
#include "algo/Lev.h"
//https://github.com/itabhijitb/UnitTestFramework
#include "OOTest/OOtest.h"

namespace DP {
	namespace LPS {
		struct Sample : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char input1[] = "palin";
				output = DP::LPS::LPS<char>(input1)();
			}
			bool IsCommitted()
			{
				return output == 1;
			}
			std::size_t output;
		};
		struct Sanity : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char input1[] = "a";
				output = DP::LPS::LPS<char>(input1)();
			}
			bool IsCommitted()
			{
				return output == 1;
			}
			std::size_t output;
		};
		struct NonTrivialOdd : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char input1[] = "sunnyn";
				output = DP::LPS::LPS<char>(input1)();
			}
			bool IsCommitted()
			{
				return output == 2;
			}
			std::size_t output;
		};
		struct NonTrivialEven : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char input1[] = "abhijit";
				output = DP::LPS::LPS<char>(input1)();
			}
			bool IsCommitted()
			{
				return output == 3;
			}
			std::size_t output;
		};
		struct ScaleUp : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char input1[] = "abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba";
				output = DP::LPS::LPS<char>(input1)();
			}
			bool IsCommitted()
			{
				return output == 52;
			}
			std::size_t output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_algo_dp_lps.csv")
				ADD_TEST(DP::LPS, Sample);
				ADD_TEST(DP::LPS, Sanity);
				ADD_TEST(DP::LPS, NonTrivialOdd);
				ADD_TEST(DP::LPS, NonTrivialEven);
				ADD_TEST(DP::LPS, ScaleUp);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace MVCS {
		struct Sample : public OOTestNS::Pledge
		{
			virtual void Honour() {
				int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
				output = DP::MVCS::MVCS<int>(arr)();
			}
			bool IsCommitted()
			{
				return output == 10;
			}
			std::size_t output;
		};
		auto UnitTestLPS() {
			BEGIN_TEST("test_cases_mvcs.csv")
				ADD_TEST(DP::MVCS, Sample);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
	namespace LEV {
		struct Sample : public OOTestNS::Pledge
		{
			virtual void Honour() {
				output = DP::Lev::Levenshtein<std::string>("Abhijit", "Arijit")();
			}
			bool IsCommitted()
			{
				return output == 3;
			}
			std::size_t output;
		};
		auto UnitTestLPS() {
			BEGIN_TEST("test_cases_lev.csv")
				ADD_TEST(DP::LEV, Sample);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
}


#endif

