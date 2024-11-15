#include "login.h"
#include "memory.h"
using namespace std;
int user_num = 0;
User new_user[MaxSize] = {};

void login(){
    int mode = 0;
    bool flag = false;

    cout << "--------------------------" << endl;
    cout << "    Select login mode:    " << endl;
    cout << "--------------------------" << endl;
    cout << "     1. Login:     " << endl;
    cout << "     2. Register:       " << endl;
    cout << "--------------------------" << endl;
    cout << "   Please select (enter 1/2):  " << endl;
    cout << "--------------------------" << endl;

    cin >> mode;
    cin.ignore();

    switch (mode){
        case 1:{
            char n[MaxSize];
            char p[MaxSize];
            cout << "Enter name:" << endl;
            cin.getline(n,sizeof (n));
            if(check_username(n)){
                cout << "Enter passward:" << endl;
                cin.getline(p,sizeof (p));
                if (check_password(p)) {
                    cout << "passward is true!" << endl;
                    memory_login();
                    cout << "已退出顺序背单词模式!" << endl;
                    break;
                }else
                    cout << "passward is error!" << endl;
                    break;
            }else{
                cout << "can not find user!" << endl;
                break;
            }
        }
        case 2:{
            char n[MaxSize];
            char p[MaxSize];
            cout << "Enter new user name:" << endl;
            cin.getline(n,sizeof (n));

            cout << "Enter new user passward:" << endl;
            cin.getline(p,sizeof (p));
            add_user(new_user,n,p,user_num);
            save_userfile();
            break;
        }
    }
}

bool check_username(char* n){
    for(int i = 0;i < user_num;i++)
        if(!(strcmp(n,new_user[i].name)))
                return true;
    return false;
}

bool check_password(char* p){
    for(int i = 0;i < user_num;i++)
            if(!(strcmp(p,new_user[i].password)))
                return true;
    return false;
}

void add_user(User user_info[],char* n,char* p,int& num){
    strncpy(user_info[num].name,n,MaxSize-1);
    user_info[num].name[MaxSize-1] = '\0';
    strncpy(user_info[num].password,p,MaxSize-1);
    user_info[num].password[MaxSize-1] = '\0';
    cout << "add new user success!" << endl;
    user_num++;
}

void load_userfile(){
    ifstream user_file("C:\\Users\\lenovo\\Desktop\\C++\\Memory_Vocabulary\\User_Information.txt");
    if(user_file.is_open()){
        while(user_file >> new_user[user_num].name >> new_user[user_num].password){
            user_num++;
        }
        user_file.close();
    }else{
        cout << "no user data found!" << endl;
    }
}

void save_userfile(){
    ofstream user_file("C:\\Users\\lenovo\\Desktop\\C++\\Memory_Vocabulary\\User_Information.txt");
    if(user_file.is_open()){
        for(int i = 0;i < user_num;i++){
            user_file << new_user[i].name << ' ' << new_user[i].password << endl;
        }
        user_file.close();
    }else{
        cout << "user txt open error!" << endl;
    }
}

void memory_login(){
    int mode = 0;
    Memory memory;
    cout << "--------------------------" << endl;
    cout << "    Select memory vocabulary mode:    " << endl;
    cout << "     1.Inorder memory:      " << endl;
    cout << "     2.Disordered memory:       " << endl;
    cout << "     3.Strange word book:       " << endl;
    cout << "     4.Find vocabulary:       " << endl;
    //cout << "     5.Challenge mode:       " << endl;
    cout << "   Please select (enter 1/5):  " << endl;
    cout << "--------------------------" << endl;
    cin >> mode;
    cin.ignore();
    switch (mode) {
        case 1:{
            memory.InorderMemory();
            break;
        }
    }
}