#ifndef MEMORY_VOCABULARY_MEMORY_H
#define MEMORY_VOCABULARY_MEMORY_H
#include <head.h>
//��������Ϊһ���࣬��˳�򱳵���+���򱳵���
//���ʱ�������ʲ���������һ��strange.txt�ļ���ӵ����ɾ�鹦��
//������Ϊһ����ļ̳У�����ʹ��KMP�㷨
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
