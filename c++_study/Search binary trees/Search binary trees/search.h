#pragma once

#include<cstdbool>
#include<initializer_list>

namespace search
{
	template<class K>
	struct BStreeNode
	{
		BStreeNode<K>* _left;
		BStreeNode<K>* _right;

		K _val;

		BStreeNode(const K& val)
			:_val(val)
			,_left(nullptr)
			,_right(nullptr)
		{}

	};

	template<class K>
	class BStree
	{

		typedef BStreeNode<K> Node;
	public:
		BStree()
			:_root(nullptr)
		{}

		BStree(std::initializer_list<K> _list)
		{
			typename std::initializer_list<K>::iterator it = _list.begin();
			while (it != _list.end())
			{
				Insert(*it);
				++it;
			}
		}


		~BStree()
		{
			Destroy(_root);
		}

		bool Insert(const K& val)
		{
			if (_root == nullptr)
			{
				_root = new Node(val);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;


			while (cur)
			{
				parent = cur;
				if (cur->_val > val)
				{
					cur = cur->_left;
				}
				else if (cur->_val < val)
				{
					cur = cur->_right;
				}
				else
					return false;
			}

			if (val > parent->_val)
				parent->_right = new Node(val);
			else
				parent->_left = new Node(val);

			
			return true;

		}

		bool Earse(const K& del)
		{
			if (_root == nullptr)
				return false;

			Node* cur = _root;


			while (cur)
			{
				if (cur->_val > val)
				{
					cur = cur->_left;
				}
				else if (cur->_val < val)
				{
					cur = cur->_right;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
					}
					else if(cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;

					}
					else
					{
						//交换值，不改变连接

						Node* parent = cur;
						Node* subLeft = cur->_right;

						while (subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}

						swap(cur->_key, subLeft->_key);

						//善后 删除最左节点，他可能还有右树，（节点）
						if (subLeft == parent->_left)
						{
							parent->_left = subLeft->_right;
						}
						else
						{
							parent->_right = subLeft->_right;
						}

						delete subLeft;
					}
				}
			}

			return false;
		}

	protected:
		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);

			delete root;

			root = nullptr;
		}
	private:
		Node* _root = nullptr;
	};
}