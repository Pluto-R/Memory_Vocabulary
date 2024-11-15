#include <login.h>
#include "memory.h"
#include "head.h"


int main()
{
    while(1) {
        load_userfile();
        load_CET4();
        //std::cout << "current user_num: " << user_num << std::endl;

        login();
    }
    //std::cout << "current word: " << idx << std::endl;
    return 0;
}