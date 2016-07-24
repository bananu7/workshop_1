
#include "Model.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, const char* argv[]) {
    std::ifstream file("teapot.obj");
    
    if (!file) {
        std::cerr << "Error opening file";
        std::exit(1);
    }
    
    std::string line;
    
    Model model;
    
    while(std::getline(file, line)) {
        std::istringstream s(line);
        
        char c;
        s >> c;
        
        switch (c) {
            case 'v':
                Vertex vertex;
                s >> vertex.x >> vertex.y >> vertex.z;
                model.vertices.push_back(vertex);
                
                break;
                
            case 'f':
                unsigned vertexNum;
                Face face;
                
                while (s >> vertexNum) {
                    face.vertices.push_back(vertexNum);
                }
                
                model.faces.push_back(face);
                
                break;
        }
    }
    
    std::cout << "Vertices: " << model.vertices.size() << '\n'
              << "Faces: " << model.faces.size() << '\n';
    
}
