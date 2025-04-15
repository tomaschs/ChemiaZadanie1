#ifndef CHEMIACV2_TRIE_H
#define CHEMIACV2_TRIE_H

#include <functional>
#include <string>
#include <iostream>

template<int K>
class trie {
private:
    struct trie_node{
        bool is_end;
        trie_node* sons[K];

        trie_node():
            is_end(false){
                for (int i = 0; i < K; ++i) {
                    this->sons[i] = nullptr;
                }
            }

        ~trie_node(){
            for (int i = 0; i < K; ++i) {
                if(this->sons[i] != nullptr){
                    delete this->sons[i];
                    this->sons[i] = nullptr;
                }
            }
        }
    };
public:
    trie(std::function<int(char)> char_to_ord, std::function<char(int)> ord_to_char);
    ~trie();
    void insert(const char* str, int str_length);
    bool contains(const char* str, int str_length);
    void print();
private:
    trie_node* root;
    std::function<int(char)> char_to_ord; //odkaz na nejaku funkciu//uchovava adresu funkcie
    std::function<char(int)> ord_to_char;
    void print_node(trie_node* node, std::string& str);
};

template<int K>
trie<K>::trie(std::function<int(char)> char_to_ord, std::function<char(int)> ord_to_char) {
    this->root = new trie_node();
    this->char_to_ord = std::move(char_to_ord);
    this->ord_to_char = std::move(ord_to_char);
}

template<int K>
trie<K>::~trie() {
    delete this->root;
    this->root = nullptr;
}

template<int K>
void trie<K>::insert(const char *str, int str_length) {
    trie_node* current = this->root;
    int str_i = 0; //indexer

    while(str[str_i] != '\0' && str_i < str_length){
        int ord = this->char_to_ord(str[str_i]);
        if(current->sons[ord] == nullptr){
            current->sons[ord] = new trie_node();
        }
        current = current->sons[ord];
        ++str_i;
    }
    current->is_end = true;
}

template<int K>
bool trie<K>::contains(const char *str, int str_length) {
    trie_node* current = this->root;
    int str_i = 0; //indexer

    while(str[str_i] != '\0' && str_i < str_length){
        int ord = this->char_to_ord(str[str_i]);
        if(current->sons[ord] == nullptr){
            return false;
        }
        current = current->sons[ord];
        ++str_i;
    }
    return current->is_end;
}

template<int K>
void trie<K>::print_node(trie_node* node, std::string& str) {
    if (node->is_end) {
        std::cout << str << std::endl;
    }
    for (int i = 0; i < K; ++i) {
        if (node->sons[i] != nullptr) {
            str.push_back(this->ord_to_char(i));
            this->print_node(node->sons[i], str);
            str.pop_back();
        }
    }
}


template<int K>
void trie<K>::print() {
    std::string str;
    trie_node* node = this->root;
    this->print_node(node, str);

}

#endif //CHEMIACV2_TRIE_H
