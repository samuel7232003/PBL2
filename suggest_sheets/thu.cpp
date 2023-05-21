#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "../Home/Home_user.cpp"
#include "../Template/LinkedList.cpp"
#include <iostream>
using namespace std;
#include <string>

int main (void)
{
   LinkedList<ticket> li;
   DIR *dp;
   struct dirent *ep;
   string s;
   dp = opendir ("../database/data_output/");
   if (dp != NULL)
   {
       while (ep = readdir (dp))
           puts (ep->d_name);
       (void) closedir (dp);
   }
   else
       perror ("Couldn't open the directory");
   return 0;
}