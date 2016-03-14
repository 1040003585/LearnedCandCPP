#include"Book.h"
#include<string>//.h
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
CBook::	CBook(char* cName,char* cIbsn,char* cPrice,char* cAuthor){
	strncpy(m_cName,cName,NUM1);
	strncpy(m_cIbsn,cIbsn,NUM1);
	strncpy(m_cPrice,cPrice,NUM2);
	strncpy(m_cAthor,cAthor,NUM2);
}
char *CBook::GetName(){
	return m_cName;
}//*
char CBook::SetName(char *cName){
	strncpy(m_cName,cName,NUM1);
}
char CBook::*GetIsbn(){
	return m_cIsbn;
}
char CBook::SetIsbn(char *cIbsn){
	strncpy(m_cIbsn,cIbsn,NUM1);
}
char CBook::*GetPrice(){
	return m_cPrice;
}
char CBook::SetPrice(char *cPrice){
	strncpy(m_cPrice,cPrice,NUM2);
}
char CBook::*GetAuthor(){
	return m_cAuthor;
}
char CBook::SetAuthor(char *cAuthor){
	strncpy(m_cAthor,cAthor,NUM2);
}

//把图书对象写入文件
void CBook::WriteData(){
	ofstream ofile;
	ofile.open("book.dat",ios::binary|ios::app);//binary,app
	try{
		ofile.write(m_cName,NUM1);
		ofile.write(m_cIsbn,NUM1);
		ofile.write(m_cPrice,NUM2);
		ofile.write(m_cAuthor,NUM2);
	}
	catch(...){
		throw "FILE ERROR OCCURRED";
		ofile.close();
	}
	ofile.close();
}

//从文件中读取数据来构建对象
void CBook::DeleteData(int iCount){
	char cName[NUM1];
	char cIsbn[NUM1];
	char cPrice[NUM2];
	char cAuthor[NUM2];
	ifstream ifile;
	ifile.open("book.dat",ios::binary);
	try{
		ifile.seekg(iCount*(NUM1+NUM1+NUM2+NUM2),ios::beg);//beg
		ifile.read(cName,NUM1);
		if(ifile.tellg()>0)	strncpy(m_cName,cName,NUM1);
		ifile.read(cIsbn,NUM1);
		if(ifile.tellg()>0)	strncpy(m_cIsbn,cIsbn,NUM1);
		ifile.read(cPrice,NUM2);
		if(ifile.tellg()>0)	strncpy(m_cPrice,cPrice,NUM2);
		ifile.read(cAuthor,NUM2);
		if(ifile.tellg()>0)	strncpy(m_cAuthor,cAuthor,NUM2);
	}
	catch(...){
		throw "File error occurred";
		ifile.close();
	}
	ifile.close();
}

//图书从文件中删除
void CBook::GetBookFromFile(int iCount){
	long respos;
	int iDataCount=0;
	fstream file;
	fstream tmpfile;
	ofstream ofile;
	char cTempBuf[NUM1+NUM1+NUM2+NUM2];
	file.open("book.dat",ios::binary|ios::in|ios::out);//in,out
	tmpfile.open("temp.dat",ios::binary|ios::in|ios::out|ios::trunc);//in,out,trunc
	file.seekg(0,ios::end);
	respos=file.tellg();
	iDataCount=respos/(NUM1+NUM1+NUM2+NUM2);
	if(iCount<0&&iCount>iDataCount){
		throw "input number error";
	}
	else{
		file.seekg((iCount)*(NUM1+NUM1+NUM2+NUM2),ios::beg);//beg
		for(int j=0;j<(iDataCount-iCount);j++){
			memset(cTempbuf,0,NUM1+NUM1+NUM2+NUM2);
			file.read(cTempbuf,NUM1+NUM1+NUM2+NUM2);
			tmpfile.write(cTempbuf,NUM1+NUM1+NUM2+NUM2);
		}
		file.close();
		tmpfile.seekg(0,ios::beg);
		ofile.open("book.dat");
		ofile.seekp((iCount-1)*(NUM1+NUM1+NUM2+NUM2),ios::beg);//beg
		for(int i=0;i<(iDataCount-iCount);i++){
			memset(cTempbuf,0,NUM1+NUM1+NUM2+NUM2);
			tmpfile.read(cTempbuf,NUM1+NUM1+NUM2+NUM2);
			ofile.write(cTempbuf,NUM1+NUM1+NUM2+NUM2);
		}	
	}
	tmpfile.close();
	ofile.close();
	remove("temp.dat");

}

