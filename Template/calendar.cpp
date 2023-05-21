#include <iostream>
#include <conio.h>
#include <ctime>
#include <winbgim.h>
#include <windows.h>
using namespace std;

void setcolor_(int backgound_color, int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

struct date
{
    int d,m,y,a;
};

int nhuan(date x) //Kiem tra nam nhuan hay ko
{
    return (x.y%4==0)?1:0;
}

long daycount(date x) //Tinh khoang cach tu ngay nhap vao voi ngay 1/1/1
{
    return x.d-1+(x.m-1)*30+(x.y-1)*365+x.a+(x.y-1)/4;
}

void print_cal(int D[], int a)
{
    date x;
    int month[42];
    int i,j,ngaymax,ngaydu,k,thu;
	time_t baygio = time(0);
    tm *ltm = localtime(&baygio);
    x.y= 1900 + ltm->tm_year;
	x.m=  1 + ltm->tm_mon;
    switch(x.m)
        {
            case 1: ngaymax=31; ngaydu=0; break;
            case 2: if(nhuan(x)) ngaymax=29; else ngaymax=28; ngaydu=1;  break;
            case 3: ngaymax=31; ngaydu=-1+nhuan(x); break;
            case 4: ngaymax=30; ngaydu=0+nhuan(x); break;
            case 5: ngaymax=31; ngaydu=0+nhuan(x); break;
            case 6: ngaymax=30; ngaydu=1+nhuan(x); break;
            case 7: ngaymax=31; ngaydu=1+nhuan(x); break;
            case 8: ngaymax=31; ngaydu=2+nhuan(x); break;
            case 9: ngaymax=30; ngaydu=3+nhuan(x); break;
            case 10: ngaymax=31; ngaydu=3+nhuan(x); break;
            case 11: ngaymax=30; ngaydu=4+nhuan(x); break;
            case 12: ngaymax=31; ngaydu=4+nhuan(x); break;
        }
        x.a=ngaydu;
        x.d=1; //Gan ngay la ngay mung 1
        thu=daycount(x)%7; //de tinh thu cua ngay dau tien cua thang
        
        for(i=0;i<5;i++)
        {
            for(j=0;j<7;j++)
            {
                if(7*i+j+1<=ngaymax) *(month+7*i+j+thu)=7*i+j+1;
            }
        } //Gan tat ca ngay trong thang vao mot day
        for(i=0;i<thu;i++)
            *(month+i)=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
        for(i=ngaymax+thu;i<42;i++)
            *(month+i)=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t";
        setcolor_(2,15); cout<<">> Lich chieu thang "<<x.m<<"-"<<x.y<<" <<"; setcolor_(0,15);
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\t\t\t"<<"SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\n";
        for(i=0;i<6;i++)
        {
            cout<<"\t\t\t\t\t\t\t\t";
            for(j=0;j<7;j++)
            {
                for(int l=0; l<a; l++){
                    if(*(month+7*i+j)==D[l]) setcolor_(0,2);
                }
                if(*(month+7*i+j)==32) cout<<"\t"; //Thay the gia tri tam thoi bang null
                else cout<<*(month+7*i+j)<<"\t";
                setcolor_(0,15);
            }
            cout<<"\n";
        }
}