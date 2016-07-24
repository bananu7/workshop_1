
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
    auto green = ColorBGRA8 { 0, 255, 0 };
    
    {
        std::ofstream ofile("image.bmp", std::ios::binary);
        saveBmpFile({ red, green, red, green } , 2, ofile);
    }
}
