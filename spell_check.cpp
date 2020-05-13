#include<bits/stdc++.h>
#include "soundex.h"
#include "edit.h"
using namespace std;

multimap <string, string> model;

void create_map_model(){
	fstream file;
	string word,tmp;
	string filename="words_alpha.txt";
	file.open(filename.c_str());
	while(file>>word){
		tmp=soundex(word);
		model.insert(pair <string, string> (tmp,word));
	}
	file.close();
}

int main(){
	create_map_model();
	multimap<string, string> :: iterator itr;
	multimap<int, string> :: iterator itr2;
	multimap <string, string> near_words;
	multimap <int, string> final;
	string a,b;
	int sum=0;
	//cout<<"Enter string:";
	cin>>a;
	b=soundex(a);
	for(itr=model.begin(); itr!=model.end(); itr++){
		if(b==itr->first)
			near_words.insert(pair<string, string> (itr->first, itr->second));
	}
	for(itr=near_words.begin(); itr!=near_words.end();itr++){
		if(edit(a,a.length(),itr->second,itr->second.length())<3){
			if(edit(a,a.length(),itr->second,itr->second.length())==0){
				cout<<"Word is valid ";
				return 0;
			}
			final.insert(pair<int, string> (edit(a,a.length(),itr->second,itr->second.length()), itr->second));
			sum++;
		}
	}
	if( sum!=0){
		for(itr2=final.begin(); itr2!=final.end();itr2++){
			cout<<itr2->second<<",";
		}
	}
	else{
		cout<<"No Suggestions ";
	}
	return 0;
}