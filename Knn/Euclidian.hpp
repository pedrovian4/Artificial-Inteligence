#pragma once
#include "DistanceMetric.hpp"
#include <vector>
#include <cmath>

template <typename T>
class Euclidian : public DistanceMetric<T>
{
    public:
        double calculate (const std::vector<T>& a, const std::vector<T>& b) const override
        {
            double sum = 0.0;
            for(size_t i = 0; i < a.size(); i++)
            {
                sum+=std::pow(a[i] -b[i],2);
            }
            return std::sqrt(sum);
        };
};