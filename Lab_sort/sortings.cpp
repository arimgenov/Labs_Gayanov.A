#include <iostream>
#include <random>
#include <algorithm>

const int n = 20;

void swap(int arr[], int i, int j) { // меняет местами
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp; 
}

void bubble(int n, int arr[]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) swap(arr, j, j+1);
        }
    }
}

void selection(int n, int arr[]) {
    for (int i=0; i<n; i++) {
        int min = i;
        for (int j=i+1; j<n; j++) if (arr[j] < arr[min]) min = j;
        swap(arr, i, min);
    }
}

void insertion(int n, int arr[]) {
    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (arr[j] > arr[j+1]) swap(arr, j, j+1);
            else break;
        }   
    }
}

void merge(int arr[], int l, int r) {
    if (l == r) return;
    int mid = (l+r)/2;
    merge(arr, l, mid);
    merge(arr, mid+1, r);

    int brr[n], k=l, i=l, j=mid+1;

    while (k <= r) {
        if (i > mid) brr[k++] = arr[j++];
        else if (j > r) brr[k++] = arr[i++];
        else {
            if (arr[i] <= arr[j]) brr[k++] = arr[i++];
            else brr[k++] = arr[j++];
        }
    }
    
    for(int i=l; i<=r; i++) arr[i] = brr[i];
}

void quicksort(int arr[], int l, int r){
  if (l < r) {
    int x = arr[(l+r)/2], i = l, j = r;
    while(i <= j) {
      while(arr[i] < x) i++;
      while(arr[j] > x) j--;
      if(i<=j) swap(arr, i++, j--); }
    quicksort(arr, l, j);
    quicksort(arr, i, r);
  }
}




int main() {
    std::random_device random_device;
    std::mt19937 generator(random_device()); 
    std::uniform_int_distribution<> distribution(1, n); // Генератор случайных чисел
    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = distribution(generator); // случайный массив
    }

    for (int i=0; i<n; i++) {
    std::cout << arr[i] << " "; // вывод массива
    }
    std::cout << "\n";

    // bubble(n, arr);
    // selection(n, arr);
    // insertion(n, arr);
    // quicksort(arr, 0, n-1); // выбери своего бойца
    merge(arr, 0, n-1);

    for (int i=0; i<n; i++) {
    std::cout << arr[i] << " "; // вывод отсортированного массива
    }
    std::cout << "\n";

    return 0;
}