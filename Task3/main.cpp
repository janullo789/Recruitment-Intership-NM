#include <iostream>

#include "trimString.h"

int main() {
    std::string text = "      123 example      ";
    std::cout << text << std::endl;
    trimString(text, isspace);
    std::cout << text << std::endl;
    return 0;
}
