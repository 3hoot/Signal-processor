#ifndef NOISE_H
#define NOISE_H

#include <vector>
#include <functional>
#include <string_view>
#include <random>

namespace signal
{
    class Basic
    {
    public:
        Basic(const double start, const double end, const int samples, std::function<double(double)> = [](auto x)
                                                                       { return x; });
        ~Basic() = default;

        // getters
        const std::vector<double> &getX() const { return m_x; };
        const std::vector<double> &getY() const { return m_y; };

        // presentation method
        void show(const std::string_view format_specifiaction = "") const;

        // noise method (irreversible!)
        void addNoise(const double amplitude);

    protected:
        std::vector<double> m_x{};
        std::vector<double> m_y{};
    };
}

#endif
