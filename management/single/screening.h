#ifndef screening_h
#define ssreening_h
#include <iostream>
using namespace std;

class screening{
    private:
        string ID_scr;
        string ID_film;
        int day, month, year;
        float start_time;
        int cost;
        int data_sheet[10][12];
    public:
        void get_scr(fstream &f, string ID_film);
        void get_sheet(fstream &f);
        void out_date();
        void out_scr();
        void out_sheet();
        void save_sheet(fstream &f);
        string get_ID_film();
        string get_ID();
        void get_suggest(int a[], int b[]);
        screening fixsheet(int x, int y);  
        bool checksheet(int x, int y);
        void save_hoa_don(fstream &f);
        int getcost();
        void set_scr(string ID_film);
        void set_new_data(fstream &f1, fstream &f2);
        void save_time_scr(fstream &f2);
        void edit_infor_scr();
        int getday();
        int getmonth();
};

#endif