# include"../../vector/vector.h"
# include"Complex.h"
#include <iostream>
using namespace std;
int main() {
	Complex A[10];
	cout << "�����������������" << endl;
	for (int j = 0; j < 10; j++) {
		A[j].read_Real(rand() % 20 + 10);
		A[j].read_Imaginary(rand() % 20 + 10);
		A[j].read_modulus();
		A[j].display();
	}//����Ļ����ʾ�������
	cout << endl;
	Vector<Complex> B(A, 10);

	//���� 
	B.unsort(0, 10);
	cout << endl << "���Һ�" << endl;
	for (int i = 0; i < 10; i++)
		B._elem[i].display();//��ʾ���Һ������ 

	//����
	cout << endl;
	int local;
	local = B.find0(A[0]);
	cout << endl << "ԭ�������һ��Ԫ�����Һ��λ��Ϊ" << endl << local << endl;

	//����
	Vector<Complex> C(A, 1);
	C[0].read_Real(rand() % 200 / 10);
	C[0].read_Imaginary(rand() % 200 / 10);
	B.insert(10, C[0]);
	cout << endl << "��ĩβ����һ���������" << endl;
	for (int i = 0; i < 11; i++)
		B._elem[i].display();
	cout << endl;

	//ɾ��
	cout << endl << "ɾ�����һ������" << endl;
	B.remove(10);
	for (int i = 0; i < 10; i++)
		B._elem[i].display();
	cout << endl;

	//Ψһ��
	Vector<Complex> D(A, 1);
	D[0].read_Real(4);
	D[0].read_Imaginary(6);
	int k = rand() % 8 + 2;
	for (int i = 0; i < k; i++)
		B.insert(rand() % 8 + 2, D[0]);
	cout << endl << "Ψһ��ǰ��" << endl;
	for (int i = 0; i < 10 + k; i++)
		B._elem[i].display();
	int x = B.deduplicate();
	cout << endl << "�ظ�Ԫ�ظ���: " << x << endl;
	cout << endl << "Ψһ����" << endl;
	B.deduplicate();
	for (int i = 0; i < (10 + k - x); i++)
		B._elem[i].display();

}

