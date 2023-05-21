#ifndef list_account_user_h
#define list_account_user_h
#include "./single/account_user.cpp"
#include "../Template/LinkedList.cpp"
#include <string>

class list_account_user :public LinkedList<account_user>{
	public:
		void getlist_account();
		void outlist_account();
		void login(account_user &a, int &k);
		int checklogin(string id, string pwd, account_user &a);
		void signup(account_user &a, int &k);
		void update_diemtichluy(int n, account_user a);
		void chance_list_account();
		void find_account(string e, account_user &a, int &index);
		void remove_account();
		void update_list_account();
		void add_account();
		bool checkid(string id);
		void add_ID(string &id);
		void find_by_ID();
		void find_by_lkh();
		void edit_account_user(account_user a);
};

#endif
