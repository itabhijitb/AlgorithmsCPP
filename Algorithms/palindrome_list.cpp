#include <forward_list>
#include <algorithm>
#include <iostream>
std::forward_list<int>::const_iterator middle(const std::forward_list<int>& lst) {
	if (lst.empty()) {
		return lst.end();
	}
	auto root = lst.begin(), it = lst.begin();
	for (; ; it = std::next(it, 2), root++) {
		
		if (it == lst.end()) {
			return root;
		} else if (std::next(it) == lst.end()) {
			return std::next(root);
		}
	}
	return root;
}

bool isPalindrom(const std::forward_list<int>& lst) {
	
	auto m_it = middle(lst);
	std::forward_list<int> second(m_it, lst.end());
	second.reverse();
	auto it2 = second.begin();
	for (auto it1 = lst.begin(); it2 != second.end() && *it1 == *it2; it1++, it2++);
	
	return it2 == second.end();
}
void palindrom_list() {
	{
		std::forward_list<int> lst = {};
		std::cout << (isPalindrom(lst) ? "YES" : "NO") << std::endl;
	}
	{
		std::forward_list<int> lst = {1};
		std::cout << (isPalindrom(lst) ? "YES" : "NO") << std::endl;
	}
	{
		std::forward_list<int> lst = { 1, 2 };
		std::cout << (isPalindrom(lst) ? "YES" : "NO") << std::endl;
	}
	{
		std::forward_list<int> lst = { 1, 2, 1 };
		std::cout << (isPalindrom(lst) ? "YES" : "NO") << std::endl;
	}
	{
		std::forward_list<int> lst = { 1, 2, 2, 1 };
		std::cout << (isPalindrom(lst) ? "YES" : "NO") << std::endl;
	}
	{
		std::forward_list<int> lst = { 1, 2, 3, 2, 1 };
		std::cout << (isPalindrom(lst) ? "YES" : "NO") << std::endl;
	}
	{
		std::forward_list<int> lst = { 1, 2, 3 };
		std::cout << (isPalindrom(lst) ? "YES" : "NO") << std::endl;
	}

}
