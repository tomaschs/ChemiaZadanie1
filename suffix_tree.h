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
    SuffixTree(std::function<int(char)> cToOrd,
               std::function<char(int)> oToChar)
            : root(new SuffixNode<K>()),
              charToOrd(cToOrd),
              ordToChar(oToChar) {}

    ~SuffixTree() {
        clear();
    }



    void build(const std::string& text);

    bool find(const std::string& pattern);

    void print();

    void clearNode(SuffixNode<K>* node) {
        if (!node) return;
        for (auto& child : node->children) {
            clearNode(child);
        }
        delete node;
    }

    void clear() {
        clearNode(root);
        root = nullptr;
    }

private:
    SuffixNode<K>* root;
    std::function<int(char)> charToOrd;
    std::function<char(int)> ordToChar;


};


#endif //ZADANIE1_SUFFIX_TREE_H
