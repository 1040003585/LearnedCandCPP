#include <iostream>
#include <string>

using namespace std;

//这个表够复杂了吧！,key要保密
string key="~@$F$6^*(f(_@#$^+_S)AD@FQ%WE';b.15f8aWEdfaR54F^$&U4FASF25fdsfa34v5%Bb%,./>Z?M>^M$?>?>>?/?.m.w6.n>%b.?5.?./b.64.^$^46/64/4.vvvv>.rt/.R.ERf.gf/g.f54af4f4f4D^2F3^!#ASDFEFdfsdf234%gB%";
int length;

string encryptAndDecryptOneTimeSystem(string cleartextOrCiphertext){
	string targetText(1000,'0');//initiaze 1000 zeros
	for(int i=0;i<length;i++){
		targetText[i]=key[i]^cleartextOrCiphertext[i];
	}
	return targetText;
} 

int main(int argc, char** argv) {
	
	string clearText,cipherText;
	cout<<"input your cleartext:";
	getline(cin,clearText);//输入可加空格
	length=clearText.length();
	
	cipherText=encryptAndDecryptOneTimeSystem(clearText);
	cout<<"after encrypting is :"<<cipherText.substr(0,length)<<endl;
	system("pause");
	
	clearText=encryptAndDecryptOneTimeSystem(cipherText);
	cout<<"after decrypting is :"<<clearText.substr(0,length)<<endl;
	system("pause");
	
	return 0;
}