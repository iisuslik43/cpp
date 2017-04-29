#ifndef HUFFMAN_H
#define HUFFMAN_H


// test: test/test.cpp src/huffman.h
// 	$(CXX) $(CXXFLAGS) test/test.cpp -o test

// test: $(BINDIR)/test.o
// 	$(CXX) test.o $(CXXFLAGS) -o test
//
// $(BINDIR)/test.o: test/test.cpp
// 	$(CXX) $(CXXFLAGS) -c -MMD -o bin/test.o test/test.cpp



//#include <libgtest.a>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
#include <exception>
#include <stdexcept>
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
        if(count != a.count)
            return count < a.count;
        return code < a.code;
    }
};

class Tree{
public:
    Tree(const std::vector<Node>& counts);
    size_t decode_file(std::ifstream& in, std::ofstream& out, std::size_t no_huffman_size);
    size_t code_file(std::ifstream& in, std::ofstream& out);
private:
    std::string ans;
    std::vector<std::string> codes;
    std::vector<Node> codes_tree;
    std::vector<Node> fake_codes_tree;
    Node* root;

    void dfs(Node* v);
    void count_codes();
};

bool isEmpty(std::ifstream& in);
bool isEmpty(std::string filename);
void archive(std::string in_file, std::string out_file);
void unarchive(std::string in_file, std::string out_file);

#endif
