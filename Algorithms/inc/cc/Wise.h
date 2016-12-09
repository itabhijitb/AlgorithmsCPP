#include <vector>
#include <map>
#include <algorithm>
namespace Techgig
{
	namespace Wise
	{
		namespace PB1
		{
			class DisjointSet
			{
			public:
				void Union(int u, int v)
				{
					links[u] = v;
					if (links.count(v) == 0)
					{
						links[v] = -1;
					}
				}
				bool IsLoop(int u, int v)
				{
					if (links.count(u) == 0)
					{
						return false;
					}
					for (int next = links[u]; next != -1; next = links[next])
					{
						if (next == v) return true;
					}
					return false;
				}
			private:
				std::map<int, int> links;
			};
			class Kruskal
			{
			public:
				typedef std::pair< int, int > edge;
				Kruskal(char* input1[], int input2[])
				{
					N = 0;
					for (; input1[N] != NULL; N++);
					E = N * (N - 1) / 2;
					for (int u = 1; u <= N; u++)
						for (int v = u + 1; v <= N; v++)
							GRAPH.push_back(std::pair< int, edge >(*(input2++), edge(u, v)));
					//parent.push_back(-1);
					//for (int i = 1; i <= N; i++) parent.push_back(i);
				}
				int operator()()
				{
					int i, pu, pv;
					std::sort(GRAPH.begin(), GRAPH.end()); // increasing weight
					for (i = total = 0; i < E; i++)
					{
						//pu = findset(GRAPH[i].second.first, parent);
						//pv = findset(GRAPH[i].second.second, parent);
						if (!ds.IsLoop(GRAPH[i].second.first, GRAPH[i].second.second))
						{
							MST.push_back(GRAPH[i]); // add to tree
							total += GRAPH[i].first; // add edge cost
							//parent[pu] = parent[pv]; // link
							ds.Union(GRAPH[i].second.first, GRAPH[i].second.second);
						}
					}
					return total;
				}
			private:
				/*int findset(int x, std::vector<int>& parent)
				{
					if (x != parent[x])
						parent[x] = findset(parent[x], parent);
					return parent[x];
				}*/
				//std::vector<int> parent;
				DisjointSet ds;
				int total, N, E;
				std::vector< std::pair< int, edge > > GRAPH, MST;
			};

		}
	}
}