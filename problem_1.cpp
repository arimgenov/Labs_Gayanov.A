#include <iostream>
#include <chrono>
#include <random>
#include <fstream>



int main() {
    int array[200000];
    for (int i = 0; i < 200000; i++) {
        array[i] = i+1;
    }

    std::ofstream out;
    out.open("points.txt");
    
    

    out.close();
    return 0;
}
