#include <vector>
#include <map>
#include <ctime>
#include <chrono>
#include <string>
#include <algorithm>
#include <random>
#include <sstream>
#include <iomanip>
struct slot {
	typedef std::chrono::system_clock::time_point TIME_POINT;
	inline std::time_t FUTURE() const {
		return std::chrono::system_clock::to_time_t(std::chrono::time_point<std::chrono::system_clock>::max());
	}
	std::time_t start, end;
	size_t mid;
	slot() : start(FUTURE()), end(FUTURE()), mid(0) {}
	slot(std::time_t start, std::time_t end, size_t mid) : start(start), end(end), mid(mid) {}
	bool operator<(const std::time_t& right) const {
		return start < right;
	}
};

class Meeting {
	std::map<std::string, std::vector<slot>> rooms;
	size_t last_mid;
public:
	Meeting() : last_mid(0) {}
	void addRooms(std::string rid) {
		rooms[rid] = std::vector<slot>();
		rooms[rid].push_back(slot());
	}
	bool isavailable(std::string rid, std::time_t start, std::time_t end) {
		auto pNext = std::lower_bound(cbegin(rooms[rid]), cend(rooms[rid]), start);
		if (pNext == rooms[rid].end()) return true;
		auto reqSlot = end - start;
		auto availSlot = pNext->start - start;
		return (availSlot >= reqSlot);

	}
	bool book(std::string rid, std::time_t start, std::time_t end) {
		if (start > end) std::swap(start, end);
		if (!isavailable(rid, start, end)) return false;
		auto pos = std::lower_bound(rooms[rid].begin(), rooms[rid].end(), start);
		rooms[rid].insert(pos, slot(start, end, ++last_mid));
		return true;
	}
	std::map<std::string, std::vector<slot>> getAvailable(std::string rid, std::time_t start, std::time_t end) {
		std::map<std::string, std::vector<slot>> availibility;
		for (auto& rid : rooms) {
			availibility[rid.first] = std::vector<slot>();
			for (auto slot_it = rid.second.begin(); slot_it != std::prev(rid.second.end()); slot_it++) {
				auto curr = slot_it;
				auto next = std::next(slot_it);
				availibility[rid.first].push_back(slot(curr->end, next->start, 0));

			}
		}
		return availibility;
	}
};
class RandTime {
public:
	RandTime(std::time_t start, std::time_t end) : m_start(start), m_end(end), dist(start, end) {
		rng.seed(std::random_device()());
	}
	std::time_t operator()() {
		return dist(rng);
	}
private:
	std::time_t m_start;
	std::time_t m_end;
	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type> dist;
};
std::time_t to_time_t(std::string time) {
	std::tm tm = {};
	std::stringstream ss(time);
	ss >> std::get_time(&tm, "%Y/%m/%d %H:%M:%S");
	return mktime(&tm);
}
void meeting_room() {
	Meeting meetings;
	RandTime rt(to_time_t("2016/7/10 00:00:00"), to_time_t("2016/9/10 24:59:59"));
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < int(rand() * 20); j++) {
			meetings.book(std::to_string(i), rt(), rt());
		}
	}
}
