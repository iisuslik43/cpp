#include "huffman.h"

using namespace std;

Options::Options(int argc, char** argv){
    for(int i = 1; i < argc; i++){
            if(!strcmp(argv[i], "-c")){
                    is_archive = 1;
            }
            else if(!strcmp(argv[i], "-u")){
                    is_archive = -1;
            }
            else if(!strcmp(argv[i], "-f") || !strcmp(argv[i], "--file")){
                    i++;
                    in_file = argv[i];
            }
            else if(!strcmp(argv[i], "-o") || !strcmp(argv[i], "--output")){
                    i++;
                    if(i >= argc)
                        throw OptionsException("no in or out");
                    out_file = argv[i];
            }
            else{
                    throw OptionsException("wrong option");
            }
    }
    if(!is_archive){
        throw OptionsException("no -c or -u");
    }
    if(in_file == "" || out_file == ""){
        throw OptionsException("no in or out");
    }
}


Tree::Tree(vector<Node>& counts){
    tree1 = counts;
    sort(tree1.begin(), tree1.end());
    tree2 = vector<Node>(counts.size());
    codes.resize(512);
    int i = 0;
    int j = 0;
    int k = 0;
    while(tree1[i].count != INF || (tree2[j].count != INF && tree2[j + 1].count != INF)){
        Node* m1, *m2;

        if(tree1[i] < tree2[j]){
            m1 = &tree1[i];
            if(tree1[i + 1] < tree2[j]){
                m2 = &tree1[i + 1];
                i += 2;
            }
            else{
                m2 = &tree2[j];
                i++;
                j++;
            }
        }
        else{
            m1 = &tree2[j];
            if(tree2[j + 1] < tree1[i]){
                m2 = &tree2[j + 1];
                j += 2;
            }
            else{
                m2 = &tree1[i];
                i++;
                j++;
            }
        }
        tree2[k].node_1 = m1;
        tree2[k].node_0 = m2;
        tree2[k].count = m1->count + m2->count;
        k++;

    }
    root = &tree2[k - 1];
}


void Tree::dfs(Node* v){
    if(!v->node_0 && !v->node_0){
        codes[v->code] = ans;
        return;
    }
    if(v->node_0){
        ans += '0';
        dfs(v->node_0);
        ans.erase(ans.size() - 1);
    }
    if(v->node_1){
        ans += '1';
        dfs(v->node_1);
        ans.erase(ans.size() - 1);
    }
    return;

}

void Tree::count_codes(){
    dfs(get_root());
    // for(size_t i = 0; i < 256; i++){
    //     if(codes[i] != "")
    //         cout << (char)i << " :" << codes[i] << endl;
    // }
}

vector<string>& Tree::get_codes(){
    return codes;
}

Node* Tree::get_root(){
    return root;
}



void archive(string in_file, string out_file){
        ifstream in(in_file, ios::binary);
        if(!in.is_open()){
            cout << "WTF: in_file";
            return;
        }
        ofstream out(out_file, ios::binary);//TODO проверка всякой херни
        if(!out.is_open()){
            cout << "WTF: out_file";
            return;
        }
        vector<Node> counts(512);
        uint8_t c;
        size_t k = 0;
        size_t l = 0;
        while(in){
            in.read((char*)&c, sizeof(char));
            if(counts[c].count == INF){
                k++;
                counts[c].code = c;
                counts[c].count = 0;
            }
            counts[c].count++;
            l++;
        }
        Tree tree(counts);
        tree.count_codes();
        vector<string> codes = tree.get_codes();
        cout << "no huffman: " << l  << endl;
        cout << "information: " << sizeof(size_t) + k * (1 + sizeof(size_t)) << endl;
        out.write((char*)&k, sizeof(std::size_t));
        out.write((char*)&l, sizeof(std::size_t));
        for(size_t i = 0; i < counts.size(); i++){
            if(counts[i].count != INF){
                out.write((char*)&i, sizeof(char));
                out.write((char*)&counts[i].count, sizeof(std::size_t));
            }
        }
        in.clear();
        in.seekg(0);
        size_t j = 0;
        char write = 0;
        size_t size = 0;;
        while(in){
            in.read((char*)&c, sizeof(char));
            string s = codes[c];
            for(size_t h = 0; h < s.size(); h++){
                if(j == 8){
                    j = 0;
                    out.write((char*)&write, sizeof(char));
                    write = 0;
                    size++;
                }
                write |= ((s[h] - '0') << j);
                j++;
            }
        }
        if(j != 0){
            out.write((char*)&write, sizeof(char));
            size++;
        }
        cout << "huffman size: " << size << endl;

}
void unarchive(string in_file, string out_file){
    ifstream in(in_file, ios::binary);
    if(!in.is_open()){
        cout << "WTF: in_file";
        return;
    }
    ofstream out(out_file, ios::binary);//TODO проверка всякой херни
    if(!out.is_open()){
        cout << "WTF: out_file";
        return;
    }
    std::size_t k, l;
    in.read((char*)&k, sizeof(std::size_t));
    in.read((char*)&l, sizeof(std::size_t));

    cout << "no huffman: " << l  << endl;
    cout << "information: " << sizeof(size_t) + k * (1 + sizeof(size_t)) << endl;
    std::vector<Node> count(260);
    for(size_t i = 0; i < k; i++){
        uint8_t c;
        size_t a;
        in.read((char*)&c, sizeof(char));
        in.read((char*)&a, sizeof(std::size_t));
        count[c].count = a;
        count[c].code = c;
    }
    Tree tree(count);
    tree.count_codes();
    Node* root = tree.get_root();
    char c;
    size_t i = 0;
    bool f = true;
    Node* now;
    size_t size = 0;
    while(in && i < l){
        in.read((char*)&c, sizeof(char));
        for(int j = 0; j < 8; j++){
            if(f){
                now = root;
                f = false;
            }
            if((1 << j) & c){
                now = now->node_1;
            }
            else{
                now = now->node_0;
            }
            if(!now->node_0 && !now->node_1){
                out.write((char*)&now->code, sizeof(char));
                i++;
                f = true;
            }
        }
        size++;
    }
    cout << "huffman size: " << size << endl;
}
