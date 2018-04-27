#include<iostream>
#include<cstring>

using namespace std;

bool is_valid_ip(char *ip){

	if(ip==NULL){
		return false;
	}
	int dots=0,i=0,l=strlen(ip);
	while(i<l){
		if(ip[i]=='.'){
	           return false;
		}
		int num=0;
		while(i<l && ip[i]!='.'){
			char c=ip[i++];
			if(c<'0' || c>'9'){
		           return false;
			}
			num=(num*10)+(c-'0');
		}
		if(i<l)
		++dots;
		if(dots>3 || num<0 || num>255){
			return false;
		}
		++i;
	}
	if(dots<3){
		return false;
	}
	else{
		return true;
	}
}

int main(){
   char ip1[] = "255.0.1a0.25a";
    if(is_valid_ip(ip1))
	cout << "valid" << endl;
    else 
	cout << "invalid "<< endl;
   return 0;
}
