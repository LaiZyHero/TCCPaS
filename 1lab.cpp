#include <iostream>

using namespace std;

void BubbleSort(int *arr, int size, int *P, int *S) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
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

    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[min])
                min = j;
            *S+=1;
        }
        if(min != i){
            swap(arr[min], arr[i]);
            *P+=3;
        }
    }
}

void MergeSort(int *a, int n, int *P, int *S)
{
  int step = 1;  
  int *temp = new int[n]; 
  while (step < n)  
  {
    int index = 0;    
    int l = 0;     
    int m = l + step;  
    int r = l + step * 2;  
    do
    {
      m = m < n ? m : n;  
      r = r < n ? r : n;
      int i1 = l, i2 = m; 
      for (; i1 < m && i2 < r; ) 
      {
        if (a[i1] < a[i2]) { temp[index++] = a[i1++]; } 
        else { temp[index++] = a[i2++]; }
        *S += 1;
      }
      
      while (i1 < m) {
		temp[index++] = a[i1++]; 
		*P += 1;
	}
      while (i2 < r) {
	   temp[index++] = a[i2++]; 
	   *P += 1;
	}
      l += step * 2; 
      m += step * 2;
      r += step * 2;
    } while (l < n); 
    for (int i = 0; i < n; i++) {
      a[i] = temp[i];
      *P += 1;
  }
    step *= 2; 
  }
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

	MergeSort(arr, size, &S, &P);
	sum = S + P;
	PrintArr(arr, size, S, P, sum);

	delete[] arr;

	return 0;
}
