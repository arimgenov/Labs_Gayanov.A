#include <iostream>
#include <chrono>
#include <random>
#include <fstream>


int search_kv(int n, int arr[], int x) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i] + arr[j] == x) {
                // y = i;
                // z = j;
                break; 
            }
        }
    }
    return 0;
}

int search_lin(int n, int arr[], int x) {
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
    return 0;
}


int main() {
    int k = 500000;
    int array[k];
    for (int i = 0; i < k; i++) {
        array[i] = i+1;
    }

    std::ofstream out;

    out.open("points_ty_lin.txt");
    std::cout << "n" << " " << "ty_lin" << "\n"; // изза того что долго работает поделил выводы
    out << "n" << " " << "ty_lin" << "\n";

    // out.open("points_ty_kv.txt");
    // std::cout << "n" << " " << "ty_kv" << "\n";
    // out << "n" << " " << "ty_kv" << "\n";


    for (int n=k/50; n<=k; n+=k/50) {
        int y = 0; // худший случай
        int ky_lin = 1, ky_kv = 0; // ky_per - количество повторений худшего случая
        int ty_lin = 0, ty_kv = 0;



        for (int i=0; i<ky_lin; i++) {
        auto begin_lin = std::chrono::steady_clock::now();
        search_lin(n, array, y);
        auto end_lin = std::chrono::steady_clock::now();
        auto time_span_lin = std::chrono::duration_cast<std::chrono::microseconds>(end_lin - begin_lin);
        ty_lin += time_span_lin.count();
        }

        for (int i=0; i<ky_kv; i++) {
        auto begin_kv = std::chrono::steady_clock::now();
        search_kv(n, array, y);
        auto end_kv = std::chrono::steady_clock::now();
        auto time_span_kv = std::chrono::duration_cast<std::chrono::milliseconds>(end_kv - begin_kv);
        ty_kv += time_span_kv.count();
        }



        ty_lin /= ky_lin; // вывод в файл
        std::cout << n << " " << ty_lin << "\n"; 
        out << n << " " << ty_lin << "\n";

        // ty_kv /= ky_kv;
        // std::cout << n << " " << ty_kv << "\n";
        // out << n << " " << ty_kv << "\n";

    }

    out.close();
    return 0;
}
