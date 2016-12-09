#include <vector>
#include <algorithm>
#undef max
#include <functional>
#include "util/Memorize.h"
namespace DP
{
	namespace MVCS
	{
		template<typename Ty>
		class MVCS : public Memorization::Memorize
		{
		public:
			template<size_t size>
			MVCS(Ty(&arr)[size]) :m_arr(std::begin(arr), std::end(arr)) {}
			MVCS(std::vector<Ty> arr) : m_arr(arr){}
			Ty operator()()
			{
				return Memoize(&MVCS::recurse, this)( m_arr.size() - 1);
			}
		private:
			Ty recurse(int j)
			{
				if (j < 0) return 0;
				return std::max(Memoize(&MVCS::recurse, this)(j - 1) + m_arr[j], m_arr[j]);
			}
			std::vector<Ty> m_arr;
		};
	}
}