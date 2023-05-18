#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 10000;

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int l, int r);
void testSort(int arr[], int n, int type);
//ð������
void bubbleSort(int arr[], int n) {
    for (int i = 0;i < n - 1;i++) {
        bool flag = false;  // ���һ�α������Ƿ����˽��������û�У���˵���Ѿ��ź����ˣ�����ֱ���˳�ѭ��
        for (int j = 0;j < n - i - 1;j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}
//��������
void insertionSort(int arr[], int n) {
    for (int i = 1;i < n;i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// ѡ������
void selectionSort(int arr[], int n) {
    for (int i = 0;i < n - 1;i++) {
        int minIndex = i;
        for (int j = i + 1;j < n;j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
// �鲢����
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
// ��������
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
}

void testSort(int arr[], int n, int type) {
    clock_t start_time, end_time;
    double duration;

    if (type == 1) {
        // ����ð����������
        cout << "ð������: ";
        start_time = clock();   // ��¼����ʼʱ��
        bubbleSort(arr, n);
        end_time = clock();   // ��¼�������ʱ��
    }
    else if (type == 2) {
        // ���Բ�����������
        cout << "��������: ";
        start_time = clock();   // ��¼����ʼʱ��
        insertionSort(arr, n);
        end_time = clock();   // ��¼�������ʱ��
    }
    else if (type == 3){
        // ����ѡ����������
        cout << "ѡ������: ";
        start_time = clock();   // ��¼����ʼʱ��
        selectionSort(arr, n);
        end_time = clock();   // ��¼�������ʱ��
    }
    else if (type == 4) {
        // ���Թ鲢��������
        cout << "�鲢����: ";
        start_time = clock();   // ��¼����ʼʱ��
        mergeSort(arr, 0, n);
        end_time = clock();   // ��¼�������ʱ��
    }
    else if (type == 5) {
        // ���Կ�����������
        cout << "��������: ";
        start_time = clock();   // ��¼����ʼʱ��
        mergeSort(arr, 0, n);
        end_time = clock();   // ��¼�������ʱ��
    }

    duration = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time: " << duration << "s." << endl;
}

int main() {
    int arr1[N], arr2[N], arr3[N], arr4[N], arr5[N];

    // ����˳������
    for (int i = 0;i < N;i++) {
        arr1[i] = i;
    }
    cout << "˳������" << endl;
    testSort(arr1, N, 1);   // ����ð����������
    testSort(arr1, N, 2);   // ���Բ�����������
    testSort(arr1, N, 3);   // ����ѡ����������
    testSort(arr1, N, 4);   // ���Թ鲢��������
    testSort(arr1, N, 5);   // ���Կ�����������
    cout << endl;
    // ������������
    for (int i = N - 1;i >= 0;i--) {
        arr2[N - i - 1] = i;
    }
    cout << "��������" << endl;
    testSort(arr2, N, 1);   // ����ð����������
    testSort(arr2, N, 2);   // ���Բ�����������
    testSort(arr2, N, 3);   // ����ѡ����������
    testSort(arr2, N, 4);   // ���Թ鲢��������
    testSort(arr2, N, 5);   // ���Կ�����������
    cout << endl;
    // �����������
    srand((unsigned int)time(NULL));
    for (int i = 0;i < N;i++) {
        arr3[i] = rand() % N;
    }
    cout << "�������" << endl;
    testSort(arr3, N, 1);   // ����ð����������
    testSort(arr3, N, 2);   // ���Բ�����������
    testSort(arr3, N, 3);   // ����ѡ����������
    testSort(arr3, N, 4);   // ���Թ鲢��������
    testSort(arr3, N, 5);   // ���Կ�����������
    cout << endl;
    return 0;
}