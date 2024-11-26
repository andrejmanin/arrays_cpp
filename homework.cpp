#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

void task1() {
    const int rows = 3, cols = 4;
    int arr[rows][cols];

    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 11 - 5;
        }
    }

    int zeroCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == 0) {
                ++zeroCount;
            }
        }
    }

    cout << "Масив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Кількість нульових елементів: " << zeroCount << endl;
}

void findMaxInBlueArea(const int n, int matrix[10][10], char pattern) {
    int maxVal = INT_MIN;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isInBlue = false;

            switch (pattern) {
                case 'a': isInBlue = (j <= i); break;
                case 'б': isInBlue = (j >= i); break;
                case 'в': isInBlue = (j <= n - i - 1); break;
                case 'г': isInBlue = (j >= n - i - 1); break;
                case 'д': isInBlue = (j == i || j == n - i - 1); break;
                case 'е': isInBlue = (j < i && j < n - i - 1) || (j > i && j > n - i - 1); break;
                case 'ж': isInBlue = (j >= i && j <= n - i - 1); break;
                case 'з': isInBlue = (j <= i && j >= n - i - 1); break;
                case 'и': isInBlue = (j > i && j < n - i - 1); break;
                case 'к': isInBlue = (j < i && j > n - i - 1); break;
            }

            if (isInBlue) {
                maxVal = max(maxVal, matrix[i][j]);
            }
        }
    }

    cout << "Найбільший елемент у синій зоні: " << maxVal << endl;
}

void task2() {
    const int n = 5;
    int matrix[10][10];

    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }

    cout << "Матриця:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    char pattern = 'a';
    cout << "\nШаблон: " << pattern << endl;
    findMaxInBlueArea(n, matrix, pattern);
}

int main() {
    // task1();
    task2();
    return 0;
}
