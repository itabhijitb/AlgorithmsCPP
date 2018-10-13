
#include "CppUnitTest.h"
#include "../Algorithms/inc/ds/Queues.h"
#include <thread>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsCPPTest
{
	TEST_CLASS(QueueTest)
	{
	private:
		Queue<int, 5> queue;
	public:
		void consumer() {
			Logger::WriteMessage("Thread 2 Executing\n");
			while( auto item = queue.pop()) {
				std::stringstream ss;
				ss << "Consumed = " << item <<std::endl;
				Logger::WriteMessage(ss.str().c_str());
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
		}
		void producer() {
			std::stringstream ss;;
			Logger::WriteMessage("Producing Some Items");
			for (int i = 1; i < 50; i++) {
				queue.push(i);
				ss << "Produced = " << i << std::endl;
				Logger::WriteMessage(ss.str().c_str());
			}
		}
		TEST_METHOD(HelloWorld)
		{
			std::thread t1([this] {this->consumer(); }), t2([this] {this->producer(); });
			t1.join();
			t2.join();
		}
		

	};
}