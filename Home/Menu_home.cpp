#include <iostream>
#include <winbgim.h>
#include <windows.h>
using namespace std;

void Menu_infor(){
 	int i, j=60;
 	setcolor(0,9);
	cout<<endl<<setw(j)<<char(201);
 	for (i=0;i<=85;i++) cout<<char(205);
	cout<<char(187);
	cout<<endl<<setw(j)<<char(186)<<setw(61)<<"TRUONG DAI HOC BACH KHOA - DAI HOC DA NANG"<<setw(26)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(53)<<"KHOA CONG NGHE THONG TIN"<<setw(34)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(87)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(54)<<"BPL2: DU AN CO SO LAP TRINH"<<setw(33)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(69)<<"DE TAI: XAY DUNG UNG DUNG DAT VE XEM PHIM TAI RAP PHIM"<<setw(18)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(87)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(27)<<"Sinh vien thuc hien:"<<setw(43)<<"Giao vien huong dan:"<<setw(17)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(12)<<char(45)<<setw(28)<<"Le Huu Minh Vu 21TCLC_KHDL2"<<setw(16)<<char(45)<<setw(18)<<"Tran Ho Thuy Tien"<<setw(13)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(12)<<char(45)<<setw(28)<<"Le Viet Thanh  21TCLC_KHDL2"<<setw(47)<<char(186);
	cout<<endl<<setw(j)<<char(186)<<setw(87)<<char(186);
	cout<<endl<<setw(j)<<char(200);
 	for (i=0;i<=85;i++) cout<<char(205);
 	cout<<char(188)<<endl;
}
void Menu_signup(int &i, int &cn){
	system("cls");
	setcolor(0,14);
	cout<<"\n\n\n\n\n";
	int j=80;
	cout<<setw(j+5)<<" "<< ">>>>> BAN MUON ? <<<<<"<<endl<<endl;
	cout<<setw(j)<<" ";
	if(cn==1) setcolor(2,15);
	cout<< "-> Dang ki tai khoan moi."<<setw(9)<<" "<<endl<<endl;
	if(cn==1) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==2) setcolor(2,15);
	cout<< "-> Dang nhap neu da co tai khoan."<<endl<<endl;
	if(cn==2) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==3) setcolor(2,15);
	cout<< "-> Tro lai."<<setw(22)<<" "<<endl<<endl;
	if(cn==3) setcolor(0,14);
    int t = getch();
	if(t == 13){
        // nhan enter
        i=cn;
    }
    else if (t==80) cn++;// nhan phim mui ten xuong
    else if (t==72) cn--; // mui ten di len
    if (cn > 3) cn=1;
    else if (cn<1) cn = 3;
	setcolor(0,15);
}

void Menu_confirm(int &i, int &cn){
	setcolor(0,14);
	cout<<"\n\n"<<setw(75)<<" "<<">>>Xac nhan lai don hang!<<<"<<endl;
	setcolor(0,15);
	cout<<setw(75)<<" ";
	if(cn==1) setcolor(2, 15); cout<<"     -> Xac nhan!"<<setw(11)<<" "; if(cn==1) setcolor(0, 15);
	cout<<endl<<setw(75)<<" ";
	if(cn==2) setcolor(2, 15); cout<<"     -> Dat phim khac!"<<setw(6)<<" "; if(cn==2) setcolor(0, 15);
	cout<<endl<<setw(75)<<" ";
	if(cn==3) setcolor(2, 15); cout<<"     -> Dang xuat!"<<setw(10)<<" "; if(cn==3) setcolor(0, 15);
	cout<<endl;
    int t = getch();
	if(t == 13){
        // nhan enter
        i=cn;
    }
    else if (t==80) cn++;// nhan phim mui ten xuong
    else if (t==72) cn--; // mui ten di len
    if (cn > 3) cn=1;
    else if (cn<1) cn = 3;
}

void Menu_home(int &i, int &cn){
	setcolor(0,14);
    cout<<endl<<setw(75)<<" "<<">>>>> CHAO MUNG BAN DEN VOI UNG DUNG DAT VE XEM PHIM <<<<<"<<endl<<endl;
	setcolor(0,15);
	cout<<setw(85)<<" ";
	if(cn==1) setcolor(2, 15);
	cout<<"-> Dang nhap/dang ki voi tu cach khach.";
	if(cn==1) setcolor(0, 15);
	cout<<endl<<setw(85)<<" ";
	if(cn==2) setcolor(2, 15);
	cout<<"-> Dang nhap Quan li."<<setw(18)<<" "<<endl;
	if(cn==2) setcolor(0, 15);
	cout<<setw(85)<<" ";
	if(cn==3) setcolor(2, 15);
	cout<<"-> De tat ung dung."<<setw(20)<<" "<<endl;
	if(cn==3) setcolor(0, 15);
	cout<<endl<<setw(85)<<" ";
	setcolor(0,8);
	cout<<"(Nhan len/ xuong de lua chon)";
	setcolor(0,15);
    int t = getch();
	if(t == 13){
        // nhan enter
        i=cn;
    }
    else if (t==80) cn++;// nhan phim mui ten xuong
    else if (t==72) cn--; // mui ten di len
    if (cn > 3) cn=1;
    else if (cn<1) cn = 3;
	// 	while (1){
    //     try{
    //         cout<<setw(85)<<" "<< "----> ";
    //         cin >> i;
    //         if (!cin) throw string("");
    //         else break;
    //     }
	// 	catch (...){
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         cout << "\n\t\t\tNhap Sai! Vui Long Nhap Lai!\n";
    //         continue;
    //     }
    // }
}

void Menu_host_chance(int &i, int &cn){
	setcolor(0,14);
	cout<<"\n\n\n\n\n";
	int j=80;
	cout<<setw(j+5)<<" "<< ">>>>> BAN MUON ? <<<<<"<<endl<<endl;
	cout<<setw(j)<<" ";
	if(cn==1) setcolor(2,15);
	cout<< "-> Kiem tra ve."<<setw(18)<<" "<<endl<<endl;
	if(cn==1) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==2) setcolor(2,15);
	cout<< "-> Them, xoa hoac chinh sua Phim."<<endl<<endl;
	if(cn==2) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==3) setcolor(2,15);
	cout<< "-> Xem, xoa tai khoan nguoi dung."<<endl<<endl;
	if(cn==3) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==4) setcolor(2,15);
	cout<< "-> Xem tinh trang dat cho."<<setw(7)<<" "<<endl<<endl;
	if(cn==4) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==5) setcolor(2,15);
	cout<< "-> Dang xuat."<<setw(17)<<" "<<endl<<endl;
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

void Menu_home_user_(int &i, int &cn){
	setcolor(0,14);
	cout<<"\n\n\n\n\n";
	int j=80;
	cout<<setw(j+15)<<" "<< ">>>>> BAN MUON ? <<<<<"<<endl<<endl;
	cout<<setw(j)<<" ";
	if(cn==1) setcolor(2,15);
	cout<< "-> Dat ve xem phim."<<setw(16)<<" "<<endl<<endl;
	if(cn==1) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==2) setcolor(2,15);
	cout<< "-> Xem/chinh sua thong tin ca nhan."<<endl<<endl;
	if(cn==2) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==3) setcolor(2,15);
	cout<< "-> Xem cac don da dat."<<setw(13)<<" "<<endl<<endl;
	if(cn==3) setcolor(0,14);
	cout<<setw(j)<<" ";
	if(cn==4) setcolor(2,15);
	cout<< "-> Dang xuat."<<setw(21)<<" "<<endl<<endl;
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