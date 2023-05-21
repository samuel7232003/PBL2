#include <iostream>
#include "list_film.h"
#include <string>
#include <fstream>
using namespace std;

void list_film::getlist_film(){ //
	fstream f;
	f.open("./database/data_film.txt");
    while(!f.eof()){
    	film t;
    	t.getfilm(f);
		t.get_list_scr();
    	this->addLast(t);
	}
	f.close();
}

void list_film::outlist_film(){ //
	cout<<"\n\n\n\n\n";
	cout<<setw(45)<<" "; setcolor(2, 15);cout<<setw(126)<<" "<<endl;setcolor(0, 15);
	cout<<setw(45)<<" ";
	setcolor(2, 15);
	cout<<setw(40)<<" "<<">>>>> DANH SACH PHIM DANG CHIEU HIEN NAY <<<<<";cout<<setw(40)<<" "<<"\n";
	setcolor(0, 15);
	cout<<setw(45)<<" "; setcolor(2, 15);cout<<setw(126)<<" "<<"\n\n\n\n";setcolor(0, 15);
	int a = this->length();
	int b= a, five = 5;
	a =a/5;
    b= b-a*5;
	int count =0, count2=1;
	for(int i=0; i<=a;i++){
		if(i==a) five = b;
		for(int j=0; j<10;j++){
			cout<<setw(40)<<" ";
			for(int z=0; z<five;z++){
				cout<<"      ";
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
					string name = this->get(count).get_name();
					cout<<setw(18-(18-name.length())/2)<<name;
					cout<<setw((18-name.length())/2+1)<<char(179);
					count++;
				}
				else if (j==4){
					cout<<char(179);
					cout<<setw(9)<<count2<<"."<<setw(9)<<char(179);
					count2++;
				}
				else {
					cout<<char(179)<<setw(19)<<char(179);
				}
			}
			cout<<endl;
		}
	}
}

void list_film::booking(int &so_ve) {//
    system("cls");
	this->outlist_film();
	int n;
	cout<<endl<<setw(45)<<" ";
	setcolor(2, 15);
	cout<<"Nhap phim muon xem (nhap 0 de tro lai):";
	setcolor(0, 15);
	cin>>n; string e; getline(cin, e);
	cout<<"\n\n";
	if(n==0){
		so_ve=0;
		return;
	}
	n=n-1;
	film film;
	film= this->get(n);
	int cn=1, k=0;
	while(k==0){
        film.outfilm();
		cout<<"\n\n\n";
		cout<<setw(50)<<" ";
		if(cn==1) setcolor(2,15); cout<< "  >>>> DAT VE <<<<  "; if(cn==1) setcolor(0,15);
		cout<<setw(20)<<" ";
		if(cn==2) setcolor(2,15); cout<< ">> CHON PHIM KHAC <<"<<endl<<endl; if(cn==2) setcolor(0,15);
		int t = getch();
		if(t == 13){
			// nhan enter
			switch(cn){
				case 1:
					k=1;
					break;
				case 2:
					k=2;
					break;
			}
		}
		else if (t==77) cn++;// nhan phim mui ten phai
		else if (t==75) cn--; // mui ten di trai
		if (cn > 2) cn=1;
		else if (cn<1) cn = 2;
	}
	if(k==2){
    	system("cls");
    	this->booking(so_ve);
    	return;
    }
    else if(k==1){
		film.out_list_scr();
    	film.book_scr(so_ve);
		if(so_ve ==0){
			system("cls");
			this->booking(so_ve);
			return;
		} 
	}
	this->removeAtIndex(n);
	if(n==0) this->addFirst(film);
	else this->addAtIndex(n, film);
}

void list_film::updatedata(){//
	for(int i=0; i<this->length();i++){
		this->get(i).updatedata();
	}
}

void list_film::outlist(){
	for(int i=0;i<this->length();i++){
		int j=i+1;
		cout<<j<<" - ";
		this->get(i).outfilm();
	} 
}

void Menu_chance_lf(int &i, int &cn){
	int j=80;
	setcolor(0,14);
	cout<<setw(j+10)<<" "<< ">>>>> BAN MUON ? <<<<<"<<endl<<endl;
	cout<<setw(j)<<" ";
	if(cn==1) setcolor(2,15);
	cout<< "-> Them phim moi."<<setw(35)<<" "<<endl<<endl;
	if(cn==1) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==2) setcolor(2,15);
	cout<< "-> Xoa phim."<<setw(40)<<" "<<endl<<endl;
	if(cn==2) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==3) setcolor(2,15);
	cout<< "-> Thay doi thong tin cua phim."<<setw(21)<<" "<<endl<<endl;
	if(cn==3) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==4) setcolor(2,15);
	cout<< "-> Them, xoa, thay doi thong tin cua cac xuat chieu."<<endl<<endl;
	if(cn==4) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==5) setcolor(2,15);
	cout<< "-> Thoat."<<setw(43)<<" "<<endl<<endl;
	if(cn==5) setcolor(0,14);
    int t = getch();
	if(t == 13){
        // nhan enter
        i=cn;
    }
    else if (t==80) cn++;// nhan phim mui ten xuong
    else if (t==72) cn--; // mui ten di len
    if (cn > 5) cn=1;
    else if (cn<1) cn = 5;
	setcolor(0,15);
}

void list_film::chance_list_film(){
	int i=0, cn=1;
	while(i==0){
        system("cls");
		this->outlist_film();
		Menu_chance_lf(i, cn);
	}
	switch (i){
		case 1: this->add_new_film(); break;
		case 2: this->remove_film();  break;
		case 3: this->edit_infor_film(); break;
		case 4: this->edit_screening(); break;
		case 5: {
			system("cls");
			return;
		}
	}
	this->chance_list_film();
}

void list_film::add_new_film(){
	system("cls");
    cout<<"\n\n\n\n"<<setw(80)<<" ";
	setcolor(2, 15); cout<< ">>> Nhap cac thong tin cua phim moi! <<<\n\n"; setcolor(0,15); 
	string new_ID, new_name, new_infor;
	cout<<setw(80)<<" "; 
	setcolor(0, 14); cout<<"ID: ";setcolor(0, 15); getline(cin,new_ID);
	int i;
	if(new_ID.empty()){
		cout<<setw(80)<<" "<<"ID khong hop le! Tiep tuc (1. Co/ 2. Thoat): ";
		cin>>i; string e; getline(cin, e);
		if(i==1) this->add_new_film();
		return;
	}
	for(int i=0; i<this->length();i++){
		if(this->get(i).checkid(new_ID)){
			cout<<setw(80)<<" "<<"ID da ton tai. Hay nhap ID khac!! Tiep tuc (1. Co/ 2. Thoat):";
			cin>>i; string e; getline(cin, e);
		    if(i==1) this->add_new_film();
		    return;
		}
	}
	setcolor(0, 14);cout<<setw(80)<<" "<<"Ten phim: "; setcolor(0,15); getline(cin,new_name);
	setcolor(0, 14);cout<<setw(80)<<" "<<"Thong tin: "; setcolor(0,15); getline(cin,new_infor);
	film t;
	t.setfilm(new_ID, new_name, new_infor);
	t.set_screening();
	this->addLast(t);
	fstream a;
	a.open("./database/data_film.txt");
    a.seekp(0, ios_base::end);
	a<<endl;
	t.save_data_film(a);
	a.close();
	string n1, n2;
	n1 = "./database/data_sheets/" + t.getID() + ".txt";
    ofstream file(n1.c_str());
	n2 = "./database/data_time/" + t.getID() + ".txt";
	ofstream file_(n2.c_str());
	file.close();
	file_.close();
	fstream f1, f2;
	f1.open(n1.c_str());
	f2.open(n2.c_str());
	t.set_new_data(f1,f2);
	f1.close();
	f2.close();
	cout<<endl<<setw(80)<<" ";
	setcolor(2, 15); cout<<setw(6)<<" "<<"Da them thanh cong!!"<<setw(6)<<" "; setcolor(0, 15);
	cout<<endl<<setw(80)<<" ";system("pause");
}

void list_film::remove_film(){
    int i, j;
	cout<<endl<<setw(45)<<" ";
	setcolor(0, 14);
	cout<<"Chon phim muon xoa (nhap 0 de tro lai): ";cin>>i; string e; getline(cin, e);
	setcolor(0, 15);
	if(i==0) return;
	i=i-1;
	film film;
	film =this->get(i);
	system("cls");
	this->get(i).outfilm();
	setcolor(0,14);
	cout<<"\n\n"<<setw(45)<<" "<<"Ban co chac muon xoa phim nay khong?"<<endl;
	setcolor(0,15);
	cout<<setw(45)<<" "<<"1. Xoa."<<endl;
	cout<<setw(45)<<" "<<"2. Khong xoa nua."<<endl;
	cout<<setw(45)<<" "<<"--->"; cin >>j; getline(cin, e);
	if(j==1){
		this->removeAtIndex(i);
		this->save_data_films();
		string t;
		t="del .\\database\\data_sheets\\" + film.getID() +".txt";
		system(t.c_str());
		t="del .\\database\\data_time\\" + film.getID() +".txt";
		system(t.c_str());
		cout<<setw(45)<<" ";
		setcolor(2,15);
		cout<<" Da xoa thanh cong!!! "<<endl;
		setcolor(0,15);
	}
}
void list_film::save_data_films(){
	ofstream f1;
	f1.open("./database/data_film.txt", ios_base::out);
	f1.close();
    fstream f;
	f.open("./database/data_film.txt");
	this->get(0).save_data_film(f);
	for(int i=1; i<this->length();i++){
		f<<endl;
		this->get(i).save_data_film(f);
	}
	f.close();
}

void list_film::edit_infor_film(){
	int i;
	cout<<endl<<setw(45)<<" ";
	setcolor(0, 14);
	cout<<"Chon phim muon thay doi thong tin: "; 
	setcolor(0, 15);
	cin>>i; string e; getline(cin, e);
	i=i-1;
	film t;
	t = this->get(i);
	t.outfilm();
	t.edit_infor_film();
	t.outfilm();
	cout<<endl<<setw(80)<<" ";
	setcolor(2,15); cout<<" >>>Xac nhan thay doi!<<< \n\n"; setcolor(0,15);
	cout<<setw(80)<<" "<<" - 1. Xac nhan"<<endl;
	cout<<setw(80)<<" "<<" - 2. Huy."<<endl;
	int j;
	cout<<setw(80)<<" "<<"---->"; cin>>j; getline(cin,e);
	if(j==1){
		this->removeAtIndex(i);
		if(i==0) this->addFirst(t);
		else this->addAtIndex(i, t);
		this->save_data_films();
	}
}

void list_film::edit_screening(){
	cout<<setw(80)<<" "<<"Nhap phim muon chinh sua xuat chieu: ";
	int i; cin>>i; i=i-1;
	film t; t=this->get(i);
	t.outfilm();
	t.out_list_scr();
	t.edit_list_scr();
}

void list_film::check_sheet(){
	system("cls");
	this->outlist_film();
	cout<<setw(45)<<" "<<"Ban muon xem tinh trang dat cho cua phim nao?"<<endl;
	int i;
	cout<<setw(45)<<" "<<"--->";cin>>i; string e; getline(cin,e);
	i=i-1;
	system("cls");
	this->get(i).out_data_sheet();
    cout<<"\n\n"<<setw(80)<<" "<<"Xem phim khac?"<<endl;
	cout<<setw(80)<<" "<<"1. Co"<<endl;
	cout<<setw(80)<<" "<<"2. Thoat"<<endl;
	cout<<setw(80)<<" "<<"---->"; cin>>i; getline(cin, e);
	if(i==1) this->check_sheet();
	else{
		system("cls");
		return;
	}
}