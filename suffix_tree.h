//
// Created by asus on 15. 4. 2025.
//

#ifndef ZADANIE1_SUFFIX_TREE_H
#define ZADANIE1_SUFFIX_TREE_H


#pragma once
#include <string>
#include <functional>
#include "suffix_node.h"

template<int K>
class SuffixTree {
public:
    // Constructor
    SuffixTree(std::function<int(char)> cToOrd,
               std::function<char(int)> oToChar)
            : root(new SuffixNode<K>()),
              charToOrd(cToOrd),
              ordToChar(oToChar) {}

    // Destructor
    ~SuffixTree() {
        delete root;
        root = nullptr;
    }

    // Build method (placeholder)
    void build(const std::string& text);

    // Find method (placeholder)
    bool find(const std::string& pattern);

    // Print method (placeholder)
    void print();

private:
    SuffixNode<K>* root;
    std::function<int(char)> charToOrd;
    std::function<char(int)> ordToChar;
};


#endif //ZADANIE1_SUFFIX_TREE_H
