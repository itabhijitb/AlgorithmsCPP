#include <tuple>
#include <vector>
#include <algorithm>
/*

a > b > c

(a - b) + (b - c) + (a - c) = 2(a - c)

a > c > b
(a - b) + (c - b) + (a - c) = 2(a - b)

b > a > c
(b - a) + (b - c) + (a - c) = 2(b - c)

*/
//std::tuple<int, int, int> findMinAbsSum(std::vector<int>& va, std::vector<int>& vb, std::vector<int>& vc) {
//	std::sort(std::begin(va), std::end(va));
//	std::sort(std::begin(vb), std::end(vb));
//	std::sort(std::begin(vc), std::end(vc));
//	std::tuple<int, int, int> result;
//	int min_value;
//	for (auto a : va){
//		auto it_b = std::lower_bound(std::begin(vb), std::end(vb), a);
//		auto b = *it_b;
//		b = abs(a - b) < abs(a - *++it_b) ? *it_b : b;
//		//auto it_c = std::lower_bound(std::begin(c), std::end(c), b);
//		//auto c = *it_c;
//		//c = abs(b - c) < abs(b - *++it_b) ? *it_c : c;
//		//auto local_min = abs(a - b) + abs(b - c) + abs(c - a);
//	}
//}