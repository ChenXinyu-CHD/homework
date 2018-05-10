#include <iostream>
#include "Digit.h"

using namespace std;

int main()
{
	Item *digit = new Digit();
	string str;

	cin>>str;
	digit->setValue(str.begin(),str.end());

	cout<<digit->getValue()<<endl;
	cout<<digit->calculate()<<endl;

	delete digit;

	return 0;
}
