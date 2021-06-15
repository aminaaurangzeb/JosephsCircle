#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<cstdio>
#include "CLList.h"
using namespace std;

template<class T>
T JosephCircle(int n, int m, CLList<T> & cl){
	CLList<T>::cIterator k = cl.begin();
	for (int i = n; i > 1; i = i - 1){
		k = k + m;
		CLList<T>::cIterator temp = k;
		k++;
		cl.remove(temp);
		cl.printlist();
	}
	return *k;
}

int main(){
	CLList<int> circle;
	circle.insert(1);
	circle.insert(2);
	circle.insert(3);
	circle.insert(4);
	circle.insert(5);
	circle.printlist();
	cout << endl << JosephCircle(5, 3, circle);
	_getch();
}
