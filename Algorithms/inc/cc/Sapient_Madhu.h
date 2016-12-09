#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
namespace Sapient_Madhu
{
	struct Node
	{
		int max_depth;
		int max_path;
		Node() :max_depth(-1), max_path(-1) {}
		bool operator < (const Node& rhs)
		{
			return max_path < rhs.max_path;
		}
	};
	class MaxMediators
	{
	public:
		MaxMediators(char* input1[]) : m_iSize(0)
		{
			for (; input1[m_iSize]; m_iSize++)
				m_input1.push_back(input1[m_iSize]);
			m_tree.resize(m_iSize);
		}
		int operator()()
		{
			recurse(1);
			return std::minmax_element(m_tree.begin(), m_tree.end()).second[0].max_path;
		}
	private:
		int recurse(size_t index)
		{
			switch (m_input1[index][0])
			{
			case 'C':
				m_tree[index].max_depth = 0;
				return 0;
			case 'D':
			{
				int left_depth = recurse(index * 2);
				int right_depth = recurse(index * 2 + 1);
				int max_depth = std::max(left_depth, right_depth) + 1;
				m_tree[index].max_depth = max_depth;
				m_tree[index].max_path = left_depth + right_depth + 1;
				return max_depth;
			}
			default:
				return -1;
			}
		}
		std::vector<Node> m_tree;
		std::vector<std::string> m_input1;
		size_t m_iSize;
	};

};