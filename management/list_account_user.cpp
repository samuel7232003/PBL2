#include <iostream>
using namespace std;
#include "list_account_user.h"
#include <fstream>
#include <string>
#include <unistd.h>
#include <conio.h>

void list_account_user::getlist_account(){
	ifstream f;
	f.open("./database/data_account_user.txt", ios_base::out);
	ifstream s;
	s.open("./database/data_account_sodiem.txt", ios_base::out);
    while(!f.eof()){
    	account_user t;
    	t.getaccount(f);
    	t.getdata_diemtichluy(s);
		t.get_lkh();
    	this->addLast(t);
	}
	f.close();
	s.close();
}

void list_account_user::outlist_account(){
	cout<<"\n\n\n"<<setw(80)<<" ";
	setcolor(2,15); cout<<" >>> Danh sach tai khoan <<< \n\n";setcolor(0,15);
	for(int i=0;i<this->length();i++){
		cout<<setw(80)<<" ";
		int j=i+1;
		cout<<" -- "<<j<<" -- \n";
		this->get(i).outaccount();
		cout<<endl;
	} 
}

string PassWord()
{
    string pw;
    for (char c; (c = getch());)
    {
        if (c == '\n' || c == '\r')
        { // phím enter
            cout << "\n";
            break;
        }
        else if (c == '\b')
        { // phím backspace
            cout << "\b \b";
            if (pw.length() != 0)
                pw.erase(pw.size() - 1);
        }
        else if (c == -32)
        {             // phím mũi tên
            _getch(); // bỏ qua kí tự tiếp theo (hướng mũi tên)
        }
        else
        {
            cout << '*';
            pw += c;
        }
    }
    return pw;
}

void list_account_user::login(account_user &a, int &k){
	int j=80;
	cout<<"\n\n\n\n\n";
	cout<<setw(j)<<" ";
	setcolor(2,15);
	cout<<setw(7)<<" "<<"---DANG NHAP!!---"<<setw(7)<<" "<<endl<<endl;
	setcolor(0,15);
	string id, pwd;
	setcolor(0,6);cout<<setw(j)<<" "<<"Nhap ten tai khoan: "; setcolor(0,15); getline(cin, id);
	setcolor(0,6);cout<<setw(j)<<" "<<"Nhap mat khau: "; setcolor(0,15); pwd = PassWord();
	int i;
	i = this->checklogin(id, pwd, a);
	if(i == 1){
		setcolor(0,4);
		cout<<setw(j)<<" "<<"Ten tai khoan khong ton tai. Ban muon dang nhap lai khong (1. Co!/ 2. Khong!):";
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

int list_account_user::checklogin(string id, string pwd, account_user &a){
	int i;
    account_user t;
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

void list_account_user::signup(account_user &a, int &k){
	int j=80;
	cout<<"\n\n\n\n\n";
	cout<<setw(j)<<" ";
	setcolor(2,15);
	cout<<setw(7)<<" "<<"---DANG KI!!---"<<setw(7)<<" "<<endl<<endl;
	setcolor(0,15);
	string new_ID, new_pwd, name;
	setcolor(0,6);cout<<setw(j)<<" "<<"Nhap ten tai khoan: "; setcolor(0,15); getline(cin, new_ID);
	if(new_ID.empty()){
		setcolor(0,4);
		cout<<setw(j)<<" "<<"Ten tai khoan khong hop le! Tiep tuc dang ki (1. Co!/ 2. Khong!): ";
		setcolor(0,15);
		cin>>k; string e; getline(cin, e);
		if (k==1) {
			system("cls");
			this->signup(a, k);
		}
		return;
	}
	for(int i=0; i<this->length();i++){
		if(this->get(i).checkid(new_ID)){
			setcolor(0,4);
			cout<<setw(j)<<" "<<"ID da ton tai. Tiep tuc dang ki (1. Co!/ 2. Khong!): ";
			setcolor(0,15);
			cin>>k; string e; getline(cin, e);
			if(k==1){
				system("cls");
				this->signup(a, k);
				system("cls");
			}
			return;
		}
	}
	setcolor(0,6); cout<<setw(j)<<" "<<"Nhap mat khau: "; setcolor(0,15); getline(cin, new_pwd);
	setcolor(0,6); cout<<setw(j)<<" "<<"Nhap ten cua ban: "; setcolor(0,15); getline(cin, name);
	a.setaccount(new_ID, new_pwd, name);
    this->addLast(a);
    this->update_list_account();
	cout<<endl<<setw(j)<<" ";
	setcolor(2,15);
	cout<<setw(5)<<" "<<"DANG KI THANH CONG!"<<setw(5)<<" "<<endl;
	setcolor(0,15);
	string n;
	n = "./database/data_acc_book/"+ new_ID+".txt";
	ofstream file(n.c_str());
	file.close();
	cout<<setw(j)<<" "; system("pause");
	system("cls");
}

void list_account_user::update_diemtichluy(int n, account_user a){
	ofstream l0;
	l0.open("./database/data_account_sodiem.txt", ios_base::out);
	l0.close();
	fstream l1;
	l1.open("./database/data_account_sodiem.txt");
	account_user b;
	for(int i=0; i<this->length();i++){
		b = this->get(i);
		if(b.checkid(a.getID())){
			if(i!=0) l1<<endl;
		    a.update_diemtichluy(n).save_update_diemtichluy(l1);
		}
		else{
			if(i!=0) l1<<endl;
			b.save_update_diemtichluy(l1);
		}
	}
	l1.close();
}

void Menu_chance_acc(int &i, int &cn){
	int j=80;
	cout<<"\n\n\n\n";
	setcolor(0,14);
	cout<<setw(j+5)<<" "<< ">>>>> BAN MUON ? <<<<<"<<endl<<endl;
	cout<<setw(j)<<" ";
	if(cn==1) setcolor(2,15);
	cout<< "-> Tra cuu thong tin tai khoan."<<endl<<endl;
	if(cn==1) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==2) setcolor(2,15);
	cout<< "-> Xoa tai khoan nguoi dung."<<setw(3)<<" "<<endl<<endl;
	if(cn==2) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==3) setcolor(2,15);
	cout<< "-> Them mot tai khoan moi."<<setw(5)<<" "<<endl<<endl;
	if(cn==3) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==4) setcolor(2,15);
	cout<< "-> Thoat."<<setw(22)<<" "<<endl<<endl;
	if(cn==4) setcolor(0,14);
    int t = getch();
	if(t == 13){
        // nhan enter
        i=cn;
    }
    else if (t==80) cn++;// nhan phim mui ten xuong
    else if (t==72) cn--; // mui ten di len
    if (cn > 4) cn=1;
    else if (cn<1) cn = 4;
	setcolor(0,15);
}

void list_account_user::chance_list_account(){
	int i=0, cn=1;
	while(i==0){
        system("cls");
		Menu_chance_acc(i, cn);
	}
	switch (i){
		case 1:{
			cout<<setw(80)<<" "<<"Nhan 1: Xem het danh sach"<<endl;
			cout<<setw(80)<<" "<<"Nhan 2: Tra cuu theo ID"<<endl;
			cout<<setw(80)<<" "<<"Nhan 3: Tra cuu theo loai khach hang"<<endl;
			int k;
			cout<<setw(80)<<" "<<"--->";cin>>k; string e; getline(cin, e);
			if(k==1){
				system("cls");
				this->outlist_account();
				cout<<setw(80)<<" ";system("pause");
			}
			else if(k==2) this->find_by_ID();
			else if(k==3) this->find_by_lkh();
			break;
		}
		case 2: this->remove_account(); break;
		case 3: this->add_account(); break;
		case 4:{
			cout<<setw(80)<<" ";system("pause");
			system("cls");
			return;
		}
	}
	system("cls");
	chance_list_account();
}

void list_account_user::find_by_ID(){
	string e; int k;
	account_user a;
    cout<<endl<<setw(80)<<" ";
	setcolor(0,14); cout<<">>Nhap ID muon xem: "; setcolor(0,15);
	getline(cin, e);
	cout<<endl;
	this->find_account(e, a, k);
	if(k==-1) return;
	a.outaccount();
	cout<<setw(80)<<" "; system("pause");
}

void list_account_user::find_by_lkh(){
	char a;
	cout<<endl<<setw(80)<<" ";
	setcolor(0,14);cout<<">>Nhap loai khach hang ban muon tra cuu (A, B, C hoac D): ";setcolor(0,15);
	cin>>a;
	system("cls");
	cout<<"\n\n\n"<<setw(80)<<" ";
	setcolor(2,15); cout<<" >>> Danh sach khach hang loai "<<a<<" <<< \n\n";setcolor(0,15);
	int count=0;
	for(int i=0; i<this->length();i++){
		if(this->get(i).getlkh()==a){
			count++;
			cout<<setw(80)<<" ";
            cout<<" -- "<<count<<" -- \n";
			this->get(i).outaccount();
			cout<<endl;
		} 
	}
	if(count==0) cout<<setw(80)<<" "<<"-->Khong co khach hang loai "<<a<<endl;
	else cout<<setw(80)<<" "<<"Danh sach nay co "<<count<<" tai khoan."<<endl;
	cout<<setw(80)<<" ";
	setcolor(0,14); cout<<"Tiep tuc tim kiem?"<<endl;setcolor(0,15);
	cout<<setw(80)<<" "<<" - 1. Co"<<endl;
	cout<<setw(80)<<" "<<" - 2. Thoat"<<endl;
	cout<<setw(80)<<" "<<">>>"; cin>>count; string e; getline(cin, e);
	if(count==1) {
	    system("cls");
		this->find_by_lkh();
	}
	return;
}

void list_account_user::find_account(string e, account_user &a, int &index){
	for(int j=0;j<this->length();j++){
		if(this->get(j).checkid(e)){
			a=this->get(j);
			index =j;
			return;
		}
	}
    cout<<setw(80)<<" ";
	setcolor(0,14);cout<<"Khong tim thay tai khoan. Ban co tim lai khong?"<<endl;setcolor(0,15);
	cout<<setw(80)<<" "<<" - 1. Tiep tuc"<<endl;
	cout<<setw(80)<<" "<<" - 2. Thoat"<<endl;
	int j; cout<<setw(80)<<" "<<"---->"; cin>>j; string g; getline(cin, g);
	if(j==1){
		cout<<endl<<setw(80)<<" ";
	    setcolor(0,14); cout<<">>Nhap ID muon xem: "; setcolor(0,15);
	    getline(cin, e);
	    cout<<endl;
		find_account(e, a, index);
	}
	else{
		index = -1;
		system("cls");
		return;
	}
}

void list_account_user::remove_account(){
	system("cls");
	string s;
	account_user a;
    int index;
	cout<<"\n\n\n\n"<<setw(80)<<" ";
	setcolor(0,14); cout<<"Nhap ID tai khoan muon xoa:"; setcolor(0,15); getline(cin,s);
	this->find_account(s, a, index);
	cout<<endl;
	a.outaccount();
	cout<<endl<<setw(80)<<" ";
	setcolor(0,14);cout<<"Ban co chac muon xoa tai khoan nay khong?"<<endl;setcolor(0,15);
	cout<<setw(80)<<" "<<" - 1. Xoa tai khoan"<<endl;
	cout<<setw(80)<<" "<<" - 2. Thoat"<<endl;
	int i;
	cout<<setw(80)<<" "<<"----> "; cin>>i; string e; getline(cin, e);
	if(i==1){
		this->removeAtIndex(index);
		this->update_list_account();
		cout<<endl<<setw(80)<<" ";
		setcolor(0,14);cout<<"Xoa thanh cong!"<<endl;setcolor(0,15);
		cout<<setw(80)<<" ";system("pause");
	}
}

void list_account_user::update_list_account(){
	ofstream f1;
	f1.open("./database/data_account_user.txt", ios_base::out);
	f1.close();
	fstream f2;
	f2.open("./database/data_account_user.txt");
	this->get(0).save_account(f2);
    for(int i=1; i<this->length();i++){
		f2<<endl;
		this->get(i).save_account(f2);
	}
	f2.close();
	account_user a;
	this->update_diemtichluy(0,a);
}

void list_account_user::add_account(){
	system("cls");
	string new_ID, new_pwd, new_name;
	cout<<"\n\n\n\n"<<setw(80)<<" ";
	setcolor(2,15); cout<<">> Hay nhap thong tin tai khoan moi! <<\n\n";setcolor(0,15);
    this->add_ID(new_ID);
	if(new_ID=="Thoat") return;
    cout<<setw(80)<<" "<<"Nhap mat khau: "; getline(cin,new_pwd);
	cout<<setw(80)<<" "<<"Nhap ho ten: "; getline(cin, new_name);
	account_user a;
	a.setaccount(new_ID, new_pwd, new_name);
	this->addLast(a);
	this->update_list_account();
	cout<<"\n\n"<<setw(80)<<" ";
	setcolor(0,14); cout<<"Them tai khoan thanh cong!"<<endl;setcolor(0,15);
	cout<<setw(80)<<" ";system("pause");
}

void list_account_user::add_ID(string &id){
    cout<<setw(80)<<" "<<"Nhap ID: "; getline(cin,id);
	if(this->checkid(id)){
		cout<<setw(80)<<" "<<"ID da ton tai. Hay nhap ID khac (1. Tiep tuc/ 2. Thoat):";
		int i; cin>>i; string e; getline(cin, e);
		if(i==1) this->add_account();
		id="Thoat";
	}
}

bool list_account_user::checkid(string id){
    for(int i=0; i<this->length();i++){
		if(this->get(i).checkid(id)) return true;
	}
	return false;
}

void list_account_user::edit_account_user(account_user a){
	system("cls");
    int z=-1;
	for(int x=0; x<this->length();x++){
		if(a.get_ID()==this->get(x).get_ID());
    	z=x;
		break;	
	}
	int j=80;
	a.edit_account_user();
	cout<<setw(j)<<" ";
	setcolor(0,2); cout<<"Ban muon chinh chua thong tin nao?\n\n"; setcolor(0,15);
	cout<<setw(j)<<" "<<"1. Ho ten."<<endl;
	cout<<setw(j)<<" "<<"2. Mat khau."<<endl;
	cout<<setw(j)<<" "<<"3. Tro lai."<<endl;
	int i;
	cout<<setw(j)<<" "<<"---> "; cin>>i; string e; getline(cin, e);
	string name_new=a.get_name(), pwd_new=a.get_pwd();
	switch (i){
		case 1:{
			cout<<setw(j)<<" ";
			setcolor(0,14); cout<<"Nhap ho ten moi: "; setcolor(0,15);
		    getline(cin, name_new);
			break;
		}
		case 2:{
			cout<<setw(j)<<" ";
			setcolor(0,14); cout<<"Nhap mat khau moi: "; setcolor(0,15);
		    getline(cin, pwd_new);
			break;
		}
		case 3: return;
	}
	cout<<endl<<setw(j)<<" ";
	setcolor(0,4); cout<<"Xac nhan thay doi (1. Co/2. Khong)?"; setcolor(0,15);
	cin>>i; getline(cin, e);
	if(i==1){
		this->removeAtIndex(z);
		if(z==0) addFirst(a.edit_hoten(name_new).edit_pwd(pwd_new));
		else this->addAtIndex(z, a.edit_hoten(name_new).edit_pwd(pwd_new));
	}
	this->update_list_account();
	this->edit_account_user(a);
}
