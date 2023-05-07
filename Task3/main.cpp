#include <iostream>

#include "trimString.h"
#include "Predicate.h"

int main() {
    std::string text = "      More examples in tests/test.cpp     ";
    std::cout << text << std::endl;
    std::cout << trimString(text, isWhitespace);
    return 0;
}
