#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
namespace Techgig
{
	namespace Ideas
	{
		namespace PB1
		{
			struct Product
			{
				int index;
				int likeness;
				Product(int index, int  likeness) : index(index), likeness(likeness) {}
			};
			struct Customer
			{
				int index;
				int likeness;
				Customer(int index, int  likeness) : index(index), likeness(likeness) {}
			};
			class Matching
			{
			public:
				Matching(std::string input)
				{
					Parse(input);
					
				}
				int operator()()
				{
					return recurseP(1);;
				}
			private:
				int recurseP(int product)
				{
					int _max = 0;
					for (auto customer : PC[product])
					{
						if (C.)
						_max = std::max(_max, recurseC(customer.index) + customer.likeness);
						
					}
					return _max;
				}
				int recurseC(int customer)
				{
					int _max = 0;
					for (auto product : CP[customer])
					{
						_max = std::max(_max, recurseP(product.index) + product.likeness);
						
						
					}
					return _max;
				}
				void Parse(std::string szInput)
				{
					
					int customer = 0, product = 0, weight = 0;
					for (const char *input = szInput.c_str(); *input;++input)
					{
						switch (*input)
						{
						case 'C':
							customer = strtol(++input,const_cast<char **>(&input),10);
							break;
						case 'P':
							product = strtol(++input, const_cast<char **>(&input), 10);
							break;
						case ' ':case '\0':
							break;
						default:
							weight = strtol(input, const_cast<char **>(&input), 10);
							//P[product] = true;
							//C[customer] = true;
							CP[customer].push_back(Product(product, weight));
							PC[customer].push_back(Customer(customer, weight));
							break;
						}
						if (!input) break;
					}
				}
				std::map<int, std::vector<Product> > CP;
				std::map<int, std::vector<Customer> > PC;
				std::set<int> P;
				std::set<int> C;
			};
		}
	}
}