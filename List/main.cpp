#include "LinerList.h"
#include "LinkList.h"

#include <iostream>

using namespace std;

int main()
{
	int datas[10] = {1,2,3,4,5,6,7,8,9,0};
	LinerList<int> linerList(datas,10);
	LinkList<int> linkList(datas,10);

	cout<<"LinerList:"<<endl;
	for(int i = 0;i < linerList.getSize();i++)
		cout<<linerList[i]<<" ";
	cout<<endl;
	linerList.invert();
	for(int j = 0;j < linerList.getSize();j++)
		cout<<linerList[j]<<" ";
	cout<<endl;
	cout<<"LinkList:"<<endl;
	for(int m = 0;m < linkList.getSize();m++)
		cout<<linkList[m]<<" ";
	cout<<endl;
	linkList.invert();
	for(int n = 0;n < linkList.getSize();n++)
		cout<<linkList[n]<<" ";
	cout<<endl;

	return 0;
}

