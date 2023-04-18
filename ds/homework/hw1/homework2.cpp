# include"../../vector/vector.h"
# include"Complex.h"
# include <iostream>
# include <ctime>
using namespace std;

int main() {
	const int N = 10000;
	Complex A[N];
	cout << "���������������" << endl;
	for (int i = 0; i < N; i++) {
		A[i].read_Real(rand() % 20 + 10);
		A[i].read_Imaginary(rand() % 20 + 10);
		A[i].read_modulus();
	}
	cout << endl;

	//ð������ 
	Vector<Complex> B(A, N);
	clock_t start_t1, end_t1;
	start_t1 = clock();
	B.bubbleSort(0, N);
	end_t1 = clock();
	double total_t1 = (double)(end_t1 - start_t1);
	cout << "����ð������ʱ��" << total_t1 << "ms" << endl;

	//�鲢����
	Vector<Complex> C(A, N);
	clock_t start_t2, end_t2;
	start_t2 = clock();
	C.mergeSort(0, N);
	end_t2 = clock();
	double total_t2 = (double)(end_t2 - start_t2);
	cout << "����鲢����ʱ��" << total_t2 << "ms" << endl;

	//ð������
	clock_t start_t3, end_t3;
	start_t3 = clock();
	B.bubbleSort(0, N);
	end_t3 = clock();
	double total_t3 = (double)(end_t3 - start_t3);
	cout << "����ð������ʱ��" << total_t3 << "ms" << endl;

	//�鲢����
	clock_t start_t4, end_t4;
	start_t4 = clock();
	C.mergeSort(0, N);
	end_t4 = clock();
	double total_t4 = (double)(end_t4 - start_t4);
	cout << "����鲢����ʱ��" << total_t4 << "ms" << endl;

	B.bubbleSort(-1, 0, N);//����
	//ð������
	clock_t start_t5, end_t5;
	start_t5 = clock();
	B.bubbleSort(0, N);
	end_t5 = clock();
	double total_t5 = (double)(end_t5 - start_t5);
	cout << "����ð������ʱ��" << total_t5 << "ms" << endl;

	C.bubbleSort(-1, 0, N);//����
	//�鲢����
	clock_t start_t6, end_t6;
	start_t6 = clock();
	C.mergeSort(0, N);
	end_t6 = clock();
	double total_t6 = (double)(end_t6 - start_t6);
	cout << "����鲢����ʱ��" << total_t6 << "ms" << endl;



}