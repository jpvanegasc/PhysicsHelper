#ifndef __RANDOM64_H
#define __RANDOM64_H
/**
 * Random number generator
 * Author : Jose Daniel Munoz et al.
 */
#include<cmath>

class CRandom{
    unsigned long long u, v, w;
    public:
        CRandom(unsigned long long seed);
        unsigned long long int64(void);
        double r(void);
        unsigned int int32(){return (unsigned int) int64();};
        double exponencial(float tau);
        double gauss(float mu, float sigma);
};

inline double CRandom::r(void){return 5.42101086242752217E-20 * int64();}

CRandom::CRandom(unsigned long long seed){
    v = 4101842887655102017LL; w=1;
    u = seed ^ v; int64();
    v = u; int64();
    w = v; int64();
}
unsigned long long CRandom::int64(void){
    u = u * 2862933555777941757LL + 7046029254386353087LL;
    v ^= v >> 17; v ^= v << 31; v ^= v >> 8;
    w = 4294957665U*(w & 0xffffffff) + (w >> 32);
    unsigned long long x = u ^ (u << 21); x ^= x >> 35; x ^= x << 4;
    
    return (x + v) ^ w;
}
inline double CRandom::exponencial(float tau){
    return -tau*std::log(r());
}
inline double CRandom:: gauss(float mu, float sigma){
    return sigma*std::sqrt(-2*std::log(r()))*std::cos(2*M_PI*r()) + mu;
}

#endif
