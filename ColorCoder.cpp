#include "ColorCoder.h"
#include <iostream>

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

    const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    ColorPair::ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor)
    {}

    MajorColor ColorPair::getMajor() const
    {
        return majorColor;
    }

    MinorColor ColorPair::getMinor() const
    {
        return minorColor;
    }

    std::string ColorPair::ToString() const
    {
        return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
    }

    ColorPair GetColorFromPairNumber(int pairNumber)
    {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor)
    {
        return major * numberOfMinorColors + minor + 1;
    }

    void PrintColorCodeManual()
    {
        std::cout << "Pair Number\tMajor Color\tMinor Color" << std::endl;
        for (int pairNumber = 1; pairNumber <= numberOfMajorColors * numberOfMinorColors; ++pairNumber)
        {
            ColorPair pair = GetColorFromPairNumber(pairNumber);
            std::cout << pairNumber << "\t\t" << MajorColorNames[pair.getMajor()] << "\t\t" 
                      << MinorColorNames[pair.getMinor()] << std::endl;
        }
    }
}
