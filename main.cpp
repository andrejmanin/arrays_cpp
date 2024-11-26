#include <iostream>
#include <climits>
#include <ctime>
using namespace std;

void task1() {
    const int rows = 3, cols = 4;
    int arr[rows][cols] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    int sum = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
            if (arr[i][j] < minVal) minVal = arr[i][j];
            if (arr[i][j] > maxVal) maxVal = arr[i][j];
        }
    }

    double average = static_cast<double>(sum) / (rows * cols);

    cout << "Сума: " << sum << endl;
    cout << "Середнє арифметичне: " << average << endl;
    cout << "Мінімальний елемент: " << minVal << endl;
    cout << "Максимальний елемент: " << maxVal << endl;
}

void task2() {
    const int rows = 3, cols = 4;
    int arr[rows][cols] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    int rowSums[rows] = {0};
    int colSums[cols] = {0};
    int totalSum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSums[i] += arr[i][j];
            colSums[j] += arr[i][j];
            totalSum += arr[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << "|  " << rowSums[i] << endl;
    }
    cout << "-------------------------" << endl;

    for (int j = 0; j < cols; ++j) {
        cout << colSums[j] << "\t";
    }
    cout << "|  " << totalSum << endl;
}

void task3() {
    const int rows1 = 5, cols1 = 10;
    const int rows2 = 5, cols2 = 5;

    int arr1[rows1][cols1];
    int arr2[rows2][cols2];

    srand(time(0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            arr1[i][j] = rand() % 51;
        }
    }

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            arr2[i][j] = arr1[i][j * 2] + arr1[i][j * 2 + 1];
        }
    }

    cout << "Перший масив:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cout << arr1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nДругий масив:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // task1();
    // task2();
    task3();

    return 0;
}