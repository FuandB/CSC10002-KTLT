#include "source.h"
#include <stdio.h>
#include <iostream>


int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cout << "Usage: " << argv[0] << " <source.bmp> <partsInHeight> <partsInWidth> <outputDir> <outputPrefix>\n";
        return 1;
    }

    char* sourceFile = argv[1];
    int partsInHeight = std::atoi(argv[2]);
    int partsInWidth = std::atoi(argv[3]);
    char* outputDir = argv[4];
    char* outputPrefix = argv[5];

    Color*** pixelsArray = nullptr;
    header h;
    DIB d;

    ReadBMP(sourceFile, pixelsArray, h, d);
    SplitBMPFile(sourceFile, h, d, pixelsArray, partsInHeight, partsInWidth);

    ReleasePixelsArray(pixelsArray, d);

    std::cout << "BMP file split successfully.\n";
    return 0;
}