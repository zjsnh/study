#pragma once


/*
* Search binary trees, 
* do not allow two identical values to be inserted, 
* and the mid-order traversal is ascending
* 
* " ^_^ "
*/



#include<iostream>
#include<cstdbool>
using namespace std;


namespace key
{

	template<class K>
	struct BStreeNode
	{
		BStreeNode<K>* _left;
		BStreeNode<K>* _right;

		K _key;

		BStreeNode(const K& key)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
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

		BStree(const BStree<K>& k)
		{
			_root=copy(k);
		}

		~BStree()
		{
			Destory(_root);
		}

		//k1 = k2;
		BStree<K>& operator=(BStree<K> k)
		{
			swap(_root, k._root);
			return *this;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;

			while (cur)
			{
				parent = cur;
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}

			return false;
		}

		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;

			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					if (cur->_left == nullptr)
					{//左为空
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
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else
					{//找右子树的最小值
						Node* parent = cur;
						Node* subLeft = cur->_right;

						while (subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}

						swap(cur->_key, subLeft->_key);

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
					return true;
				}
			}

			return false;
		}


		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}



	private:

		Node* copy(Node*& root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newNode = new Node(root->_key);
			newNode->_left = copy(root->_left);
			newNode->_right = copy(root->_right);

			return newNode;
		}

		void Destory(Node* root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);

			delete root;
			root = nullptr;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);

		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
				return _FindR(root->_left, key);
			else if (root->_key > key)
				return _FindR(root->_right, key);
			else
				return true;
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
				return _InsertR(root->_left, key);
			else if (root->_key < key)
				return _InsertR(root->_right, key);
			else
				return false;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
				return _EraseR(root->_left, key);
			else if (root->_key < key)
				return _EraseR(root->_right, key);
			else
			{
				if (root->_left == nullptr)
				{//左为空
					Node* cur = root;
					root = root->_right;
					delete cur;

					return true;
				}
				else if (root->_right == nullptr)
				{
					Node* cur = root;
					root = root->_left;
					delete cur;
					return true;
				}
				else
				{
					Node* subLeft = root->_right;

					while (subLeft->_left)
					{
						subLeft = subLeft->_left;
					}

					swap(root->_key, subLeft->_key);
					/*root = subLeft->_right;*/
					_EraseR(root->_right, key);

				}
			}

			return false;

		}


	private:
		Node* _root = nullptr;
	};
}

namespace key_value
{

	template<class K,class V>
	struct BStreeNode
	{
		BStreeNode<K,V>* _left;
		BStreeNode<K,V>* _right;

		K _key;
		V _value;

		BStreeNode(const K& key, const V& value)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}

	};

	template<class K,class V>
	class BStree
	{
		typedef BStreeNode<K,V> Node;

	public:

		BStree()
			:_root(nullptr)
		{}

		~BStree()
		{
			Destory(_root);
		}


		bool Insert(const K& key,const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,value);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;

			while (cur)
			{
				parent = cur;
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key,value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;

			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					if (cur->_left == nullptr)
					{//左为空
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
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else
					{//找右子树的最小值
						Node* parent = cur;
						Node* subLeft = cur->_right;

						while (subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}

						swap(cur->_key, subLeft->_key);

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
					return true;
				}
			}

			return false;
		}


		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		
	private:

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ":"<<root->_value;
			_InOrder(root->_right);

		}

		void Destory(Node* root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);

			delete root;
			root = nullptr;
		}

	private:
		Node* _root = nullptr;
	};
}