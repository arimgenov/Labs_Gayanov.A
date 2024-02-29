#include <iostream>
#include <random>


void swap(int arr[], int i, int j) { // меняет местами
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp; 
}

void synthesis (int n, int a_1[], int m, int a_2[]) { // обьединет упорядоченные массивы

}

void fastsort(int n, int arr[]) {
    int mid = n/2, l = 0, r = n-1;
    while (l < mid and r > mid) {
        if (arr[l] > arr[mid]) {
            if (arr[r] < arr[mid]) {
                swap(arr, l, r);
                l++;
            } else {
                r--;
            }
        } else {
            l++;
        }
    }
}

void merge(int n, int arr[]) {

}

void bubble(int n, int arr[]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
}

void selection(int n, int arr[]) {
    for (int i=0; i<n; i++) {
        int min = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr, i, min);
    }
}

void insertion(int n, int arr[]) {
    std::cout << std::endl;
    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            } else {
                break;
            }
        }   
    }
}


int main() {
    int n=40;
    std::random_device random_device;
    std::mt19937 generator(random_device()); 
    std::uniform_int_distribution<> distribution(0, n); // Генератор случайных чисел
    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = distribution(generator); // случайный массив
    }

    for (int i=0; i<n; i++) {
    std::cout << arr[i] << " "; // вывод отсортированного массива
    }
    std::cout << "\n";

    // bubble(n, arr);
    // selection(n, arr);
    // insertion(n, arr);
    fastsort(n, arr);
    // merge(n, arr);

    for (int i=0; i<n; i++) {
    std::cout << arr[i] << " "; // вывод отсортированного массива
    }

    return 0;
}