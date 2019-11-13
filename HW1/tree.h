#pragma once
#include<string>
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;

class Answer;

class DecisionTreeNode
{
public:
	DecisionTreeNode();
	DecisionTreeNode(string val) { _value = val; _isLeaf = true;	}
	~DecisionTreeNode();
	void del();
	void addAnswer(string, string);
	bool isLeaf() { return _isLeaf; }
	void isLeaf(bool b) { _isLeaf=b; }
	void setValue(string str) { _value = str; }
	DecisionTreeNode* search(string str ,DecisionTreeNode*& father);
	void print();
	bool show();

protected:
	string _value;
	list<Answer*> answers;
	list<Answer*>::iterator it;
	bool _isLeaf;

};

class Answer
{
public:
	Answer();
	Answer(string ans) { _ans = ans; }
	~Answer() { delete _son; }
	void setSon(DecisionTreeNode* son) { _son = son; }
	DecisionTreeNode* son() { return _son; }
	string ans() { return _ans; }
protected:
	string _ans;
	DecisionTreeNode* _son;
};
class Tree: public DecisionTreeNode
{
public:
private:
	DecisionTreeNode* _root;

public:

	Tree() { _root = nullptr; }
	~Tree();
	void addRoot(string str) { DecisionTreeNode* _root = new DecisionTreeNode(str); }
	DecisionTreeNode* search(string str, DecisionTreeNode*& father);
	bool addSon(string father, string val, string sol);
	void printAllTree();
	void searchAndPrint(string val) { DecisionTreeNode* temp = new DecisionTreeNode; temp = temp->search(val, _root); temp->print(); delete temp; }
	void deleteSubTree(string val) { DecisionTreeNode* temp = new DecisionTreeNode; temp = temp->search(val, _root); temp->del(); delete temp; }
	void process();
};

