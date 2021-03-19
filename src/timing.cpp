/**
 * Time code for algorithms performance tests
 */
#include<iostream>
#include<chrono>

#define TMAX 10000
#define RUNS 10

int main(void){

    double products[10][10] = {0};

    // ~~~~~~~~~~~~~~~~~~~~
    // Timing starts here
    long average = 0;

    for(int r=0; r<RUNS; r++){
        auto start = std::chrono::high_resolution_clock::now();

        for(int t=0; t<TMAX; t++){ // write the code you want to test here:
            for(int ix=0; ix<10; ix++)
                for(int iy=0; iy<10; iy++)
                    for(int i=0; i<1000; i++)
                        products[ix][iy] += i;
        }

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        average += duration.count();

        std::cout << "\tTime in run " << r+1 <<": " << duration.count() << " ms" << std::endl;
    }

    average /= RUNS;

    std::cout << "Average time: " << average << " ms" << std::endl;

    // Up to here
    // ~~~~~~~~~~~~~~~~~~~~

    std::cout << products[0] << std::endl;


    return 0;
}