#include <iostream>

auto printOddEven(int n) -> void {
    static auto ifFirst = bool(true);
    static auto current = int(0);
    if (n < 1) {
        current = 0;
        ifFirst = true;
        return;
    }
    if (n % 2 == 0) {
        current += 2;
    } else {
        if (ifFirst) {
            current += 1;
            ifFirst = false;
        } else {
            current += 2;
        }
    }
    std::cout << current << " ";
    printOddEven(n - 2);
}

auto hailstone(int n) -> void {
    if (n == 1) {
        return;
    }
    n % 2 == 0 ?  n = n / 2 : n = 3 * n + 1;
    std::cout << n << " ";
    hailstone(n);
}

auto gcdRec(int a, int b) -> int {
    return b == 0 ? a : gcdRec(b, a % b);
}

auto numDigits(int n) -> int {
    return n == 0 ? 0 : 1 + numDigits(n / 10);
}

auto sumDigits(int n) -> int {
    return n == 0 ? 0 : (n % 10) + sumDigits(n / 10);
}

auto main() -> int {
    std::cout << "gcdRec(12, 42) = "
        << gcdRec(12, 42) << std::endl
        << "gcdRec(12, 25) = "
        << gcdRec(12, 25) << std::endl;

    std::cout << "sumDigits(123) = "
        << sumDigits(123) << std::endl
        << "sumDigits(971) = "
        << sumDigits(971) << std::endl;

    std::cout << "numDigits(12345) = "
        << numDigits(12345) << std::endl
        << "numDigits(971) = "
        << numDigits(971) << std::endl;

    std::cout << "printOddEven(15): ";
    printOddEven(15);
    std::cout << std::endl;

    std::cout << "printOddEven(14): ";
    printOddEven(14);
    std::cout << std::endl;

    std::cout << "hailstone(13): ";
    hailstone(13);
    std::cout << std::endl;

    return 0;
}
