#include <memory>
#include <iterator>
namespace Itertools
{
	template<typename TyElem> class Product;
	template<typename TyElem>
	class Iter :public std::iterator<std::input_iterator_tag, Product<TyElem>>
	{
	public:
		Iter() : end_of_iteration(true), _pProduct(nullptr) {};
		Iter(const Product<TyElem>* pProduct) : _pProduct(pProduct), end_of_iteration(false)
		{
			odometer.resize(_pProduct->m_arr.size());
		}
		Iter& operator++()
		{
			if (end_of_iteration) return *this;
			size_t carry = 1;
			for (size_t i = 0; carry; i++)
			{
				if (i >= odometer.size())
				{
					// Back to Square One
					odometer.clear();
					odometer.resize(_pProduct->m_arr.size());
					end_of_iteration = true;
					return *this;
				}
				carry = (++odometer[i]) / _pProduct->m_arr[i].size();
				odometer[i] %= _pProduct->m_arr[i].size();
			}
			return *this;
		}

		std::vector<TyElem> operator*()
		{
			std::vector<TyElem> instance;
			for (size_t i = 0; i < odometer.size(); i++)
			{
				instance.push_back(_pProduct->m_arr[i][odometer[i]]);
			}
			return instance;
		}
		bool operator!=(const Iter<TyElem>& rhs)
		{
			return end_of_iteration != rhs.end_of_iteration;
		}
	private:
		const Product<TyElem>* _pProduct;
		std::vector<size_t> odometer;
		bool end_of_iteration;
	};
	template<typename TyElem>
	class Product
	{
		friend Iter<TyElem>;
	public:
		
		Iter<TyElem> begin()
		{
			return Iter<TyElem>(this);
		}
		Iter<TyElem> end()
		{
			return Iter<TyElem>();
		}
		template<typename Ty0>
		Product& operator()(Ty0 arg0)
		{
			m_arr.push_back(arg0);
			return *this;
		}
		template<typename Ty0, typename ... TyRest>
		Product& operator()(Ty0 arg0, TyRest ... args)
		{
			m_arr.push_back(arg0);
			this->operator()(args...);
			return *this;
		}
	private:
		

		std::vector<std::vector<TyElem>> m_arr;
	};

}