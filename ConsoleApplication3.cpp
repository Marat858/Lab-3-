#include <iostream>

using namespace std;

void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int* i = arr + start; i < arr + end; i++) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        end--;
        for (int* i = arr + end - 1; i >= arr + start; i--) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                swapped = true;
            }
        }
        start++;
    }
}

int main() {
    setlocale(0, "Rus");
    const int N = 6;
    // Пункт 1 а
    int arr2[10][10];
    int Ibeg = 0, Ifin = 0, Jbeg = 0, Jfin = 0;
    int k_ = 1;
    int i_ = 0;
    int j_ = 0;
    while (k_ <= N * N) {
        arr2[i_][j_] = k_;
        if (i_ == Ibeg && j_ < N - Jfin - 1)
            ++j_;
        else if (j_ == N - Jfin - 1 && i_ < N - Ifin - 1)
            ++i_;
        else if (i_ == N - Ifin - 1 && j_ > Jbeg)
            --j_;
        else
            --i_;

        if ((i_ == Ibeg + 1) && (j_ == Jbeg) && (Jbeg != N - Jfin - 1)) {
            ++Ibeg;
            ++Ifin;
            ++Jbeg;
            ++Jfin;
        }
        ++k_;
    }
    cout << "Исходная матрица спиралью:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr2 + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Пункт 1 б
    int arr[N][N];
    int k = 1;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) {
                *(*(arr + j) + i) = k; // arr[j][i] = k;
                k++;
            }
        }
        else {
            for (int j = N - 1; j >= 0; j--) {
                *(*(arr + j) + i) = k;
                k++;
            }
        }
    }
    cout << "Исходная матрица змейкой:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Пункт 2
    // Пункт б
    int arr_copy[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(arr_copy + i) + j) = *(*(arr + i) + j);
        }
    }
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            int c = *(arr_copy[i] + j);
            *(*(arr_copy + i) + j) = *(*(arr_copy + i + N / 2) + j + N / 2);
            *(*(arr_copy + i + N / 2) + j + N / 2) = c;
            c = *(*(arr_copy + i + N / 2) + j);
            *(*(arr_copy + i + N / 2) + j) = *(*(arr_copy + i) + j + N / 2);
            *(*(arr_copy + i) + j + N / 2) = c;
           
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr_copy + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Пункт а
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(arr_copy + i) + j) = *(*(arr + i) + j);
        }
    }
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            int c = *(*(arr_copy + i) + j);
            *(*(arr_copy + i) + j) = *(*(arr_copy + i) + j + N / 2);
            *(*(arr_copy + i) + j + N / 2) = c;

            c = *(*(arr_copy + i) + j);
            *(*(arr_copy + i) + j) = *(*(arr_copy + i + N / 2) + j + N / 2);
            *(*(arr_copy + i + N / 2) + j + N / 2) = c;

            c = *(*(arr_copy + i) + j);
            *(*(arr_copy + i) + j) = *(*(arr_copy + i + N / 2) + j);
            *(*(arr_copy + i + N / 2) + j) = c;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr_copy + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Пункт с    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(arr_copy + i) + j) = *(*(arr + i) + j);
        }
    }

    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            
            swap(*(*(arr_copy + i) + j), *(*(arr_copy + i + N / 2) + j));
        }
    }

    for (int i = N / 2; i < N; i++) {
        for (int j = N / 2; j < N; j++) {
           
            swap(*(*(arr_copy + i) + j), *(*(arr_copy + i - N / 2) + j));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr_copy + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Пункт d    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(arr_copy + i) + j) = *(*(arr + i) + j);
        }
    }

    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
           
            swap(*(*(arr_copy + i) + j), *(*(arr_copy + i) + j + N / 2));
        }
    }

    for (int i = N / 2; i < N; i++) {
        for (int j = N / 2; j < N; j++) {
            
            swap(*(*(arr_copy + i) + j), *(*(arr_copy + i) + j - N / 2));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr_copy + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Задание 3
    cocktailSort(*arr, N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Задание 4
    int op;
    float a;
    cout << "Введите a: ";
    cin >> a;
    cout << "Если хотите прибавить, введите 1." << endl;
    cout << "Если хотите вычесть, введите 2." << endl;
    cout << "Если хотите умножить, введите 3." << endl;
    cout << "Если хотите делить, введите 4." << endl;
    cin >> op;
    if (op == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                *(*(arr + i) + j) += a;
                //arr[i][j] += a;
            }
        }
    }
    else if (op == 2) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                *(*(arr + i) + j) -= a;
    }
    else if (op == 3) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                *(*(arr + i) + j) *= a;
    }
    else if (op == 4) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                *(*(arr + i) + j) /= a;
    }
    else {
        cout << "Операция введена неправильно." << endl;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
    return 0;
}
