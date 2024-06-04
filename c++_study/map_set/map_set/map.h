#pragma once
#include"RBtree.h"

namespace mp
{
	template<class K,class V>
	class map
	{
	public:
		struct MapKetOfT
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
		// ����ģ��ȡ��Ƕ���ͣ���typename���߱���������������
		typedef typename RBTree<K, pair<K, V>, MapKetOfT>::iterator iterator;//������

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return (ret.first)->second;
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.insert(kv);
		}


	private:

		RBTree<K, pair<K, V>, MapKetOfT> _t;
	};


}