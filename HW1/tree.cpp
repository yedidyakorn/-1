#include "tree.h"

DecisionTreeNode::DecisionTreeNode()
{
	_isLeaf = true;
}

DecisionTreeNode::~DecisionTreeNode()
{
	answers.~list();
	delete *it;
}

void DecisionTreeNode::del()
{	
	if (_isLeaf==false)
		it = answers.begin();
	(*answers.begin())->ans();
	if (answers.empty())
		delete &answers;
	while (it != answers.end())
	{
		(**it++).son()->del();
	}
	//if (!answers.empty())
	//	for_each(answers.begin(),answers.end(),); 
	answers.~list();
}



void DecisionTreeNode::addAnswer(string str,string son)
{
	if (isLeaf())
		_isLeaf = false;
	Answer* temp = new Answer(str);
	answers.push_back(temp);
	DecisionTreeNode* temp2 = new DecisionTreeNode(son);
	temp->setSon(temp2);
	temp2->_isLeaf = true;
}

DecisionTreeNode* DecisionTreeNode::search(string str, DecisionTreeNode*& father)
{

	if (this->_value == str)
		return this;
	if (this->isLeaf() == true)
		return nullptr;
	it = answers.begin();
	father = this;
	while (it != answers.end())
	{
		(**it++).son()->search(str,father);
	}
	//for_each(this->answers.begin(), this->answers.end(), search(str,father));
	
}

void DecisionTreeNode::print()
{
	cout << _value << endl;
	it = answers.begin();
	while (it != answers.end())
	{
		cout << (**it).ans();
		(**it++).son()->print();
	}
	/*for_each(answers.begin(), answers.end(), [](Answer* ans) {cout<<(*ans).ans<<endl<<(*ans).son.print(); });*/
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
	_root->del();
}

DecisionTreeNode * Tree::search(string str ,DecisionTreeNode*& father)
{
	return _root->search(str,father);

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
	_root->print();
}

void Tree::process()
{
	_root->show();
}
