
#include <vector>

#include "signal.h"
#include "threshold.h"

signal::Signal signal::threshold(const signal::Signal &base, double threshold)
{
    std::vector<double> y{};
    for (const auto &element : base.getY())
    {
        y.push_back(element >= threshold ? 1 : 0);
    }

    return {base.getT(), y};
}
