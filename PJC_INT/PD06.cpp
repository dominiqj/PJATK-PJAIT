#include <iostream>

auto checkpass(std::string pass) -> int {
    auto passTier = int(0);

    auto hasCapital = [pass]() -> bool {
        auto trueOrFalse = bool(false);
        for (auto e : pass) {
            if (std::isupper(e)) {
                trueOrFalse = true;
            }
        }
        return trueOrFalse;
    };

    auto hasNoCapital = [pass]() -> bool {
        auto trueOrFalse = bool(false);
        for (auto e : pass) {
            if (!std::isupper(e)) {
                trueOrFalse = true;
            }
        }
        return trueOrFalse;
    };

    auto hasNumber = [pass]() -> bool {
        auto trueOrFalse = bool(false);
        for (auto e : pass) {
            if (std::isdigit(e)) {
                trueOrFalse = true;
            }
        }
        return trueOrFalse;
    };

    auto hasNonAlfNum = [pass]() -> bool {
        auto trueOrFalse = bool(false);
        for (auto e : pass) {
            if (!std::isalnum(e)) {
                trueOrFalse = true;
            }
        }
        return trueOrFalse;
    };

    auto hasSixDiffChars = [pass]() -> bool {
        auto nonUniqueCount = int(0);

        for (int i = 0; i < pass.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (pass[j] == pass[i] && i != j) {
                    nonUniqueCount++;
                }
            }
        }
        if (pass.size() - nonUniqueCount < 6) {
            return false;
        } else {
            return true;
        }
    };

    if (pass.size() < 8) {
        passTier++;
        std::cout << "Too short" << "\n";
    }
    if (!hasCapital()) {
        passTier++;
        std::cout << "No uppercase letter" << "\n";
    }
    if (!hasNoCapital()) {
        passTier++;
        std::cout << "No lowercase letter" << "\n";
    }
    if (!hasNumber()) {
        passTier++;
        std::cout << "No digit" << "\n";
    }
    if (!hasNonAlfNum()) {
        passTier++;
        std::cout << "No non-alphanumeric character" << "\n";
    }
    if (!hasSixDiffChars()) {
        passTier++;
        std::cout << "Too few different characters" << "\n";
    }
    if (passTier != 0) {
        return false;
    }
    return true;
}

auto main() -> int {
//    std::string pass;
//    std::cin >> pass;
//
//    std::cout << checkpass(pass) << std::endl;
//    using std::cout; using std::endl;
    const std::string passes[] = {
            "AbcDe93", "A1b:A1b>", "Ab:Acb<", "abc123><", "Zorro@123"
    };
    for (size_t i = 0; i < std::size(passes); i++) {
        std::cout << "checking " << passes[i] << std::endl;
        if (checkpass(passes[i])) std::cout << "OK" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
