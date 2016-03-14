struct pubtime				//定义出版时间为结构体变量
{
	int year;				//出版年
	int mon;				//出版月
	int day;				//出版日
};
class Book
{
 public:
	string getbname()const{return bname;}				//获取书名
	string getauthor()const{return author;}				//获取作者
	string getclassif()const{return classif;}           //获得出版时间

	void tinput();										//输入出版时间
	void input();										//输入图书信息
	void tidisplay();									//输出出版时间
	void display();										//输出图书信息
	int stock;					//库存量
	int num;					//登录号 
	bool mark;					//借出标记，false为未借出，true为借出
protected:
	float price;				//价格
	char bname[30];				//书名
	char author[30];			//作者
	char classif[30];			//书的分类
	char pubunit[30];			//出版单位     
	pubtime time;				//出版时间
};