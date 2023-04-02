# include"../../vector/vector.h"
# include"Complex.h"
#include <iostream>
using namespace std;
int main() {
	Complex A[10];
	cout << "随机生成无序复数向量" << endl;
	for (int j = 0; j < 10; j++) {
		A[j].read_Real(rand() % 20 + 10);
		A[j].read_Imaginary(rand() % 20 + 10);
		A[j].read_modulus();
		A[j].display();
	}//在屏幕上显示随机向量
	cout << endl;
	Vector<Complex> B(A, 10);

	//置乱 
	B.unsort(0, 10);
	cout << endl << "置乱后" << endl;
	for (int i = 0; i < 10; i++)
		B._elem[i].display();//显示置乱后的向量 

	//查找
	cout << endl;
	int local;
	local = B.find0(A[0]);
	cout << endl << "原向量组第一个元素置乱后的位置为" << endl << local << endl;

	//插入
	Vector<Complex> C(A, 1);
	C[0].read_Real(rand() % 200 / 10);
	C[0].read_Imaginary(rand() % 200 / 10);
	B.insert(10, C[0]);
	cout << endl << "在末尾插入一个随机向量" << endl;
	for (int i = 0; i < 11; i++)
		B._elem[i].display();
	cout << endl;

	//删除
	cout << endl << "删除最后一个向量" << endl;
	B.remove(10);
	for (int i = 0; i < 10; i++)
		B._elem[i].display();
	cout << endl;

	//唯一化
	Vector<Complex> D(A, 1);
	D[0].read_Real(4);
	D[0].read_Imaginary(6);
	int k = rand() % 8 + 2;
	for (int i = 0; i < k; i++)
		B.insert(rand() % 8 + 2, D[0]);
	cout << endl << "唯一化前：" << endl;
	for (int i = 0; i < 10 + k; i++)
		B._elem[i].display();
	int x = B.deduplicate();
	cout << endl << "重复元素个数: " << x << endl;
	cout << endl << "唯一化后：" << endl;
	B.deduplicate();
	for (int i = 0; i < (10 + k - x); i++)
		B._elem[i].display();

}

