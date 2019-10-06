/************************************************************************
    > File Name: node.h
    > Author: wpf
    > Mail: wpf9264@163.com 
    > Created Time: 2019年04月25日 星期四 16时58分45秒
************************************************************************/

#ifndef _NODE_H
#define _NODE_H
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;


class Node{
	public:
		friend class Tree;
		Node():c(' '),w(-1),bits(""),lc(nullptr),rc(nullptr){}
		Node(const char ch,const int weight):c(ch),w(weight),bits(""),lc(nullptr),rc(nullptr){}
		Node(const Node &rhs)	//拷贝构造函数
		{
			c	= rhs.c;
			w	= rhs.w;
			bits= rhs.bits;
			lc	= rhs.lc;
			rc	= rhs.rc;
		}
		//Node* clone()const
		//{ return new Node(*this); }
		int get_weight()const
		{ return w; }
		char get_char()const
		{ return c; }
		Node& get_lchild()
		{ return *lc; }			
		Node& get_rchild()
		{ return *rc; }
		/* 设置左右子结点 */
		void set(const Node& l,const Node& r)
		{
			lc = new Node(l);	
			rc = new Node(r);
		}
		/* 设置编码信息 */
		void set_bits(const string &str)
		{ bits = str; }

	//private:
		char	c;
		int		w;
		string	bits;
		Node*	lc;	//左节点
		Node*	rc;	//右节点


};

struct Bigger{
	bool operator()(const Node&lhs,const Node& rhs)const
	{ return lhs.get_weight()<rhs.get_weight(); }
};


class Tree{
public:
	friend class Node;
	Tree(){}		
	void add_node(Node& n)
	{ nodes.insert(n); }
	Node pop()
	{
		Node n(*nodes.begin());		//调用Node的拷贝构造函数，存储即将删除的元素
		nodes.erase(nodes.begin());	//从multiset中删除首元素
		return n;
	}
	size_t size()
	{ return nodes.size(); }
	Node get_Node()
	{ return *nodes.begin();}

	void get_code(Node* root,Node* child)
	{	
		//用于判断是否重新判断根节点的右子树
		if (root->bits=="#")
			tmp="";
		//说明遇到了叶节点
		if (child->lc==nullptr){
			if (child==root->lc){
				tmp += "0";
			}else{
				tmp += "1";
			}
			codes.insert({child->c,tmp});
			child->bits = tmp;
			cout<<child->c<<" : "<<child->bits<<endl;
			return;
		}
		//遇到非叶节点
		if (child==root->lc){
			tmp += "0";
		}else{
			tmp += "1";
		}
		get_code(child,child->lc);
		tmp.erase(tmp.end()-1);
		get_code(child,child->rc);
		tmp.erase(tmp.end()-1);
	}
	map<char,string> codes;

private:
	multiset<Node,Bigger> nodes;
	string tmp;
};





#endif
