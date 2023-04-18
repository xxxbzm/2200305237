#ifndef STACK
#define STACK
#include "../vector/Vector.h"
#include <iostream>
using namespace std;

template <typename T> class Stack: public Vector<T> { //����������/ĩ����Ϊջ��/��
public: //size()��empty()�Լ��������Žӿڣ�����ֱ������
   void push ( T const& e ) { this -> insert (this -> size(), e ); } //��ջ����Ч�ڽ���Ԫ����Ϊ������ĩԪ�ز���
   T pop() { return this -> remove ( this -> size() - 1 ); } //��ջ����Ч��ɾ��������ĩԪ��
   T& top() { return ( *this ) [this->size() - 1]; } //ȡ����ֱ�ӷ���������ĩԪ��
};
#endif
