#include <iostream>
#include <limits>

enum Banks {PKO, BGZ, BRE, BPH};

struct Account {
    Banks bank;
    int balance;
};

struct Person {
    char name[20];
    Account account;
};

struct Couple {
    Person he;
    Person she;
};

const Couple* bestClient(const Couple* cpls, int size, Banks bank) {
    const Couple* bestCouple = nullptr;
    auto maxSavings = double(std::numeric_limits<double>::lowest());
    auto currentSaving = double(0);

    for (auto i = 0; i < size; i++) {
//        const Couple& current = cpls[i];
        if (cpls[i].he.account.bank == bank || cpls[i].she.account.bank == bank) {
            currentSaving = cpls[i].he.account.balance + cpls[i].she.account.balance;
            if (currentSaving > maxSavings) {
                maxSavings = currentSaving;
                bestCouple = &cpls[i];
            }
        }
    }
    return bestCouple;
}

auto main() -> int {
    using std::cout; using std::endl;
    Couple cpls[] = {
            {"Johnny", PKO, 1200, "Mary", BGZ, 1400},
            {"Peter", BGZ, 1400, "Suzy", BRE, -1500},
            {"Kevin", PKO, 1600, "Katy", BPH, 1500},
            {"Kenny", BPH, 200, "Lucy", BRE, -201}
    };

    const Couple* p = bestClient(cpls, 4, BRE);
    if (p) {
        cout << p->he.name << " and " << p->she.name
             << ": " << p->he.account.balance +
                        p->she.account.balance << endl;
    } else {
        cout << "No such couple...\n";
    }

    return 0;
}
