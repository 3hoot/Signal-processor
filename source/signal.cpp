
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
#include "dft.h"

namespace mp = matplot;
namespace py = pybind11;

// submodules from different files
void INIT_signal_processing_submodule1(py::module &);

PYBIND11_MODULE(signal_processing, handle)
{
    py::class_<signal::Signal>(handle, "Signal")
        .def(py::init<double, double, int, std::function<double(double)>>())
        .def(py::init<std::vector<double>, std::vector<double>>())
        .def("show", &signal::Signal::show, py::arg("format_specification"))
        .def("addNoise", &signal::Signal::addNoise, py::arg("amplitude"))
        .def("__add__", [](const signal::Signal &self, const signal::Signal &other)
             { return self + other; })
        .def("__sub__", [](const signal::Signal &self, const signal::Signal &other)
             { return self - other; });

    py::class_<signal::Wave>(handle, "Wave")
        .def(py::init<double, double, double>())
        .def_readwrite("amplitude", &signal::Wave::amplitude)
        .def_readwrite("frequency", &signal::Wave::frequency)
        .def_readwrite("offset", &signal::Wave::offset);

    py::class_<signal::DFTSignal>(handle, "DFTSignal")
        .def(py::init<const signal::Signal &>())
        .def("show", &signal::DFTSignal::show, py::arg("format_specification"))
        .def("showImaginary", &signal::DFTSignal::showImaginary, py::arg("format_specification"))
        .def("showModulus", &signal::DFTSignal::showModulus, py::arg("format_specification"))
        .def("__add__", [](const signal::DFTSignal &self, const signal::DFTSignal &other)
             { return self + other; })
        .def("__sub__", [](const signal::DFTSignal &self, const signal::DFTSignal &other)
             { return self - other; });

    handle.def("sin", &signal::sin);
    handle.def("cos", &signal::cos);
    handle.def("square", &signal::square);
    handle.def("sawtooth", &signal::sawtooth);
}

signal::Signal::Signal(const double start, const double end, const int samples, std::function<double(double)> function)
    : m_t{mp::linspace(start, end, static_cast<size_t>(samples))},
      m_y{mp::transform(m_t, function)}
{
}

void signal::Signal::show(const std::string_view format_specifiaction) const
{
    mp::plot(m_t, m_y, format_specifiaction);
    mp::show();
}

void signal::Signal::addNoise(const double amplitude)
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

signal::Signal signal::Signal::operator+(const signal::Signal rho) const
{
    // Check if the sizes of m_y are equal
    if (m_y.size() != rho.m_y.size())
    {
        throw std::runtime_error("Cannot add signals with different sizes");
    }

    // Create a new Signal object to store the result
    signal::Signal result(*this);

    // Add the corresponding elements of m_y and rho.m_y
    for (size_t i = 0; i < m_y.size(); ++i)
    {
        result.m_y[i] += rho.m_y[i];
    }

    return result;
}

signal::Signal signal::Signal::operator-(const signal::Signal rho) const
{
    // Check if the sizes of m_y are equal
    if (m_y.size() != rho.m_y.size())
    {
        throw std::runtime_error("Cannot subtract signals with different sizes");
    }

    // Create a new Signal object to store the result
    signal::Signal result(*this);

    // Subtract the corresponding elements of m_y and rho.m_y
    for (size_t i = 0; i < m_y.size(); ++i)
    {
        result.m_y[i] -= rho.m_y[i];
    }

    return result;
}
