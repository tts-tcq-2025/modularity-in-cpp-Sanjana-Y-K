#include <assert.h>
#include <iostream>
#include "colorcoder.h"

using namespace TelCoColorCoder;

static void testNumberToPair(int pairNumber,MajorColor expectedMajor,MinorColor expectedMinor) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    std::cout << "Testing Number → Pair: " << pairNumber
              << " | Got: " << colorPair.ToString() << "\n";
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

static void testPairToNumber(MajorColor major, MinorColor minor,int expectedPairNumber) {
    int pairNumber = GetPairNumberFromColor(major, minor);
    std::cout << "Testing Pair → Number: "
              << ColorPair(major, minor).ToString()
              << " | Got: " << pairNumber << "\n";
    assert(pairNumber == expectedPairNumber);
}

void RunAllTests() {
    std::cout << "----- Running All Color Code Tests -----\n";
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    std::cout << "✅ All tests passed successfully!\n";
}
