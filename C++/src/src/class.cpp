#include <iostream>
#include <format>
#include <compare>
#include <string>

class Test {
private:
    int a, b;
    std::string name;

public:
    Test( const int &_a, const int &_b, const std::string &_name )
        : a( _a ), b( _b ), name( _name ) {
        std::cout << "Build Test\n";
    };
    Test( const Test &t ) : a( t.a ), b( t.b ), name( t.name ) {
        std::cout << "Copy Complete Test\n";
    }

    bool operator==( const Test &t ) const {
        return this->a == t.a && this->b == t.b;
    }

    bool operator<( const Test &t ) const {
        return this->a < t.a && this->b < t.b;
    }

    bool operator>( const Test &t ) const {
        return this->a > t.a && this->b > t.b;
    }

    bool operator<=( const Test &t ) const {
        return this->a <= t.a && this->b <= t.b;
    }

    bool operator>=( const Test &t ) const {
        return this->a >= t.a && this->b >= t.b;
    }

    void operator=( const Test &t ) {
        this->a = t.a;
        this->b = t.b;
    }

    void operator-=( const Test &t ) {
        this->a -= t.a;
        this->b -= t.b;
    }

    void operator+=( const Test &t ) {
        this->a += t.a;
        this->b += t.b;
    }

    Test operator+( const Test &t ) {
        this->a += t.a;
        this->b += t.b;
        this->name = t.name;
        return *this;
    }

    Test operator-( const Test &t ) {
        this->a -= t.a;
        this->b -= t.b;
        this->name = t.name;
        return *this;
    }

    void operator++() {
        this->a++;
        this->b++;
    }

    void operator--() {
        this->a--;
        this->b--;
    }

    void operator()() { std::cout << "SB\n"; }

    friend std::istream &operator>>( std::istream &is, Test &t ) {
        is >> t.name >> t.a >> t.b;
        return is;
    }

    friend std::ostream &operator<<( std::ostream &os, Test &t ) {
        os << t.name << ' ' << t.a << ' ' << t.b;
        return os;
    }

    ~Test() { std::cout << "Delete Test\n"; }
};

inline int check( const Test &a, const Test &b ) { return a == b; }

int main() {

    // Test t(1 , 3 , "3rquir") , a(5 , 342 , "q23r389");
    //
    // if(auto data = check(t , a); data) {
    //     std::cout << "Nice\n";
    // } else {
    //     std::cout << "No\n";
    // }

    std::pair<int, int> a = std::make_pair( 1, 2 );
    // std::string s         = std::format( "Hello CppCon {}!", a.first );
    // std::cout << s << '\n';

    return 0;
}
