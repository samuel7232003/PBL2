#include <iostream>
using namespace std;
#include "list_screening.h"
#include "../suggest_sheets/main_suggest.cpp"
#include <fstream>
#include <string>
#include "../Template/calendar.cpp"
#include <ctime>

void list_screening::get_list_scr(string ID_film){
    string t1, t2;
    t1 ="./database/data_time/" + ID_film +".txt";
    t2 ="./database/data_sheets/" + ID_film +".txt";
    fstream f;
    f.open(t1.c_str());
    fstream s;
    s.open(t2.c_str());
    while(!f.eof()){
        screening scr;
        scr.get_scr(f, ID_film);
        scr.get_sheet(s);
        this->addLast(scr);
    }
    f.close();
    s.close();
}

void list_screening::out_list_scr(){
    int a = this->length();
    int D[a+1], m;
    time_t baygio = time(0);
    tm *ltm = localtime(&baygio);
	m=  1 + ltm->tm_mon;
    for(int i =0;i<this->length();i++){
        if(this->get(i).getmonth()==m) D[i]=this->get(i).getday();
    }
    print_cal(D, a);
    cout<<setw(65)<<" ";
    setcolor(2,15); cout<<"    >>>> DANH SACH CAC SUAT CHIEU <<<<    \n\n"; setcolor(0,15);
    for(int i=0; i<this->length();i++){
        cout<<setw(55)<<" ";
        cout<<"->> Xuat "<<i+1<<" <<-   ";
        this->get(i).out_scr();
    }
}

void choose_sheet(int &x, int &y){
	cout<<"\n"<<setw(80)<<" "<< "Nhap tung vi tri (vi du: 'A1'): ";
	char a;
	cin >> a;
	x = int(a)-65;
    cin >> y; y--; 
}

void list_screening::booking_banphim(screening t, int &n, int x[], int y[]){
    system("cls");
    cout<<"\n\n\n\n";
    t.out_sheet();
    for(int i=0;i<n;i++){
	    choose_sheet(x[i],y[i]);
	    while(t.checksheet(x[i], y[i])==0){
		    cout<<setw(80)<<" ";
            setcolor(0,4); cout<< "Ghe da duoc dat. Vui long chon lai!"<<endl; setcolor(0,15);
		    choose_sheet(x[i], y[i]);
	    }
	}
    system("cls");
    cout<<"\n\n\n\n\n";
}

void list_screening::booking_scr(int &so_ve){
    cout<<endl<<setw(55)<<" ";
    setcolor(0,14); cout<<"Ban muon chon xuat chieu nao (nhap 0 de chon phim khac)?"<<endl;
	int i, num;
	cout<<setw(55)<<" "<<"--->"; setcolor(0,15);
    cin>>i; i=i-1; num = i; string e; getline(cin, e);
    if(i==-1){
        so_ve = 0;
        return;
    }
    cout<<setw(55)<<" "; system("pause");
    system("cls");
	cout<<endl<<setw(80)<<" ";
    setcolor(2,15);
    cout<<setw(7)<<" "<< "-----So do cho ngoi----- "<<setw(7)<<" ";
    setcolor(0,15);
    cout<<"\n\n";
    this->get(i).out_sheet();
    int c=0, k, cn=1;
	cout<<setw(80)<<" "<<"Nhap so luong ve muon dat: "; cin>>so_ve;
    list_screening l;
    screening t;
    t=this->get(i);
    if(k!=1) while(c==0){
        main_suggest(l,t,so_ve, k);
        menu_suggest(c, cn);
    }
    else if(k==1) c=2;
    int x[so_ve], y[so_ve];
	switch (c){
        case 1: get_suggest(l, x, y); break;
        case 2: this->booking_banphim(t,so_ve,x,y); break;
        case 3: {
            this->out_list_scr();
            this->booking_scr(so_ve);
            return;
        }
        case 4: {
            so_ve=0;
            return;
        }
	}
    for(int j=0; j<so_ve;j++){
     	t.fixsheet(x[j],y[j]);
	}
    this->removeAtIndex(i);
    if(i==0) this->addFirst(t);
    else this->addAtIndex(i,t);
    fstream f4;
    f4.open("./database/hoa_don.txt");
	f4.seekg(0,ios_base::end);
	t.save_hoa_don(f4);
    f4<<t.getcost()*so_ve<<" "<<so_ve<<endl;
    for(int j=0; j<so_ve;j++){
        f4<< x[j]<<" "<<y[j]<<endl;
    }
	f4.close();
}

void list_screening::save_data_sheet(string ID_film){
    string t;
	t ="./database/data_sheets/"  + ID_film+ ".txt";
	ofstream f1;
	f1.open(t.c_str(),ios_base::out);
	f1.close();
	fstream f2;
	f2.open(t.c_str());
    this->get(0).save_sheet(f2);
    for(int i=1;i<this->length();i++){
        this->get(i).save_sheet(f2);
    }
    f2.close();
}

void list_screening::set_list_scr(string ID_film){
    int a[0];
    print_cal(a, 0);
    cout<<"\n\n"<<setw(80)<<" ";
    setcolor(2,15); cout<<">> Nhap cac suat chieu cua phim nay <<\n\n"; setcolor(0,15);
    int t=0, i=1;
    while(i==1){
        t++;
        screening c;
        setcolor(0,14);cout<<setw(90)<<" "<<"--Xuat "<<t<<"--"<<endl; setcolor(0,15);
        c.set_scr(ID_film);
        this->addLast(c);
        setcolor(0,2);
        cout<<endl<<setw(80)<<" "<<"Them xuat chieu (1. Co/ 2. Khong)?"; 
        cin>>i; string e; getline(cin, e);
        setcolor(0,15);
    }
}

void list_screening::set_new_data(fstream &f1, fstream &f2){
    this->get(0).set_new_data(f1,f2);
    for(int i=1;i<this->length();i++){
        f2<<endl;
        this->get(i).set_new_data(f1, f2);
    }
}

void list_screening::edit_list_scr(string ID_film){
    list_screening li;
    li.get_list_scr(ID_film);
    *this = li;
    cout<<"\n\n";
    int j=80;
    cout<<setw(j+5)<<" ";
    setcolor(2, 15); cout<<">>>Ban muon<<<\n\n"; setcolor(0, 15);
    cout<<setw(j)<<" "<<" 1. Them xuat chieu"<<endl;
    cout<<setw(j)<<" "<<" 2. Xoa xuat chieu"<<endl;
    cout<<setw(j)<<" "<<" 3. Chinh sua xuat chieu"<<endl;
    cout<<setw(j)<<" "<<" 4. Thoat"<<endl;
    cout<<setw(j)<<" "<<"--->";
    int i; cin>>i;
    switch (i){
        case 1: {
            system("cls");
            screening c;
            c.set_scr(ID_film);
            this->add_new_scr(c);
            system("cls");
            this->out_list_scr();
            break;
        }
        case 2: {
            this->remove_scr(ID_film);
            system("cls");
            this->out_list_scr();
            break;
        }
        case 3: {
            this->edit_scr(ID_film);
            system("cls");
            this->out_list_scr();
            break;
        }
        case 4: return;
    }
    this->edit_list_scr(ID_film);
}

void list_screening::add_new_scr(screening c){
    this->addLast(c);
    string e;
    e ="./database/data_sheets/"+c.get_ID_film()+".txt";
    fstream f1, f2;
    f1.open(e.c_str());
    f1.seekg(0,ios_base::end);
    c.save_sheet(f1);
    f1.close();
    e ="./database/data_time/"+c.get_ID_film()+".txt";
    f2.open(e.c_str());
    f2.seekg(0, ios_base::end);
    f2<<endl;
    c.save_time_scr(f2);
    f2.close();
    cout<<setw(80)<<" "<<"Da them thanh cong!!"<<endl;
    cout<<setw(80)<<" "; system("pause");
}

void list_screening::remove_scr(string ID_film){
    setcolor(0,14);
    cout<<setw(45)<<" "<<"Chon suat chieu ban muon xoa (nhap 0 de thoat)? "<<endl;
    setcolor(0,15);
    int i; cout<<setw(45)<<" "<<"--->";cin>>i;
    if(i==0) return;
    i=i-1;
    system("cls");
    cout<<"\n\n\n\n"<<setw(80)<<" ";
    this->get(i).out_scr();
    this->get(i).out_sheet();
    setcolor(0,14);
    cout<<"\n"<<setw(45)<<" "<<"Ban co chac muon xoa xuat chieu nay khong?"<<endl;
    setcolor(0,15);
    cout<<setw(45)<<" "<<" 1. Xoa"<<endl;
    cout<<setw(45)<<" "<<" 2. Thoat"<<endl;
    int j; cout<<setw(45)<<" "<<"--->";cin>>j;
    if(j==1){
        this->removeAtIndex(i);
        this->update_data_scr(ID_film);
        cout<<"\n"<<setw(45)<<" "<<"Xoa xuat chieu thanh cong!"<<endl;
        cout<<setw(45)<<" "; system("pause");
        this->out_list_scr();
    }
}

void list_screening::edit_scr(string ID_film){
    setcolor(0,14);
    cout<<setw(45)<<" "<<"Chon xuat chieu muon chinh sua thong tin: ";
    setcolor(0,15);
    int i; cin>>i;i=i-1;
    screening c;
    c=this->get(i);
    c.edit_infor_scr();
    this->removeAtIndex(i);
    if(i==0) this->addFirst(c);
    else this->addAtIndex(i, c);
    this->update_data_scr(ID_film);
    cout<<"\n"<<setw(80)<<" ";
    setcolor(0,2); cout<<"Chinh sua thong tin thanh cong!"<<endl; setcolor(0,15);
    cout<<setw(80)<<" "; system("pause");
    this->out_list_scr();
}

void list_screening::update_data_scr(string ID_film){
    string e1, e2;
    e1 = "./database/data_sheets/" + ID_film + ".txt";
    e2 = "./database/data_time/" + ID_film +".txt";
    ofstream f1, f2;
    f1.open(e1.c_str(),ios_base::out);
    f1.close();
    f2.open(e2.c_str(),ios_base::out);
    f1.close();
    fstream f3, f4;
    f3.open(e1.c_str());
    f4.open(e2.c_str());
    this->set_new_data(f3,f4);
    f3.close();
    f4.close();
}

void list_screening::out_data_sheet(){
    this->out_list_scr();
    cout<<"\n\n"<<setw(50)<<" "<<"Chon xuat chieu ban muon xem?"<<endl;
    int i; cout<<setw(50)<<" "<<"--->"; cin>>i; string e; getline(cin, e);
    i=i-1;
    this->get(i).out_sheet();
}