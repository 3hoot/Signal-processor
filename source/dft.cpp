
#include <complex>
#include <vector>
#include <cmath>
#include <corecrt_math_defines.h>

#include <matplot/matplot.h>

#include "signal.h"
#include "dft.h"

namespace mp = matplot;

signal::DFTSignal::DFTSignal(const Signal &base)
{
    for (const auto &element : base.getT())
    {
        m_t.push_back(element);
    }

    std::vector<std::complex<double>> x{};
    for (const auto &element : base.getY())
    {
        x.push_back({element, 0});
    }

    const std::vector<std::complex<double>> X{inner::DFT(x)};
    for (const auto &element : X)
    {
        m_y.push_back(element.real());
        m_i.push_back(element.imag());
    }
}

signal::Signal signal::reverseDFT(const DFTSignal &base)
{
    std::vector<std::complex<double>> X{};
    for (int i{0}; i < base.getI().size(); ++i)
    {
        X.push_back({base.getY()[i], base.getI()[i]});
    }

    std::vector<std::complex<double>> x{inner::revDFT(X)};
    std::vector<double> moduli{};
    for (const auto &element : x)
    {
        moduli.push_back(std::sqrt(element.imag() * element.imag() + element.real() * element.real()));
    }

    return {base.getT(), moduli};
}

void signal::DFTSignal::showImaginary(const std::string_view format_specifiaction) const
{
    mp::plot(m_t, m_i, format_specifiaction);
    mp::show();
}

void signal::DFTSignal::showModulus(const std::string_view format_specifiaction) const
{
    std::vector<double> moduli{};
    for (int i{0}; i < m_i.size(); ++i)
    {
        moduli.push_back(std::sqrt(m_i[i] * m_i[i] + m_y[i] * m_y[i]));
    }

    mp::plot(m_t, moduli, format_specifiaction);
    mp::show();
}

signal::DFTSignal signal::DFTSignal::operator+(const signal::DFTSignal &rho) const
{
    std::vector<double> t;
    std::vector<double> y;
    std::vector<double> i;

    // Check if the sizes of the signals are the same
    if (m_t.size() != rho.m_t.size() || m_y.size() != rho.m_y.size() || m_i.size() != rho.m_i.size())
    {
        throw std::runtime_error("Signal sizes do not match");
    }

    // Perform element-wise addition
    for (int j = 0; j < m_t.size(); ++j)
    {
        t.push_back(m_t[j] + rho.m_t[j]);
        y.push_back(m_y[j] + rho.m_y[j]);
        i.push_back(m_i[j] + rho.m_i[j]);
    }

    return {t, y, i};
}

signal::DFTSignal signal::DFTSignal::operator-(const signal::DFTSignal &rho) const
{
    std::vector<double> t;
    std::vector<double> y;
    std::vector<double> i;

    // Check if the sizes of the signals are the same
    if (m_t.size() != rho.m_t.size() || m_y.size() != rho.m_y.size() || m_i.size() != rho.m_i.size())
    {
        throw std::runtime_error("Signal sizes do not match");
    }

    // Perform element-wise subtraction
    for (int j = 0; j < m_t.size(); ++j)
    {
        t.push_back(m_t[j] - rho.m_t[j]);
        y.push_back(m_y[j] - rho.m_y[j]);
        i.push_back(m_i[j] - rho.m_i[j]);
    }

    return {t, y, i};
}

std::vector<std::complex<double>> signal::inner::DFT(const std::vector<std::complex<double>> &x)
{
    size_t N = x.size();

    std::complex<double> sum;

    std::vector<std::complex<double>> X(N);

    for (int k = 0; k < N; k++)
    {
        sum = (0.0, 0.0);
        for (int n = 0; n < N; n++)
        {
            double Re = cos((2 * M_PI) / N * k * n);
            double Im = sin((2 * M_PI) / N * k * n);
            std::complex t(Re, -Im);

            sum += x[n] * t;
        }
        X[k] = sum;
    }

    return X;
}

std::vector<std::complex<double>> signal::inner::revDFT(const std::vector<std::complex<double>> &A)
{
    size_t N = A.size();

    std::complex<double> sum;

    std::vector<std::complex<double>> a(N);

    for (int k = 0; k < N; k++)
    {
        sum = (0.0, 0.0);
        for (int n = 0; n < N; n++)
        {
            double Re = cos((2 * M_PI) / N * k * n);
            double Im = sin((2 * M_PI) / N * k * n);
            std::complex t(Re, Im);

            sum += A[n] * t;
        }
        sum /= static_cast<double>(N);

        a[k] = sum;
    }

    return a;
}
