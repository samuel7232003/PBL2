#ifndef account_h
#define account_h
#include <string>
#include <iostream>
using namespace std;

class account{
    private:
        string ID_acc;
	    string pwd_acc;
	    string name_acc;
    protected:
        void set_name(string name);
        void set_pwd(string pwd);
    public:
        string get_ID();
        string get_pwd();
        string get_name();
        void getaccount(ifstream &f);
        void out_account();
        bool checkid(string id);
		bool checkpwd(string pwd);
        void set_account(string ID, string pwd, string name);
        void save_account(fstream &f);
};

#endif