#pragma once

#include <vector>
#include <istream>

struct Vertex {
    float x, y, z;
};

struct Face {
    std::vector<unsigned> vertices;
};

struct Model {
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
};

Model loadModel(std::istream& stream);