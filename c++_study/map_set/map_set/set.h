#pragma once
#include"RBtree.h"

namespace st
{
	template<class K>
	class set
	{
		struct SetKetOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		// 对类模板取内嵌类型，加typename告诉编译器这里是类型
		typedef typename RBTree<K, K, SetKetOfT>::iterator iterator;//迭代器

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _t.insert(key);
		}


	private:

		RBTree<K, K, SetKetOfT> _t;
	};


}