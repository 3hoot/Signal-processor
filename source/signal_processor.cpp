#include <pybind11/pybind11.h>

namespace py = pybind11;

int sum(int a, int b) { return a + b; }

PYBIND11_MODULE(example, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("sum", &sum, "A function which adds two numbers");
}
