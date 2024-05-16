#include <complex>
#include <vector>
#include <cmath>
#include <corecrt_math_defines.h>

#include "dft.h"
//DFT function
std::vector<std::complex<double>> signal::DFT(std::vector<std::complex<double>> x)
{
    int N = x.size();

    std::complex<double> sum;

    std::vector<std::complex<double>> X(N);

    for(int k = 0; k < N; k++)
    {
        sum = (0.0, 0.0);
        for(int n = 0; n < N; n++)
        {
            double Re = cos((2 * M_PI ) / N * k * n);
            double Im = sin((2 * M_PI ) / N * k * n);
            std::complex t (Re, -Im);
            
            sum += x[n] * t; 
        }
        X.push_back(sum);
    }

    return X;
}
//Reverse DFT function
std::vector<std::complex<double>> signal::revDFT(std::vector<std::complex<double>> A)
{
   int N = A.size();

    std::complex<double> sum;

    std::vector<std::complex<double>> a(N);

    for(int k = 0; k < N; k++)
    {
        sum = (0.0, 0.0);
        for(int n = 0; n < N; n++)
        {
            double Re = cos((2 * M_PI ) / N * k * n);
            double Im = sin((2 * M_PI ) / N * k * n);
            std::complex t (Re, Im);
            
            sum += A[n] * t; 
        }
        sum /= N;
        
        a.push_back(sum);
    }

    return a;
}
//returns modulus of a complex number raised to the power of 2
std::vector<double> signal::norm(std::vector<std::complex<double>> comnumber)
{
    int N = comnumber.size();

    std::vector<double> magnitude(N);

    for(int i = 0; i < N; i++)
    {
        magnitude[i] = std::norm(comnumber[i]);
    }

    return magnitude;
}
//double to complex with imaginary = 0
std::vector<std::complex<double>> signal::rtoc(std::vector<double> rel)
{
    int N = rel.size();
    std::vector<std::complex<double>> com(N);

    for(int i = 0; i < N; i++)
    {
        com[i] = (rel[i], 0.0);
    }

    return com;
}