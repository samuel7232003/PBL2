#include <iostream>
using namespace std;
#include "list_account_host.h"
#include <fstream>
#include <string>

void list_account_host::getlist_account(){
	ifstream f;
	f.open("./database/data_account_host.txt", ios_base::out);
    while(!f.eof()){
    	account_host t;
    	t.getaccount(f);
    	this->addLast(t);
	}
	f.close();
}

void list_account_host::outlist_account(){
	cout<<"Danh sach tai khoan:"<<endl;
	for(int i=0;i<this->length();i++){
		int j=i+1;
		cout<<j<<" - ";
		this->get(i).out_account();
	} 
}

void list_account_host::login(account_host &a, int &k){
	int j=80;
	cout<<"\n\n\n\n\n";
	cout<<setw(j)<<" ";
	setcolor(2,15);
	cout<<setw(7)<<" "<<"---DANG NHAP!!---"<<setw(7)<<" "<<endl<<endl;
	setcolor(0,15);
	string id, pwd;
	setcolor(0,6);cout<<setw(j)<<" "<<"Nhap ID: "; setcolor(0,15); getline(cin, id);
	setcolor(0,6);cout<<setw(j)<<" "<<"Nhap mat khau: "; setcolor(0,15); pwd = PassWord();
	int i;
	i = this->checklogin(id, pwd, a);
	if(i == 1){
		setcolor(0,4);
		cout<<setw(j)<<" "<<"ID khong ton tai. Ban muon dang nhap lai khong (1. Co!/ 2. Khong!):";
		setcolor(0,15);
		cin>>k; string e; getline(cin, e);
		if(k==1){
			system("cls");
			this->login(a, k);
		}
		return;
	}
	else if (i == 2){
		setcolor(0,4);
		cout<<setw(j)<<" "<< "Mat khau sai. Ban muon dang nhap lai khong (1. Co!/ 2. Khong!)?";
		setcolor(0,15);
		cin>>k; string e; getline(cin, e);
		if(k==1){
			system("cls");
			this->login(a, k);
		}
		return;
	}
	else{
		cout<<endl<<setw(j)<<" ";
		setcolor(2,15);
		cout<<setw(5)<<" "<<"DANG NHAP THANH CONG!"<<setw(5)<<" "<<endl;
		k=1;
		setcolor(0,15);
		cout<<setw(j)<<" "; system("pause");
	}
	system("cls");
}

int list_account_host::checklogin(string id, string pwd, account_host &a){
	int i;
    account_host t;
	for(i=0; i<this->length();i++){
		if(this->get(i).checkid(id)){
			t=this->get(i);
			i=this->length();
		}
	}
	if(i==this->length()) return 1;
	else{
		if(t.checkpwd(pwd)){
			a=t;
			return 3;
		}
		else return 2;
	}
}