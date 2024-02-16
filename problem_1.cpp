#include <iostream>
#include <chrono>
#include <random>


void search_ln(int n, int arr[], int x) {
    int l = 0, r = n-1, s;
    while (r >= l) {
        s = (l + r)/2;
        if (arr[s] == x) {
            // y = s;
            break;
        } else if (arr[s] > x) {
            r = s - 1;
        } else {
            l = s + 1;
        }
    }
}

void search_lin(int n, int arr[], int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            // y = i;
            break;
        }
    }
}


int main() {
    int tame_arr[1000];
    int array[100000];

    for (int i = 0; i < 100000; i++) {
        array[i] = i;
    }

    for (int n=100; n<=1000000; n+=100) {
        std::random_device random_device;
        std::mt19937 generator(random_device()); 
        std::uniform_int_distribution<> distribution(0, n); // Генератор случайных чисел

        int x = distribution(generator); // Случайное число от 0 до n

    }



    // auto begin = std::chrono::steady_clock::now(); // запуск таймера
    // auto end = std::chrono::steady_clock::now(); // остановка таймера
    // auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    
    return 0;
}
