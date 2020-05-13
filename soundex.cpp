#include "soundex.h"
//#include<bits/stdc++.h>
//using namespace std;

const int out_len=4;

char convert(char x){
    switch(x){
        case 'B':
        case 'F':
        case 'P':
        case 'V': return '1';
        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z': return '2';
        case 'D':
        case 'T': return '3';
        case 'L': return '4';
        case 'M':
        case 'N': return '5';
        case 'R': return '6';
        default: return '0';
      }
}

string ConvertToUpperCase(string s){
    for(int i=0;i<s.length();i++)
        s[i]=toupper(s[i]);
    return s;
}

string soundex(string s){
    string output;
    int i;
    s=ConvertToUpperCase(s);
    for(i=0;i<s.length();i++){
        if(i==0)
            output+=s[i];
        if(i>0&&isalpha(s[i]))
            output+=convert(s[i]);
    }
    for(i=1;i<output.length();i++){
        if(output[i-1]==output[i]||output[i]=='0'){
            output.erase(i,1);
            i--;
        }
    }
    if(output.length()<out_len){
        int k=out_len-output.length();
        for(i=0;i<k;i++)
            output+='0';
    }
    else if(output.length()>out_len){
        output=output.substr(0,out_len);
    }
    return output;
}

//int main(){
//    string s;
//    cout<<"Input string:";
//    cin>>s;
//    cout<<"soundex="<<soundex(s);
//    return 0;
//}