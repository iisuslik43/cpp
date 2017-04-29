#include "huffman.h"

using namespace std;

int main(int argc, char* argv[]){
    try{
        Options o(argc, argv);
        if(o.is_archive == 1){//архивация
            archive(o.in_file, o.out_file);
        }
        else{
            unarchive(o.in_file, o.out_file);
        }
    }
    catch(runtime_error& e){
        cerr << e.what( ) << endl;
    }
}
