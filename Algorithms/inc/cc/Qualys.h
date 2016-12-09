#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <sstream>
namespace Techgig
{
	
	namespace Qualys
	{
		char *output[1000];
		std::string repr(char **output)
		{
			std::stringstream st;
			char **p = output;
			if (strcmp(*p, "No Solution") == 0)
			{
				return "No Solution";
			}
			size_t num_tolls = strtol(p[0], &p[0], 10); ++p[0];
			size_t max_cost = strtol(p[0], &p[0], 10); ++p[0];
			st << "{" << num_tolls << "#" << max_cost;
			for (size_t i = 1; i <= num_tolls; i++)
			{
				st << ", " << p[i];
			}
			st << "}";
			return st.str();

		}
		struct Node
		{
			size_t in_count;
			size_t out_count;
			Node() : in_count(0), out_count(0){};
		};
		struct Path
		{
			int path_num;
			int cost;
			Path(int path_num = 0, int cost = 0) : path_num(path_num), cost(cost) {}
		};

		class Traffic
		{
			typedef std::pair<std::pair < size_t, size_t >, size_t> TOLL_TYPE;
			typedef std::vector <TOLL_TYPE > TOLLS_TYPE;
			typedef std::vector<std::pair<std::vector<size_t>, size_t> > PATHS_TYPE;
			typedef std::map < size_t, std::map<size_t, Path> > ROAD_TYPE;
			struct ComparatorSort
			{
				ComparatorSort(ROAD_TYPE& roads) : roads(roads) {}
				
				
				bool operator()(const TOLL_TYPE& a, const TOLL_TYPE& b) 
				{
					return roads[a.first.first][a.first.second].index < roads[b.first.first][b.first.second].index;
				}

				ROAD_TYPE& roads;
			};
			struct ComparatorUnique
			{
				bool operator()(const TOLL_TYPE& a, const TOLL_TYPE& b)
				{
					return a.first == b.first;
				}
			};
		public:
			Traffic(char *input1[])
			{
				size_t num_nodes = strtol(input1[0], &input1[0], 10); ++input1[0];
				size_t num_paths = strtol(input1[0], &input1[0], 10); ++input1[0];
				for (size_t i = 1; i <= num_nodes; i++)
				{
					nodes[i] = Node();
				}
				for (size_t i = 1; i <= num_paths; i++)
				{
					size_t src = strtol(input1[i], &input1[i], 10); ++input1[i];
					size_t dest = strtol(input1[i], &input1[i], 10); ++input1[i];
					int cost = strtol(input1[i], &input1[i], 10);
					roads[src].insert(std::make_pair(dest, Path(cost, i)));
					nodes[dest].in_count++;
					nodes[src].out_count++;
				}
			}
			char ** operator()()
			{
				size_t max_path = maxpath(1);
				//addtoll(max_path);
				//std::vector<std::string> op;
				//if (tolls.size() == 0)
				//{
				//	op.push_back("No Solution");
				//}
				//else
				//{
				//	{
				//		std::stringstream st;
				//		st << tolls.size() << "#" << max_path;
				//		op.push_back(st.str());
				//	}
				//	for (TOLLS_TYPE::iterator it = tolls.begin(); it != tolls.end(); it++)
				//	{
				//		std::stringstream st;
				//		st << roads[it->first.first][it->first.second].index << "#" << it->second;
				//		op.push_back(st.str());
				//	}
				//}
				//for (size_t i = 0; i < op.size(); i++)
				//{
				//	output[i] = new char[op[i].size() + 1];
				//	strncpy(output[i], op[i].c_str(), op[i].size() + 1);
				//}
				return output;
				 

			}
		private:
			size_t maxpath(Path start, std::vector<Path> path = std::vector<Path>())
			{
				size_t max_path = 0;
				path.push_back(start);
				if (roads[start].size() == 0)
				{
					all_paths.push_back(path);
				}
				for (std::multimap<size_t, Path> ::iterator it = roads[start].begin();
					it != roads[start].end();
					it++)
				{
					size_t path_cost = it->second.cost +  maxpath(it->first, path);
					max_path = std::max(max_path, path_cost);

				}
				return max_path;
			}
			//void addtoll(size_t max_cost)
			//{
			//	for (PATHS_TYPE::iterator it_path = all_paths.begin();
			//		it_path != all_paths.end();
			//		it_path++)
			//	{
			//		TOLL_TYPE toll_fwd, toll_rev;
			//		for (std::vector<size_t>::iterator it = it_path->first.begin();
			//			it != it_path->first.end() - 1;
			//			it++)
			//		{
			//			if (nodes[*(it + 1)].in_count > 1)
			//			{
			//				toll_fwd = std::make_pair(std::make_pair(*it, *(it + 1)), max_cost - it_path->second);
			//				break;
			//			}
			//		}
			//		for (std::vector<size_t>::reverse_iterator it = it_path->first.rbegin();
			//			it != it_path->first.rend() - 1;
			//			it++)
			//		{
			//			if (nodes[*(it + 1)].out_count > 1)
			//			{
			//				toll_rev = std::make_pair(std::make_pair(*(it + 1),*it), max_cost - it_path->second);
			//				break;
			//			}
			//		}
			//		if (toll_fwd.second > 0)
			//		{
			//			if (toll_fwd.first.first > toll_rev.first.first && pseudo2real.count(toll_fwd.first.first) == 0)
			//			{
			//				tolls.push_back(toll_fwd);
			//			}
			//			else
			//			{
			//				tolls.push_back(toll_rev);
			//			}
			//		}
			//	}
			//	std::sort(tolls.begin(), tolls.end(), ComparatorSort(roads));
			//	TOLLS_TYPE::iterator it = std::unique(tolls.begin(), tolls.end(), ComparatorUnique());
			//	if (it != tolls.end())
			//	{
			//		tolls.clear();
			//	}

			//}
			// src -> (dest, cost)
			std::map<size_t, std::multimap<size_t, Path> > roads;
			std::map<size_t, Node> nodes;
			std::vector<std::vector<Path> > all_paths;
		};
	}
}