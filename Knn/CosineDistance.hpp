#pragma once

#include "DistanceMetric.hpp"
#include <cmath>
#include <vector>

template <typename T>
class CosineDistance : public DistanceMetric<T> {
public:
    double calculate(const std::vector<T>& a, const std::vector<T>& b) const override {
        double dot_product = 0.0;
        double norm_a = 0.0;
        double norm_b = 0.0;

        for (size_t i = 0; i < a.size(); ++i) {
            dot_product += a[i] * b[i];
            norm_a += std::pow(a[i], 2);
            norm_b += std::pow(b[i], 2);
        }

        return 1.0 - (dot_product / (std::sqrt(norm_a) * std::sqrt(norm_b)));
    }
};
