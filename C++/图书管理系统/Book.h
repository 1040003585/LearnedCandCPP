//TP312 L764  C++项目开发全程实录——图书管理系统
#define NUM1 128
#define NUM2 50
class CBook
{
public:
	CBook(){}
	CBook(char* cName,char* cIbsn,char* cPrice,char* cAuthor);
	~CBook(){}//{cout<<"析构\n";}
public:
	char *GetName();
	char SetName(char *cName);
	char *GetIsbn();
	char SetIsbn(char *cIbsn);
	char *GetPrice();
	char SetPrice(char *cPrice);
	char *GetAuthor();
	char SetAuthor(char *cAuthor);
	void WriteData();
    void DeleteData(int iCount);
	void GetBookFromFile(int iCount);
protected:
	char m_cName[NUM1];
	char m_cIbsn[NUM1];
	char m_cPrice[NUM2];
	char m_cAuthor[NUM2];
}
