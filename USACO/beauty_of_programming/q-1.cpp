#include <iostream>
#include <string>
#include <fstream>
#include <string.h>


const int MAX_SENTENCE_WORD = 120;
const int MAX_WORD_LEN = 25;
const int MAX_WORD_NUM = MAX_SENTENCE_WORD +  2*100; // total kind of possible words

int str_index[MAX_SENTENCE_WORD];
int word_nr;
char * word_dict[MAX_WORD_NUM];
int word_map[MAX_WORD_NUM];

void process_pairs(const std::string &s);
void process_sentence(const std::string &s);
void change_word();
void output_sentence(int c);
void clean_up();
namespace acm {
void getline(std::istream &in, std::string &s) {
    std::getline(in, s);
    while (s.empty()) {
        std::getline(in, s);
        if ( in.eof() )
            break;
    }
}
}
/**
 * @param s string to add into dict
 * @return id of the word
 */
int add_to_dict(std::string &word) {
    const char * word_data = word.c_str();
    int i=0;
    for (i=0; word_dict[i] != NULL; i++) {
    	if ( 0 == strcmp(word_dict[i], word_data) ) {
            return i;
        }
    }
    word_dict[i] = new char[MAX_WORD_LEN];   
    strcpy(word_dict[i], word_data);
    word_map[i] = i;
    return i;
}

int main() {
   //input case nr 
   int c;
   std::string s;
   std::istream &in = std::cin;
   clean_up();
   in >> c;
   for (int i=0; i<c; i++) {
        //input N, input M, N is player number, M is word list len
        int n,m;
        in >> n >> m;
        for (int j=0; j<m; j++) {
            //input paris, mapping index is stroed in word_map
            acm::getline(in, s);
            process_pairs(s);
        }
        //input sentence, sentecne is stored in str_index
        acm::getline(in, s);
        process_sentence(s);
        //start from str_index, change index according to word_map for N times
    for (int j=0; j<n-1; j++) {
	    change_word();
	}
   	//output converted sentence
    	output_sentence(i+1);
        clean_up();
   }
   return 0;
}
void clean_up() {
    word_nr = 0;
    for (int i=0; i<MAX_WORD_NUM; i++) {
    	delete word_dict[i];
        word_dict[i] = NULL; 
    }
    for (int i=0; i<MAX_WORD_NUM; i++) // need a trick in add_to_map
    	word_map[i] = -1;
}
void output_sentence(int c) {
    std::cout <<"Case #" << c <<":";
    for (int i=0; i<word_nr; i++) {
        std::cout << " ";
        std::cout << word_dict[str_index[i]];
    }
    std::cout << std::endl;
}
void change_word() {
    for (int i=0; i<word_nr; i++) {
        int id = str_index[i];
        if ( word_map[id] != id ) {
            str_index[i] = word_map[id];
        }
    }
}
void process_pairs(const std::string &s) {
    int v1=0, v2=0, v3=0;
    int id[2];
    for (int i=0; i<2; i++) {
        v2 = s.find_first_not_of(' ', v1);
        v3 = s.find_first_of(' ', v2);
        if (v3 == std::string::npos) v3 = s.length();
        std::string sub = s.substr(v2, v3-v2);
        id[i] = add_to_dict(sub);
        v1 = v3;
    }
    word_map[id[0]] = id[1];  
}

void process_sentence(const std::string &s) {
   int v1=0, v2=0, v3=0;
   for (int i=0; v3 != s.length(); i++) {
       v2 = s.find_first_not_of(' ', v1);
       v3 = s.find_first_of(' ', v2);
       if (v3 == std::string::npos) v3 = s.length();
       std::string sub = s.substr(v2, v3-v2);
       int id = add_to_dict(sub);
       v1 = v3;
       str_index[i] = id;
       word_nr++;
   }
}
