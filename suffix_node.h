//
// Created by asus on 15. 4. 2025.
//

#ifndef ZADANIE1_SUFFIX_NODE_H
#define ZADANIE1_SUFFIX_NODE_H

#pragma once
#include <iostream>
#include <array>

template<int K>
class SuffixNode {
public:
    bool isEnd;
    std::array<SuffixNode<K>*, K> children;
    SuffixNode<K>* suffixLink;

    SuffixNode();
    ~SuffixNode();
};

template<int K>
SuffixNode<K>::SuffixNode()
    : isEnd(false), suffixLink(nullptr) {
    children.fill(nullptr);
}

template<int K>
SuffixNode<K>::~SuffixNode() {
    for (auto& child : children) {
        delete child;
        child = nullptr;
    }
}


#endif //ZADANIE1_SUFFIX_NODE_H
