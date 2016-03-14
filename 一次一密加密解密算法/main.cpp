#include <iostream>
#include <string>

using namespace std;

string key(100,'0');//100 zeros
int length;

string encryptAndDecryptOneTimeSystem(string cleartextOrCiphertext){
	string targetText(100,'0');//initiaze 100 zeros
	for(int i=0;i<length;i++){
		targetText[i]=key[i]^cleartextOrCiphertext[i];
	}
	return targetText;
} 

int main(int argc, char** argv) {
	
	string clearText,cipherText;
	cout<<"input your cleartext:";
	cin>>clearText;
	length=clearText.length();
	
	cipherText=encryptAndDecryptOneTimeSystem(clearText);
	cout<<"after encrypting is :"<<cipherText.substr(0,length)<<endl;
	system("pause");
	
	clearText=encryptAndDecryptOneTimeSystem(cipherText);
	cout<<"after decrypting is :"<<clearText.substr(0,length)<<endl;
	system("pause");
	
	return 0;
}
