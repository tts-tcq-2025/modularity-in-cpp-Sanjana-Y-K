#ifndef TELCO_COLORCODER_H_
#define TELCO_COLORCODER_H_

#include <string>

namespace TelCoColorCoder {

enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

class ColorPair {
private:
    MajorColor majorColor;
    MinorColor minorColor;

public:
    ColorPair(MajorColor major, MinorColor minor);

    MajorColor getMajor() const;  
    MinorColor getMinor() const;   
    std::string ToString() const;  
};

ColorPair GetColorFromPairNumber(int pairNumber);

int GetPairNumberFromColor(MajorColor major, MinorColor minor);

}  // namespace TelCoColorCoder

#endif // TELCO_COLORCODER_H_
