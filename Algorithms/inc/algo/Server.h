#include <vector>
namespace BackTracking
{
	class TaskScheduling
	{
	public:
		template<typename Iter>
		TaskScheduling(
			Iter beginServer, Iter endServer,
			Iter beginTasks, Iter endTasks) : m_servers(beginServer, endServer), m_tasks(beginTasks, endTasks) {}
		bool operator()()
		{
			return recurse(0);

		}

	private:
		bool recurse(size_t j)
		{
			if (j >= m_tasks.size()) return true;
			for (auto server: m_servers)
			{
				if (server >= m_tasks[j])
				{
					server -= m_tasks[j];
					return recurse(j + 1);
					server += m_tasks[j];
				}
			}
			return false;
		}
		std::vector<size_t> m_servers;
		std::vector<size_t> m_tasks;
	};
}