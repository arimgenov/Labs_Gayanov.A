#include <iostream>
#include <chrono>
#include <random>
#include <fstream>


int search_ln(int n, int arr[], int x) {
    int l = 0, r = n-1, s;
    while (r > l and r != l+1) {
        s = (l + r)/2;
        if (arr[s] == x) {
            // y = s;
            break;
        } else if (arr[s] > x) {
            r = s;
        } else {
            l = s;
        }
        // std::cout << l << " " << r << "\n";
    }
    return 0;
}

int search_lin(int n, int arr[], int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            // y = i;
            break;
        }
    }
    return 0;
}


int main() {
    const int k = 500000; // макс колво элементов
    int array[k];
    for (int i = 0; i<k; i++) {
        array[i] = i+1;
    }

    std::ofstream out;
    out.open("points_1.txt");
    std::cout << "n" << " " << "tx_ln" << " " << "ty_ln" << " " << "tx_lin" << " " << "ty_lin" << "\n";
    out << "n" << " " << "tx_ln" << " " << "ty_ln" << " " << "tx_lin" << " " << "ty_lin" << "\n";
    
    for (int n=k/50; n<=k; n+=k/50) {
        std::random_device random_device;
        std::mt19937 generator(random_device()); 
        std::uniform_int_distribution<> distribution(0, n); // Генератор случайных чисел
        const int y = 0; // худший случай
        const int ky = 100, kx = 100; // ky - количество повторений худшего случая, kx среднего
        int ty_lin = 0, ty_ln = 0, tx_lin = 0, tx_ln=0;

        for (int i = 0; i < kx; i ++) { // проверяем средний случай 10000 раз
        int x = distribution(generator); // Случайное число от 0 до n



        auto begin_lin = std::chrono::steady_clock::now();
        search_lin(n, array, x);
        auto end_lin = std::chrono::steady_clock::now();
        auto time_span_lin = std::chrono::duration_cast<std::chrono::microseconds>(end_lin - begin_lin);
        tx_lin += time_span_lin.count();

        auto begin_ln = std::chrono::steady_clock::now();
        search_ln(n, array, x);
        auto end_ln = std::chrono::steady_clock::now();
        auto time_span_ln = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ln - begin_ln);
        tx_ln += time_span_ln.count();
        }

        for (int i = 0; i < ky; i ++) { // проверяем худший случай 1000 раз

        auto begin_lin = std::chrono::steady_clock::now();
        search_lin(n, array, y);
        auto end_lin = std::chrono::steady_clock::now();
        auto time_span_lin = std::chrono::duration_cast<std::chrono::microseconds>(end_lin - begin_lin);
        ty_lin += time_span_lin.count();

        auto begin_ln = std::chrono::steady_clock::now();
        search_ln(n, array, y);
        auto end_ln = std::chrono::steady_clock::now();
        auto time_span_ln = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ln - begin_ln);
        ty_ln += time_span_ln.count();
        }



        ty_lin /= ky;
        ty_ln /= ky;
        tx_lin /= kx;
        tx_ln /= kx; // среднее время

        std::cout << n << " " << tx_ln << " " << ty_ln << " " << tx_lin << " " << ty_lin << "\n";
        out << n << " " << tx_ln << " " << ty_ln << " " << tx_lin << " " << ty_lin << "\n";

    }

    out.close();
    return 0;
}
