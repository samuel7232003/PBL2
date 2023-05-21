#ifndef film_h
#define film_h
#include <string>
#include <fstream>
using namespace std;
#include "../list_screening.cpp"

class film{
	private: 
		string ID_film;
		string name_film;
		string infor_film;
		list_screening lst;
	public:
	    void getfilm(fstream &f); //
		void get_list_scr(); //
	    void outname_film(); //
		void out_list_scr(); //
		void book_scr(int &so_ve); //
		string getID();//
		string get_name();
		void updatedata();//
	    void outfilm(); //
	    void setfilm(string id, string name, string infor);//
		void set_screening();//
		void set_new_data(fstream &f1, fstream &f2);//
		bool checkid(string id);
		void save_data_film(fstream &f);
		void edit_infor_film();//
		void edit_list_scr();
		void out_data_sheet();
};

#endif
