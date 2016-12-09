#ifndef __SSTACK_H__
#define __SSTACK_H__
#include<stack>
#include<list>
namespace SSTACK {
	template<typename Ty>
	auto nextGreaterElement(std::initializer_list<Ty> il, Ty defval) {
		std::stack<Ty> stk;
		std::list<Ty> ll;
		for (auto& elem : il) {
			if (stk.empty()) {
				stk.push(elem);
			}
			else if (stk.top() > elem) {
				stk.push(elem);
			}
			else {
				while (!stk.empty() && stk.top() < elem) {
					stk.pop();
					ll.push_back(elem);
				}
				stk.push(elem);
			}
		}
		while (!stk.empty()) {
			ll.push_back(defval);
			stk.pop();
		}
		return ll;
	}
}
#endif
