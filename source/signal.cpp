
#include <matplot/matplot.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // conversion between C++ and Python types
#include <pybind11/functional.h>

#include <vector>
#include <functional>
#include <string_view>
#include <random>

#include "signal.h"
#include "generic.h"

namespace mp = matplot;
namespace py = pybind11;

// submodules from different files
void INIT_signal_processing_submodule1(py::module &);

PYBIND11_MODULE(signal_processing, handle)
{
    py::class_<signal::Basic>(handle, "Basic")
        .def(py::init<double, double, int, std::function<double(double)>>())
        .def("show", &signal::Basic::show, py::arg("format_specification"))
        .def("addNoise", &signal::Basic::addNoise, py::arg("amplitude"));

    py::class_<signal::Wave>(handle, "Wave")
        .def(py::init<double, double, double>())
        .def_readwrite("amplitude", &signal::Wave::amplitude)
        .def_readwrite("frequency", &signal::Wave::frequency)
        .def_readwrite("offset", &signal::Wave::offset);

    handle.def("sin", &signal::sin);
    handle.def("cos", &signal::cos);
    handle.def("square", &signal::square);
    handle.def("sawtooth", &signal::sawtooth);
}

signal::Basic::Basic(const double start, const double end, const int samples, std::function<double(double)> function)
    : m_t{mp::linspace(start, end, static_cast<size_t>(samples))},
      m_y{mp::transform(m_t, function)}
{
}

void signal::Basic::show(const std::string_view format_specifiaction) const
{
    mp::plot(m_t, m_y, format_specifiaction);
    mp::show();
}

void signal::Basic::addNoise(const double amplitude)
{
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(-amplitude, amplitude);

    // Add random noise to each element of m_y
    for (double &value : m_y)
    {
        value += distribution(gen);
    }
}
