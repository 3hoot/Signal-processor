
#include <random>
#include <vector>

#include "noise.h"

std::vector<double> signal::getNoise(double amplitude, int size)
{
    std::vector<double> noise;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dist(0, amplitude);

    for (int i = 0; i < size; i++)
    {
        noise.push_back(dist(gen));
    }
    return noise;
}

void signal::addNoise(std::vector<double> &data, double amplitude)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dist(0, amplitude);

    for (double &value : data)
    {
        value += dist(gen);
    }
}
