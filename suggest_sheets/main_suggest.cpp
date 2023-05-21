#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "suggest_sheets.cpp"
#include "../management/list_screening.h"

void print_suggest(list_screening &li, int &i){
	system("cls");
    fstream fsug3;
    fsug3.open("./suggest_sheets/data_suggest.txt");
	char a;
	fsug3>>a;
	if(a==NULL){
		cout<<"Khong co goi y nao! Hay nhap tu ban phim!"<<endl;
		i=1;
		return;
	}
	fsug3.seekp(0,ios_base::beg);
    while(!fsug3.eof()){
    	screening t;
    	t.get_sheet(fsug3);
    	li.addLast(t);
	}
	int count=1;
    for(int i=0;i<li.length()&&i<3;i++){
    	cout<<endl<<setw(78)<<" ";
		setcolor(2,15); cout<<setw(12)<<" "<<"---> Goi y "<<count<<" <---"<<setw(12)<<" ";setcolor(0,15);
		count++;
		cout<<endl;
    	li.get(i).out_sheet();
	}
	fsug3.close();
}

void main_suggest(list_screening &l, screening f, int so_ve, int &i){
    ofstream fsug1;
    fsug1.open("./suggest_sheets/data_film_sheet.txt",std::ofstream::out); fsug1.close();
	fstream fsug3;
	fsug3.open("./suggest_sheets/data_film_sheet.txt");
    f.save_sheet(fsug3);
	fsug3.close();
    ofstream fsug2;
    fsug2.open("./suggest_sheets/data_suggest.txt",std::ofstream::out); fsug2.close();
	i=0;
    suggest_sheets(so_ve);
    print_suggest(l, i);
}

void menu_suggest(int &c, int &cn){
	cout<<"     Ban muon chon theo goi y tren khong?"<<endl<<endl;
	cout<<"     ";if(cn==1) setcolor(2, 15); cout<<"- Chon theo goi y      "<<endl; if(cn==1) setcolor(0, 15);
	cout<<"     ";if(cn==2) setcolor(2, 15); cout<<"- Nhap vi tri khac     "<<endl; if(cn==2) setcolor(0, 15);
	cout<<"     ";if(cn==3) setcolor(2, 15); cout<<"- Chon suat chieu khac."<<endl; if(cn==3) setcolor(0, 15);
	cout<<"     ";if(cn==4) setcolor(2, 15); cout<<"- Chon phim khac.      "<<endl; if(cn==4) setcolor(0, 15);
    int t = getch();
	if(t == 13){
        // nhan enter
        c=cn;
    }
    else if (t==80) cn++;// nhan phim mui ten xuong
    else if (t==72) cn--; // mui ten di len
    if (cn > 4) cn=1;
    else if (cn<1) cn = 4;
} 

void get_suggest(list_screening sug, int x[], int y[]){
	cout<<endl<<"     "<<"Ban muon chon goi y nao?"<<endl;
	int t;
	cout<<"     "<<"----> "; cin>>t; string e; getline(cin, e);
    sug.get(t-1).get_suggest(x,y);
	system("cls");
	sug.get(t-1).out_sheet();
}
