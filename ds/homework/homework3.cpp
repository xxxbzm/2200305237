//���� 
#include<windows.h> 
#include <ctime>
#include<iostream>
#include <stdlib.h>
#include<cstdio>
#include "Complex.h"
#include "../../vector/vector.h"
using namespace std;
int main()
{
	double m1 = 10, m2 = 20;
	Complex A[10];
	cout << "��������������������������ʾ:" <<endl; 
	for (int j = 0; j < 10; j++){
	   A[j].read_Real(rand() % 200 / 10.0);
	   A[j].read_Imaginary(rand() % 200 / 10.0);
	   A[j].read_modulus();
       //A[j].display();//����Ļ����ʾ 
    }//���ɸ��� 
    Vector<Complex>v(A, 10);
    v.bubbleSort(0,10);
    for(int i=0; i<10; i++)
    {
    	v._elem[i].display();
	}
	cout<<endl;
	cout<<"ģ�ڷ�Χ[10��20����ĸ������£�"<<endl;
    for(int i=0; i<10; i++)
    {
    	if(A[i].m_modulus >= m1 && A[i].read_modulus() < m2 )
    		v._elem[i].display();
	}
}
