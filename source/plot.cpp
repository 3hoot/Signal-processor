
#include <vector>
#include <matplot/matplot.h>

#include "plot.h"

void signal::show(const std::vector<double> &data)
{
    matplot::plot(data);
    matplot::show();
}
