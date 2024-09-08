#include <iostream>

const double* aver(const double* arr, size_t size, double& average) {
    const double* closestElement = &arr[0];
    auto sumUp = double();

    for (int  i = 0; i < size; i++) {
        sumUp += arr[i];
    }
    sumUp /= (double)size;
    average = sumUp;

    auto minDiff = double(std::abs(*closestElement - average));
    auto diff = double();
    for (size_t i = 1; i < size; ++i) {
        diff = std::abs(arr[i] - average);
        if (diff < minDiff) {
            minDiff = diff;
            closestElement = &arr[i];
        }
    }
    return closestElement;
}

auto main() -> int {
    double arr[] = {1, 2,-1.5 , 3.25, 5.5, 7.75,-0.25, 5.75};
    size_t size = std::size(arr);
    double average = 0;
    const double* p = aver(arr, size, average);
    std::cout << *p << " " << average << std::endl;
    return 0;
}
