#ifndef __TEST_CODE_COMP_H__
#define __TEST_CODE_COMP_H__
#include <algorithm>
#include "util/pprinter.h"
#include "cc/Sapient.h"
#include "cc/Sapient_Madhu.h"
//https://github.com/itabhijitb/UnitTestFramework
#include "OOTest/OOtest.h"

namespace Sapient {
	namespace MaxMed {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char *arr[] = {
					" ", "D1", "D2", "D3", "D4", "D5", "D6"," ",
					"C1", " ", "C2", "C3", "D7", "D8", " ", " ",
					" ", " ", " ", " ", " ", " ", " ", " ", "C4",
					" ", "C5", "C6", " ", " ", " ", " ", 0 };
				output = Sapient::maxMediators(arr);
			}
			bool IsCommitted()
			{
				return output == 1;
			}
			std::size_t output;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char *arr[] = { " ", "D1", "C1", "C2",  0 };
				output = Sapient::maxMediators(arr);
			}
			bool IsCommitted()
			{
				return output == 1;
			}
			std::size_t output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_cc_sapient_maxmed.csv")
				ADD_TEST(Sapient::MaxMed, Sample1);
			ADD_TEST(Sapient::MaxMed, Sample2);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
};
namespace SapientMadhu {
	namespace MaxMed {
		struct Sample1 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char *arr[] = {
					" ", "D1", "D2", "D3", "D4", "D5", "D6"," ",
					"C1", " ", "C2", "C3", "D7", "D8", " ", " ",
					" ", " ", " ", " ", " ", " ", " ", " ", "C4",
					" ", "C5", "C6", " ", " ", " ", " ", 0 };
				output = Sapient_Madhu::MaxMediators(arr)();
			}
			bool IsCommitted()
			{
				return output == 1;
			}
			std::size_t output;
		};
		struct Sample2 : public OOTestNS::Pledge
		{
			virtual void Honour() {
				char *arr[] = { " ", "D1", "C1", "C2",  0 };
				output = Sapient_Madhu::MaxMediators(arr)();
			}
			bool IsCommitted()
			{
				return output == 1;
			}
			std::size_t output;
		};
		auto UnitTest() {
			BEGIN_TEST("test_cases_cc_sapient_maxmed.csv")
				ADD_TEST(Sapient::MaxMed, Sample1);
			ADD_TEST(Sapient::MaxMed, Sample2);
			END_TEST(ALL, FORMATTED, std::cout)
		}
	}
};


#endif

