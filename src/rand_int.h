#ifndef RAND_INT_H
#define RAND_INT_H
#include <random>

class Rand_int
{
    public:
        Rand_int(int low, int high) :dist{low,high} {}
        int operator()() {return dist(re);}
    private:
        std::default_random_engine re;
        std::uniform_int_distribution<> dist;
};

#endif // RAND_INT_H
