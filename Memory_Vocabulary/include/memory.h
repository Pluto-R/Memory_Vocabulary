#ifndef MEMORY_VOCABULARY_MEMORY_H
#define MEMORY_VOCABULARY_MEMORY_H
#include <head.h>
#include <login.h>
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
    virtual void InorderMemory() const = 0;
    virtual void DisorderMemory() const = 0;
    virtual ~Memory() {}
};

class StrangeBook : public Memory{
public:
    void InorderMemory() const override;
    void DisorderMemory() const override;
    void JoinNewWord(int cur_idx);
    void DeleteWord(int cur_idx);
};
extern StrangeBook strangeBook;

class FindVocabulary : public Memory{
    std::string find(char* word);
};

#endif
