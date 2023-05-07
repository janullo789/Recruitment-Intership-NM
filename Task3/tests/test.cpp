#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <doctest.h>

#include "trimString.h"
#include "predicate.h"


TEST_CASE("testing the isWhitespace predicate with function") {
    std::string text = "    Hello World!  ";
    CHECK(trimString(text, isWhitespace) == "Hello World!");
    
    text = "In hac habitasse platea dictumst.";
    CHECK(trimString(text, isWhitespace) == "In hac habitasse platea dictumst.");

    text = "   AAAAA      BBBBBBB       C       ";
    CHECK(trimString(text, isWhitespace) == "AAAAA      BBBBBBB       C");

    char cText[] = "\nText in char []        ";
    CHECK(trimString(cText, isWhitespace) == "Text in char []");
}

