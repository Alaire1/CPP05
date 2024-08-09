#include "whatever.hpp"
#include <limits>

int main() 
{
    std::cout << YELLOW << "Basic test: " << RESET << std::endl;
    int a = 2;
    int b = 3;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    std::cout << YELLOW << "Float test: " << RESET << std::endl;
    float e = 1.23f;
    float f = 4.56f;
    std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    std::cout << YELLOW << "Char test: " << RESET << std::endl;
    char g = 'A';
    char h = 'B';
    std::cout << "Before swap: g = " << g << ", h = " << h << std::endl;
    ::swap(g, h);
    std::cout << "After swap: g = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
    std::cout << "max(g, h) = " << ::max(g, h) << std::endl;

    std::cout << YELLOW << "The same val test: " << RESET << std::endl;
    int k = 100;
    int l = 100;
    std::cout << "Before swap: k = " << k << ", l = " << l << std::endl;
    ::swap(k, l);
    std::cout << "After swap: k = " << k << ", l = " << l << std::endl;
    std::cout << "min(k, l) = " << ::min(k, l) << std::endl;
    std::cout << "max(k, l) = " << ::max(k, l) << std::endl;

    std::cout << YELLOW << "Double test: " << RESET << std::endl;
    double m = std::numeric_limits<double>::max();
    double n = std::numeric_limits<double>::min();
    std::cout << "Before swap: m = " << m << ", n = " << n << std::endl;
    ::swap(m, n);
    std::cout << "After swap: m = " << m << ", n = " << n << std::endl;
    std::cout << "min(m, n) = " << ::min(m, n) << std::endl;
    std::cout << "max(m, n) = " << ::max(m, n) << std::endl;

    std::cout << YELLOW << "Negative values test: " << RESET << std::endl;
    int neg1 = -10;
    int neg2 = -20;
    std::cout << "Before swap: neg1 = " << neg1 << ", neg2 = " << neg2 << std::endl;
    ::swap(neg1, neg2);
    std::cout << "After swap: neg1 = " << neg1 << ", neg2 = " << neg2 << std::endl;
    std::cout << "min(neg1, neg2) = " << ::min(neg1, neg2) << std::endl;
    std::cout << "max(neg1, neg2) = " << ::max(neg1, neg2) << std::endl;

    std::cout << YELLOW << "Mixed values test: " << RESET << std::endl;
    int mix1 = -5;
    int mix2 = 15;
    std::cout << "Before swap: mix1 = " << mix1 << ", mix2 = " << mix2 << std::endl;
    ::swap(mix1, mix2);
    std::cout << "After swap: mix1 = " << mix1 << ", mix2 = " << mix2 << std::endl;
    std::cout << "min(mix1, mix2) = " << ::min(mix1, mix2) << std::endl;
    std::cout << "max(mix1, mix2) = " << ::max(mix1, mix2) << std::endl;

    std::cout << YELLOW << "Smallest and Biggest int test: " << RESET << std::endl;
    int minInt = std::numeric_limits<int>::min();
    int maxInt = std::numeric_limits<int>::max();
    std::cout << "Before swap: minInt = " << minInt << ", maxInt = " << maxInt << std::endl;
    ::swap(minInt, maxInt);
    std::cout << "After swap: minInt = " << minInt << ", maxInt = " << maxInt << std::endl;
    std::cout << "min(minInt, maxInt) = " << ::min(minInt, maxInt) << std::endl;
    std::cout << "max(minInt, maxInt) = " << ::max(minInt, maxInt) << std::endl;

    return 0;
}



/* output of basic test:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2 */