#include <vector>
#include <algorithm>
#include "util/Memorize.h"
namespace DP
{
	namespace IntegerKnapsack
	{
		class IntegerKnapsack : public Memorization::Memorize
		{
		public:
			template<size_t size>
			IntegerKnapsack(int(&weight)[size], int(&value)[size])
				:m_weight(std::begin(weight), std::end(weight)),
				m_value(std::begin(value), std::end(value)){}

			IntegerKnapsack(std::vector<int> weight, std::vector<int> value)
				:m_weight(weight), m_value(value) {};
			std::tuple<int, std::vector<std::tuple<int, int>>> operator()(int W)
			{
				auto result =  recurse(m_weight.size(), W);
				return result;
			}
		private:
			std::tuple<int, std::vector<std::tuple<int, int>>> recurse(size_t j, int W)
			{
				if (j == 0 || W == 0) return std::make_tuple(0, std::vector<std::tuple<int, int>>());
				if (m_weight[j - 1] > W)
				{
					return Memoize(&IntegerKnapsack::recurse, this)(j - 1, W);
				}
				else
				{
					auto lhs = Memoize(&IntegerKnapsack::recurse, this)(j - 1, W);
					auto rhs = Memoize(&IntegerKnapsack::recurse, this)(j - 1, W - m_weight[j - 1]);
					std::get<0>(rhs) += m_value[j - 1];
					std::get<1>(rhs).push_back(std::make_tuple(m_weight[j - 1], m_value[j - 1]));
					return std::max(lhs, rhs,
						[](decltype(lhs) lhs, decltype(rhs) rhs)
					{
						return std::get<0>(lhs) < std::get<0>(rhs);
					}
					);
				}
			}
			std::vector<int> m_weight; // Also Size
			std::vector<int> m_value;  // Also Cost
		};
	}
}