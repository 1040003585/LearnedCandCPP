#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	cout<<"\n                      The Results Is Following:"<<endl<<endl<<endl;
	while(1){
        int weeks,days,hours,Hours;
		cout<<"  Please input the Hours (input 0 is to exit):  ";
		cin>>Hours;
		while(Hours<0){                      //���ӳ�����ݴ���                                     
			cout<<"  Your input isn't stardand."<<endl<<endl
				<<"  Please input again (input 0 is to exit):  ";
			cin>>Hours;
		}
        if(Hours==0){                 //(input 0 is to exit):
        	cout<<"�˳�\n";
            exit(1);
		}            
//		switch((char)(Hours)){               //��Xʱ�˳�
//		case 120:                            //���У�EXIT()Ҳ����//x120 X88
//		case 88:goto end;
//		}
	    weeks=Hours/(7*24);
		days=(Hours-weeks*7*24)/24;
		hours=Hours%24;
		cout<<"  The Hours is same of   :  "
			<<weeks<<"weeks "
			<<days<<"days "
			<<hours<<"hours "<<endl<<endl;	
	}
//end:cout<<"End\n";
	return 0;
}