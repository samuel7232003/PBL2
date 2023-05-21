#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include "ticket.h"
#include "ctime"

template <typename T> string tostr(const T& t){
	ostringstream os; os<<t; return os.str();
}

void ticket::getticket(fstream &f){
	string e;
	getline(f,this->ID_ticket);
	getline(f,this->ID_acc,'-');
	getline(f,this->ID_film,'-');
    getline(f,this->ID_scr);
	f>>this->day_now; f>>this->month_now; f>>this->year_now;
	f>>this->day; f>>this->month; f>>this->year; 
	f>>this->start_time; getline(f, e);
	f>>this->so_ve;
    getline(f,this->vi_tri);
	f>>this->cost; getline(f, e);
	f>>this->so_bap; f>>this->so_nuoc; getline(f, e);
	this->hang[1]=-1;
}

void ticket::get_date_now(){
	time_t baygio = time(0);
    tm *ltm = localtime(&baygio);
    this->year_now= 1900 + ltm->tm_year;
	this->month_now=  1 + ltm->tm_mon;
	this->day_now=  ltm->tm_mday ;
}

void ticket::out_date(){
	cout<<this->day<<"/"<<this->month<<"/"<<this->year;
}
void ticket::out_date_now(){
	cout<<this->day_now<<"/"<<this->month_now<<"/"<<this->year_now;
}

string chance(int x, int y)
{
	string newstring="";
	newstring+=char(x+65);
	if (y+1<=9)
	newstring+=char(y+1+48);
	else
	{
		newstring+=char(1+48);
		newstring+=char((y+1)%10+48);
	}
	return newstring;
}

void ticket::set_ID(){
	string new_ID;
	time_t baygio = time(0);
	int t = baygio;
    new_ID= new_ID + this->ID_acc + this->ID_film + tostr(t%100000);
	this->ID_ticket = new_ID;
}

void ticket::setticket(fstream &f){
	string e;
	getline(f,this->ID_acc,'-');
    getline(f,this->ID_film,'-');
	getline(f,this->ID_scr,'-');
	getline(f,e);
	f>>this->day; f>>this->month;f>>this->year; f>>this->start_time;
	int cost_film;
	f>>cost_film;
	f>>this->so_ve;
	getline(f,e);
	for(int i=0;i<this->so_ve;i++){
		f>>this->hang[i];
	    f>>this->cot[i];
		getline(f,e);
	}
	f>>this->so_bap;
	f>>this->so_nuoc;
	this->cost = cost_film+(so_bap+so_nuoc)*30000;
	this->get_date_now();
	this->set_ID();
}

void fix_time_(float x){
	int t;
	t=x;
	int p;
	p=(x-int(x))*60;
	string a = " AM";
	if(t>12){
		a = " PM";
        t=t-12;
	}
	cout<< t<<"h"<<p<<a;
}

string search_name_acc(string id){
    fstream f;
	f.open("./database/data_account_user.txt");
	string check;
	while (!f.eof()){
		getline(f,check,'-');
		if(id==check) {
			getline(f,check,'-');
         getline(f, check);
         return check;
		}
		else getline(f, check);
	}
	f.close();
}

string search_name_film(string id){
    fstream f;
	f.open("./database/data_film.txt");
	string check;
	while (!f.eof()){
		getline(f,check,'-');
		if(id==check) {
			getline(f,check,'-');
        	return check;
		}
		else getline(f, check);
	}
	f.close();
}

void _yellow(string a){
	setcolor(0,14);
	cout<<a;
	setcolor(0,15);
}

void ticket::outticket(int &so_tien){
	cout<<"\n\n\n\n"<<setw(70)<<" ";
	setcolor(2,15);
	cout<<setw(5)<<" "<<"---Hoa don mua ve xem phim---"<<setw(5)<<" "<<endl<<endl;
	setcolor(0,15);
	cout<<setw(70)<<" ";_yellow("Ma don hang: ");cout<<this->ID_ticket<<endl;
	cout<<setw(70)<<" ";_yellow("Ngay dat: "); this->out_date_now(); cout<<endl;
	string acc;
	acc = search_name_acc(this->ID_acc);
	cout<<setw(70)<<" ";_yellow("Ten khach hang: ");cout<<acc<<endl;
	acc = search_name_film(this->ID_film);
	cout<<setw(70)<<" ";_yellow("Ten phim: ");cout<<acc<<endl;
	cout<<setw(70)<<" ";_yellow("Thoi gian chieu: "); fix_time_(this->start_time);cout<<endl;
	cout<<setw(70)<<" ";_yellow("Ngay: "); this->out_date(); cout<<endl;
	cout<<setw(70)<<" ";_yellow("So luong: ");cout<<this->so_ve<<endl;
	cout<<setw(70)<<" ";_yellow("Vi tri: ");
	if(this->hang[1]==-1) cout<<this->vi_tri;
	else{
        for(int i=0; i<this->so_ve;i++){
		    cout<< chance(this->hang[i],this->cot[i]);
		    cout<<" ";
	    }
	}
	cout<<endl;
	cout<<setw(70)<<" ";_yellow("Dat them: ");cout<<this->so_bap<< " bap, "<<this->so_nuoc<<" pepsi"<<endl;
	cout<<setw(70)<<" "<<" ------"<<endl;
	cout<<setw(70)<<" ";setcolor(0,9); cout<<"Thanh tien: "<<this->cost<<" VND"<<endl<<endl; setcolor(0,15);
	cout<<setw(70)<<" ";
	setcolor(2,15); cout<<setw(41)<<" "<<endl; setcolor(0,15);
	so_tien = this->cost;
}

void ticket::savedata(){
	string s;
	s = "./database/data_output/" + this->ID_ticket + ".txt";
	ofstream f1(s.c_str());
	f1.close();
	fstream f;
	f.open(s.c_str());
	f<<this->ID_ticket<<endl;
	f<<this->ID_acc<<"-"<<this->ID_film<<"-"<<this->ID_scr<<endl;
	f<<this->day_now<<" "<<this->month_now<<" "<<this->year_now<<" ";
    f<<this->day<<" "<<this->month<<" "<<this->year<<" "<<this->start_time<<endl;
	f<<this->so_ve<<" ";
	for(int i=0;i<this->so_ve;i++){
		f<<chance(this->hang[i],this->cot[i])<<",";
	}
	f<<endl<<this->cost;
	f<<endl<<this->so_bap<<" "<<this->so_nuoc;
	f.close();

	s = "./database/data_acc_book/" + this->ID_acc + ".txt";
	fstream f2;
	f2.open(s.c_str());
	f2.seekg(0,ios_base::end);
	f2<<this->ID_ticket<<endl;
	f2<<this->ID_acc<<"-"<<this->ID_film<<"-"<<this->ID_scr<<endl;
	f2<<this->day_now<<" "<<this->month_now<<" "<<this->year_now<<" ";
    f2<<this->day<<" "<<this->month<<" "<<this->year<<" "<<this->start_time<<endl;
	f2<<this->so_ve<<" ";
	for(int i=0;i<this->so_ve;i++){
		f2<<chance(this->hang[i],this->cot[i])<<",";
	}
	f2<<endl<<this->cost;
	f2<<endl<<this->so_bap<<" "<<this->so_nuoc<<endl;
	f2.close();
} 

bool ticket::checkid(string id){
	if(this->ID_ticket==id) return true;
	else return false;
}

void ticket::check_ticket(){
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<setw(80)<<" ";
	setcolor(2,15); cout<<">>Hay nhap ID ve can kiem tra!<<"<<endl; setcolor(0,15);
	cout<<setw(80)<<" "; cout<<"---> "; 
	string ID, file; getline(cin,ID);
    file = "./database/data_output/" + ID + ".txt";
	fstream f;
	f.open(file.c_str());
	if(!f){
		setcolor(0,4);
		cout<<endl<<setw(80)<<" "<<"Khong tim thay ket qua nao!"<<endl;
		setcolor(0,15);
		cout<<endl<<setw(80)<<" "<<"Nhap lai khong (1. Co/ 2.Thoat) ?";
		int i; cin >>i; getline(cin, ID);
		if(i==1) check_ticket();
		return;
	}
    this->getticket(f);
	int bla;
    this->outticket(bla);
	cout<<endl<<setw(80)<<" "; system("pause");
}

void ticket::update_cost(int so_tien){
	this->cost = so_tien;
}

void ticket::set_ID(string ID){
	this->ID_ticket = ID;  
}