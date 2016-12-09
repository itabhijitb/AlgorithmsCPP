#include <string>
#include <tuple>
namespace RLD
{
	class RLD
	{
	public:
		RLD(std::string buf) :m_buf(buf) {}
		size_t operator()(size_t k)
		{

		}
	private:
		std::tuple<std::string, size_t>
			split(std::string st)
		{
			auto index = st.find_last_not_of("0123456789");
			return std::make_tuple(st.substr(0, index), atoi(st.substr(index, st.size()).c_str()));
		}
	private:
		std::string m_buf;

	};
};