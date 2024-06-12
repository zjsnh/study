#pragma once
#include"bitset.h"

struct BKDRHash
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& e : str)
		{
			hash *= 31;
			hash += e;
		}
		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			char ch = str[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 5381;
		for (auto ch : key)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};



template<size_t N,class V = string,
	class HashFunc1 = BKDRHash,
	class HashFunc2 = APHash,
	class HashFunc3 = DJBHash>
class BloomFilter
{
public:
	void set(const V& key)
	{
		size_t hashi1 = HashFunc1()(key) % N;
		size_t hashi2 = HashFunc2()(key) % N;
		size_t hashi3 = HashFunc3()(key) % N;

		Bloom.set(hashi1);
		Bloom.set(hashi2);
		Bloom.set(hashi3);
	}

	bool which(const V& key)
	{

		size_t hashi1 = HashFunc1()(key) % N;
		if (Bloom.which(hashi1))
			return false;
		size_t hashi2 = HashFunc2()(key) % N;
		if (Bloom.which(hashi2))
			return false;
		size_t hashi3 = HashFunc3()(key) % N;
		if (Bloom.which(hashi3))
			return false;


		return true;
	}
private:
	bitset<N> Bloom;
};
