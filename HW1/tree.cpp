#include "tree.h"

DecisionTreeNode::~DecisionTreeNode()
{	
	if (!answers.empty())
	{
		for_each(answers.begin(),answers.end(),answers.front()->son->~DecisionTreeNode); 
	}
	answers.~list();
}

void DecisionTreeNode::addAnswer(string str,string son)
{
	Answer* temp = new Answer(str);
	answers.push_back(temp);
	DecisionTreeNode* temp2 = new DecisionTreeNode(son);
	temp->setSon(temp2);
	temp2->isLeaf = true;
}

DecisionTreeNode * DecisionTreeNode::search(string str, DecisionTreeNode*& father)
{

	if (this->_value == str)
		return this;
	if (this->isLeaf == true)
		return ;
	for_each(this->answers.begin(), this->answers.end(), search(str,father));
	
}

void DecisionTreeNode::ptint()
{
	cout << _value << endl;
	for_each(answers.begin(), answers.end(), [](Answer & ans) {cout<<ans.ans<<endl<<ans.son.print(); });
}

bool DecisionTreeNode::show()
{
	if (!isLeaf())
	{
		DecisionTreeNode* tmp;
		string temp;
		cout << _value << endl;
		cin >> temp;
		tmp = tmp->search(temp,tmp);
		tmp->show();
	}
	return false;
}

Tree::~Tree()
{
	_root->~DecisionTreeNode();
}

DecisionTreeNode * Tree::search(string str ,DecisionTreeNode*& father)
{
	_root->search(str,father);
	return nullptr;

}

bool Tree::addSon(string father, string val, string sol)
{
	DecisionTreeNode* temp;
	if (temp=nullptr)
		return false;
	else
	{
		if (temp->isLeaf())
			temp->isLeaf(false);
		temp->addAnswer(val,sol);
	}
}

void Tree::printAllTree()
{
	_root->ptint();
}

void Tree::process()
{
	_root.show();
}
