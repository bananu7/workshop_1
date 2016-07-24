#pragma once

#include <vector>

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
