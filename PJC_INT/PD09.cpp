#include <iostream>

class Segment {
    double A, B;

public:
    Segment(double a, double b) : A(a), B(b) {
        if (A > B) std::swap(this->A, this->B);
    }

    Segment operator*(double d) const {
        return Segment(A * d, B * d);
    }

    friend Segment operator*(double d, const Segment& seg) {
        return Segment(d * seg.A, d * seg.B);
    }

    Segment operator-(double d) const {
        return Segment(A - d, B - d);
    }

    friend Segment operator-(double d, const Segment& seg) {
        return Segment(seg.A - d, seg.B - d);
    }

    Segment operator+(double d) const {
        return Segment(A + d, B + d);
    }

    friend Segment operator+(double d, const Segment& seg) {
        return Segment(seg.A + d, seg.B + d);
    }

    Segment operator+(const Segment& other) const {
        return Segment(std::min(A, other.A), std::max(B, other.B));
    }

    Segment operator/(double d) const {
        return Segment(A/d, B/d);
    }

    bool operator()(double d) const {
        return d >= A && d <= B;
    }

    friend std::ostream& operator<<(std::ostream& ostream, const Segment& seg) {
        return ostream << "[" << seg.A << "," << seg.B << "]";
    }

};

auto main() -> int {
    using std::cout, std::endl;
    
    Segment seg{2,3}, s = 1 + 2*((seg-2)/2+seg)/3;
    cout << s << endl << std::boolalpha;
    for (double x = 0.5; x < 4; x += 1)
        cout << "x=" << x << ": " << s(x) << endl;
    return 0;
}
