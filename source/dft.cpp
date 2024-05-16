#include <complex>
#include <vector>
#include <cmath>
#include <corecrt_math_defines.h>

#include "dft.h"
//DFT function
std::vector<double> signal::DFT(std::vector<std::complex<double>> x)
{
    int N = x.size();

    std::complex<double> sum;

    std::vector<double> X(N);

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
        double value = pow(std::real(sum), 2) + pow(std::imag(sum), 2);
        X.push_back(value);
    }

    return X;
}
//Reverse DFT function
std::vector<double> signal::revDFT(std::vector<std::complex<double>> A)
{
   int N = A.size();

    std::complex<double> sum;

    std::vector<double> a(N);

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
        double value = pow(std::real(sum), 2) + pow(std::imag(sum), 2);
        a.push_back(value);
    }

    return a;
}

// std::vector<double> signal::getSignal(std::vector<double> &signal)
// {
//     int a = signal.size();

//     std::vector<std::complex<double>> test;

//     for(int i = 0; i < a; i++)
//     {
//         test[i] = (&signal, 0.0);
//     }

//     std::vector<double> test1 = DFT(test);


//     return test1;
// }