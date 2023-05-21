#ifndef ticket_h 
#define ticket_h
#include "./single/account_user.h"
#include <string>
 
class ticket{
	private:
	    string ID_ticket, ID_acc, ID_film, ID_scr, vi_tri;
		int day_now, month_now, year_now;
		int day, month, year;
		float start_time;
		int so_ve;
		int hang[120];
		int cot[120]; 
		int so_bap, so_nuoc;
		int cost;
	public:
	    void set_ID(string ID);
	    void getticket(fstream &f);
		void setticket(fstream &f);//
		void outticket(int &so_tien);//
		void savedata();//
		void get_date_now();
		void out_date();
		void out_date_now();
		void set_ID();
		bool checkid(string id);
		void check_ticket();
		void update_cost(int so_tien);
};

#endif
