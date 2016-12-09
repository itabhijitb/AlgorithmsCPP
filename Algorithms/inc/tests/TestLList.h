#ifndef __TEST_LIST_H__
#define __TEST_LIST_H__
#include <algorithm>
#include "util/pprinter.h"
#include "ds/LList.h"
//https://github.com/itabhijitb/UnitTestFramework
#include "OOTest/OOtest.h"
namespace LL {
	struct LListReverse : public OOTestNS::Pledge
	{
		virtual void Honour() {
			LLIST::reverse(ll);
		}
		bool IsCommitted()
		{
			LLIST::LList<int> base = { 11, 9, 7, 5, 3, 1 };
			return std::equal(std::begin(ll), std::end(ll), std::begin(base));
		}
		LLIST::LList<int> ll = { 1,3,5,7,9,11 };
	};
	struct LListMerge : public OOTestNS::Pledge
	{
		virtual void Honour() {
			ml = LLIST::merge(ll, rl);
		}
		bool IsCommitted()
		{
			LLIST::LList<int> base = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
			return std::equal(std::begin(ll), std::end(ll), std::begin(base));
		}
		LLIST::LList<int> ll = { 1,3,5,7,9,11 };
		LLIST::LList<int> rl = { 2,4, 6, 8 };
		LLIST::LList<int> ml;
	};
	struct InsertSorted : public OOTestNS::Pledge
	{
		virtual void Honour() {
			LLIST::insertInSorted(fl, 5);
		}
		bool IsCommitted()
		{
			std::forward_list<int> base = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			return base == fl;
		}
		std::forward_list<int> fl = { 1,2,3,4,6,7,8,9 };
	};

	struct FullAdder1 : public OOTestNS::Pledge
	{
		virtual void Honour() {
			auto C = LLIST::fullAdder(A, B);
		}
		bool IsCommitted()
		{
			std::forward_list<int> base = { 3, 1, 6 };
			return C == base;
		}
		std::forward_list<int> A = { 5, 6, 3 };
		std::forward_list<int> B = { 8, 4, 2 };
		std::forward_list<int> C;
	};

	struct FullAdder2 : public OOTestNS::Pledge
	{
		virtual void Honour() {
			auto C = LLIST::fullAdder(A, B);
		}
		bool IsCommitted()
		{
			std::forward_list<int> base = { 5, 0, 0, 5, 6 };
			return C == base;
		}
		std::forward_list<int> A = { 7,5,9,4,6 };
		std::forward_list<int> B = { 8, 4 };
		std::forward_list<int> C;
	};
	auto UnitTest() {
		BEGIN_TEST("test_cases_ds_ll.csv")
			ADD_TEST(LL, LListReverse);
			ADD_TEST(LL, LListMerge);
			ADD_TEST(LL, InsertSorted);
			ADD_TEST(LL, FullAdder1);
			ADD_TEST(LL, FullAdder2);
			ADD_TEST(LL, FullAdder2);
		END_TEST(ALL, FORMATTED, std::cout)
	}
}
#endif

