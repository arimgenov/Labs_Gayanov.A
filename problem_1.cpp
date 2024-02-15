#include <iostream>
#include <chrono>
#include <random>


void search_ln(int n, int arr[], int x, int &y) {
    int l = 0, r = n-1, s;
    while (r >= l) {
        s = (l + r)/2;
        if (arr[s] == x) {
            y = s;
            break;
        } else if (arr[s] > x) {
            r = s - 1;
        } else {
            l = s + 1;
        }
    }
}

void search_lin(int n, int arr[], int x, int &y) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            y = i;
            break;
        }
    }
}


int main() {
    int n, x, y; // n - число элементов массива, x - искомый элемент, y - номер элемента (-1 если его нет)
    std::cin >> n >> x;
    int array[n];
    for (int i = 0; i < n; i++) { // вписываю в массив значения
        std::cin >> array[i];
    }

    y = -1;
    search_lin(n, array, x, y);
    std::cout << y << "\n";

    y = -1;
    search_ln(n, array, x, y);
    std::cout << y << "\n";

    return 0;
}
