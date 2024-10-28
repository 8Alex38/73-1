#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
bool CountPositiveAfterZero(int** a, const int rowCount, const int colCount, int& count);
void FindSaddlePoints(int** a, const int rowCount, const int colCount);
bool IsMaxInRow(int** a, const int n, const int k, const int colCount);
bool IsMinInCol(int** a, const int n, const int k, const int rowCount);

int main() {
    srand(static_cast<unsigned>(time(0)));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;

    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int count = 0;
    if (CountPositiveAfterZero(a, rowCount, colCount, count))
        cout << "Count of positive elements after zeroes = " << count << endl;
    else
        cout << "There are no zero elements" << endl;

    cout << endl;
    FindSaddlePoints(a, rowCount, colCount);
    cout << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool CountPositiveAfterZero(int** a, const int rowCount, const int colCount, int& count) {
    bool hasZero = false;
    count = 0;

    for (int j = 0; j < colCount; j++) {
        bool foundZeroInCol = false;

        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] == 0) {
                hasZero = true;
                foundZeroInCol = true;

                for (int k = i + 1; k < rowCount; k++) {
                    if (a[k][j] > 0) {
                        count++;
                    }
                }
                break;
            }
        }
    }

    return hasZero;
}

bool IsMaxInRow(int** a, const int n, const int k, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        if (a[n][j] > a[n][k]) {
            return false;
        }
    }
    return true;
}

bool IsMinInCol(int** a, const int n, const int k, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        if (a[i][k] < a[n][k]) {
            return false;
        }
    }
    return true;
}

void FindSaddlePoints(int** a, const int rowCount, const int colCount) {
    cout << "Saddle points: max in row & min in col" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;

    for (int n = 0; n < rowCount; n++) {
        for (int k = 0; k < colCount; k++) {
            if (IsMaxInRow(a, n, k, colCount) && IsMinInCol(a, n, k, rowCount)) {
                cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
            }
        }
    }
}
