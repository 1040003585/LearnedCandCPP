struct pubtime				//�������ʱ��Ϊ�ṹ�����
{
	int year;				//������
	int mon;				//������
	int day;				//������
};
class Book
{
 public:
	string getbname()const{return bname;}				//��ȡ����
	string getauthor()const{return author;}				//��ȡ����
	string getclassif()const{return classif;}           //��ó���ʱ��

	void tinput();										//�������ʱ��
	void input();										//����ͼ����Ϣ
	void tidisplay();									//�������ʱ��
	void display();										//���ͼ����Ϣ
	int stock;					//�����
	int num;					//��¼�� 
	bool mark;					//�����ǣ�falseΪδ�����trueΪ���
protected:
	float price;				//�۸�
	char bname[30];				//����
	char author[30];			//����
	char classif[30];			//��ķ���
	char pubunit[30];			//���浥λ     
	pubtime time;				//����ʱ��
};