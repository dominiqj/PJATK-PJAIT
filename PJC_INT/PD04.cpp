#include <iostream>

auto koduj(int plec, int stan_cyw, int grupa_wiek, int edu, int zam, int region, int odp) -> unsigned short {
    unsigned short code = 0;
    unsigned short temp;

    temp = plec & 0b1;
    code = (code << 1) | temp;

    temp = stan_cyw & 0b11;
    code = (code << 2) | temp;

    temp = grupa_wiek & 0b11;
    code = (code << 2) | temp;

    temp = edu & 0b11;
    code = (code << 2) | temp;

    temp = zam & 0b11;
    code = (code << 2) | temp;

    temp = region & 0b1111;
    code = (code << 4) | temp;

    temp = odp & 0b111;
    code = (code << 3) | temp;

    return code;
}

auto info(unsigned short code) -> void {
    unsigned short temp;

    temp = code;
    temp >>= 15;
    std::cout << "plec:\t\t" << temp << "\n";

    temp = code;
    temp = (temp >> 13) & 0b0000000000000011;
    std::cout << "stan cywilny:\t" << temp << "\n";

    temp = code;
    temp = (temp >> 11) & 0b0000000000000011;
    std::cout << "grupa wiekowa:\t" << temp << "\n";

    temp = code;
    temp = (temp >> 9) & 0b0000000000000011;
    std::cout << "wyksztalcenie:\t" << temp << "\n";

    temp = code;
    temp = (temp >> 7) & 0b0000000000000011;
    std::cout << "miejsce zam:\t" << temp << "\n";

    temp = code;
    temp = (temp >> 3) & 0b0000000000001111;
    std::cout << "region:\t\t" << temp << "\n";

    temp = code;
    temp &= 0b0000000000000111;
    std::cout << "odpowiedz:\t" << temp << std::endl;
}

int main() {
    const unsigned short x = koduj(0,3,1,3,2,12,7);
    info(x);

    return 0;
}