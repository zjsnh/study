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
		typedef typename RBTree<K, K, SetKetOfT>::const_iterator iterator;//������
		typedef typename RBTree<K, K, SetKetOfT>::const_iterator const_iterator;//������

		iterator begin() const
		{
			return _t.begin();
		}

		iterator end() const 
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