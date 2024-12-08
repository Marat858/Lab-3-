#include <iostream>

using namespace std;

int main() {
	setlocale(0, "Rus");
	const int N = 3;
	int arr[N][N];
	int count = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			//arr[i][j] = count++;

		}

	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (*(*(arr + i) + j) % 2 == 0)
				cout << *(*(arr + i) + j) - 1<<" ";
			else
				cout << *(*(arr + i) + j) + 1<<" ";

		}
		if (i != N - 1)
			cout << endl;
	}
	return 0;
	cout << endl;
}

	// с указателями 
/*	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] % 2 == 0) {
				int c = *(arr + 1);
				//arr[i][j] = count++;
			}
		}

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";

		}
		cout << endl;
	}
    return 0;
	cout << endl;
}
 


























/*void quicksort(int* arr, int  end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) quicksort(arr, l, begin);
	if (f < end) quicksort(arr, end, f);
}*/
/*srand(time(0));
 const int N = 10;
 int a[N];
 int c;
 cin >> c;

 for (int i = 0; i < N; i++) {
	 a[i] = rand() % 10;
	 cout << a[i]<<" ";

 }
 quicksort(arr, end, begin);
 for (int i = 0;i<N;i++)
	 if (c == )*/
