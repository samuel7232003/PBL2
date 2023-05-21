#ifndef list_screening_h
#define list_screening_h
#include <string>
#include "../Template/LinkedList.cpp"
#include "./single/screening.cpp"

class list_screening :public LinkedList<screening>{
    public:
        void get_list_scr(string ID_film);
        void out_list_scr();
        void booking_scr(int &so_ve);
        void booking_banphim(screening t, int &n, int x[], int y[]);
        void save_data_sheet(string ID_film);
        void set_list_scr(string ID_film);
        void set_new_data(fstream &f1, fstream &f2);
        void edit_list_scr(string ID_film);
        void add_new_scr(screening c);
        void remove_scr(string ID_film);
        void edit_scr(string ID_film);
        void update_data_scr(string ID_film);
        void out_data_sheet();
};  

#endif