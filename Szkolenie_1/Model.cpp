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

std::pair<Vertex, Vertex> findExtents(Model const& model) {
    Vertex min, max;
    
    auto compareX = [](Vertex const& a, Vertex const& b) { return a.x < b.x; };
    auto compareY = [](Vertex const& a, Vertex const& b) { return a.y < b.y; };
    auto compareZ = [](Vertex const& a, Vertex const& b) { return a.z < b.z; };
    
    min.x = std::min_element(model.vertices.begin(),  model.vertices.end(), compareX) -> x;
    min.y = std::min_element(model.vertices.begin(),  model.vertices.end(), compareY) -> y;
    min.z = std::min_element(model.vertices.begin(),  model.vertices.end(), compareZ) -> z;
    
    max.x = std::max_element(model.vertices.begin(),  model.vertices.end(), compareX) -> x;
    max.y = std::max_element(model.vertices.begin(),  model.vertices.end(), compareY) -> y;
    max.z = std::max_element(model.vertices.begin(),  model.vertices.end(), compareZ) -> z;
    
    return { min, max };
}