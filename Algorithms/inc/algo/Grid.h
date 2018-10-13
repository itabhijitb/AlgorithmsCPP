#ifndef __GRID_H_
#define __GRID_H_
#include <array>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <algorithm>
#include "../../PrintStl/PrintStl/pprintstl.h"

namespace BackTracking
{
	template<int R, int C>
	//constexpr int R = 10, C = 10;
	class Grid {
	public:
		struct LOC {
			int r, c;
			bool operator==(const LOC rhs) const {
				return r == rhs.r && c == rhs.c;
			}

		};
	private:
		typedef std::array<std::array<int, C>, R> GRID;
		typedef std::vector<LOC> PATH;
		
		PATH min_path;
	public:
		GRID grid, visit{ false };
		size_t count = 0;
		Grid(GRID grid) : grid(grid) {}
		auto isValid(LOC loc) {
			return (0 <= loc.r && loc.r < R && 0 <= loc.c && loc.c < C && grid[loc.r][loc.c] == 0);
		}
		auto get_neighbours(LOC loc) {
			auto r = loc.r, c = loc.c;
			std::vector<LOC> neighbours{};
			for (int rx = r - 1; rx <= r + 1; rx++) {
				for (int cx = c - 1; cx <= c + 1; cx++) {
					if ((rx != r || cx != c) && isValid(LOC{ rx, cx })) {
						neighbours.push_back(LOC{ rx, cx });
					}

				}
			}
			return neighbours;
		}
		auto operator()(const LOC& start, const LOC& goal) {
			visit[start.r][start.c] = true;
			traverse(start, goal);
			return min_path;

		}
	private:
		void traverse(const LOC& start, const LOC& goal, PATH& path = PATH()) {
			count++;
			if (start == goal) {
				if (min_path.size() == 0 || min_path.size() > path.size()) {
					min_path = path;
					return;
				}
			}
			for (auto neighbour : get_neighbours(start)) {
				if (visit[neighbour.r][neighbour.c] <= 0) {
					visit[neighbour.r][neighbour.c] = abs(visit[neighbour.r][neighbour.c]) + 1;
					path.push_back(neighbour);
					traverse(neighbour, goal, path);
					path.pop_back();
					visit[neighbour.r][neighbour.c] *= -1;

				}

			}
		}
	};
}
#endif