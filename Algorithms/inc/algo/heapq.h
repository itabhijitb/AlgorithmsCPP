#include <vector>
#include <array>
#include <algorithm>
namespace Tree
{
	namespace HeapQ
	{
		template<typename Ty>
		class HeapQ
		{
		public:
			template<typename Iter>
			HeapQ(Iter begin, Iter end)
			{
				for (Iter it = begin; it != end; it++)
				{
					m_arr.push_back(*it);
					for (size_t pos = m_arr.size(), parent = pos / 2;
						pos != 1;
						pos = parent, parent = pos / 2)
					{
						if (m_arr[pos - 1] > m_arr[parent - 1])
						{
							std::swap(m_arr[pos - 1], m_arr[parent - 1]);
						}
					}
				}
			}
			std::vector<Ty> operator()()
			{
				
				for (size_t last = m_arr.size();
					last > 1;
					last--)
				{
					auto ifExist = [&](size_t pos, size_t size) { return pos >= size ? 0 : pos; };
					std::swap(m_arr[0], m_arr[last - 1]);
					
					for (size_t pos = 1, lchild = ifExist(2 * pos, last), rchild = ifExist(2 * pos + 1, last);
						lchild;
						lchild = ifExist(2 * pos, last), rchild = ifExist(2 * pos + 1, last))
					{
						size_t next = (!rchild || m_arr[lchild - 1] >= m_arr[rchild - 1]) ? lchild : rchild;
						if (m_arr[pos - 1] < m_arr[next - 1])
							std::swap(m_arr[pos - 1], m_arr[next - 1]);
						else
							break;
						pos = next;
					}
					
				}
				return m_arr;
			}
		private:
			std::vector<Ty> m_arr;
		};
	}
}