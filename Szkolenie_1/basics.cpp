/*
 1. C++11.
 2. STL: String.
 3. STL: Smart pointers.
 4. STL: Containers.
 5. STL: Iterators.
 6. STL: Algorithms.
 7. STL: Stream-based I/O.
 */

#include <iostream>
#include <vector>

// C++11/14
void part1() {
    // Init and auto
    {
        // Old C++
        std::vector<int> a = std::vector<int>(10,5);
        
        // New C++ - auto
        auto b = std::vector<int>(10,5);
        
        // New C++ - initializer list
        auto c = std::vector<int>{ 1, 2, 3, 4, 5 };
        
        // PITFALL
        auto d = { 1, 2, 3, 4, 5 }; // What's the x type?
    }
    
    // Mention unique_ptr
    
    // Lambdas:
    {
        auto f = [](){}; // a valid lambda
    }
}

// String
void part2() {
    // Underlying class
    {
        /*
        Type                    Definition
        std::string             std::basic_string<char>
        std::wstring            std::basic_string<wchar_t>
        std::u16string (C++11)  std::basic_string<char16_t>
        std::u32string (C++11)  std::basic_string<char32_t>
        */
    }

    // Init
    {
        std::string a = "abcdefxyz";
        std::string b ('a', 5);
    }

    // Common operations
    {
        std::string a = "abcdefxyz";
        std::string c = a.substr(3,3); // first character inclusive, length
    }
}

// Smart pointers
void part3() {
    // unique_ptr
    // shared_ptr
    // weak_ptr

    // PITFALL
    // auto_ptr - deprecated in C++11
}

// Iterators
void part5() {
    /*
    The Iterator concept describes types that can be used to identify and traverse the elements of a container.
    Iterator is the base concept used by other iterator types: 
     * InputIterator
     * OutputIterator
     * ForwardIterator
     * BidirectionalIterator
     * RandomAccessIterator.
    Iterators can be thought of as an abstraction of pointers.
    */
}
