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
//冒泡排序
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;  // 标记一次遍历中是否发生了交换，如果没有，则说明已经排好序了，可以直接退出循环
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}
//插入排序
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// 选择排序
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
// 归并排序
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
// 快速排序
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
        // 测试冒泡排序性能
        cout << "冒泡排序: ";
        start_time = clock();   // 记录排序开始时间
        bubbleSort(arr, n);
        end_time = clock();   // 记录排序结束时间
    }
    else if (type == 2) {
        // 测试插入排序性能
        cout << "插入排序: ";
        start_time = clock();   // 记录排序开始时间
        insertionSort(arr, n);
        end_time = clock();   // 记录排序结束时间
    }
    else if (type == 3) {
        // 测试选择排序性能
        cout << "选择排序: ";
        start_time = clock();   // 记录排序开始时间
        selectionSort(arr, n);
        end_time = clock();   // 记录排序结束时间
    }
    else if (type == 4) {
        // 测试归并排序性能
        cout << "归并排序: ";
        start_time = clock();   // 记录排序开始时间
        mergeSort(arr, 0, n);
        end_time = clock();   // 记录排序结束时间
    }
    else if (type == 5) {
        // 测试快速排序性能
        cout << "快速排序: ";
        start_time = clock();   // 记录排序开始时间
        mergeSort(arr, 0, n);
        end_time = clock();   // 记录排序结束时间
    }

    duration = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time: " << duration << "s." << endl;
}

int main() {
    int arr1[N], arr2[N], arr3[N], arr4[N], arr5[N];

    // 生成顺序序列
    for (int i = 0; i < N; i++) {
        arr1[i] = i;
    }
    cout << "顺序序列" << endl;
    testSort(arr1, N, 1);   // 测试冒泡排序性能
    testSort(arr1, N, 2);   // 测试插入排序性能
    testSort(arr1, N, 3);   // 测试选择排序性能
    testSort(arr1, N, 4);   // 测试归并排序性能
    testSort(arr1, N, 5);   // 测试快速排序性能
    cout << endl;
    // 生成逆序序列
    for (int i = N - 1; i >= 0; i--) {
        arr2[N - i - 1] = i;
    }
    cout << "逆序序列" << endl;
    testSort(arr2, N, 1);   // 测试冒泡排序性能
    testSort(arr2, N, 2);   // 测试插入排序性能
    testSort(arr2, N, 3);   // 测试选择排序性能
    testSort(arr2, N, 4);   // 测试归并排序性能
    testSort(arr2, N, 5);   // 测试快速排序性能
    cout << endl;
    // 生成随机序列
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        arr3[i] = rand() % N;
    }
    cout << "随机序列" << endl;
    testSort(arr3, N, 1);   // 测试冒泡排序性能
    testSort(arr3, N, 2);   // 测试插入排序性能
    testSort(arr3, N, 3);   // 测试选择排序性能
    testSort(arr3, N, 4);   // 测试归并排序性能
    testSort(arr3, N, 5);   // 测试快速排序性能
    cout << endl;
    return 0;
}