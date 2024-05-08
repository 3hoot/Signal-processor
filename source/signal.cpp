
#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // conversion between C++ and Python types

#include "noise.h"
#include "plot.h"

namespace py = pybind11;

PYBIND11_MODULE(signal, handle)
{
    handle.doc() = "pybind11 signal processing module"; // optional module docstring

    handle.def("show", &signal::show);
    handle.def("noise", &signal::getNoise);
}
