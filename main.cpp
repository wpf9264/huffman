/************************************************************************
    > File Name: main.cpp
    > Author: wpf
    > Mail: wpf9264@163.com 
    > Created Time: 2019年04月25日 星期四 19时58分31秒
************************************************************************/

#include<iostream>
#include <string>
#include"node.h"
#include<string>
using namespace std;

int main(int argc,char** argv)
{
	int n,w;
	char c;
	string s;
	cout<<"enter size of char:";
	cin>>n;
	Tree bn;
	for(int i=0; i!=n; ++i){
		cout<<"enter char and weight:";
		cin>>c>>w;
		Node a(c,w);
		bn.add_node(a);
		cin.clear();		//清空输入缓冲流
	}
	while(bn.size()!=1){
		Node n1 = bn.pop();
		Node n2 = bn.pop();	//获取权重最小的两个节点
		Node h(' ',n1.get_weight()+n2.get_weight());	//将前者合并为新节点
		if (n1.get_weight()<n2.get_weight()){
			h.set(n1,n2);		//设置左右节点
		}else{
			h.set(n2,n1);
		}
		bn.add_node(h);
	}
	cout<<"================="<<endl;
	Node root = bn.get_Node();
	root.set_bits("#");	//设置根节点的标志，用于遍历右子树时的判定
	cout<<"left ======="<<endl;
	bn.get_code(&root,root.lc);
	cout<<"right======="<<endl;
	bn.get_code(&root,root.rc);
	cout<<"================="<<endl;

	for(auto&i:bn.codes){
		cout<<i.first<<" : "<<i.second<<endl;
	}



	return 0;
}
