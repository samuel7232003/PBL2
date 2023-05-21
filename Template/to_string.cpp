#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T> 
string to_string(T &i){
   ofstream f;
   f.open("nhap.txt",ios_base::out);
   f.close();
   fstream s;
   s.open("nhap.txt");
   s<<i;
   s.seekg(0,ios_base::beg);
   string t;
   getline(s,t);
   s.close();
   return t;
}