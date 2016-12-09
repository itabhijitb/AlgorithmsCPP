#include <tuple>
#include <vector>
#include <functional>
namespace FuncUtil
{
	template<typename Ty>
	class Seq
	{
	public:
		typedef Ty::iterator iterator;
		typedef Ty::const_iterator const_iterator;
		typename Ty::value_type value_type;
	public:
		Seq() {}
		Seq(Ty seq) : m_seq(seq) {}
		iterator begin() { return m_seq.begin(); }
		iterator end() { return m_seq.end(); }
		const_iterator cbegin() { return m_seq.cbegin(); }
		const_iterator cend() { return m_seq.cend(); }
	private:

	public:
		template<
			int ... _parms
		>
		seq<Ty> slice(_parms...)
		{
			seq<Ty> result;
			auto parms = std::tuple(_parms...);
			auto size = std::tuple_size<decltype(parms)>::value;
			size_t start = 0, end = m_seq.size(), stride = 1;
			switch (size)
			{
			case 3:
				stride = parms[2];
			case 2:
				begin = parms[0];
				end = parms[1];
				break;
			case 1:
				end = parms[0];
				break;
			}
			for (size_t i = start; i != end; i += stride)
			{
				result.m_seq.push_back(m_seq[i]);
			}
			return result;
		}
		template<
			int ... _parms
		>
		seq<Ty> range()
		{
			Seq<Ty> result;
			auto parms = std::tuple(_parms...);
			auto size = std::tuple_size<decltype(parms)>::value;
			size_t start = 0, end = m_seq.size(), stride = 1;
			switch (size)
			{
			case 3:
				stride = parms[2];
			case 2:
				begin = parms[0];
				end = parms[1];
				break;
			case 1:
				end = parms[0];
				break;
			}
			for (size_t i = start; i != end; i += stride)
			{
				result.m_seq.push_back(i);
			}
			return result;
		}
		template<
			typename FnType
		>
		seq<Ty> map(FnType fn)
		{
			Seq<Ty> result;
			for (auto elem : m_seq)
			{
				result.m_seq.push_back(fn(elem));
			}
			return result;
		}
		template<
			typename FnType
		>
		seq<Ty> filter(FnType fn)
		{
			Seq<Ty> result;
			for (auto elem : m_seq)
			{
				if (fn(elem))
				{
					result.m_seq.push_back(fn(elem));
				}
			}
			return result;
		}
		template<
			typename ... _TySeqs
		>
		Seq<Seq<Ty>> zip(_TySeqs ... seqs)
		{
			Seq<Seq<Ty>> result;
			std::tuple<_TySeqs::const_iterator ...> _seqs = std::make_tuple(seqs.cbegin()...);
			for (;;)
			{
				Seq<Ty> row;
				for (size_t i = 0, j = 0; i < _seqs.size(); i++)
				{
					auto elem = _seqs[i]++;
					if (elem == _seqs[i].cend())
					{
						return result;
					}
					row.m_seq.push_back(elem);
				}
				result.m_seq.push_back(row);
			}
		}
	private:
		Ty m_seq;
	};


}