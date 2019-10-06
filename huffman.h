/************************************************************************
    > File Name: huffman.h
    > Author: wpf
    > Mail: wpf9264@163.com 
    > Created Time: 2019年04月25日 星期四 16时59分01秒
************************************************************************/

#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include<iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

template<typename T>
class Huffman{
	public:
		Huffman(T *ptr=nullptr):pn(ptr),use_count(new size_t(1)){}
		Huffman(const Huffman &rhs):pn(rhs.pn),use_count(rhs.use_count)
	{
		++*use_count;
	}

		T& operator*()
		{
			if (pn){
				return *pn;
			}
			throw runtime_error("dereference error:pn is nullptr");
		}
		T& operator->()
		{
			if (pn){
				return pn;
			}
			throw runtime_error("dereference error:pn is nullptr");
		}
		const T& operator*()const
		{
			if (pn){
				return *pn;
			}
			throw runtime_error("dereference error:pn is nullptr");
		}
		const T& operator->()const
		{
			if (pn){
				return pn;
			}
			throw runtime_error("dereference error:pn is nullptr");
		}
		Huffman& operator=(const Huffman &rhs)
		{
			++*rhs.use_count;
			rm_ref();	//为什么要删除？是为了判断引用次数是否为零。
			pn = rhs.pn;
			use_count = rhs.use_count;
			return *this;
		}
		~Huffman()
		{
			rm_ref();
		}

	private:
		T	*pn;	//对象指针
		size_t	*use_count;		//使用次数
		void rm_ref()
		{
			if (--use_count==0){
				delete pn;
				delete use_count;
			}
		}



};

#endif
