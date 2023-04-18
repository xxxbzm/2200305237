#include <iostream>
#include "../../queue/Queue.h"
#include <stdlib.h>
using namespace std;

queue A; 
 
void cul(int* height,int n)
{
	int maxa = 0;//��maxa��¼�����������
	height[n+1]=-1;
    for(int i=1; i <= n+1; i++)
    {
        if(A.empty() || height[ A.getlast() ] <= height[i]) {A.push(i);}
        else
        {   int suc;
            while(A.getLength() && (height[i] < height[A.getlast()] ) )  
            {
                suc = A.getlast(); 
                maxa = max(height[A.getlast()]*(i-A.getlast()), maxa);
                A.out();
            }
        A.push(suc);
        height[suc] = height[i];
        }
    }
    cout<<endl<<"���������Ϊ"<<maxa<<endl;
}
int main()
{
	const int N = 105;
	int height[1000];
	for(int j = 1; j<=N; j++)
    	{height[j] = rand()%100+1;
    	cout<<height[j]<<" ";}
    cul(height, N);
    
	int n;
	cout<<"������θ���:"<<endl;
	cin>>n;
	cout<<"��������θ߶�:"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>height[i];
	}
		cul(height,n);
}
