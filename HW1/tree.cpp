#include "tree.h"

DecisionTreeNode::~DecisionTreeNode()
{	
	if (!answers.empty())
		answers.front()->son->~DecisionTreeNode;
	answers.~list();
}

DecisionTreeNode * DecisionTreeNode::search(string str)
{
	if (this->_value == str)
		return this;
	if (this->isLeaf == true)
		return ;
	for (auto it =this->answers.begin();it!=this->answers.end();it++)
	{
		return this->search(str);
	}
}

Tree::~Tree()
{
	root.~DecisionTreeNode();
}

DecisionTreeNode * Tree::search(string str)
{
	if ()
	return nullptr;
}
