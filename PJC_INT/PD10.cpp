#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string; using std::ostream;

class Animal {
public :
    virtual string voice() const = 0;
    virtual int legs() const = 0;
    string getSpecies() const {
        return species;
    }
    string getName() const {
        return name;
    }

    Animal(const string &name, const string &species) : name(name), species(species) {};

protected:
    string species;
    string name;

    friend ostream& operator<<(ostream& s, const Animal& a) {
        s << a.getSpecies() + " " + a.getName() + ", " + std::to_string(a.legs()) + " legs, voice: \"" + a.voice() + "\"";
        return s;
    }
    friend ostream& operator<<(ostream& s, const Animal* p) {
        s << p->getSpecies() + " " + p->getName() + ", " + std::to_string(p->legs()) + " legs, voice: \"" + p->voice() + "\"";
        return s;
    }
};

class Cat : public Animal{
public:
    string voice() const override {
        return "Meow";
    }
    int legs() const override{
        return 4;
    }

    explicit Cat(const string &name) : Animal(name, "Cat") {};
};

class Snake : public Animal{
public:
    string voice() const override {
        return "Ssss";
    }
    int legs() const override{
        return 0;
    }

    explicit Snake(const string &name) : Animal(name, "Snake") {};
};

int main() {
    Cat cat1("Oliver"), cat2("Sophie");
    Snake snake("Wire");
    Animal* arr[] = {&cat1, &cat2, &snake};
    for (const auto& e : arr) {
        cout << *e << endl;
    }
    cout << endl;
    for (const auto& e : arr) {
        cout << e << endl;
    }

    return 0;
}
