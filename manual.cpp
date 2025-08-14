#include "manual.h"
#include "colorcoder.h"
#include <ostream>
#include <sstream>
#include <iomanip>

namespace TelCoColorCoder {

std::string FormatReferenceManual() {
    std::ostringstream out;
    out << "25-Pair Color Code Reference\n";
    out << "--------------------------------------\n";
    out << std::left << std::setw(6) << "Pair#"
        << std::setw(12) << "Major"
        << std::setw(12) << "Minor" << "\n";
    out << "--------------------------------------\n";

    for (int n = 1; n <= 25; ++n) {
        ColorPair p = GetColorFromPairNumber(n);

        // Split the "Major Minor" string into two columns
        std::string colorStr = p.ToString();
        size_t spacePos = colorStr.find(' ');
        std::string majorColor = colorStr.substr(0, spacePos);
        std::string minorColor = colorStr.substr(spacePos + 1);

        // Print neatly aligned table
        out << std::left << std::setw(6) << n
            << std::setw(12) << majorColor
            << std::setw(12) << minorColor << "\n";
    }
    return out.str();
}
void PrintReferenceManual(std::ostream& os) {
    os << FormatReferenceManual();
}
} // namespace TelCoColorCoder
