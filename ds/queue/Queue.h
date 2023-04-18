#include<iostream>
using namespace std;

class queue{
public: 
    queue(){	//初始化
        first=0;
        last=-1;
        count=0;
    }
    bool empty(){	//判断是否为空
        if(count==0){return true;}
        return false;
    }

    int getlast(){	//取尾
        if(empty()){
            return -1;
        }
        return data[last];
    }
    
    bool push(int num){	//入队
        last++;
        data[last]=num; 
        count++;
        return true;
    }

    bool out(){	//出队
        if(empty()){return false;}
        last--;
        count--;
        return true;
    }
    
    int getLength(){	//队列长度
        return count;
    }
private:
    int first;
    int last;
    int count;
    int data[1000];
};

