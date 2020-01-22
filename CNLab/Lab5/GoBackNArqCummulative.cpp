 #include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
 int nf,N;
 int no_tr=0;
 srand(time(NULL));
 cout<<"Enter the number of frames : ";
 cin>>nf;
 cout<<"Enter the Window Size : ";
 cin>>N;
 int i=1;
 while(i<=nf)
 {
     int x=0;
     for(int j=i;j<i+N && j<=nf;j++)
     {
         cout<<"Sent Frame "<<j<<endl;
         no_tr++;
     }
     int LastFrame = 0 ;
     for(int j=i;j<i+N && j<=nf;j++)
     {
         int flag = rand()%3;
         if(flag)
             {
                 x++;
                 cout<<"\t\t\tFrame received "<<j<<endl;
             }
         else
             {   
                LastFrame = j;
                break;
             }
     }
     if(LastFrame==0)
     {
        if(i+N<=nf)
        cout<<"Acknowledgment "<<i+N<<endl;
     }
     else
     {
        cout<<"Acknowledgment "<<LastFrame<<endl;
     }
     cout<<endl;
     i+=x;
 }
 cout<<"Total number of transmissions : "<<no_tr<<endl;
 return 0;
}


