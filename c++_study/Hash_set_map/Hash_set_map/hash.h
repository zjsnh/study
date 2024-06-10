#pragma once
#include<string>
#include<stdbool.h>
#include<vector>


//https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html


template<class K>
struct hashFuns
{
	size_t operator()(const K& key)
	{
		return size_t(key);
	}
};

template<>
struct hashFuns<string>
{
	
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};


//Map

template<class T>
struct HashNode
{
	HashNode* _next;
	T _data;


	HashNode(const T& data)
		:_data(data)
		, _next(nullptr)
	{	}
};

//哈希表需要迭代器，迭代器需要哈希表，相互依赖，提前声明

template<class K, class T, class KeyOfT, class HashFun>
class Hash;

template<class K, class T, class Ref, class Ptr, class KeyOfT, class HashFun>
struct __hashIterator
{
	typedef HashNode<T> Node;
	typedef __hashIterator<K, T, Ref, Ptr, KeyOfT, HashFun> Self;
	typedef __hashIterator<K, T, T&, T*, KeyOfT, HashFun> iterator;
	typedef __hashIterator<K, T, const T&, const T*, KeyOfT, HashFun> const_iterator;
	Node* _node;
	typename const Hash<K, T, KeyOfT, HashFun>* _pht;//传入指向表的指针用于找数据
	size_t _hashi;

	__hashIterator(const iterator& it)
		:_node(it._node)
		,_hashi(it._hashi)
		,_pht(it._pht)
	{

	}

	__hashIterator(Node* node, Hash<K, T, KeyOfT, HashFun>* pht, size_t hashi)
		:_node(node)
		,_pht(pht)
		,_hashi(hashi)
	{

	}

	__hashIterator(Node* node,const Hash<K, T, KeyOfT, HashFun>* pht, size_t hashi)
		:_node(node)
		, _pht(pht)
		, _hashi(hashi)
	{

	}
	

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	Self& operator++()//单向迭代器
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			_hashi++;
			while (_hashi < _pht->_tables.size())
			{
				if (_pht->_tables[_hashi])
				{
					_node = _pht->_tables[_hashi];
					break;
				}

				++_hashi;
			}


			if (_hashi == _pht->_tables.size())
			{
				_node = nullptr;
			}
		}

		return *this;
	}


	bool operator==(const Self& s)
	{
		return _node == s._node;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

};

template<class K, class T,class KeyOfT, class HashFun>
class Hash
{
	typedef HashNode<T> Node;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	friend struct __hashIterator;


public:

	typedef __hashIterator<K, T, T&, T*, KeyOfT, HashFun> iterator;
	typedef __hashIterator<K, T,const T&,const T*, KeyOfT, HashFun> const_iterator;

	iterator begin()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			if (_tables[i])
			{
				return iterator(_tables[i], this, i);
			}
		}

		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this, -1);
	}

	const_iterator begin() const
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			if (_tables[i])
			{
				return const_iterator(_tables[i], this, i);
			}
		}

		return end();
	}

	const_iterator end() const
	{
		return const_iterator(nullptr, this, -1);
	}

	Hash()
	{
		_tables.resize(10);
	}

	~Hash()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* prev = cur->_next;
				delete cur;
				cur = prev;
			}

			_tables[i] = nullptr;
		}
	}

	pair<iterator,bool> Insert(const T& data)
	{
		HashFun hf;
		KeyOfT key;

		iterator it = Find(key(data));

		if(it._node)
		{
			return make_pair(it,false);
		}

		

		if (_n *10 / _tables.size()==7)
		{
			size_t newsize = _tables.size() * 2;
			Hash<K, T, KeyOfT,HashFun> newHash;
			newHash._tables.resize(newsize);
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				_tables[i] = nullptr;
				while (cur)
				{
					Node* prev = cur->_next;
					//size_t hashi = hf(cur->_data.first) % newHash._tables.size();
					size_t hashi = hf(key(cur->_data)) % newHash._tables.size();
					cur->_next = newHash._tables[hashi];
					newHash._tables[hashi] = cur;

					/*newHash.Insert(cur->_data);
					cur = cur->next;*/
					//浪费

					cur = prev;
				}
			}

			_tables.swap(newHash._tables);

		}

		size_t hashi = hf(key(data)) % _tables.size();

		Node* newNode = new Node(data);
		newNode->_next = _tables[hashi];
		_tables[hashi] = newNode;

		_n++;

		return make_pair(iterator(newNode, this, hashi), true);
	}


	iterator Find(const K& key)
	{
		HashFun hf;
		KeyOfT kot;
		size_t hashi = hf(key) % _tables.size();
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (kot(cur->_data) == key)
			{
				return iterator(cur, this, hashi);
			}

			cur = cur->_next;
		}

		return end();
	}


	bool Earse(const K& key)
	{
		HashFun hf;
		size_t hashi = hf(key) % _tables.size();
		Node* cur = _tables[hashi];
		Node* prev = nullptr;
		while (cur)
		{
			if (kot(cur->_data) == key)
			{
				if (prev == nullptr)
				{
					_tables[hashi] = cur->_next;
				}
				else
				{
					prev = cur->_next;
				}
				delete cur;

				return true;
			}

			prev = cur;
			cur = cur->_next;
		}

		return false;
	}

private:
	vector<Node* > _tables;

	//哈希桶
	size_t _n = 0;//记录值
};
