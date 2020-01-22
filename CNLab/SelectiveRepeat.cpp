#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
 int nf,N;
 int no_tr=0;
 srand(time(NULL));
 cout<<"Enter the total frames : ";
 cin>>nf;
 cout<<"Enter the value of N : ";
 cin>>N;
 int i=0;
 int br=nf+1;
 int success[nf] = {0};
 int n=0;
 while(i<nf)
 {
     int x=0;
     for(int j=i;j<nf;j++)
     {        
         if(success[j]==0)
         {
            cout<<"Sent Frame "<<j<<endl;   
            no_tr++;
            n+=1;
            if(n==N)
                break;
         }
         
     }
     n=0;
     for(int j=i;j<nf;j++)
     {
         if(success[j]==1)
         {
            j++;
         }
         int flag = rand()%2;
         if(!flag)
             {
                 cout<<"Acknowldgement "<<j<<endl;
                 success[j]=1;
                 x++;
                 n+=1;
             }
         else
             {   
                 
                 cout<<"Negative Acknowledgement "<<"Frame "<<j<<endl;
                 if(br>j)
                    br=j;                    
                 cout<<"Retransmitting"<<endl;
                 n+=1;                
             }
             if(n==N)
                break;
     }
     cout<<endl;
     i=br;
     br=nf+1;
     n=0;
    
 }
 cout<<"Total number of transmissions : "<<no_tr<<endl;
 return 0;
}
