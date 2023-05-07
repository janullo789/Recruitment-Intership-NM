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

TEST_CASE("testing the isDigit predicate with function") {
    std::string text = "2Hello World!987  55";
    CHECK(trimString(text, isDigit) == "Hello World!987  ");

    text = "123A";
    CHECK(trimString(text, isDigit) == "A");

    text = "ABC123ABC";
    CHECK(trimString(text, isDigit) == "ABC123ABC");
}

TEST_CASE("testing the isAlpha predicate with function") {
    std::string text = "Hello World!";
    CHECK(trimString(text, isAlpha) == " World!");

    text = "    Hello World!  ";
    CHECK(trimString(text, isAlpha) == "    Hello World!  ");

    text = "ABC123ABC";
    CHECK(trimString(text, isAlpha) == "123");
}

TEST_CASE("testing the isUpperCase predicate with function") {
    std::string text = "Hello World!";
    CHECK(trimString(text, isUpperCase) == "ello World!");

    text = "AaBbCc";
    CHECK(trimString(text, isUpperCase) == "aBbCc");
}

TEST_CASE("testing the isLowerCase predicate with function") {
    std::string text = "Hello World";
    CHECK(trimString(text, isLowerCase) == "Hello W");

    text = "aaaBBBccc";
    CHECK(trimString(text, isLowerCase) == "BBB");
}
