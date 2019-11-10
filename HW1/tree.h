#pragma once
#include<string>
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class Answer;

class DecisionTreeNode
{
public:
	DecisionTreeNode();
	~DecisionTreeNode();
protected:
	string _value;
	list<Answer*> answers;
	bool isLeaf;

public:
	//DecisionTreeNode& operator=(const DecisionTreeNode&);
	//DecisionTreeNode& operator=(DecisionTreeNode&&);

	void setValue(string str) { _value = str; }
	DecisionTreeNode* search(string str ,DecisionTreeNode*& father);
};

class Answer
{
public:
	Answer();
	~Answer();
	string ans;
	DecisionTreeNode* son;
};
class Tree: public DecisionTreeNode
{
public:
private:
	DecisionTreeNode* _root;

public:

	Tree() { _root = nullptr; }
	~Tree();
	void addRoot(string str) { _root->setValue(str); }
	DecisionTreeNode* search(string str, DecisionTreeNode*& father);
};

