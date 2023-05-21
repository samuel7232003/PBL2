#include <iostream>
using namespace std;
#include "../management/list_film.cpp"
#include "../management/list_account_user.cpp"
#include "../management/ticket.cpp"
#include "../Template/LinkedList.cpp"
#include "Menu_home.cpp"
#include <fstream>
#define Max 120

void print_list_ticket(string ID_acc){
    LinkedList<ticket> li;
	string s = "./database/data_acc_book/" + ID_acc +".txt";
	fstream f;
	f.open(s.c_str());
	while(!f.eof()){
        ticket t;
		t.getticket(f);
		li.addLast(t);
	}
	f.close();
	cout<<setw(80)<<" "<<"Danh sach cac don hang da dat";
	for(int i=0; i<li.length()-1;i++){
		int j;
		li.get(i).outticket(j);
		cout<"\n";
	}
}

void Home_user_(int &i){
	int cn=1;
	while(i==0){
        system("cls");
	    Menu_home_user_(i, cn);
	}
}

void Home_user(){
	system("cls");
	account_user a;
	list_account_user la;
	la.getlist_account();
	int i=-1, n, k =1, cn=1;
	while(i==-1){
	    Menu_signup(i, cn);
	}
	switch (i){
		case 1: {
			system("cls");
			la.signup(a, k);
			if(k!=1) Home_user(); 
			break;
		}
		case 2:{
			system("cls");
            la.login(a, k);
			if(k!=1) Home_user();
			break;
		} 
		case 3: {
			system("cls");
			return;
		}
    }
	loop:;
	ofstream o;
	o.open("./database/hoa_don.txt",ios_base::out);
	o.close();
	fstream f;
	f.open("./database/hoa_don.txt");
	f<<a.getID()<<"-";
	f.close();
    int so_ve=Max;
	i=0;
	while(i==0){
		Home_user_(i);
		switch (i){
			case 1: break;
			case 2: {
				la.edit_account_user(a);
				i=0;
				break;
			}
			case 3:{
				print_list_ticket(a.get_ID());
				cout<<setw(80)<<" ";system("pause");
				i=0;
				break;
			}
			case 4:{
				Home_user();
				return;
			}
			default: {
				i=0;
				break;
			}
		}
	}
	list_film lf;
	lf.getlist_film();
	lf.booking(so_ve);
	if(so_ve==0){
		goto loop;
		return;
	}
	a.booking_snack(so_ve);
	ticket t;
    fstream ft;
	ft.open("./database/hoa_don.txt");
	t.setticket(ft);
	ft.close();
	int so_tien;
	t.outticket(so_tien);
	a.discout(so_tien);
	t.update_cost(so_tien);
	int cn1=1, l=0;
	while(l==0){
		system("cls");
		t.outticket(so_tien);
		Menu_confirm(l, cn1);
	}
	switch (l){
		case 1:
		   	lf.updatedata();
	        la.update_diemtichluy(so_tien,a); 
	        t.savedata();
			setcolor(0,2);
	        cout<<"\n\n"<<setw(65)<<" "<<"Dat ve thanh cong!Ban da duoc cong "<<so_tien/1000<<" diem tich luy!"<<endl;
			cout<<setw(65)<<" "<<"Cam on ban!"<<endl;
			setcolor(0,15);
			cout<<setw(65)<<" ";system("pause");
			system("cls");
	        goto loop;
	        break;
	    case 2: 
		    goto loop; break;
		case 3:
			Home_user(); break;
	}
}
