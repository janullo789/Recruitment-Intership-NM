#include <iostream>

#include "trimString.h"
#include "Predicate.h"

int main() {
    std::string text = "      123 example      ";
    std::cout << text << std::endl;
    trimString(text, isWhitespace);
    std::cout << text << std::endl;
    return 0;
}
