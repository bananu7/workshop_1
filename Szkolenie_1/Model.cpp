#include "Model.hpp"

#include <string>
#include <sstream>

Model loadModel(std::istream& stream) {
    Model model;
    std::string line;
    
    while(std::getline(stream, line)) {
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
    
    return model;
}