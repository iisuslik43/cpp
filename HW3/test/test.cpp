#include "../src/huffman.h"
#include "../src/options.h"
#include <gtest/gtest.h>
using namespace std;


TEST(TreeTest, IsCorrect){
    vector<Node> counts(260);
    counts['a'].count = 10;
    counts['a'].code = 'a';
    counts['b'].count = 1;
    counts['b'].code = 'b';
    counts['c'].count = 2;
    counts['c'].code = 'c';
    Tree tree(counts);
    Node* root = tree.root;
    ASSERT_TRUE(root);
    ASSERT_TRUE(root->node_1 && root->node_0);
    ASSERT_TRUE(root->node_1->code == 'a' || root->node_0->code == 'a');

    if(root->node_1->code == 'a'){
        ASSERT_TRUE(!root->node_1->node_0 && !root->node_1->node_1);
        EXPECT_EQ(root->node_1->count, 5);
        root = root->node_0;
    }
    else{
        ASSERT_TRUE(!root->node_0->node_1 && !root->node_0->node_0);
        root = root->node_1;
    }
    EXPECT_EQ(root->count, 3);
    ASSERT_TRUE(root->node_1 && root->node_0);
    ASSERT_TRUE(root->node_1->code == 'c' || root->node_0->code == 'c');
    ASSERT_TRUE(root->node_1->code == 'b' || root->node_0->code == 'b');

}

TEST(TreeTest, IsCorrectGetCodes){
    vector<Node> counts(260);
    counts['a'].count = 10;
    counts['a'].code = 'a';

    counts['b'].count = 1;
    counts['b'].code = 'b';

    counts['c'].count = 2;

    counts['c'].code = 'c';
    Tree tree(counts);
    tree.count_codes();
    vector<string> codes = tree.get_codes();
    ASSERT_TRUE(codes.size() > 3);
    ASSERT_TRUE(codes['a'] == "1" || codes['a'] == "0");
    if(codes['a'] == "1"){
        ASSERT_TRUE((codes['b'] == "01" && codes['c'] == "00") || (codes['b'] == "00" && codes['c'] == "01"));
    }
}


// class OptionsTest: public ::testing Test{
//     Options o1(5, {"huffman.exe", "-f", "file1", "-o", "file2"});
//     Options o2(6, {"huffman.exe", "-u" , "-f", "-o", "file1", "file2"});
//     Options o3(5, {"huffman.exe", "-c", "-f", "file1", "-o"});
//     Options o4(4, {"huffman.exe", "-c", "-f", "file1"});
//
// }

TEST(OptionsTest, WithNOcOru){
    bool wasException = true;
    char** argv = new char*[5];
    argv[0] = const_cast<char*>("huffman.exe");
    argv[1] = const_cast<char*>("-f");
    argv[2] = const_cast<char*>("file1");
    argv[3] = const_cast<char*>("-o");
    argv[4] = const_cast<char*>("file2");
    try{
        Options o1(5, argv);
        wasException = false;
    }
    catch(runtime_error& e){
        EXPECT_EQ(wasException, true);
        ASSERT_TRUE(!strcmp(e.what(), "no -c or -u"));
    }
    delete [] argv;
}

TEST(OptionsTest, WrongSequence){
    bool wasException = true;
    char** argv = new char*[6];
    argv[0] = const_cast<char*>("huffman.exe");
    argv[1] = const_cast<char*>("-u");
    argv[2] = const_cast<char*>("-f");
    argv[3] = const_cast<char*>("-o");
    argv[4] = const_cast<char*>("file1");
    argv[5] = const_cast<char*>("file2");
    try{
        Options o1(6, argv);
        wasException = false;
    }
    catch(runtime_error& e){
        EXPECT_EQ(wasException, true);
        ASSERT_TRUE(!strcmp(e.what(), "wrong option"));
    }
    delete [] argv;
}

TEST(OptionsTest, WithNOFile2){
    bool wasException = true;
    char** argv = new char*[5];
    argv[0] = const_cast<char*>("huffman.exe");
    argv[1] = const_cast<char*>("-c");
    argv[2] = const_cast<char*>("-f");
    argv[3] = const_cast<char*>("file1");
    argv[4] = const_cast<char*>("-o");
    try{
        Options o1(5, argv);
        wasException = false;
    }
    catch(runtime_error& e){
        EXPECT_EQ(wasException, true);
        ASSERT_TRUE(!strcmp(e.what(), "no in or out"));
    }
    delete [] argv;
}

TEST(OptionsTest, WithNOo){
    bool wasException = true;
    char** argv = new char*[4];
    argv[0] = const_cast<char*>("huffman.exe");
    argv[1] = const_cast<char*>("-f");
    argv[2] = const_cast<char*>("-o");
    argv[3] = const_cast<char*>("file1");
    try{
        Options o1(4, argv);
        wasException = false;
    }
    catch(runtime_error& e){
        EXPECT_EQ(wasException, true);
        ASSERT_TRUE(!strcmp(e.what(), "wrong option"));
    }
    delete [] argv;
}

TEST(OptionsTest, WrongOPtion){
    bool wasException = true;
    char** argv = new char*[6];
    argv[0] = const_cast<char*>("huffman.exe");
    argv[1] = const_cast<char*>("-c");
    argv[2] = const_cast<char*>("-lol");
    argv[3] = const_cast<char*>("-file1");
    argv[4] = const_cast<char*>("-o");
    argv[5] = const_cast<char*>("file2");
    try{
        Options o1(6, argv);
        wasException = false;
    }
    catch(runtime_error& e){
        EXPECT_EQ(wasException, true);
        ASSERT_TRUE(!strcmp(e.what(), "wrong option"));
    }
    delete [] argv;
}

TEST(OptionsTest, NotWrongOption2){
    bool wasException = true;
    char** argv = new char*[6];
    argv[0] = const_cast<char*>("huffman.exe");
    argv[1] = const_cast<char*>("-c");
    argv[2] = const_cast<char*>("--file");
    argv[3] = const_cast<char*>("-file1");
    argv[4] = const_cast<char*>("--output");
    argv[5] = const_cast<char*>("file2");
    try{
        Options o1(6, argv);
        wasException = false;
    }
    catch(runtime_error& e){
        ASSERT_TRUE(!strcmp(e.what(), "wrong option"));
    }
    EXPECT_EQ(wasException, false);
    delete [] argv;
}

TEST(ArchieveTest, Empty){
    archive("empty", "empty.kek");
    ASSERT_TRUE(isEmpty("empty.kek"));
    unarchive("empty.kek", "empty2");
    ASSERT_TRUE(isEmpty("empty2"));

}

TEST(ArchieveTest, Easy){
    archive("a", "a.kek");
    unarchive("a.kek", "b");
    ifstream in1("a", ios::binary);
    ifstream in2("b", ios::binary);
    ASSERT_FALSE(system("diff -s a b"));
}
