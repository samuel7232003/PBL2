#ifndef list_account_host_h
#define list_account_host_h
#include "./single/account_host.h"
#include "../Template/LinkedList.cpp"
#include <string>

class list_account_host :public LinkedList<account_host>{
    public:
        void getlist_account();
        void outlist_account();
        void login(account_host &a, int &k);
		int checklogin(string id, string pwd, account_host &a);
};

#endif