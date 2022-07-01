#include<iostream>
#include<string>
#include<cstring>
#include"PQueue.h"
#include"compound.cpp"
using namespace std;


int main()
{
	Stack<int>stack;
	string input;//要转换的数值
	int trans;//要转换的进制
	int region;//原本的进制
	int output = 0;
	int num = 0;
	cout << "请输入要转换的数值" << endl;
	cin >> input;
	cout << "请输入原本的进制" << endl;
	cin >> region;
	cout << "请输入要转换的进制" << endl;
	cin >> trans;
	for (int i = 0; i < input.length(); i++) {
			int temp;
			int n = input.length();
			switch (input[i]){
			case '0':temp = 0; break;
			case '1':temp = 1; break;
			case '2':temp = 2; break; 
			case '3':temp = 3; break; 
			case '4':temp = 4; break; 
			case '5':temp = 5; break; 
			case '6':temp = 6; break; 
			case '7':temp = 7; break; 
			case '8':temp = 8; break; 
			case '9':temp = 9; break;
			case 'A': temp = 10; break;
			case 'B': temp = 11; break;
			case 'C': temp = 12; break;
			case 'D': temp = 13; break;
			case 'E': temp = 14; break;
			case 'F': temp = 15; break;

			}
			num = num + temp * pow(region, n - 1 - i);

	}

	if (trans <= 0) {
		cout << "error";
	}
	else if (trans>0)
	{
		int a = 0;
		
		for (;;) 
		{		
			if (num >= trans) {
				output = num % trans;
				stack.push(output);
				num = num / trans;
			}
			if (num < trans) {
				stack.push(num);
				break;
			}
		}
			for (;;) {
				a = stack.pop();
				if (a==-1) break;
				
				if(a>9){
					char b = 'A' +(a-10) ;
					cout << b;
				}
				else{
					cout << a;
				}
			}
	}
}
