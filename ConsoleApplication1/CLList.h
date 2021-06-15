#pragma once
#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

template <class T>
class node{
private:
	T data;
	node<T>* next;
public:
	node(const T& value, node<T>* nxt = nullptr){
		data = value;
		next = nxt;
	}
	node<T>* getnext(){ return next; }
	void setnext(node<T>* nxt){ next = nxt; }
	T getdata(){ return data; }
	void setdata(const T& dat){ data = dat; }
	~node(){
		if (next != NULL && next!=this)
			delete next;
		else
			next = nullptr;
	}
};

template<class T>
class CLList{
private:
	node<T>* tail;
	class cListIterator{
	private:
		node<T>* iptr;
	public:
		cListIterator(node<T>* ptr){
			iptr = ptr;
		}
		node<T>* getiptr(){
			return iptr;
		}
		T operator * (){//dereference
			return iptr->getdata();
		}
		cListIterator operator ++ (int){//postfix
			cListIterator temp = *this;
			if (iptr != NULL){
				iptr = iptr->getnext();
			}
			return temp;
		}
		cListIterator operator ++ (){//prefix
			if (iptr != NULL){
				iptr = iptr->getnext();
			}
			return *this;
		}
		bool operator == (const cListIterator &obj){//isequal
			return (iptr == obj.iptr);
		}
		bool operator != (const cListIterator &obj){//notequal
			return !(iptr == obj.iptr);
		}
		const cListIterator& operator = (const cListIterator& obj){
			iptr = obj.iptr;
			return *this;
		}
		cListIterator operator+ (int num){//ite=ite+int
			cListIterator temp(iptr);
			for (int i = 0; i < num; i++){
				temp++;
			}
			return temp;
		}
		cListIterator operator- (int num){//ite=ite-int
			cListIterator temp(iptr);
			for (int i = 0; i < num; i++){
				temp--;
			}
			return temp;
		}
		~cListIterator(){
			iptr = nullptr;
		}
	};
public:
	typedef cListIterator cIterator;
	CLList(node<T>* tl = nullptr){
		tail = tl;
	}
	cIterator begin(){
		cIterator i(tail->getnext());
		return i;
	}
	cIterator end(){
		cIterator i(tail);
		return i;
	}
	void insert(T newdata){
		if (tail == nullptr){
			//empty list
			tail = new node<T>(newdata, nullptr);
			tail->setnext(tail);
		}
		else {
			//at end
			node<T>* temp = tail->getnext();
			tail->setnext(new node<T>(newdata, temp));
			tail = tail->getnext();
		}
	}
	void remove(cIterator ite){
		if (tail != nullptr){
			if (tail == tail->getnext()){
				//only one element
				delete tail;
				tail = nullptr;
			}
			else if (ite.getiptr() == tail && tail->getnext()!=tail){
				node<T>* curr = tail->getnext();
				while (curr->getnext() != tail)
					curr = curr->getnext();
				curr->setnext(tail->getnext());
				tail->setnext(nullptr);
				delete tail;
				tail = curr;
			}
			else{
				node<T>* curr = tail->getnext();
				while (curr->getnext() != ite.getiptr())
					curr = curr->getnext();
				node<T>* temp = curr->getnext();
				curr->setnext(ite.getiptr()->getnext());
				temp->setnext(nullptr);
				delete temp;
			}
		}
	}
	void printlist(){
		cout << endl;
		node<T>* curr = tail->getnext();
		for (; curr != tail; curr = curr->getnext())
			cout << curr->getdata() << " ";
		cout << tail->getdata();
		curr = nullptr;
	}
	~CLList(){
		if (tail)
			delete tail;
		else
			tail = nullptr;
	}
};
