#ifndef DFT_H
#define DFT_H

#include <vector>
#include <complex>

namespace signal
{
    std::vector<std::complex<double>> DFT(std::vector<std::complex<double>> x);
    std::vector<std::complex<double>> revDFT(std::vector<std::complex<double>> A);
    std::vector<double> norm(std::vector<std::complex<double>> comnumber);
    std::vector<std::complex<double>> rtoc(std::vector<double> rel);
}

#endif
