#include "colorcoder.h"
#include <string>
#include <iostream>

namespace TelCoColorCoder {

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

ColorPair::ColorPair(MajorColor major, MinorColor minor)
    : majorColor(major), minorColor(minor) {}

MajorColor ColorPair::getMajor() const { return majorColor; }
MinorColor ColorPair::getMinor() const { return minorColor; }

std::string ColorPair::ToString() const {
    return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor major = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
    return ColorPair(major, minor);
}
int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}

} 
