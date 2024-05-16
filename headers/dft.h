#ifndef DFT_H
#define DFT_H

#include <vector>
#include <complex>

#include "signal.h"

namespace signal
{
    class DFTSignal : public Signal
    {
    public:
        DFTSignal(const Signal &x);
        DFTSignal(const std::vector<double> &t, const std::vector<double> &y, const std::vector<double> &i)
            : Signal{t, y}, m_i{i} {};
        ~DFTSignal() = default;

        // getters
        const std::vector<double> &getI() const { return m_i; };

        // basic operations
        DFTSignal operator+(const DFTSignal &rho) const;
        DFTSignal operator-(const DFTSignal &rho) const;

        // presentation method
        void showImaginary(const std::string_view format_specifiaction = "") const;
        void showModulus(const std::string_view format_specifiaction = "") const;

    private:
        std::vector<double> m_i{}; // holds imaginary part
    };

    Signal reverseDFT(const DFTSignal &X);

    // inner functions
    // shouldn't be used outside
    namespace inner
    {
        std::vector<std::complex<double>> DFT(const std::vector<std::complex<double>> &x);
        std::vector<std::complex<double>> revDFT(const std::vector<std::complex<double>> &A);
    }

}

#endif
