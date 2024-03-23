#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int**& a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Rotate90Degrees(int**& a, const int n, int numberOfRepetitions);
int ColumnWithMostZeros(int** a, const int n, const int k);

void Create(int**& a, const int n, const int Low, const int High) {
    srand((unsigned)time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Rotate90Degrees(int**& a, const int n, int numberOfRepetitions) {
    for (int iteration = 0; iteration < numberOfRepetitions; iteration++) {
        int** copy_a = new int* [n];
        for (int i = 0; i < n; i++) {
            copy_a[i] = new int[n];
            for (int j = 0; j < n; j++) {
                copy_a[i][j] = a[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[j][n - i - 1] = copy_a[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            delete[] copy_a[i];
        }
        delete[] copy_a;
    }
}

int ColumnWithMostZeros(int** a, const int n, const int k) {
    int maxZeros = 0, columnIndex = -1;
    for (int j = 0; j < n; ++j) {
        int zeroCount = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 0) {
                zeroCount++;
            }
        }
        if (zeroCount >= maxZeros) {
            maxZeros = zeroCount;
            columnIndex = j;
        }
    }
    return columnIndex;
}

int main() {
    srand((unsigned)time(NULL));
    int Low = -5;
    int High = 5;
    int n;
    int numberOfRepetitions;
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> numberOfRepetitions;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    Create(a, n, Low, High);
    Print(a, n);

    Rotate90Degrees(a, n, numberOfRepetitions);
    Print(a, n);

    int colWithMostZeros = ColumnWithMostZeros(a, n, numberOfRepetitions);
    cout << "Colum with most zeros: "
        << colWithMostZeros + 1 << endl;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
