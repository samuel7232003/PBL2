#ifndef list_film_h
#define list_film_h
#include "./single/film.cpp"
#include "../Template/LinkedList.cpp"

class list_film: public LinkedList<film>
{
	public:
		void getlist_film(); //
		void outlist_film(); //
		void booking(int &so_ve);//
		void updatedata();//
		void outlist();//
        void chance_list_film();//
		void add_new_film();//
		void remove_film();//
		void save_data_films();//
		void edit_infor_film();//
		void edit_screening(); //
		void check_sheet();
}; 

#endif
