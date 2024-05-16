#ifndef GENERIC_H
#define GENERIC_H

#include <cmath>
#include <functional>

namespace signal
{
    // simple struct to hold wave characteristics
    struct Wave
    {
        double frequency{0};
        double amplitude{0};
        double offset{0};
    };

    // generic functions
    // can be used as lambas to initialize
    std::function<double(double)> sin(const Wave &chrs);
    std::function<double(double)> cos(const Wave &chrs);
    std::function<double(double)> square(const Wave &chrs);
    std::function<double(double)> sawtooth(const Wave &chrs);
}

#endif
