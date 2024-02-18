#include <iostream>
#include <chrono>
#include <random>
#include <fstream>


void search_kv(int n, int arr[], int x) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i] + arr[j] == x) {
                // y = i;
                // z = j;
                break; 
            }
        }
    }
}

void search_lin(int n, int arr[], int x) {
    int l = 0, r = n-1;
    while (r > l) {
        if (arr[l] + arr[r] == x) {
            // y = l+1;
            // z = r+1;
            break; 
        } else if (arr[l] + arr[r] > x) {
            r--;
        } else {
            l++;
        }
    }
}


int main() {
    int k = 500000;
    int array[k];
    for (int i = 0; i < k; i++) {
        array[i] = i+1;
    }

    std::ofstream out;
    out.open("points.txt");
    std::cout << "n" << " " << "tx_kv" << " " << "ty_kv" << " " << "tx_lin" << " " << "ty_lin" << "\n";
    out << "n" << " " << "tx_kv" << " " << "ty_kv" << " " << "tx_lin" << " " << "ty_lin" << "\n";

    for (int n=k/50; n<=k; n+=k/50) {
        std::random_device random_device;
        std::mt19937 generator(random_device()); 
        std::uniform_int_distribution<> distribution(0, n); // Генератор случайных чисел
        int y = 0; // худший случай
        int ky = 1000, kx = 1000; // ky - количество повторений худшего случая, kx среднего
        int ty_lin = 0, ty_kv = 0, tx_lin = 0, tx_kv=0;

        for (int i=0; i<ky; i++) {
        auto begin_lin = std::chrono::steady_clock::now();
        search_lin(n, array, y);
        auto end_lin = std::chrono::steady_clock::now();
        auto time_span_lin = std::chrono::duration_cast<std::chrono::microseconds>(end_lin - begin_lin);

        ty_lin += time_span_lin.count();
        }

        ty_lin /= ky;

        std::cout << n << " " << ty_lin << "\n";
        out << n << " " << ty_lin << "\n";

    }

    out.close();
    return 0;
}
