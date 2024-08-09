#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
#include "DistanceMetric.hpp"

template <typename T>
class KNN
{
public:
    KNN(int k, std::shared_ptr<DistanceMetric<T>> distance_metric) 
        : k_(k), distance_metric_(distance_metric) {}

    void fit(const std::vector<std::vector<T>>& x, const std::vector<int>& y) {
        x_train_ = x;
        y_train_ = y;
    }

    int predict(const std::vector<T>& x) const {
        std::vector<int> neighbors = find_k_nearest_neighbors(x);
        std::map<int, int> label_counts;
        for (int idx : neighbors) {
            int label = y_train_[idx];
            label_counts[label]++;
        }

        int most_common_label = -1;
        int max_count = 0;
        for (const auto& pair : label_counts) {
            if (pair.second > max_count) {
                most_common_label = pair.first;
                max_count = pair.second;
            }
        }

        return most_common_label;
    }

    std::vector<int> predict(const std::vector<std::vector<T>>& X) const {
        std::vector<int> predictions;
        for (const auto& x : X) {
            predictions.push_back(predict(x));
        }
        return predictions;
    }

private:
    int k_;
    std::shared_ptr<DistanceMetric<T>> distance_metric_;
    std::vector<std::vector<T>> x_train_;
    std::vector<int> y_train_;

    std::vector<int> find_k_nearest_neighbors(const std::vector<T>& x) const {
        std::vector<std::pair<double, int>> distances;
        for (size_t i = 0; i < x_train_.size(); i++) {
            double dist = distance_metric_->calculate(x_train_[i], x);
            distances.push_back(std::make_pair(dist, i));
        }
        std::sort(distances.begin(), distances.end());
        std::vector<int> neighbors;
        for (int i = 0; i < k_; i++) {
            neighbors.push_back(distances[i].second);
        }
        return neighbors;
    }
};
