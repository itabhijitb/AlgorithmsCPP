#ifndef __SAPIENT_H__
#define __SAPIENT_H__
#undef max
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

namespace Sapient
{
	struct Node
	{
		int left_height;
		int right_height;
		int max_path;
		Node() :left_height(-1), right_height(-1), max_path(-1) {}
		friend bool operator < (const Node& lhs, const Node& rhs)
		{
			return lhs.max_path < rhs.max_path;
		}
	};
	int maxMediators(char* input1[])
	{
		size_t size = 0;
		for (; input1[size]; size++);
		if (size < 2) return 0;
		std::vector<Node> tree(size);
		for (size_t i = size - 1; i > 1; i--)
		{
			switch (input1[i][0])
			{
			case 'C':
				tree[i].left_height = tree[i].right_height = tree[i].max_path = 0;
			case 'D':

				if (i % 2)
				{
					tree[i / 2].right_height = std::max(tree[i].left_height, tree[i].right_height) + 1;
				}
				else
				{
					tree[i / 2].left_height = std::max(tree[i].left_height, tree[i].right_height) + 1;
					
				}
				tree[i / 2].max_path = tree[i / 2].left_height + tree[i/2].right_height - 1;
			}
		}
		return std::minmax_element(tree.begin(), tree.end()).second[0].max_path;
	}
};
#endif