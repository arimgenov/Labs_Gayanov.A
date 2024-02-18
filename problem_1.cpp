#include <iostream>
#include <chrono>
#include <random>
#include <fstream>


void search_kv(int x, int arr[], int n) {
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

void search_lin(int x, int arr[], int n) {

}


int main() {
    int k = 500000;
    int y = 0;
    int array[k];
    for (int i = 0; i < k; i++) {
        array[i] = i+1;
    }

    

    std::ofstream out;
    out.open("points.txt");
    





    out.close();
    return 0;
}
