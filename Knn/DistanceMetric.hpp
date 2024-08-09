#pragma once

#include <vector>  

template <typename T>
class DistanceMetric {
public:
    virtual double calculate(const std::vector<T>& a, const std::vector<T>& b) const = 0;
    virtual ~DistanceMetric() = default;
};
