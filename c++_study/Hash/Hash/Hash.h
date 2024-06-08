#pragma once


#include<vector>
#include<string>



//https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html

template<class K>
struct hashFuncs
{
	size_t operator()(const K& key)
	{
		return size_t(key);
	}
};

template<>
struct hashFuncs<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto& e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};


namespace hs
{
	//记录存储状态
	enum Status
	{
		EMPTY,
		EXIST,
		DELEYE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _data;
		Status _status;

		/*HashData(const pair<K,V>& data)
			:_data(data)
			,_status(EMPTY)
		{	}*/
	};


	template<class K, class V,class HashFun=hashFuncs<int>>
	class Hash
	{
	public:
		// 默认的析构函数会调用自定义类型的析构函数，自定义类型是vector 
		Hash()
		{
			_tables.resize(10);

		}

		bool Insert(const pair<K, V>& data)
		{
			HashFun hf;

			if (_n * 10 / _tables.size() == 7)
			{
				// 负载因子 < 0.7
				size_t newsize = _tables.size() * 2;
				Hash<K, V> newHash;
				newHash._tables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._status == EXIST)
					{
						newHash.Insert(_tables[i]._data);
					}
				}
				
				_tables.swap(newHash._tables);
			 
			}


			//size_t hashi = data.first % _tables.size();
			size_t hashi = hf(data.first) % _tables.size();
			while(_tables[hashi]._status == EXIST)
			{
				hashi++;

				//若是走到末尾，从头开始找
				hashi %= _tables.size();
			}

			_tables[hashi]._data = data;
			_tables[hashi]._status = EXIST;
			_n++;

			return true;
		}
	private:
		vector<HashData<K,V>> _tables;
		size_t _n = 0;
	};
}


namespace hash_bucket//哈希桶
{

	//Map

	template<class K, class V>
	struct HashNode
	{
		HashNode* _next;
		pair<K, V> _data;
		

		HashNode(const pair<K,V>& data)
			:_data(data)
			,_next(nullptr)
		{	}
	};

	template<class K, class V, class HashFun = hashFuncs<int>>
	class Hash
	{
		typedef HashNode<K, V> Node;
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
					Node* prev = cur->next;
					delete cur;
					cur = prev;
				}

				_tables[i] = nullptr;
			}
		}

	public:
		bool Insert(const pair<K, V>& data)
		{

			if (Find(data.first))
			{
				return false;
			}

			HashFun hf;

			if (_n == _tables.size())
			{
				size_t newsize = _tables.size() * 2;
				Hash<K, V> newHash;
				newHash._tables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						/*newHash._tables[i]->_next = cur;
						cur = cur->_next;*/

						newHash.Insert(cur->_data);
						cur = cur->next;


						//浪费
					}
				}

				_tables.swap(newHash._tables);

			}

			size_t hashi = hf(data.first) % _tables.size();

			Node* newNode =new Node(data);
			newNode->_next = _tables[hashi];
			_tables[hashi] = newNode;

			_n++;

			return true;
		}


		bool Find(const K& key)
		{
			size_t hashi = data.first % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_data.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return false;
		}

	private:
		vector<Node* > _tables;

		//哈希桶
		size_t _n = 0;//记录值
	};
}