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
    

    for (int n=k/50; n<=k; n+=k/50) {
        int y = 0;

        auto begin_lin = std::chrono::steady_clock::now();
        search_lin(n, array, y);
        auto end_lin = std::chrono::steady_clock::now();
        auto time_span_lin = std::chrono::duration_cast<std::chrono::microseconds>(end_lin - begin_lin);

        std::cout << time_span_lin.count() << "\n";

    }


    out.close();
    return 0;
}
