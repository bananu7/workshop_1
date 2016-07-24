#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, const char* argv[]) {
    std::ifstream f("teapot.obj");
    
    if (!f) {
        std::cerr << "Error opening file";
        std::exit(1);
    }
    
    std::string line;
    unsigned faceCount = 0, vertCount = 0;
    while(std::getline(f, line)) {
        std::istringstream s(line);
        
        char c;
        s >> c;
        
        switch (c) {
            case 'f': faceCount += 1; break;
            case 'v': vertCount += 1; break;
        }
    }
    
    std::cout << "Vertices: " << vertCount << '\n'
              << "Faces: " << faceCount << '\n';
    
}
