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
		// ����ģ��ȡ��Ƕ���ͣ���typename���߱���������������
		typedef typename RBTree<K, K, SetKetOfT>::iterator iterator;//������

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