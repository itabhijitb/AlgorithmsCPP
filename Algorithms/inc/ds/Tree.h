#include <vector>
#include <array>
#include <algorithm>
#include <memory>
namespace Tree
{
	namespace BST
	{
		template<typename Ty>
		struct Node {
			std::shared_ptr<Node> m_left = nullptr, m_right = nullptr;
			Ty m_val;
			Node(Ty val) : m_val(val) {}
		};
		template<typename Ty>
		class BST {
		public:
			BST& operator+=(Ty val) {
				recursiveadd(m_root, val);
				return *this;
			}
			auto LCS() {
				Ty res;
				recurseLCS(m_root, 0, m_root->m_val, res);
				return res;
			}
			void Flip() {
				recurseFlip(m_root);
			}
		private:
			std::shared_ptr<Node<Ty>> recurseFlip(const std::shared_ptr<Node<Ty>>& root) {
				if (!root || !root->m_left)
					return root;
				auto parent = recurseFlip(root->m_left);
				auto right = root;
				auto left = root->m_right;
				parent->m_left = left;
				parent->m_right = right;
				return parent;

			}
			void recurseLCS(const std::shared_ptr<Node<Ty>>& root,Ty currLen, Ty  expected, Ty&  res) {
				if (!root) {
					return;
				}
				if (root->m_val == expected)
					currLen++;
				else
					currLen = 1;
				res = std::max(res, currLen);
				recurseLCS(root->m_left, currLen, root->m_val + 1, res);
				recurseLCS(root->m_right, currLen, root->m_val + 1, res);
			}
			void recursiveadd(std::shared_ptr<Node<Ty>>& root, Ty val) {
				if (!root) {
					root = std::make_shared<Node<Ty>>(val);
					return;
				}
				if (root->m_val > val) {
					recursiveadd(root->m_left, val);
				}
				else {
					recursiveadd(root->m_right, val);
				}
			}
			std::shared_ptr<Node<Ty>> m_root = nullptr;
		};
	}
}