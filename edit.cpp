#include "edit.h"
//#include<bits/stdc++.h>
//using namespace std;

int edit(string s1, int m, string s2, int n){
    int ed[m+1][n+1];
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            
            if(i==0){
                ed[i][j]=j;
            }    
            else if(j==0){
                ed[i][j]=i;
            }    
            else if(s1[i-1]==s2[j-1]){
                ed[i][j]=ed[i-1][j-1];
            }
            else{
                ed[i][j]=min(min(ed[i-1][j],ed[i][j-1]),ed[i-1][j-1])+1;
            }
        }
    }
    
    return ed[m][n];
}

//int main(){
//    string s1,s2;
//    cout<<"Enter two words:";
//    cin>>s1>>s2;
//    cout<<"Edit distance:"<<edit(s1,s1.length(),s2,s2.length());
//    return 0;
//}
