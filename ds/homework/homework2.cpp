# include"../../vector/vector.h"
# include"Complex.h"
# include <iostream>
# include <ctime>
using namespace std;

int main() {
	const int N = 10000;
	Complex A[N];
	cout << "Éú³ÉËæ»úÎÞÐòÏòÁ¿" << endl;
	for (int i = 0; i < N; i++) {
		A[i].read_Real(rand() % 20 + 10);
		A[i].read_Imaginary(rand() % 20 + 10);
		A[i].read_modulus();
	}
	cout << endl;

	//Ã°ÅÝÅÅÐò 
	Vector<Complex> B(A, N);
	clock_t start_t1, end_t1;
	start_t1 = clock();
	B.bubbleSort(0, N);
	end_t1 = clock();
	double total_t1 = (double)(end_t1 - start_t1);
	cout << "ÎÞÐòÃ°ÅÝÅÅÐòÊ±¼ä" << total_t1 << "ms" << endl;

	//¹é²¢ÅÅÐò
	Vector<Complex> C(A, N);
	clock_t start_t2, end_t2;
	start_t2 = clock();
	C.mergeSort(0, N);
	end_t2 = clock();
	double total_t2 = (double)(end_t2 - start_t2);
	cout << "ÎÞÐò¹é²¢ÅÅÐòÊ±¼ä" << total_t2 << "ms" << endl;

	//Ã°ÅÝÅÅÐò
	clock_t start_t3, end_t3;
	start_t3 = clock();
	B.bubbleSort(0, N);
	end_t3 = clock();
	double total_t3 = (double)(end_t3 - start_t3);
	cout << "ÓÐÐòÃ°ÅÝÅÅÐòÊ±¼ä" << total_t3 << "ms" << endl;

	//¹é²¢ÅÅÐò
	clock_t start_t4, end_t4;
	start_t4 = clock();
	C.mergeSort(0, N);
	end_t4 = clock();
	double total_t4 = (double)(end_t4 - start_t4);
	cout << "ÓÐÐò¹é²¢ÅÅÐòÊ±¼ä" << total_t4 << "ms" << endl;

	B.bubbleSort(-1, 0, N);//µ¹Ðò
	//Ã°ÅÝÅÅÐò
	clock_t start_t5, end_t5;
	start_t5 = clock();
	B.bubbleSort(0, N);
	end_t5 = clock();
	double total_t5 = (double)(end_t5 - start_t5);
	cout << "µ¹ÐòÃ°ÅÝÅÅÐòÊ±¼ä" << total_t5 << "ms" << endl;

	C.bubbleSort(-1, 0, N);//µ¹Ðò
	//¹é²¢ÅÅÐò
	clock_t start_t6, end_t6;
	start_t6 = clock();
	C.mergeSort(0, N);
	end_t6 = clock();
	double total_t6 = (double)(end_t6 - start_t6);
	cout << "µ¹Ðò¹é²¢ÅÅÐòÊ±¼ä" << total_t6 << "ms" << endl;



}