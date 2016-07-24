#pragma once

#include <fstream>

struct BmpFileHeader {
    uint16_t type;           // Magic number for file
    uint32_t size;           // Size of file
    uint16_t reserved1;      // Reserved
    uint16_t reserved2;
    uint32_t offBits;        // Offset to bitmap data
} __attribute__((packed));

#  define BF_TYPE 0x4D42             /* "MB" */

struct BmpInfoHeader                      /**** BMP file info structure ****/
{
    uint32_t size;           /* Size of info header */
    int32_t width;          /* Width of image */
    int32_t height;         /* Height of image */
    uint16_t planes;         /* Number of color planes */
    uint16_t bitCount;       /* Number of bits per pixel */
    uint32_t compression;    /* Type of compression to use */
    uint32_t sizeImage;      /* Size of image data */
    int32_t xPelsPerMeter;  /* X pixels per meter */
    int32_t yPelsPerMeter;  /* Y pixels per meter */
    uint32_t colorUsedCount;        /* Number of colors used */
    uint32_t colorImportantCount;   /* Number of important colors */
} __attribute__((packed));

/*
 * Constants for the biCompression field...
 */

#  define BI_RGB       0             /* No compression - straight BGR data */
#  define BI_RLE8      1             /* 8-bit run-length compression */
#  define BI_RLE4      2             /* 4-bit run-length compression */
#  define BI_BITFIELDS 3             /* RGB bitmap with RGB masks */

struct ColorBGRA8                       /**** Colormap entry structure ****/ {
    uint8_t b, g, r, reserved;
} __attribute__((packed));

void saveBmpFile(std::vector<ColorBGRA8> const& pixels, unsigned width, std::ofstream& ofs) {
    BmpFileHeader fileHeader;
    fileHeader.type = BF_TYPE;
    fileHeader.size = sizeof(BmpFileHeader) + sizeof(BmpInfoHeader) + pixels.size() * 4;
    fileHeader.offBits = sizeof(BmpFileHeader) + sizeof(BmpInfoHeader);
    fileHeader.reserved1 = 0;
    fileHeader.reserved2 = 0;
    
    BmpInfoHeader infoHeader;
    infoHeader.size = sizeof(BmpInfoHeader);
    infoHeader.width = width;
    infoHeader.height = pixels.size() / width;
    infoHeader.planes = 1;
    infoHeader.bitCount = 32;
    infoHeader.compression = 0;
    infoHeader.sizeImage = 0; // can be 0 because uncrompressed
    infoHeader.xPelsPerMeter = 100;
    infoHeader.yPelsPerMeter = 100;
    infoHeader.colorUsedCount = 0;
    infoHeader.colorImportantCount = 0;
    
    ofs.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
    ofs.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));
    ofs.write(reinterpret_cast<const char*>(pixels.data()), pixels.size() * 4);
}