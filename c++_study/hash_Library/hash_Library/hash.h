#pragma once

#include<vector>
#include<list>
#include<set>


namespace hash_bucket
{
	template<class K,class V>
	class Hash
	{
	public:
		Hash()
	    {	
			_kv.resize(10);
		}
		Hash(const pair<K,V>& kv )
			:_kv(kv)
			,_n(0)
		{	
		}

		bool Insert(const pair<K, V>& kv)
		{
			if ((_n *10)/ _kv.size()==7)
			{
				Rehash();
			}


			size_t h = kv.first % _kv.size();

			if (_kv[h]._len==0)
			{
				++_n;
				_kv[h]._list.push_front(kv);
				++(_kv[h]._len);

				return true;
			}
			

			if (_kv[h]._len > 8)
			{
				pair<typename set<pair<K, V>>::iterator, bool> result = _kv[h]._rbtree.insert(kv);
				//auto
				if (result.second == false)
				{
					return false;
				}
			}
			else
			{
				typename list <pair<K, V>>::iterator it = _kv[h]._list.begin();
				while (it != _kv[h]._list.end())
				{
					if (kv.second == it->second)
					{
						return false;
					}
					++it;
				}

				_kv[h]._list.push_front(kv);
			}

			++(_kv[h]._len);
			return true;
		}

	private:

		void Rehash()
		{
			vector<bucket> old_kv = std::move(_kv);
			_kv.resize(old_kv.size() * 2);
			for (auto& e : _kv)
			{
				e._list.clear();		
				e._rbtree.clear();	
				e._len = 0;
			}

			_n = 0;

			for (const auto& e : old_kv)
			{
				for (const auto& b : e._list)
				{
					Insert(b);
				}

				for (const auto& b : e._rbtree)
				{
					Insert(b);
				}
			}


		}
		struct bucket
		{
			list<pair<K, V>> _list;
			set<pair<K, V>> _rbtree;

			size_t _len;
		};

		vector<bucket> _kv;
		size_t  _n;
	};
}
