%{
	#include<stdio.h>
	#include<string.h>
	#include "string"
	#include "iostream"
	#include "algorithm"
	using namespace std;
	string st;
	string str[10];
	int n=0;
	int INT_MAX=100000000;
%}

%%
[A-Z][-][>]	{
	st = yytext;
}
[|]			{}
[A-Za-z]+		{
	str[n++]=yytext;
}

\n 			{return 0;}
%%
int findMinLength(string arr[], int n) 
{ 
    int min = INT_MAX; 
  
    for (int i=0; i<=n-1; i++) 
        if (arr[i].length() < min) 
            min = arr[i].length(); 
    return(min); 
} 
  
bool allContainsPrefix(string arr[], int n, string str, 
                       int start, int end) 
{ 
    for (int i=0; i<=n-1; i++) 
        for (int j=start; j<=end; j++) 
            if (arr[i][j] != str[j]) 
                return (false); 
    return (true); 
} 
  
string commonPrefix(string arr[], int n) 
{ 
    int index = findMinLength(arr, n); 
    string prefix;
    int low = 0, high = index; 
  
    while (low <= high) 
    { 
        int mid = low + (high - low) / 2; 
  
        if (allContainsPrefix (arr, n, arr[0], low, mid)) 
        { 
            prefix = prefix + arr[0].substr(low, mid-low+1); 
            low = mid + 1; 
        } 
  
        else 
            high = mid - 1; 
    } 
  
    return (prefix); 
} 
int yywrap();
main()
{
	yylex();
	string ans = commonPrefix(str,n);
	if(ans.length()!=0)
	{
		cout<<st<<ans<<"X\n";
		cout<<"X ->";
		for(int i =0;i<n;i++)
			{
				string tmp;
				if(i==n-1)
					{
						if(str[i].length()-ans.length())
						cout<<str[i].substr(ans.length(),str[i].length()-ans.length());
						else
						cout<<"^";
				}
				else
					{
						if(str[i].length()-ans.length())
						cout<<str[i].substr(ans.length(),str[i].length()-ans.length())<<" | ";
						else
						cout<<"^ | ";
				}
			}
	}
	else
	{
		cout<<"Not require!";
	}
	cout<<endl;
}