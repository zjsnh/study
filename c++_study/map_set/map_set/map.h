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
		// 对类模板取内嵌类型，加typename告诉编译器这里是类型
		typedef typename RBTree<K, pair<K, V>, MapKetOfT>::iterator iterator;//迭代器
		/*typedef typename RBTree<const K, pair<const K, V>, MapKetOfT>::iterator iterator;
		typedef typename RBTree<const K, const pair<K, V>, MapKetOfT>::iterator const_iterator;*/

		iterator begin()
		{
			return _t.begin();
		}  

		iterator end()
		{
			return _t.end();
		}

		/*const_iterator begin() const
		{
			return _t.begin();
		}

		const_iterator end() const
		{
			return _t.end();
		}*/

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