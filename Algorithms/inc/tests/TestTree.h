#ifndef __TEST_TREE_H__
#define __TEST_TREE_H__
#include <algorithm>
#include <chrono>
#include <random>
#include "util/pprinter.h"
#include "ds/Tree.h"
//https://github.com/itabhijitb/UnitTestFramework
#include "OOTest/OOtest.h"

namespace Tree {
	namespace BST {
		struct SampleLCS : public OOTestNS::Pledge
		{
			virtual void Honour() {
				tree += 6;
				tree += 9;
				tree += 7;
				tree += 10;
				tree += 11;
			}
			bool IsCommitted()
			{
				return tree.LCS() == 4;
			}
			Tree::BST::BST<int> tree;
		};
		struct SampleFLIP : public OOTestNS::Pledge
		{
			virtual void Honour() {
				tree += 6;
				tree += 4;
				tree += 3;
				tree += 5;
				tree += 8;
				tree += 7;
				tree += 9;
			}
			bool IsCommitted()
			{
				return false;
			}
			Tree::BST::BST<int> tree;
		};		
	}
	auto UnitTest() {
		BEGIN_TEST("test_cases_sort_mergesort.csv")
			ADD_TEST(Tree::BST, SampleLCS);
			ADD_TEST(Tree::BST, SampleFLIP);
		END_TEST(ALL, FORMATTED, std::cout)
	}
}


#endif

