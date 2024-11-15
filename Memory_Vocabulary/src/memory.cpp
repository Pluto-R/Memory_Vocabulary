#include "memory.h"
using namespace std;
#define Max_word 8000

Word word_list[Max_word];
int idx = 0;

void load_CET4() {
    std::ifstream cet4("C:\\Users\\lenovo\\Desktop\\C++\\Memory_Vocabulary\\CET4.txt");
    if(cet4.is_open()){
        while(cet4 >> word_list[idx].word >> word_list[idx].property >> word_list[idx].translate){
            //cout << word_list[idx].word << ' ' << word_list[idx].property << ' ' << word_list[idx].translate << endl;
            idx++;
        }
        //cout << word_list[4299].word << ' ' << word_list[4299].property << ' ' << word_list[4299].translate << endl;
        cet4.close();
    }else
        cout << "load cet4 occor error!" << endl;
}

void Memory::InorderMemory() {
    for(int i = 0; i < idx; i++) {
        cout << "第" << (i + 1) << "个单词是:" << endl
             << word_list[i].word << ' ' << word_list[i].property << ' ' << word_list[i].translate;
        char next = cin.get();
        if(next == 32)
            break;
        if (next == '\n') {
        }
    }
}

void Memory::DisorderMemory() {
    int falg = 0;

}
