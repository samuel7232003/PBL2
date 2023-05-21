#include <iostream>
using namespace std;
#include <fstream>
#include "Home_user.cpp"
#include "Home_host.cpp"

void Home(){
    int i=-1, cn=1;
    while(i==-1){
        system("cls");
        Menu_infor();
        Menu_home(i, cn);
    }
    system("cls");
    switch (i){
        case 1: Home_user(); break;
        case 2: Home_host(); break;
        case 3: exit(0);
    }
    Home();
}