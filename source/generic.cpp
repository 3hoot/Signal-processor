
#include <cmath>
#include <functional>

#include "generic.h"

std::function<double(double)> signal::sin(const Wave &chrs)
{
    return [=](double x)
    { return chrs.amplitude * std::sin(chrs.frequency * x - chrs.offset); };
}

std::function<double(double)> signal::cos(const Wave &chrs)
{
    return [=](double x)
    { return chrs.amplitude * std::cos(chrs.frequency * x - chrs.offset); };
}

std::function<double(double)> signal::square(const Wave &chrs)
{
    return [=](double x)
    { return chrs.amplitude * std::sin(chrs.frequency * x - chrs.offset) > 0 ? 1 : -1; };
}

std::function<double(double)> signal::sawtooth(const Wave &chrs)
{
    return [=](double x)
    {
        double phase = x * chrs.frequency;
        phase = phase - std::floor(phase);                         // normalize phase to [0, 1)
        return chrs.amplitude * (2.0 * phase - 1.0) - chrs.offset; // map phase to [-1, 1) and add offset
    };
}
