#include <iostream>
#include "Knn.hpp"
#include "Euclidian.hpp"
#include "CosineDistance.hpp"

int main() {
    std::shared_ptr<DistanceMetric<double>> euclidean = std::make_shared<Euclidian<double>>();
    KNN<double> knn(3, euclidean);

    std::vector<std::vector<double>> X_train = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {5.0, 5.0}};
    std::vector<int> y_train = {0, 1, 1, 0};

    knn.fit(X_train, y_train);

    std::vector<double> x_test = {2.5, 3.5};
    int prediction = knn.predict(x_test);

    std::cout << "Predicted label: " << prediction << std::endl;

    return 0;
}
