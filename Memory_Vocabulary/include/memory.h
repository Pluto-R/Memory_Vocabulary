#ifndef MEMORY_VOCABULARY_MEMORY_H
#define MEMORY_VOCABULARY_MEMORY_H
#include <head.h>
//背单词作为一个类，有顺序背单词+无序背单词
//生词本如果单词不会就添加至一个strange.txt文件，拥有增删查功能
//查找作为一个类的继承？我想使用KMP算法
extern int idx;
void load_CET4();

class Word{
public:
    std::string word;
    std::string property;
    std::string translate;
};

class Memory : public Word{
public:
    void InorderMemory();
    void DisorderMemory();
};

class StrangeBook : public Word{

};

class FindVocabulary : public Memory,public StrangeBook{
    std::string find(char* word);
};

#endif
