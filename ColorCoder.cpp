#include "colorcoder.h"
#include <string>

namespace TelCoColorCoder {

const char* MajorColorNames[] = {"White","Red","Black","Yellow","Violet"};
int numberOfMajorColors = sizeof(MajorColorNames)/sizeof(MajorColorNames[0]);
const char* MinorColorNames[] = {"Blue","Orange","Green","Brown","Slate"};
int numberOfMinorColors = sizeof(MinorColorNames)/sizeof(MinorColorNames[0]);

ColorPair::ColorPair(MajorColor major, MinorColor minor)
  : majorColor(major), minorColor(minor) {}

MajorColor ColorPair::getMajor() { return majorColor; }
MinorColor ColorPair::getMinor() { return minorColor; }

std::string ColorPair::ToString() {
  std::string s = MajorColorNames[majorColor];
  s += " ";
  s += MinorColorNames[minorColor];
  return s;
}

ColorPair GetColorFromPairNumber(int pairNumber) {
  int zeroBased = pairNumber - 1;
  MajorColor major = static_cast<MajorColor>(zeroBased / numberOfMinorColors);
  MinorColor minor = static_cast<MinorColor>(zeroBased % numberOfMinorColors);
  return ColorPair(major, minor);
}

int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
  return major * numberOfMinorColors + minor + 1;
}

}  // namespace TelCoColorCoder
