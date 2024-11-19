#include "memory.h"
#include "login.h"
#include <ctime>
#include <cstdlib>
#include <random>
using namespace std;
#define Max_word 8000
StrangeBook strangeBook;
Word word_list[Max_word];
Word strange_list[Max_word];
//vector<Word> strange_list;
int idx = 0;
int cur_idx = 0;

void load_CET4() {
    std::ifstream cet4("C:\\Users\\lenovo\\Desktop\\C++\\Memory_Vocabulary\\CET4.txt");
    if(cet4.is_open()){
        while(cet4 >> word_list[idx].word >> word_list[idx].property >> word_list[idx].translate){
            //如果在读入流中一直输入单词就会导致错误发生
            //cout << word_list[idx].word << ' ' << word_list[idx].property << ' ' << word_list[idx].translate << endl;
            idx++;
        }
//        for(int i = 0;i <= idx;i++){
//            cout << word_list[i].word << ' ' << word_list[i].property << ' ' << word_list[i].translate << endl;
//        }
        cet4.close();
    }else
        cout << "load cet4 occor error!" << endl;
}
void Memory::InorderMemory() const{
    for(int i = 0; i < idx; i++) {
        cout << "第" << (i + 1) << "个单词是:" << endl
             << word_list[i].word << ' '
             << word_list[i].property << ' '
             << word_list[i].translate << endl;
        cout << "---------------------------" << endl;
        cout << "进入下一题请按Enter: " << endl;
        cout << "收藏该生词请按 j or J: " << endl;
        cout << "输入您的选择: " << endl;
        char next_operator = cin.get();
        if (next_operator == 'x' || next_operator == 'X')
            break;
        if (next_operator == 'j' || next_operator == 'J'){

            cur_idx = i;
            strangeBook.JoinNewWord(cur_idx);

            cin.ignore();
        }
        if (next_operator == '\n') {
        }
    }
}
void Memory::DisorderMemory() const{
    while (1) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, idx);
        int i = dis(gen);
//        cout << i <<"单词是：" << endl;
//        cout << word_list[i].property << endl;
        cout << "第" << (i + 1) << "个单词是:" << endl
             << word_list[i].word << ' '
             << word_list[i].property << ' '
             << word_list[i].translate << endl;
        cout << "---------------------------" << endl;
        cout << "进入下一题请按Enter: " << endl;
        cout << "收藏该生词请按 j or J: " << endl;
        cout << "输入您的选择: " << endl;
        char next_operator = cin.get();

        if (next_operator == 'x' || next_operator == 'X') {
            cin.ignore();
            return;
        }
        if (next_operator == 'j' || next_operator == 'J'){

            cur_idx = i;
            strangeBook.JoinNewWord(cur_idx);

            cin.ignore();
        }

        if (next_operator == '\n') {
        }
    }
}
void StrangeBook::InorderMemory() const{
    for(int i = 0; i < idx; i++) {
        cout << "第" << (i + 1) << "个单词是:" << endl
             << strange_list[i].word << ' ' << strange_list[i].property << ' ' << strange_list[i].translate;
        char next_operator = cin.get();
        if(next_operator == 32)
            break;
        if (next_operator == '\n') {
        }
    }
}
void StrangeBook::DisorderMemory() const{
    while (1) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, idx);
        int i = dis(gen);
//        cout << i <<"单词是：" << endl;
//        cout << word_list[i].property << endl;
        cout << "第" << (i + 1) << "个单词是:" << endl
             << strange_list[i].word << ' ' << strange_list[i].property << ' ' << strange_list[i].translate;
        char next_operator = cin.get();
        if (next_operator == 'x' || next_operator == 'X')
            break;
        if (next_operator == 'j' || next_operator == 'J'){
            cur_idx = i;
            strangeBook.JoinNewWord(cur_idx);
        }
        if (next_operator == '\n') {
        }
    }
}

void StrangeBook::JoinNewWord(int cur_idx) {

    std::ofstream strange_w("C:\\Users\\lenovo\\Desktop\\C++\\Memory_Vocabulary\\StrangeBook.txt", std::ios::app);    //需要使用追加写的模式，不然会覆盖原内容
    if (!strange_w.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    std::ifstream strange_r("C:\\Users\\lenovo\\Desktop\\C++\\Memory_Vocabulary\\StrangeBook.txt");
    if(strange_r.is_open()){
        int i = 0;
        while(strange_r >> strange_list[i].word
        >> strange_list[i].property
        >> strange_list[i].translate){
            i++;
        }

        if(word_list[cur_idx].word == strange_list[i].word
        && word_list[cur_idx].property == strange_list[i].property
        && word_list[cur_idx].translate == strange_list[i].translate){
            cerr << "生词本中已经存在该单词!" << endl;
            strange_r.close();
            return;
        }
        strange_r.close();
    }
    strange_w << word_list[cur_idx].word << ' '
    << word_list[cur_idx].property <<' '
    << word_list[cur_idx].translate << endl;

    strange_w.close();
}

void StrangeBook::DeleteWord(int cur_idx) {
    std::ofstream strange_w("C:\\Users\\lenovo\\Desktop\\C++\\Memory_Vocabulary\\StrangeBook.txt", std::ios::app);    //需要使用追加写的模式，不然会覆盖原内容
    if (!strange_w.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

}