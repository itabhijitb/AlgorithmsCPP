#include <vector>
#include <map>
#include "../../../PrintStl/PrintStl/pprintstl.h"
namespace BackTracking
{
	class Maze
	{
	public:
		Maze(std::vector<std::vector<int> > maze, size_t limit)
			: maze(maze), limit(limit), count(0), down_extent(0), right_extent(0)
		{
			for (size_t i = 0; i < maze.size(); i++)
			{
				path_count.push_back(std::vector<int>(maze[0].size()));
			}
		}
		size_t operator()()
		{
			std::vector<std::pair<int, int>> path;
			return recurseRight(0, 0, path);
		}
	private:
		size_t recurseRight(size_t x, size_t y, std::vector<std::pair<int, int>> path)
		{
			path.push_back(std::make_pair(x, y));
			if (x >= maze.size() || y >= maze[0].size())
			{
				return 0;
			}
			if (path_count[x][y])
			{
				return path_count[x][y];
			}
			down_extent = 0;
			if (right_extent++ > limit)
			{
				path_count[x][y] = 0;
			}
			
			else if (maze[x][y] == 0)
			{
				path_count[x][y] = 0;
			}
			else if (x == maze.size() - 1 && y == maze[0].size() - 1)
			{
				path_count[x][y] = 1;
				//std::cout<<pprint::pprint<decltype(path)>()(path)<<std::endl;
			}			
			else
			{
				path_count[x][y] = recurseRight(x, y + 1,path) + recurseDown(x + 1, y,path);
			}
			return path_count[x][y];
		}
		size_t recurseDown(size_t x, size_t y, std::vector<std::pair<int, int>> path)
		{
			path.push_back(std::make_pair(x, y));
			if (x >= maze.size() || y >= maze[0].size())
			{
				return 0;
			}
			if (path_count[x][y])
			{
				return path_count[x][y];
			}
			right_extent = 0;
			
			if (down_extent++ > limit)
			{
				path_count[x][y] = 0;
			}
			else if (maze[x][y] == 0)
			{
				path_count[x][y] = 0;
			}
			else if (x == maze.size() - 1 && y == maze[0].size() - 1)
			{
				path_count[x][y] = 1;
				std::cout << pprint::pprint<decltype(path)>()(path) << std::endl;
			}
			else
			{
				path_count[x][y] = recurseRight(x, y + 1, path) + recurseDown(x + 1, y, path);
			}
			return path_count[x][y];
		}
		
		std::vector<std::vector<int> > maze;
		std::vector<std::vector<int> > path_count;
		size_t limit;
		size_t count;
		size_t down_extent, right_extent;
	};
}