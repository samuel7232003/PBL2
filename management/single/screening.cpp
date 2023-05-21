#include <iostream>
#include "screening.h"
#include <fstream>
#include <string>
#include <winbgim.h>
#include <windows.h>
#include "../../Template/to_string.cpp"
#include <iomanip>
using namespace std;

void setcolor(int backgound_color, int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void screening::get_scr(fstream &f, string ID_film){
    this->ID_film=ID_film;
    getline(f,this->ID_scr,'-');
    f>>this->start_time;
    f>>this->day;
    f>>this->month;
    f>>this->year;
    f>>this->cost;
    string e;
    getline(f,e);
}

void screening::get_sheet(fstream &f){
    string e;
	getline(f,e);
	for(int j=0;j<10;j++){
	    for(int i=0;i<12;i++){
	    	f>>this->data_sheet[j][i];
		}
		getline(f, e);
    }
}

void screening::out_date(){
	cout<<this->day<<"/"<<this->month<<"/"<<this->year;
}

void fix_time(float x){
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

void screening::out_scr(){
    cout<<"Ngay: "; this->out_date(); cout<<"  ";
    cout<<"Gio: "; fix_time(this->start_time); cout<<"   ";
    cout<<"Gia ve: "<<this->cost<<endl;
}

void screening::out_sheet(){
    cout<<setw(80)<<" "<<"            ---Man Hinh---    "<<endl;
	cout<<setw(80)<<" "<<"   1  2  3  4  5  6  7  8  9  10 11 12  "<<endl;
	cout<<setw(80)<<" "<<"    -------------------------------"<<endl;
	char a='A';
	for(int i=0; i<10;i++){
		cout<<setw(80)<<" "<<char(a+i)<<"- ";
    	for(int j=0; j<12;j++){
			if(this->data_sheet[i][j]==0){
                cout<<char(254)<<"  ";
			}
    		if(this->data_sheet[i][j]==1){
				setcolor(0,4);
				cout<<char(254)<<"  ";
				setcolor(0,15);
			}
			if(this->data_sheet[i][j]==3){
				setcolor(0,10);
				cout<<char(254)<<"  ";
				setcolor(0,15);
			}
		}
		cout<<endl;
	}
}

void screening::save_sheet(fstream &f){
    f<<this->ID_scr<<endl;
	for(int i=0; i<10;i++){
    	for(int j=0; j<11;j++){
    		f<<this->data_sheet[i][j]<<" ";
		}
		f<<this->data_sheet[i][11]<<endl;
	}
}

string screening::get_ID_film(){
	return this->ID_film;
}

string screening::get_ID(){
	return this->ID_scr;
}

void screening::get_suggest(int x[], int y[]){
	int c = 0; 
	for(int i=0;i<10;i++){
		for(int j=0;j<12;j++){
			if(this->data_sheet[i][j]==3){
				x[c]=i;
				y[c]=j;
				c++;
			}
		}
	}
	cout<<endl;
}

screening screening::fixsheet(int x, int y){
	this->data_sheet[x][y]=1;
	return *this;
}

bool screening::checksheet(int x, int y){
	if(this->data_sheet[x][y]==1) return false;
	else return true;
}

void screening::save_hoa_don(fstream &f){
	f<<this->ID_film<<"-"<<this->ID_scr<<"-"<<endl;
	f<<this->day<<" "<<this->month<<" "<<this->year<<" "<<this->start_time<<" ";
}

int screening::getcost(){
	return this->cost;
}

void screening::set_scr(string ID_film){
	cout<<"\n\n\n\n"<<setw(80)<<" ";
    setcolor(2,15);
	cout<<"Nhap thong tin xuat chieu muon them"<<endl<<endl;
	setcolor(0,15);
	this->ID_film = ID_film;
	string e;
	cout<<setw(80)<<" "<<"Nhap gio chieu: "; cin>>this->start_time;
	cout<<setw(80)<<" "<<"Nhap ngay chieu (dd mm yyyy): "; cin>>this->day; cin>>this->month; cin>>this->year;
	cout<<setw(80)<<" "<<"Nhap gia ve: "; cin>>this->cost;
    getline(cin, e);
    for(int i=0; i<10;i++){
		for(int j=0; j<12;j++){
			this->data_sheet[i][j]=0;
		}
	}
	this->ID_scr=this->ID_film + to_string(this->day) + to_string(this->month) + to_string(this->year) + to_string(this->start_time);
}

void screening::set_new_data(fstream &f1, fstream &f2){
	this->save_sheet(f1);
    f2<<this->ID_scr<<"- "<<this->start_time<<" "<<this->day<<" "<<this->month<<" "<<this->year<<" "<<this->cost;
}

void screening::save_time_scr(fstream &f2){
	f2<<this->ID_scr<<"- "<<this->start_time<<" "<<this->day<<" "<<this->month<<" "<<this->year<<" "<<this->cost;
}

void screening::edit_infor_scr(){
	int i;
	system("cls");
	cout<<"\n\n\n"<<setw(75)<<" ";
	this->out_scr();
	cout<<"\n\n";
	this->out_sheet();
	cout<<endl<<setw(80)<<" ";
	setcolor(0, 14); cout<<"Ban muon thay doi thong tin gi?"<<endl; setcolor(0, 15);
	cout<<setw(80)<<" "<<" - 1. Ngay chieu"<<endl;
	cout<<setw(80)<<" "<<" - 2. Gio chieu"<<endl;
	cout<<setw(80)<<" "<<" - 3. Gia ve"<<endl;
	cout<<setw(80)<<" "<<"----->"; cin>>i;
	cout<<"\n\n";
	switch (i){
		case 1: {
			cout<<setw(80)<<" "<<"Nhap ngay moi (dd mm yyyy): ";
			cin>>this->day; cin>>this->month; cin>>this->year;
			break;
		}
		case 2: {
			cout<<setw(80)<<" "<<"Nhap gio chieu moi: ";
			cin>>this->start_time;
			break;
		}
		case 3: {
			cout<<setw(80)<<" "<<"Nhap gia ve moi: ";
			cin>>this->cost;
			break;
		}
	}
	int t;
	cout<<"\n\n"<<setw(80)<<" "<<"Thay doi them (1. Co, 2. Khong) ?"; cin>>t;
	if(t==1) this->edit_infor_scr();
}

int screening::getday(){
	return this->day;
}

int screening::getmonth(){
	return this->month;
}