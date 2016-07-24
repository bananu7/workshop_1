
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
        std::ofstream ofile("image.bmp", std::ios::binary);
        
        std::vector<ColorBGRA8> pixels(400 * 400, black);
        
        auto setPixel = [&pixels](unsigned x, unsigned y, ColorBGRA8 color) {
            pixels[y * 400 + x] = color;
        };
        
        float extentSizeX = extents.second.x - extents.first.x;
        float extentSizeY = extents.second.y - extents.first.y;
        float extentSizeZ = extents.second.z - extents.first.z;
        
        for (auto const& vertex : model.vertices) {
            unsigned x = (vertex.x - extents.first.x) / extentSizeX * 400;
            unsigned y = (vertex.y - extents.first.y) / extentSizeY * 400;
            setPixel(x, y, red);
        }
        
        saveBmpFile(pixels, 400, ofile);
    }
}
