#ifndef __LLIST_H__
#define __LLIST_H__
#include <forward_list>
#include <memory>
#include <initializer_list>
#include <iostream>
namespace LLIST {
	template<typename Ty>
	struct Node {
		typedef typename Ty value_type;
		Node() : _next(nullptr), val(Ty()) {}
		Node(Ty val) : _next(nullptr), val(val) {}
		std::shared_ptr<Node> _next;
		Ty val;
		bool operator<(const Node& rhs) { return val < rhs.val; }
		bool operator<=(const Node& rhs) { return val <= rhs.val; }
		bool operator==(const Node& rhs) const { return val == rhs.val; }
	};
	template<typename Ty>
	struct LList {
		struct Iterator: public std::iterator<std::forward_iterator_tag, Node<Ty>> {
			Iterator(std::shared_ptr<Node<Ty>> ptr) : _ptr(ptr) {}
			Iterator(const Iterator& rhs) {
				_ptr = rhs._ptr;
			}
			operator bool() {
				return _ptr != nullptr;
			}
			bool operator!=(const Iterator& rhs) const {
				return _ptr != rhs._ptr;
			}
			bool operator==(const Iterator& rhs) const {
				return _ptr == rhs._ptr;
			}
			Iterator& operator++() {
				_ptr = _ptr->_next;
				return *this;
			}
			Iterator operator++(int) {
				auto temp = *this;
				_ptr = _ptr->_next;
				return temp;
			}
			std::shared_ptr<Node<Ty>> operator->() {
				return _ptr;
			}
			Node<Ty> operator*() {
				return *_ptr;
			}
			operator std::shared_ptr<Node<Ty>>() {
				return _ptr;
			}
			std::shared_ptr<Node<Ty>> _ptr;
		};
		LList(std::shared_ptr<Node<Ty>> root) : _root(root) {}
		LList() : _root(nullptr) {}
		LList(std::initializer_list<Ty> il) {
			for (const auto& elem : il) {
				*this += elem;
			}
		}
		template<typename Iter>
		LList(const Iter& start, const Iter& end) {
			for (auto& it = start; it != end; it++) {
				*this += *it;
			}
		}
		LList& operator+=(Ty val) {
			if (!_root) {
				_root = std::make_shared<Node<Ty>>(val);
			}
			else {
				auto new_node = std::make_shared<Node<Ty>>(val);
				new_node->_next = _root;
				_root = new_node;
			}
			return *this;
		}
		LList& operator+=(const Node<Ty>& node) {
			*this += node.val;
			return *this;
		}
		LList& operator+=(const LList<Ty>& ll) {
			for (auto& elem : ll) {
				*this += elem;
			}
		}
		Iterator begin() {return Iterator(_root);}
		Iterator end() { return Iterator(nullptr); }
		const Iterator begin() const { return Iterator(_root); }
		const Iterator end() const { return Iterator(nullptr); }
		friend std::ostream& operator<<(std::ostream& os, const LList& ll) {
			for (const auto& elem : ll) {
				os << elem.val << ",";
			}
			return os;
		}
		std::shared_ptr<Node<Ty>> _root;
	};
	template<typename Ty>
	LList<Ty>& reverse(LList<Ty>& ll) {
		auto p = std::begin(ll);
		auto r = p;
		for (auto q = std::next(p);q != std::end(ll);) {
			auto temp = q->_next;
			q->_next = r;
			p->_next = temp;
			r = q;
			q = p->_next;
		}
		ll._root = r;
		return ll;
	}
	template<typename Ty>
	LList<Ty> merge(LList<Ty>& left_ll, LList<Ty>& right_ll) {
		LList<int> new_list;
		auto ll = left_ll.begin(), rl = right_ll.begin();
		for(;ll != left_ll.end(), rl != right_ll.end();) {
			if (*ll <= *rl) {
				new_list += *ll;
				ll++;
			}
			else {
				new_list += *rl;
				rl++;
			}
		}
		for (; ll != left_ll.end(); ll++) {
			new_list += *ll;
		}
		for (; rl != right_ll.end(); rl++) {
			new_list += *rl;
		}
		return reverse(new_list);
	}
	template<typename Iter>
	auto middle(Iter start, Iter end) {
		for (auto it1 = start, it2 = start; ; it1++, std::advance(it2, 2)) {
			if (it2 == end) {
				return it1;
			}
		}
	}
	template<typename Iter>
	auto mergeSort(Iter start, Iter end) {
		if (start == end) {
			return std::iterator_traits<Iter>::value_type();
		}
		if (std::next(start) == end) {
			//return std::iterator_traits<Iter>::value_type(start, end);
		}
		auto mid = middle(start, end);
		auto left = mergeSort(start, mid);
		auto right = mergeSort(mid, end);
		return merge(left, right)
	}
	template<typename Ty>
	auto insertInSorted(std::forward_list<Ty>& ll, Ty val) {
		for (auto it1 = ll.begin(), it2 = std::next(ll.begin());
		it2 != ll.end();
			it1++, it2++) {
			if (val >= *it1 && val <= *it2) {
				ll.emplace_after(it1, val);
				break;
			}
		}
	}

	auto fullAdder(std::forward_list<int>& llA, std::forward_list<int>& llB) {
		typedef typename int  value_type;
		std::forward_list<int> llC;
		auto itA = llA.begin(), itB = llB.begin(), itC = llC.begin();
		value_type carry{};
		auto halfadder = [&llC,&itC](
			const value_type& a,
			const value_type& b,
			value_type& carry) {
			auto sum = carry + a + b;
			carry = sum / 10;
			sum = sum % 10;
			if (itC == llC.end()) {
				llC.push_front(sum);
				itC = llC.begin();
			}
			else {
				llC.emplace_after(itC, sum);
				itC++;
			}
			return carry;
		};
		
		for (;itA != llA.end() && itB != llB.end();itA++, itB++) {
			carry = halfadder(*itA, *itB, carry);
		}
		for (; itA != llA.end() ; itA++) {
			carry = halfadder(*itA, 0, carry);
		}
		for (; itB != llB.end(); itB++) {
			carry = halfadder(0, *itB, carry);
		}
		return llC;

	}
}

#endif
