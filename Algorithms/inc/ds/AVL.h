#include <array>
#include <vector>
#include <tuple>
namespace Tree
{
	namespace HeapSort
	{
		template<typename Ty> class HeapQ;
		template<typename Ty>
		class iterator
		{
		public:
			iterator(const HeapQ& heapq, size_t pos)
				: pos(pos)
				, heapq(heapq)
			{ }

			// these three methods form the basis of an iterator for use with
			// a range-based for loop
			bool
				operator!= (const Iter& other) const
			{
				return pos != other.pos;
			}

			// this method must be defined after the definition of IntVector
			// since it needs to use it
			std::tuple<std::tuple<size_t, Ty>, std::tuple<size_t, Ty>>  operator* () const
			{
				if (pos == 0)
				{
					return std::make_tuple(std::make_tuple(-1, 0), std::make_tuple(-1, 0));
				}
				if (pos % 2)
				{
					return std::make_tuple(
						std::make_tuple(pos - 3, heapq.m_arr[pos - 3]),
						std::make_tuple(pos - 2, heapq.m_arr[pos - 2]));
				}
				else
				{
					return std::make_tuple(
						std::make_tuple(pos - 2, heapq.m_arr[pos - 3]),
						std::make_tuple(-1, 0));
				}
			}

			const Iter& operator++ ()
			{
				pos-=(3 - pos % 2);
				// although not strictly necessary for a range-based for loop
				// following the normal convention of returning a value from
				// operator++ is a good idea.
				return *this;
			}

		private:
			size_t pos;
			const HeapQ& heapq;
		};
		template<typename Ty>
		class HeapQ
		{
		public:
			friend iterator < Ty >;
			template<size_t SIZE>
			Heap(Ty[&arr)[SIZE] ):m_arr(std::begin(arr), std::end(arr)) {}
			template<size_t SIZE>
			Heap(std::array<Ty, SIZE> arr) : m_arr(std::begin(arr), std::end(arr)) {}
			Heap(std::vector<Ty> arr) : m_arr(arr0));
			std::tuple<size_t, Ty> Root() const { return std::make_tuple(0, arr[0]); }
			std::tuple<size_t, Ty> LastChild() const { return std::make_tuple(arr.size() - 1, arr.last()); }
			std::tuple<size_t, Ty> LeftChild(Ty parent) const
			{ 
				size_t pos = 2 * parent + 1;
				if (pos >= m_arr.size())
				{
					return std::make_tuple(-1, 0);
				}
				else
				{
					return std::make_tuple(pos, arr[pos]);
				}

			}
			std::tuple<size_t, Ty> RightChild(Ty parent) const
			{
				size_t pos = 2 * parent + 2;
				if (pos >= m_arr.size())
				{
					return std::make_tuple(-1, 0);
				}
				else
				{
					return std::make_tuple(pos, arr[pos]);
				}

			}
			std::tuple<size_t, Ty> Parent(Ty child) const
			{
				if (child == 0)
				{
					return std::make_tuple(-1, 0);
				}
				size_t pos = (child + 1) / 2;
				return std::make_tuple(pos, arr[pos]);
			}
			iterator<Ty> begin()
			{
				return Iter(*this, pos);
			}
			iterator<Ty> end()
			{
				return Iter(*this, -1);
			}
		private:
			void Heapify()
			{
				for (auto elem : *this)
				{

				}
			}
			std::array<Ty> m_arr;
		};
		class HeapSort
		{

		};
	}
}