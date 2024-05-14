#ifndef GENERIC_H
#define GENERIC_H

#include <vector>

namespace signal
{
    enum class SignalType
    {
        Sine,
        Cosine,
        Square,
        Triangle,
        Sawtooth
    };

    std::vector<double> generate(SignalType type, double frequency, double amplitude, double duration, double samplingFrequency);
}

#endif
