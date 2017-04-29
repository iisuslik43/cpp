#ifndef OPTIONS_H
#define OPTIONS_H
#include "huffman.h"
class Options{
public:
    Options(int argc, char** argv);
    std::string in_file, out_file;
    int is_archive;
};

bool isEmpty(std::ifstream& in);
bool isEmpty(std::string filename);
#endif
