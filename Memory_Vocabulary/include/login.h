#ifndef MEMORY_VOCABULARY_LOGIN_H
#define MEMORY_VOCABULARY_LOGIN_H
#define MaxSize 20
#include <head.h>
#include <memory.h>
extern int user_num;

class User{
public:
    char name[MaxSize];
    char password[MaxSize];
};
    extern User new_user[MaxSize];
    void add_user(User user_info[],char* n,char* p,int& num);
//  bool check_password(char* n,char* p);
    bool check_password(char* p);
    bool check_username(char* n);

    void save_userfile();
    //加入生词本

    void login();
    void load_userfile();
    void memory_login();

#endif