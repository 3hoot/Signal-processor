
#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // conversion between C++ and Python types

#include "noise.h"
#include "plot.h"

PYBIND11_MODULE(signal, handle)
{
    handle.doc() = "pybind11 signal processing module"; // optional module docstring

    // functions
    handle.def("show", &signal::show);
    handle.def("noise", &signal::getNoise);
}
