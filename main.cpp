#include <fstream>
#include <iostream>
#include "manual.h"

void RunAllTests();

int main() {
    RunAllTests();

    std::ofstream file("color_code_manual.txt");
    if (!file) {
        std::cerr << "Error: Could not create output file 'color_code_manual.txt'\n";
        return 1; // Exit with error code
    }

    file << TelCoColorCoder::FormatReferenceManual();
    file.close();

    return 0;
}
