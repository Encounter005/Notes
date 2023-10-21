#include <iostream>
#include "List.hpp"
#include <initializer_list>

int main() {
    List<int> a(std::initializer_list<int>{1 , 293 , 48 , 382 , 298});
    decltype(a) b(10 , 114514);
    b.merge(a);
    std::cout << b << std::endl;
    
    return 0;
}
