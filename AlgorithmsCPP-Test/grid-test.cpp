
#include "CppUnitTest.h"
#include "../Algorithms/inc/algo/Grid.h"
#include <array>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsCPPTest
{		
	TEST_CLASS(GridTest)
	{
	public:
		
		TEST_METHOD(HelloWorld)
		{
			typedef BackTracking::Grid<5, 5>::LOC LOC;
			std::vector<LOC> path;
			std::array<std::array<int, 5>, 5> array_grid{{
			{0, 1, 1, 0, 1},
			{0, 1, 0, 0, 1},
			{0, 0, 1, 1, 0},
			{1, 0, 1, 0, 1},
			{0, 1, 1, 1, 0}
			} };
			BackTracking::Grid<5, 5> grid{ array_grid };
			auto min_path = grid(LOC{ 0,0 }, LOC{ 4,4 });
			
		}
		TEST_METHOD(SizeOne)
		{
			typedef BackTracking::Grid<1, 1>::LOC LOC;
			std::vector<LOC> path;
			std::array<std::array<int, 1>, 1> array_grid{ {0} };
			BackTracking::Grid<1, 1> grid{ array_grid };
			auto min_path = grid(LOC{ 0,0 }, LOC{ 0, 0 });
		}
		TEST_METHOD(Complexity)
		{
			constexpr int size = 5;
			typedef BackTracking::Grid<size, size>::LOC LOC;
			std::vector<LOC> path;
			std::array<std::array<int, size>, size> array_grid{ {0} };
			BackTracking::Grid<size, size> grid{ array_grid };
			auto min_path = grid(LOC{ 0,0 }, LOC{ size, size });
			std::stringstream ss;
			ss << "size = " << size << "count = " << grid.count / pow(8, size * size);
			Logger::WriteMessage(ss.str().c_str());

		}
		TEST_METHOD(Negative)
		{
			typedef BackTracking::Grid<5, 5>::LOC LOC;
			std::vector<LOC> path;
			std::array<std::array<int, 5>, 5> array_grid{ {
			{0, 1, 1, 0, 1},
			{1, 1, 0, 0, 1},
			{0, 0, 1, 1, 0},
			{1, 0, 1, 0, 1},
			{0, 1, 1, 1, 0}
			} };
			BackTracking::Grid<5, 5> grid{ array_grid };
			auto min_path = grid(LOC{ 0,0 }, LOC{ 4,4 });
		}

	};
}