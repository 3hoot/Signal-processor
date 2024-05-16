#ifndef DFT_H
#define DFT_H

#include <vector>
#include <complex>

namespace signal
{
    std::vector<double> DFT(std::vector<std::complex<double>> x);
    std::vector<double> revDFT(std::vector<std::complex<double>> A);
    //std::vector<double> getSignal(std::vector<double> &signal);
}

#endif
