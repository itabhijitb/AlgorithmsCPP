#include <iostream>
namespace Loop
{
	template<size_t N>
	struct Print
	{
		void operator()()
		{
			Print<N - 1>()();
			std::cout << N << std::endl;

		}
	};
	template<>
	struct Print < 1 >
	{
		void operator()()
		{
			std::cout << 1 << std::endl;

		}
	};
}