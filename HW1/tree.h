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
	DecisionTreeNode* search(string str);
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
	DecisionTreeNode root;

public:

	Tree() { root = nullptr; }
	~Tree();
	void addRoot(string str) { root.setValue(str); }
	DecisionTreeNode* search(string str);
};

