#pragma once


enum color
{
	RED,
	BACK
};

//�ڵ�ṹ��

template<class K>
struct RBtree_Node
{
	RBtree_Node<K>* _parent;
	RBtree_Node<K>* _right;
	RBtree_Node<K>* _left;

	color _color;
	K _value;

	RBtree_Node(const K& value)
		:_parent(nullptr)
		,_right(nullptr)
		,left(nullptr)
		,_color(RED)
		,_value(value)
	{}

};


template<class K>
class RBtree
{
	typedef RBtree_Node<K> Node;
public:
	bool Insert(const K& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_colour = BLACK;
			return  true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		Node* newNode = cur;


		while (cur)
		{
			if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		cur->_colour = RED;
		if (parent->_data > data)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//��ת + ��ɫ

		while (parent && parent->_color == RED)
		{

			//1 . ��ɫ���
			Node* pparent = parent->_parent;   //������ת�����½ڵ㶪ʧ
			if (parent == pparent->_left)
			{
				//��uncle

				Node* uncle = pparent->_right;

				if (uncle && uncle->_color == RED)
				{
					//��ɫ

					uncle->_color = BACK;
					parent->_color = BACK;
					pparent->_color = RED;

					//���½ڵ�

					cur = pparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur = parent->_left)
					{
						//����

						//�ҵ���
						RotateR(pparent);

						//��ɫ
						pparent->_colour = RED;
						parent->_colour = BLACK;
					}
					else
					{
						����

						//����˫��

						//��ɫ

					}
				}

			}

		}





	}

	void RotateR(Node*& parent)
	{
		Node* pparent = parent->_parent;
		Node* subL = parent->_left;
		 
		Node* subLR = subL->_right;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		subL->_parent = pparent;
		parent->_parent = subL;

		if (pparent == nullptr)
		{
			_root = subL;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}
	}



private:
	Node* _root = nullptr;
};