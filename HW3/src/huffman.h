#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdint.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
#include <exception>
//size_t k, size_t l, k * (char code, size_t count), data

static std::size_t INF = (std::size_t)(1e10);

class Options{
public:
    Options(int argc, char** argv);
    std::string in_file, out_file;
    int is_archive;
};

class Node{
public:
    Node(){
        count = INF;
        node_1 = NULL;
        node_0 = NULL;
    }

    std::size_t count;
    uint8_t code;
    Node* node_0,* node_1;
    bool operator<(Node& a){
        return count < a.count;
    }
};

class Tree{
public:
    Tree(std::vector<Node>& counts);
    void count_codes();
    std::vector<std::string>& get_codes();
    Node* get_root();
    void dfs(Node* v);
private:
    std::string ans;
    std::vector<std::string> codes;
    std::vector<Node> tree1;
    std::vector<Node> tree2;
    Node* root;
};

class OptionsException{
public:
        OptionsException(std::string mes){
                message = mes;
        }
        std::string message;
};


void archive(std::string in_file, std::string out_file);
void unarchive(std::string in_file, std::string out_file);

#endif
