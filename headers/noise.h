#ifndef NOISE_H
#define NOISE_H

#include <vector>

namespace signal
{
    std::vector<double> getNoise(double amplitude, int size);

    void addNoise(std::vector<double> &data, double amplitude);
}

#endif
