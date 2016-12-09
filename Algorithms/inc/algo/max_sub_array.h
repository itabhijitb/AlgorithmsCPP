//#include <algorithm>
//#include <vector>
//#include <iterator>
//#include <tuple>
//namespace Others
//{
//	namespace max_sub_array
//	{
//		template<typename Ty, size_t PD> class ndarray;
//		template<typename Ty, size_t PD>
//		class Iterndarray : public virtual std::iterator<std::bidirectional_iterator_tag, ndarray>
//		{
//
//		};
//		template<typename Ty, size_t PD>
//		struct ndarray
//		{
//			typedef Ty type[PD];
//			
//			type data;
//			Ty& operator[](size_t index) {	return data[index];	}
//			const Ty& operator[](size_t index) const { return data[index]; }
//		};
//		template<typename Ty, size_t PD, size_t ... Dimensions>
//		struct ndarray
//		{
//			typedef typename ndarray<Ty, Dimensions>::type  N_minus1_Dim;
//			typedef N_minus1_Dim type[PD];
//			std::tuple<PD, Dimensions...> dimensions;
//			type data;
//			Ty& operator[](size_t index) { return data[index]; }
//			const Ty& operator[](size_t index) const { return data[index]; }
//		};
//		template<typename Ty, size_t ... Dimensions>
//		class max_sub_array
//		{
//		public:
//			
//			max_sub_array(ndarray<Ty, Dimensions...)::type arr) : m_arr(begin, end) {}
//			int operator()()
//			{
//				int relative_max_sum, absolute_max_sum;
//				for (auto elem : m_arr)
//				{
//					relative_max_sum = std::max(0, relative_max_sum + elem);
//					absolute_max_sum = std::max(relative_max_sum, absolute_max_sum);
//				}
//				return absolute_max_sum;
//			}
//		private:
//			ndarray<Ty, Dimensions...)::type m_arr;
//		};
//	}
//}