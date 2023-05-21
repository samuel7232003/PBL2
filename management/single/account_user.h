#ifndef account_user_h
#define account_user_h
#include "account.cpp"
#include <string>

class account_user: public account{
	private:
	    int soluongbap,soluongnuoc;
		int diemtichluy;
		char loai_khach_hang;
	public:
		void getdata_diemtichluy(ifstream &f);
		void outaccount();
		void outaccount_ticket();
		string getID();
		char getlkh();
		void get_lkh();
		void setaccount(string ID, string pwd, string name);
		account_user update_diemtichluy(int n);
		void save_update_diemtichluy(fstream &f);
		void booking_snack(int so_ve);
		void booking_snack_banphim();
		void discout(int &so_tien);
		void edit_account_user();
		account_user edit_hoten(string ht);
		account_user edit_pwd(string pwd);
};

#endif
