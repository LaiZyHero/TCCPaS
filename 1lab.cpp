#include <iostream>

using namespace std;

void BubbleSort(int *arr, int size, int *P, int *S) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				*P += 3;
			}
			*S += 1;
		}
	}
}

void SelectSort(int* arr, int size, int *P, int *S) {
	int min;
	for (int i = 0; i < size - 1; ++i) {
		min = i;
		for (int j = 0; j < size - 1; ++j) {
			*S += 1;
			if (arr[j] < arr[min])
				min = j;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		*P += 3;
	}
}

void MergeSort() {

}

void PrintArr(int* arr, int size, int P, int S, int sum) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl << "Sravn: " << S << endl << "Prirav: " << P << endl << "Summa: " << sum ;
}
int main()
{
	int* arr;
	int size = 0;
	int P = 0, S = 0, sum = 0;
	cout << "Enter N: ";
	cin >> size;

	arr = new int[size];
	
	for (int i = 0; i < size; ++i) {
		cout << "arr[" << i << "] =";
		cin >> arr[i];
	}

	BubbleSort(arr, size, &S, &P);
	sum = S + P;
	PrintArr(arr, size, S, P, sum);

	delete[] arr;

	return 0;
}
