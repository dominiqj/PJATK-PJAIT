#include <iostream>

auto main() -> int {
    auto temp = int();
    auto current = int(0);
    auto currCount = int(0);
    auto maxCount = int(0);
    auto maxNum = int(0);

    while (std::cin >> temp) {
        if (current == temp) {
            currCount++;
        } else if (current != temp) {
            if (maxCount <= currCount) {
                maxCount = currCount;
                maxNum = current;
            }
            current = temp;
            currCount = 1;
        }
        if (temp == 0) {
            std::cout << "Longest sequnce: " << maxCount << " times " << maxNum << std::endl;
            return 0;
        }
    }
}
