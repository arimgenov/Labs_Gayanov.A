#include <iostream>
#include <random>
#include <algorithm>

const int n = 40;

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

void quicksort(int arr[], int l, int r) {
  if (l < r) {
    int x = arr[(l+r)/2], i = l, j = r;
    while(i <= j) {
      while(arr[i] < x) i++;
      while(arr[j] > x) j--;
      if(i<=j) swap(arr, i++, j--);}
    quicksort(arr, l, j);
    quicksort(arr, i, r);
  }
}

void see(int n, int arr[]) { // выводит массив в виде кучи
    int s=1, k=2;
    while (s-1<n){
        if (s==k) {
        k *= 2;
        std::cout << std::endl;
        }
        std::cout << arr[s-1] << " ";
        s++;
    }
    std::cout << "\n";
    std::cout << "\n";
}

void heapswap(int arr[], int h, int j) { // выберает упорядочивание для родителя и его детей
    int l = 2*h+2, r = 2*h+1;
    if (l<j and arr[l] > arr[h] and arr[l] >= arr[r]) {
        swap(arr, l, h);
        heapswap(arr, l, j);
    } else if (r<j and arr[r] > arr[h]) {
        swap(arr, r, h);
        heapswap(arr, r, j);
    }
}

void heapsort(int n, int arr[]) {
    for(int i=n/2; i>=0; i--) { // создаем максимальную кучу
        heapswap(arr, i, n);
    }
    for(int j=n-1; j>0; j--){
        swap(arr, 0, j);
        heapswap(arr, 0, j);
    }
}


int main() {
    std::random_device random_device;
    std::mt19937 generator(random_device()); 
    std::uniform_int_distribution<> distribution(1, n); // Генератор случайных чисел
    int arr[n];
    for (int i=0; i<n; i++) arr[i] = distribution(generator); // случайный массив

    for (int i=0; i<n; i++) std::cout << arr[i] << " "; // вывод массива
    std::cout << "\n";

    // bubble(n, arr);
    // selection(n, arr);
    // insertion(n, arr);
    // quicksort(arr, 0, n-1); // выбери своего бойца
    // merge(arr, 0, n-1);
    heapsort(n, arr);

    for (int i=0; i<n; i++) std::cout << arr[i] << " "; // вывод отсортированного массива
    std::cout << "\n";

    return 0;
}