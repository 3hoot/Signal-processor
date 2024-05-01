#include <pybind11/pybind11.h>
#include <matplot/matplot.h>

#include <cmath>

namespace py = pybind11;

void testPlot()
{
    using namespace matplot;
    std::vector<double> x = linspace(0, 2 * pi, 50);

    std::vector<std::vector<double>> Y(2);
    Y[0] = transform(x, [](auto x)
                     { return cos(x); });
    Y[1] = transform(x, [](auto x)
                     { return 0.5 * sin(x); });

    stem(Y, "-o");

    show();
}

PYBIND11_MODULE(Signal_processor, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("testPlot", &testPlot, "A function which displays example plot");
}
