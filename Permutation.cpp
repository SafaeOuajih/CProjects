#include <iostream>
using namespace std;
#include <string>

int main(){

int len = 2100000;
string word;
string word2;
string w1; 
string w2;
int k = 0;
int test =0;
cin >> word;
int l = word.size();
if(l>len){
cout << "invalid len";
exit(1);
}

for(int j =0; j<l ; j++){

	k = 0;
	for(int i =0; i<l/2 ; i++){
		w1[i]=word[i];
	}

	for(int i =0; i<l/2 ; i++){
		w2[i]=word[l-i-1];
	}
	
	for (int i =0; i<l/2 ; i++){
		if(w1[i]!=w2[i] ){
			k = 1;	
		}
	}
	if ( k == 0){
		//cout<<"valid\n";
		test =1;  
		
	}
	word2[0] = word[l-1];
	//cout<< word2<<" \n";
	for(int i =1;i< l;i++){		
		word2[i]=word[i-1];
	}
	for(int i =0;i< l;i++){		
		word[i]=word2[i];
	}
	//cout<<word<<"  \n";
	//word = word2;	
	//cout<< word<<" \n";
	//cout<< word2<<" \n";
}
if(test)
cout<<"VALID"; 
else
cout<<"NOT VALID"; 	
//cout<< word[0];
return 0;
}
