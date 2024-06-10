#pragma once
#include"hash.h"



template<class K,class HashFun = hashFuns<K>>
class unordered_set
{
	//¼ÆËãkeyÖµ
	struct setKeyofT
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};


public:

	typedef typename Hash<K, K, setKeyofT, HashFun>::const_iterator iterator;
	typedef typename Hash<K, K, setKeyofT, HashFun>::const_iterator const_iterator;


	iterator begin() const
	{
		return _ht.begin();
	}

	iterator end() const
	{
		return _ht.end();
	}

	pair<iterator,bool> insert(const K& key)
	{
		return _ht.Insert(key);
	}


private:
	Hash<K, K , setKeyofT , HashFun> _ht;
};
