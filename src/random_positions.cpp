/**
 * Generate an array (or vector) of random integers.
 */
#include<iostream>
#include<vector>

#include"random64.h"


int main(void){
    CRandom ran(1);

    unsigned int N = 10;

    std::vector<unsigned int> values;
    for(int i=0; i<N; i++) values.push_back(i);

    std::vector<unsigned int> random_positions_vector;

    while(values.size() != 0){
        unsigned int pos = (unsigned int)values.size()*ran.r();

        random_positions_vector.push_back(values[pos]);
        values.erase(values.begin() + pos);
    }

    unsigned int random_positions_array[N] = {0};

    for(int i=0; i<N; i++) random_positions_array[i] = random_positions_vector[i];

    return 0;
}