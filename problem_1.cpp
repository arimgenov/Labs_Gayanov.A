#include <iostream>
#include <chrono>
#include <random>
#include <fstream>



int main() {
    int array[300000];
    for (int i = 0; i < 300000; i++) {
        array[i] = i+1;
    }

    std::ofstream out;
    out.open("points.txt");
    
    std::cout << array[0] << " Uspex\n";

    out.close();
    return 0;
}
