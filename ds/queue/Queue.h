#include<iostream>
using namespace std;

class queue{
public: 
    queue(){	//��ʼ��
        first=0;
        last=-1;
        count=0;
    }
    bool empty(){	//�ж��Ƿ�Ϊ��
        if(count==0){return true;}
        return false;
    }

    int getlast(){	//ȡβ
        if(empty()){
            return -1;
        }
        return data[last];
    }
    
    bool push(int num){	//���
        last++;
        data[last]=num; 
        count++;
        return true;
    }

    bool out(){	//����
        if(empty()){return false;}
        last--;
        count--;
        return true;
    }
    
    int getLength(){	//���г���
        return count;
    }
private:
    int first;
    int last;
    int count;
    int data[1000];
};

