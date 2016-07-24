
#include "Model.hpp"

#include "BMP.h"

#include <iostream>
#include <fstream>

int main(int argc, const char* argv[]) {
    std::ifstream file("teapot.obj");
    
    if (!file) {
        std::cerr << "Error opening file";
        std::exit(1);
    }
    
    auto model = loadModel(file);
    
    std::cout << "Vertices: " << model.vertices.size() << '\n'
              << "Faces: " << model.faces.size() << '\n';
    
    auto extents = findExtents(model);
    std::cout << "Extents: " << extents.first << " - " << extents.second << '\n';
    
    
    auto red = ColorBGRA8 { 0, 0, 255 };
    auto black = ColorBGRA8 { 0, 0, 0 };
    {
        float extentSizeX = extents.second.x - extents.first.x;
        float extentSizeY = extents.second.y - extents.first.y;
        //float extentSizeZ = extents.second.z - extents.first.z;
        
        float imageRatio = extentSizeX / extentSizeY;
        
        std::ofstream ofile("image.bmp", std::ios::binary);
        const unsigned height = 400;
        const unsigned width = imageRatio * height;
    
        std::vector<ColorBGRA8> pixels(width * height, black);
        
        auto setPixel = [&pixels, &width](unsigned x, unsigned y, ColorBGRA8 color) {
            pixels[y * width + x] = color;
        };
        
        for (auto const& vertex : model.vertices) {
            unsigned x = (vertex.x - extents.first.x) / extentSizeX * width;
            unsigned y = (vertex.y - extents.first.y) / extentSizeY * height;
            setPixel(x, y, red);
        }
        
        saveBmpFile(pixels, width, ofile);
    }
}
