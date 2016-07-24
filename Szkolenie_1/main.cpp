
#include "Model.hpp"

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
}
