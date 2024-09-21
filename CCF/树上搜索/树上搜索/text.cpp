#include<iostream>
using namespace std;
#include<vector>


struct _tree
{
	int _weighted;
	_tree* _parent;
	vector<_tree*> _node;
};


int Weighted(_tree* node) 
{
	if (node->_node.size() == 0)
		return 0;

	int weighted = node->_weighted;
	for (int i = 0; i < node->_node.size(); i++) {
		weighted += Weighted((node->_node)[i]);
	}
	return weighted;
}

_tree* Link(vector<int> weighted, vector<int> link)
{
	_tree* head = (_tree*)malloc(sizeof(_tree));
	head->_parent = nullptr;
	head->_weighted = weighted[0];

	for (int i = 0; i < link.size(); i++)
	{

	}

}

int main()
{

	int node_nums, text_num;
	cin >> node_nums >> text_num;

	vector<int> weighted(node_nums);
	for (auto& e : weighted)
	{
		cin >> e;
	}

	vector<int> link(node_nums - 1);
	for (auto& l : link)
	{
		cin >> l;
	}

	Link(weighted, link);

	while (text_num--)
	{
		int text;
		cin >> text;
		vector<int> _weight;






	}

	
	
	return 0;
}