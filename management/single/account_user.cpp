#include <iostream>
using namespace std;
#include "account_user.h"
#include <string>
#include <fstream>

char xep_loai_acc(int n){
	if(n>=5000) return 'A';
	else if (n>=2000) return 'B';
	else if (n>=500) return 'C';
	else return 'D';
}

void account_user::getdata_diemtichluy(ifstream &f){
	string e;
	getline(f, e, '-');
	f>>this->diemtichluy;
}

void account_user::outaccount(){
	this->out_account();
	cout<<setw(80)<<" ";
	setcolor(0,14); cout<< "Diem tich luy: ";setcolor(0,15); cout<< this->diemtichluy<< endl;
	cout<<setw(80)<<" ";
	setcolor(0,14);cout<< "Loai khach hang: ";setcolor(0,15); cout<< this->loai_khach_hang<<endl;
} 

void account_user::outaccount_ticket(){
	cout<<setw(80)<<" ";
	setcolor(0,14); cout<< "ID: "; setcolor(0,15); cout<<this->get_ID()<<endl;
	cout<<setw(80)<<" "; 
	setcolor(0,14); cout<< "Ten khach hang: "; setcolor(0,15); cout<<this->get_name()<<endl;
	cout<<setw(80)<<" "; 
	setcolor(0,14); cout<< "Loai khach hang: "; setcolor(0,15); cout<< this->loai_khach_hang<<endl; 
}

string account_user::getID(){
	return this->get_ID();
}

char account_user::getlkh(){
	return this->loai_khach_hang;
}

void account_user::get_lkh(){
	this->loai_khach_hang=xep_loai_acc(this->diemtichluy);
}

void account_user::setaccount(string ID, string pwd, string name){
	this->set_account(ID, pwd, name);
	this->diemtichluy=0;
	this->loai_khach_hang='D';
}


account_user account_user::update_diemtichluy(int n){
	n=n/1000;
	this->diemtichluy=this->diemtichluy+n;
	return *this;
}

void account_user::save_update_diemtichluy(fstream &f){
	f<<this->getID()<<"-"<<this->diemtichluy;
}

void account_user::booking_snack(int so_ve){
	cout<<endl<<setw(70)<<" ";
	setcolor(2,15); cout<<"Ban muon dat them bap, nuoc khong?\n\n"; setcolor(0,15);
	cout<<setw(70)<<" "<<"1. Combo "<<so_ve<<" bap, "<<so_ve<<" pepsi "<<"gia: "<<2*so_ve*30000<<endl;
	cout<<setw(70)<<" "<<"2. Dat theo lua chon"<<endl;
	cout<<setw(70)<<" "<<"3. Khong dat "<<endl;
	int n;
	cout<<endl<<setw(70)<<" "<<"--->"; cin>>n; string e; getline(cin, e);
	switch (n) {
        case 1:{
			this->soluongbap = so_ve;
			this->soluongnuoc = so_ve;
			break;
		}
		case 2: booking_snack_banphim(); break;
		case 3:{
            this->soluongbap = 0;
			this->soluongnuoc = 0;
			break;
		}
	}
	fstream f;
	f.open("~/../database/hoa_don.txt");
	f.seekg(0, ios::end);
	f<<this->soluongbap<<" "<<this->soluongnuoc;
	f.close();
}

void account_user::booking_snack_banphim(){
	system("cls");
	cout<<"\n\n\n\n\n"<<setw(70)<<" ";
	setcolor(2,15); cout<<"  Hay nhap so luong bap nuoc ma ban muon  \n\n"; setcolor(0,15);
	int so_bap, so_nuoc;
	cout<<setw(70)<<" ";setcolor(0,14); cout<<"- So bap: "; setcolor(0,15); cin>>so_bap;
	cout<<setw(70)<<" ";setcolor(0,14); cout<<"- So nuoc: "; setcolor(0,15); cin>>so_nuoc;
	cout<<"\n"<<setw(70)<<" ";setcolor(0,2);cout<<">>> Gia tien: "<<30000*(so_bap+so_nuoc)<<endl<<endl;setcolor(0,15);
	cout<<setw(70)<<" "<<"Xac nhan so luong bap va nuoc?"<<endl;
	cout<<setw(70)<<" "<<"1. Xac nhan"<<endl;
	cout<<setw(70)<<" "<<"2. Dat lai"<<endl;
	cout<<setw(70)<<" "<<"3. Khong dat nua"<<endl;
	int n;
	cout<<setw(70)<<" "<<"-->"; cin>>n; string e; getline(cin, e);
	switch (n){
		case 1:{
			this->soluongbap = so_bap;
			this->soluongnuoc = so_nuoc;
			break;
		}
		case 2: this->booking_snack_banphim(); break;
		case 3:{
			this->soluongbap = 0;
			this->soluongnuoc = 0;
			break;
		}
	}
}

void account_user::discout(int &so_tien){
	cout<<"\n\n";
	int j= 65;
	setcolor(0,2);
	cout<<setw(j)<<" "<<">>Ban co muon doi diem tich luy de lay discout khong?<<"<<endl;
	setcolor(0,15);
	setcolor(0,8);cout<<setw(j)<<" "<<"(ban dang co: "<<this->diemtichluy<<" diem)"<<endl<<endl; setcolor(0,15);
	cout<<setw(j)<<" "<<"1. 500 diem giam 5% tong gia tri don hang"<<endl;
	cout<<setw(j)<<" "<<"2. 1000 diem giam 10% tong gia tri don hang"<<endl;
    cout<<setw(j)<<" "<<"3. 2000 diem giam 25% tong gia tri don hang"<<endl;
	cout<<setw(j)<<" "<<"4. 5000 diem giam 75% tong gia tri don hang"<<endl;
	cout<<setw(j)<<" "<<"5. Thoat!"<<endl;
	int n;
	cout<<setw(j)<<" "<<"--->";cin>>n; string e; getline(cin, e);
	switch (n){
        case 1:{
			if(this->diemtichluy>=500){
				so_tien = so_tien - (so_tien/20);
				this->update_diemtichluy(-500000);
				return;
			}
			break;
		}
		case 2:{
			if(this->diemtichluy>=1000){
				so_tien = so_tien - (so_tien/10);
				this->update_diemtichluy(-1000000);
				return;
			}
			break;
		}
		case 3:{
			if(this->diemtichluy>=2000){
				so_tien = so_tien - (so_tien/4);
				this->update_diemtichluy(-2000000);
				return;
			}
			break;
		}
		case 4:{
			if(this->diemtichluy>=5000){
				so_tien = so_tien - ((so_tien/4)*3);
				this->update_diemtichluy(-5000000);
				return;
			}
			break;
		}
		case 5: return;
	}
	setcolor(0,4);
    cout<<setw(j)<<" "<<"Khong du diem tich luy de chon muc nay, chon lai (1. Co/ 2.Thoat)?"<<endl;
	setcolor(0,15);
	int i;
    cout<<setw(j)<<" "<<"-->";cin>>i; string f; getline(cin, f);
	if(i==1){
		system("cls");
		this->discout(so_tien);
	}
	return;
}

void account_user::edit_account_user(){
	system("cls");
	cout<<"\n\n\n\n";
	int j=80;
    cout<<setw(j)<<" ";
	setcolor(2,15); cout<<" >> Thong tin ve tai khoan cua ban << "<<"\n\n"; setcolor(0,15);
	this->outaccount();
	cout<<setw(j)<<" ";
    setcolor(0,14); cout<<"Mat khau: "; setcolor(0,15); cout<<this->get_pwd()<<endl;
	cout<<"\n\n";
}

account_user account_user::edit_hoten(string ht){
    this->set_name(ht);
	return *this;
}

account_user account_user::edit_pwd(string pwd){
    this->set_pwd(pwd);
	return *this;
}
