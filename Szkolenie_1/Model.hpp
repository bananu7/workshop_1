#pragma once

#include <vector>
#include <istream>
#include <algorithm>

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

std::pair<Vertex, Vertex> findExtents(Model const& model);

inline std::ostream& operator<<(std::ostream& os, Vertex const& v) {
    return os << '[' << v.x << ", " << v.y << ", " << v.z << ']';
}