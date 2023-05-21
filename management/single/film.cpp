#include <iostream>
#include "film.h"
#include <fstream>
#include <string>
using namespace std;

void film::getfilm(fstream &f){  //
	getline(f, this->ID_film, '-');
	getline(f, this->name_film, '-');
	getline(f, this->infor_film);
}

void film::get_list_scr(){  //
	list_screening lst;
	lst.get_list_scr(this->ID_film);
	this->lst = lst;
}

void film::outname_film(){ //
	cout<<this->name_film<<endl;
}

void film::outfilm(){ //
    system("cls");
	cout<<"\n\n\n";
	for(int j=0; j<10;j++){
		cout<<setw(40)<<" ";	
		cout<<"      ";
		setcolor(2,15);
		if(j==0){
		    cout<<char(218);
		    for(int y=0; y<18;y++) cout<<char(196);
		    cout<<char(191);
		}
		else if(j==9){
			cout<<char(192);
			for(int y=0; y<18;y++) cout<<char(196);
			cout<<char(217);
		}
		else if (j==5){
			cout<<char(179);
			string name = this->name_film;
			cout<<setw(18-(18-name.length())/2)<<name;
			cout<<setw((18-name.length())/2+1)<<char(179);
		}
		else {
			cout<<char(179)<<setw(19)<<char(179);
		}
		setcolor(0,15);
		cout<<endl;
	}
	cout<<endl;
	cout<<setw(45)<<" ";
	setcolor(0,6); cout<<"->Thong tin: ";setcolor(0,15);
    int a = this->infor_film.length();
    this->infor_film.c_str();
    for(int i=0; i < a;i++){
        if(i%100==0) cout<<endl<<setw(45)<<" ";;
        cout<<this->infor_film.c_str()[i];
    }
}

void film::out_list_scr(){ //
	this->lst.out_list_scr(); 
}

void film::book_scr(int &so_ve){ //
	this->lst.booking_scr(so_ve);
}

string film::getID(){ //
	return this->ID_film;
}

string film::get_name(){ //
	return this->name_film;
}

void film::updatedata(){//
	this->lst.save_data_sheet(this->ID_film);
}

bool film::checkid(string id){
	if(this->ID_film==id) return true;
	else return false;
}

void film::setfilm(string id, string name, string infor){
    this->ID_film=id;
	this->name_film=name;
	this->infor_film=infor;
}

void film::set_screening(){
	this->lst.set_list_scr(this->ID_film);
}

void film::save_data_film(fstream &f){
    f<<this->ID_film<<"-"<<this->name_film<<"-"<<this->infor_film;
}

void film::set_new_data(fstream &f1, fstream &f2){
	this->lst.set_new_data(f1,f2);
}

 void film::edit_infor_film(){
	int i;
	cout<<"\n\n\n"<<setw(80)<<" ";
	setcolor(0,14); cout<<"Ban muon thay doi thong tin gi?"<<endl; setcolor(0,15);
	cout<<setw(80)<<" "<<" - 1. Ten phim"<<endl;
	cout<<setw(80)<<" "<<" - 2. Thong tin"<<endl;
	cout<<setw(80)<<" "<<"----->"; cin>>i; string e; getline(cin, e);
	string new_infor;
	getline(cin,new_infor);
	switch (i){
		case 1: {
			cout<<setw(80)<<" ";
			setcolor(0,14); cout<<"Nhap ten moi: "; setcolor(0,15);
			getline(cin, new_infor);
			this->name_film = new_infor;
			break;
		}
		case 2: {
			cout<<setw(80)<<" ";
			setcolor(0,14); cout<<"Nhap thong tin moi: "; setcolor(0,15);
			getline(cin, new_infor);
			this->infor_film = new_infor;
			break;
		}
	}
	int t;
	cout<<endl<<setw(80)<<" ";
	cout<<"Thay doi them (1. Co, 2. Khong) ?"; cin>>t; getline(cin, e);
	if(t==1) this->edit_infor_film();
 }

void film::edit_list_scr(){
	this->lst.edit_list_scr(this->ID_film);
}

void film::out_data_sheet(){
	this->lst.out_data_sheet();
}