//TP312 L764  C++��Ŀ����ȫ��ʵ¼����ͼ�����ϵͳ
#define NUM1 128
#define NUM2 50
class CBook
{
public:
	CBook(){}
	CBook(char* cName,char* cIbsn,char* cPrice,char* cAuthor);
	~CBook(){}//{cout<<"����\n";}
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
