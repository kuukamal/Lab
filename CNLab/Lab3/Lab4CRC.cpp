#include<bits/stdc++.h>

using namespace std;

string Xor(string s1,string s2)
{
    int l1 = s1.length(), l2 = s2.length();
    if(l1 <= l2)
    {
        string s = s1;
        s1 = s2;
        s2 = s;
        int l = l1;
        l1 = l2;
        l2 = l;
    }
    while(l2-- && l1--)
    {
        if(s1[l1] == s2[l2])
            s1[l1] = '0';
        else
            s1[l1] = '1';
    }
    
    return s1;
}
int Val(string s)
{
    int val = 0;
    for(int i=s.length()-1; i >= 0 ;i--)
    {
        val += (s[i] - '0') * (1 << s.length()-1-i);
    }
    return val;
}
string mod2div(string transMsg,string key)
{
    int l_key = key.length() , l = transMsg.length() - 1;
    string s = transMsg.substr(0,l_key);
    int pos = l_key;
    while(pos < transMsg.length())
    {
        //cout<<s<<" "<<key<<" "<<pos<<endl;
        if(Val(s) >= Val(key))
        {
            s = Xor(s,key);
            s = s + transMsg[pos++];
        }
        else
        {
            s = s + transMsg[pos++];
        }
    }
    return s;
}
main()
{
     srand(time(0)); 
    string msg = "11110110110010", key = "10011"; // error in 1st and 3rd bits from right
    string rem = mod2div(msg,key);
    string transMsg = Xor(msg,rem);
    cout<<"------------------------- With out Error -----------------------------------------\n";
    cout<<"Sent Message\t: "<<msg<<endl<<"Reminder\t: "<<rem<<endl<<"Encoded Message\t: "<<transMsg<<endl<<"Recived Message\t: "<<transMsg<<endl;
    string test = mod2div(transMsg,key);
    cout<<"Test output\t: "<<test<<endl;
    cout<<"------------------------- With Error ---------------------------------------------\n";
    cout<<"Sent Message\t: "<<msg<<endl<<"Reminder\t: "<<rem<<endl<<"Encoded Message\t: "<<transMsg<<endl;
    int l = rand()%msg.length();
    if(transMsg[l] == '0')transMsg[l] = '1';
    else transMsg[l] = '0';
    cout<<"Recived Message\t: "<<transMsg<<endl;
    test = mod2div(transMsg,key);
    cout<<"Test output\t: "<<test<<endl;
    
}
