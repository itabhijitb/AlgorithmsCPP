//#include "MVCS.h"
//#include "Lev.h"
//#include "LIS.h"
//#include <string>
//#include "IntegerKnapsack.h"
//#include <iostream>
//#include <vector>
//#include "mergesort.h"
//#include "mergesort_async.h"
//#include "qsort.h"
//#include "qsort_async.h"
//#include "heapq.h"
//#include "max_sub_array.h"
//#include "Sapient.h"
//#include "Sapient_Madhu.h"
//#include "Loop.h"
//#include <chrono>
//#include <random>
//#include "Permutation.h"
//#include "Maze.h"
//#include "Server.h"
////#include "Qualys.h"
////#include "Ideas.h"
//#include "Wise.h"
//#include "LPS.h"
//#include "pprinter.h"
//#include "Tree.h"
//#include "LList.h"
//#include "SStack.h"
//void test()
//{
//	{
//		LLIST::LList<int> ll = { 1,3,5,7,9,11 };
//		LLIST::LList<int> rl = { 8,6,4,2 };
//		std::cout << ll << std::endl;
//		LLIST::reverse(ll);
//		std::cout << ll << std::endl;
//		std::cout << rl << std::endl;
//		auto ml = LLIST::merge(ll, rl);
//		std::cout << ml << std::endl;
//		std::cout << LLIST::middle(std::begin(ml), std::end(ml)) << std::endl;
//		LLIST::reverse(ml);
//		//std::cout << LLIST::mergeSort(std::begin(ml), std::end(ml)) << std::endl;
//	}
//	{
//		std::forward_list<int> fl = { 1,2,3,4,6,7,8,9 };
//		std::cout << pprint::pprint<decltype(fl)>()(fl) << std::endl;
//		LLIST::insertInSorted(fl, 5);
//		std::cout << pprint::pprint<decltype(fl)>()(fl) << std::endl;
//	}
//	{
//		{
//			std::forward_list<int> A = { 5, 6, 3 };
//			std::forward_list<int> B = { 8, 4, 2 };
//			auto C = LLIST::fullAdder(A, B);
//			std::cout << pprint::pprint<decltype(C)>()(C) << std::endl;
//		}
//		{
//			std::forward_list<int> A = { 7,5,9,4,6 };
//			std::forward_list<int> B = { 8, 4 };
//			auto C = LLIST::fullAdder(A, B);
//			std::cout << pprint::pprint<decltype(C)>()(C) << std::endl;
//		}
//	}
//	{
//		{
//			auto arr = SSTACK::nextGreaterElement<int>({ 4, 5, 2, 25 }, -1);
//			std::cout << pprint::pprint<decltype(arr)>()(arr) << std::endl;
//		}
//		{
//			auto arr = SSTACK::nextGreaterElement<int>({ 13, 7, 6, 1 }, -1);
//			std::cout << pprint::pprint<decltype(arr)>()(arr) << std::endl;
//		}
//	}
//	{
//		char input1[] = "palin";
//		std::cout << DP::LPS::LPS<char>(input1)() << std::endl;
//	}
//	{
//		char input1[] = "a";
//		std::cout << DP::LPS::LPS<char>(input1)() << std::endl;
//	}
//	{
//		char input1[] = "palin";
//		std::cout << DP::LPS::LPS<char>(input1)() << std::endl;
//	}
//	{
//		char input1[] = "palin";
//		std::cout << DP::LPS::LPS<char>(input1)() << std::endl;
//	}
//	{
//		char input1[] = "sunnyn";
//		std::cout << DP::LPS::LPS<char>(input1)() << std::endl;
//	}
//	{
//		char input1[] = "abhijit";
//		std::cout << DP::LPS::LPS<char>(input1)() << std::endl;
//	}
//	{
//		char *input1[] = { "A", "B", "C", "D" , NULL};
//		int input2[] = { 2, 1, 3, 2, 4, 3 };
//		std::cout << Techgig::Wise::PB1::Kruskal(input1, input2)() << std::endl;
//	}
//	{
//		char *input1[] = { "A", "B", "C", "D", NULL };
//		int input2[] = { 1, 1, 1, 1, 1, 1 };
//		std::cout << Techgig::Wise::PB1::Kruskal(input1, input2)() << std::endl;
//	}
//	{
//		char *input1[] = { NULL };
//		int input2[] = { -9999};
//		std::cout << Techgig::Wise::PB1::Kruskal(input1, input2)() << std::endl;
//	}
//	//{
//	//	char *st = "C1(P2,5,P4,3)C2(P1,4,P2,6)C3(P1,7,P3,5,P4,6)C4(P4,10,P5,5)C5(P4,9)";
//	//	std::cout << Techgig::Ideas::PB1::Matching(st)() << std::endl;
//	//}
//	//{
//	//	char *arr[] = { "4#6", "1#2#7", "1#2#8", "1#3#10", "2#4#4", "2#4#3", "3#4#15", NULL };
//	//	std::cout << Techgig::Qualys::repr(Techgig::Qualys::Traffic(arr)()) << std::endl;
//	//}
//	//{
//	//	char *arr[] = { "4#5", "1#2#7", "1#2#8", "1#3#10", "2#4#4", "3#4#15", NULL };
//	//	std::cout << Techgig::Qualys::repr(Techgig::Qualys::Traffic(arr)()) << std::endl;
//	//}
//	//{
//	//	char *arr[] = { "4#4", "1#2#8", "1#3#7", "2#3#2",  "4#4#8", NULL };
//	//	std::cout << Techgig::Qualys::repr(Techgig::Qualys::Traffic(arr)()) << std::endl;
//	//}
//
//	//{
//	//	char *arr[] = { "6#8", "1#2#8", "1#4#7", "1#5#12", "2#3#4", "2#4#2", "3#6#6", "4#6#8", "5#6#10", NULL };
//	//	std::cout << Techgig::Qualys::repr(Techgig::Qualys::Traffic(arr)()) << std::endl;
//	//}
//	{
//		int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
//		std::cout<<DP::MVCS::MVCS<int>(arr)() <<std::endl;
//	}
//	{
//		std::cout << DP::Lev::Levenshtein<std::string>("Abhijit", "Arijit")() << std::endl;
//	}
//	{
//		int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
//		std::cout << DP::LIS::LIS<int>(arr)() << std::endl;
//	}
//	{
//		std::vector<int> arr(10000);
//		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
//		std::minstd_rand0 generator(seed);
//		std::generate(arr.begin(), arr.end(), generator);
//		{
//			auto start_time = std::chrono::system_clock::now().time_since_epoch();
//			auto result = Sort::MergeSort::MergeSort<int>(arr.begin(), arr.end())();
//			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch() - start_time);
//			//std::cout << pprint::pprint<decltype(result)>()(result) << std::endl;
//			std::cout << "Time Taken " << duration.count() << " ns " << std::endl;
//		}
//		{
//			auto start_time = std::chrono::system_clock::now().time_since_epoch();
//			auto result = Sort::MergeSortAsync::MergeSortAsync<int>(arr.begin(), arr.end())();
//			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch() - start_time);
//			//std::cout << pprint::pprint<decltype(result)>()(result) << std::endl;
//			std::cout << "Time Taken " << duration.count() << " ns " << std::endl;
//		}
//	}
//	//{
//	//	std::vector<int> arr(100);
//	//	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
//	//	std::minstd_rand0 generator(seed);
//	//	std::generate(arr.begin(), arr.end(), generator);
//	//	{
//	//		auto start_time = std::chrono::system_clock::now().time_since_epoch();
//	//		auto result = Sort::QuickSort::QuickSort<int>(arr.begin(), arr.end())();
//	//		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch() - start_time);
//	//		//std::cout << pprint::pprint<decltype(result)>()(result) << std::endl;
//	//		std::cout << "Time Taken " << duration.count() << " ns " << std::endl;
//	//	}
//	//	{
//	//		auto start_time = std::chrono::system_clock::now().time_since_epoch();
//	//		auto result = Sort::QuickSortAsync::QuickSortAsync<int>(arr.begin(), arr.end())();
//	//		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch() - start_time);
//	//		//std::cout << pprint::pprint<decltype(result)>()(result) << std::endl;
//	//		std::cout << "Time Taken " << duration.count() << " ns " << std::endl;
//	//	}
//	//}
//	{
//		int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//		auto result = Sort::QuickSort::QuickSort<int>(arr)();
//		std::cout << pprint::pprint<decltype(result)>()(result) << std::endl;
//	}
//	{
//		int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//		auto result = Sort::QuickSortAsync::QuickSortAsync<int>(arr)();
//		std::cout << pprint::pprint<decltype(result)>()(result) << std::endl;
//	}
//	{
//		int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
//		auto result = Tree::HeapQ::HeapQ<int>(std::begin(arr), std::end(arr))();
//		std::cout << pprint::pprint<decltype(result)>()(result) << std::endl;
//	}
//	{
//		char *arr[] = { " ", "D1", "D2", "D3", "D4", "D5", "D6", " ", "C1", " ", "C2", "C3", "D7", "D8", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "C4", " ", "C5", "C6", " ", " ", " ", " ", 0 };
//		std::cout << Sapient::maxMediators(arr) << std::endl;
//	}
//	{
//		char *arr[] = { " ", "D1", "C1", "C2",  0 };
//		std::cout << Sapient::maxMediators(arr) << std::endl;
//	}
//	{
//		/*
//		
//		                                                          D1
//													     /                 \
//													    D2                 D3
//												   /        \              / \  
//												  D4        D5           D6  
//												/          /  \       /    \
//											   C1         C2  C3     D7    D8 
//											                        /      / \
//															       C4    C5   C6
//
//		
//		*/
//		char *arr[] = { " ", "D1", "D2", "D3", "D4", "D5", "D6", " ", "C1", " ", "C2", "C3", "D7", "D8", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "C4", " ", "C5", "C6", " ", " ", " ", " ", 0 };
//		std::cout << Sapient_Madhu::MaxMediators(arr)() << std::endl;
//	}
//	{
//		char *arr[] = { " ", "D1", "C1", "C2", 0 };
//		std::cout << Sapient_Madhu::MaxMediators(arr)() << std::endl;
//	}
//	{
//		std::vector<std::string> L1 = { "a1", "b1", "c1", "d1" };
//		std::vector<std::string> L2 = { "a2", "b2", "c2" };
//		std::vector<std::string> L3 = { "a3", "b3", "c3" };
//		auto P = Itertools::Product<std::string>()(L1, L2, L3);
//		for (auto perm : P)
//		{
//			std::cout << "[";
//			for (auto elem : perm)
//			{
//				std::cout << elem << ',';
//			}
//			std::cout << "]" << std::endl;
//		}
//	}
//	{
//		size_t servers[] = { 8, 16, 8, 32 };
//		size_t  tasks[] = { 18, 4, 8, 4, 6, 6, 8, 8 };
//		std::cout << BackTracking::TaskScheduling(
//			std::begin(servers), std::end(servers),
//			std::begin(tasks), std::end(tasks))() << std::endl;
//
//	}
//	{
//		size_t servers[] = { 1, 3 };
//		size_t  tasks[] = { 4 };
//		std::cout << BackTracking::TaskScheduling(
//			std::begin(servers), std::end(servers),
//			std::begin(tasks), std::end(tasks))() << std::endl;
//
//	}
//	//{
//	//	std::vector<std::vector<int>> maze;
//	//	size_t R, C, d;
//	//	std::cin >> R >> C >> d;
//	//	for (size_t i = 0; i < R; i++)
//	//	{
//	//		maze.push_back(std::vector<int>(C));
//	//		for (size_t j = 0; j < C; j++)
//	//		{
//	//			std::cin >> maze[i][j];
//	//		}
//	//	}
//	//	//R = C = d = 300;
//	//	//for (size_t i = 0; i < R; i++)
//	//	//{
//	//	//	maze.push_back(std::vector<int>(C));
//	//	//	for (size_t j = 0; j < C; j++)
//	//	//		maze[i][j] = 1;
//	//	//}
//	//	std::cout << BackTracking::Maze(maze, d)() << std::endl;;
//
//	//}
//
//}
//
//int main() {
//	test();
//	{
//		Tree::BST::BST<int> tree;
//		tree += 6;
//		tree += 9;
//		tree += 7;
//		tree += 10;
//		tree += 11;
//		std::cout << tree.LCS() << std::endl;
//	}
//	{
//		Tree::BST::BST<int> tree;
//		tree += 6;
//		tree += 4;
//		tree += 3;
//		tree += 5;
//		tree += 8;
//		tree += 7;
//		tree += 9;
//		tree.Flip();
//	}
//}
void UnitTestAll();
int main() {
	UnitTestAll();
}