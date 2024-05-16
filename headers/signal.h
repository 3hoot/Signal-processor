#ifndef NOISE_H
#define NOISE_H

#include <vector>
#include <functional>
#include <string_view>
#include <random>

namespace signal
{
    class Signal
    {
    public:
        Signal(const double start, const double end, const int samples, std::function<double(double)> = [](auto x)
                                                                        { return x; });
        Signal(const std::vector<double> &t, const std::vector<double> &y)
            : m_t{t}, m_y{y} {};
        Signal() = default;
        ~Signal() = default;

        // getters
        const std::vector<double> &getT() const { return m_t; };
        const std::vector<double> &getY() const { return m_y; };

        // basic operations
        Signal operator+(const Signal rho) const;
        Signal operator-(const Signal rho) const;

        // presentation method
        void show(const std::string_view format_specifiaction = "") const;

        // noise method (irreversible!)
        void addNoise(const double amplitude);

    protected:
        std::vector<double> m_t{};
        std::vector<double> m_y{};
    };
}

#endif
