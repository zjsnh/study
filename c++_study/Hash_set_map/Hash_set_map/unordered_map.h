#pragma once
#include"hash.h"

template<class K,class V, class HashFun = hashFuns<K>>
class unordered_map
{

	//¼ÆËãkeyÖµ
	struct mapKeyofT
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};

public:
	typedef typename Hash<K, pair<const K, V>, mapKeyofT, HashFun>::iterator iterator;
	typedef typename Hash<K, pair<K, V>, mapKeyofT, HashFun>::const_iterator const_iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	iterator begin() const
	{
		return _ht.begin();
	}

	iterator end() const
	{
		return _ht.end();
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
		return ret.first->second;
	}

	const V& operator[](const K& key) const
	{
		pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
		return ret.first->second;  //  pair  _data
	    /*Ptr operator->()
		{
			return &(_node->_data);
		}*/
	}

	pair<iterator,bool> insert(const pair<K,V>& key)
	{
		return _ht.Insert(key);
	}

private:
	Hash<K, pair<const K, V>, mapKeyofT, HashFun> _ht;
};

