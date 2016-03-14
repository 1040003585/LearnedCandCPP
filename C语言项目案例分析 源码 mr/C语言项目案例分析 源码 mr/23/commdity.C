#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

#define LEN sizeof(struct commdity)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA comm[i].num,comm[i].name,comm[i].price,comm[i].count,comm[i].total


struct commdity/*定义商品信息结构体*/
{ 
    int num;/*编号*/
    char name[15];/*商品名称*/
    double price;/*单价*/
    double count;/*数量*/
    double total;/*总金额*/
};

struct commdity comm[50];/*定义结构体数组*/

void in();/*录入商品信息*/
void show();/*显示商品信息*/
void order();/*按总金额排序*/
void del();/*删除商品信息*/
void modify();/*修改商品息*/
void menu();/*主菜单*/
void insert();/*插入商品信息*/
void total();/*计算总商品数*/
void search();/*查找商品信息*/



void main()/*主函数*/
{ 
    int n;
    menu();
    scanf("%d",&n);/*输入选择功能的编号*/
    while(n)
    { 
        switch(n)
        {
        case 1: 
            in();    /*调用录入商品信息过程*/
            break;
        case 2: 
            search();   /*查找商品信息过程*/
            break;
        case 3: 
            del();     /*调用删除商品信息的过程*/
            break;
        case 4:
            modify();   /*调用修改商品信息的过程*/
            break;
        case 5:
            insert();   /*调用插入数据的过程*/
            break;
        case 6:
            order();   /*调用排序过程*/
            break;
        case 7:
            total();   /*计算总数*/
            break;
        default:break;
        }
        getch();
        menu();   /*执行完功能再次显示菜单界面*/
        scanf("%d",&n);
    }
}



void in()/*录入商品信息*/
{ 
    int i,m=0;/*m是记录的条数*/
    char ch[2];
    FILE *fp;/*定义文件指针*/
    if((fp=fopen("data","ab+"))==NULL)/*打开指定文件*/
    { 
        printf("不能打开文件!\n");
        return;
    }
    while(!feof(fp)) 
    { 
        if(fread(&comm[m] ,LEN,1,fp)==1)
            m++;/*统计当前记录条数*/
    }
    fclose(fp);
    if(m==0) 
        printf("没有找到!\n");
    else 
    {
        system("cls");
        show();/*调用show函数，显示原有信息*/
    }
    if((fp=fopen("data","wb"))==NULL)
    { 
        printf("不能打开文件!\n");
        return;
    }
    for(i=0;i<m;i++) 
        fwrite(&comm[i] ,LEN,1,fp);/*向指定的磁盘文件写入信息*/
    printf("是否输入?(y/n):");
    scanf("%s",ch);
    while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要录入新信息*/
    {
        printf("编号:");
        scanf("%d",&comm[m].num);/*输入学生学号*/
        for(i=0;i<m;i++)
            if(comm[i].num == comm[m].num)
            {
                printf("该记录已经存在，按任意键继续!");
                getch();
                fclose(fp);
                return;
            }
            printf("商品名:");
            scanf("%s",comm[m].name);   /*输入学生姓名*/
            printf("单价:");
            scanf("%lf",&comm[m].price);   /*输入商品单价*/
            printf("数量:");
            scanf("%lf",&comm[m].count);   /*输入商品数量*/
            comm[m].total=comm[m].price * comm[m].count;  /*计算出总金额*/
            if(fwrite(&comm[m],LEN,1,fp)!=1)  /*将新录入的信息写入指定的磁盘文件*/
            {
                printf("不能保存!"); 
                getch(); 
            }
            else
            { 
                printf("%s 已经保存!\n",comm[m].name);
                m++;
            }
            printf("是否继续?(y/n):");/*询问是否继续*/
            scanf("%s",ch);
    }
    fclose(fp);
    printf("OK!\n");
}





void show()     /*显示商品信息*/
{
    FILE *fp;
    int i,m=0;
    fp=fopen("data","ab+");
    while(!feof(fp))
    {
        if(fread(&comm[m] ,LEN,1,fp)==1) 
            m++;
    }  
    fclose(fp);
    printf("编号     商品名称      单价       数量      总金额\t\n");
    for(i=0;i<m;i++)
    { 
        printf(FORMAT,DATA);/*将信息按指定格式打印*/
    }
}





void menu()           /*自定义函数实现菜单功能*/
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t|-------------------商品管理系统-----------------|\n");
    printf("\t\t|\t 0. 退出                                 |\n");
    printf("\t\t|\t 1. 录入记录                             |\n");
    printf("\t\t|\t 2. 查找记录                             |\n");
    printf("\t\t|\t 3. 删除记录                             |\n");
    printf("\t\t|\t 4. 修改记录                             |\n");
    printf("\t\t|\t 5. 插入记录                             |\n");
    printf("\t\t|\t 6. 排序记录                             |\n");
    printf("\t\t|\t 7. 统计记录                             |\n");
    printf("\t\t|------------------------------------------------|\n\n");
    printf("\t\t\t选择(0-7):");
}






void order()    /*自定义排序函数*/
{ 
    FILE *fp;
    struct commdity t;
    int i=0,j=0,m=0;
    if((fp=fopen("data","ab+"))==NULL)
    { 
        printf("不能打开文件!\n");
        return;
    }
    while(!feof(fp)) 
        if(fread(&comm[m] ,LEN,1,fp)==1) 
            m++;
        fclose(fp);
        if(m==0) 
        {
            printf("没有记录!\n");
            return;
        }
        for(i=0;i<m-1;i++)
            for(j=i+1;j<m;j++)   /*双重循环实现总金额比较并交换*/
                if(comm[i].total < comm[j].total)
                { 
                    t=comm[i];
                    comm[i]=comm[j];
                    comm[j]=t;
                }
                if((fp=fopen("data","wb"))==NULL)
                { 
                    printf("不能打开\n");
                    return;
                }
                for(i=0;i<m;i++)/*将重新排好序的内容重新写入指定的磁盘文件中*/
                    if(fwrite(&comm[i] ,LEN,1,fp)!=1)
                    { 
                        printf("%s 不能保存!\n"); 
                        getch();
                    }
                    fclose(fp);
                    printf("保存成功\n");
}




void del()/*自定义删除函数*/
{
    FILE *fp;
    int snum,i,j,m=0;
    char ch[2];
    if((fp=fopen("data","ab+"))==NULL)
    { 
        printf("不能打开文件\n");
        return;
    }
    while(!feof(fp))  
        if(fread(&comm[m],LEN,1,fp)==1) 
            m++;
        fclose(fp);
        if(m==0) 
        {
            printf("没有记录!\n");
            return;
        }
        printf("请输入编号:");
        scanf("%d",&snum);
        for(i=0;i<m;i++)
            if(snum==comm[i].num)
                break;
            if(i==m)
            {
                printf("没有找到!");
                getchar();
                return;
            }
            printf("已经找到该记录，是否删除?(y/n)");
            scanf("%s",ch);
            if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要进行删除*/
            {
                for(j=i;j<m;j++)
                    comm[j] = comm[j+1];/*将后一个记录移到前一个记录的位置*/
                m--;/*记录的总个数减1*/
                printf("成功删除!\n");
            }
            if((fp=fopen("data","wb"))==NULL)
            { 
                printf("不能打开!\n");
                return;
            }
            for(j=0;j<m;j++)/*将更改后的记录重新写入指定的磁盘文件中*/
                if(fwrite(&comm[j] ,LEN,1,fp)!=1)
                { 
                    printf("不能保存!\n");
                    getch();
                }
                fclose(fp);
                
}






void search()/*自定义查找函数*/
{ 
    FILE *fp;
    int snum,i,m=0;
    char ch[2];
    if((fp=fopen("data","ab+"))==NULL)
    { 
        printf("不能打开文件\n");
        return;
    }
    while(!feof(fp)) 
        if(fread(&comm[m],LEN,1,fp)==1) 
            m++;
        fclose(fp);
        if(m==0)
        {
            printf("没有记录!\n");
            return;
        }
        printf("请输入编号:");
        scanf("%d",&snum);
        for(i=0;i<m;i++)
            if(snum == comm[i].num)/*查找输入的编号是否在记录中*/
            { 
                printf("已经找到该记录，是否显示?(y/n)");
                scanf("%s",ch);
                if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
                {
                    printf("编号     商品名称      单价       数量      总金额 \t\n");
                    printf(FORMAT,DATA);/*将查找出的结果按指定格式输出*/
                    break;
                }
                else
                    return;
            }   
            if(i==m) 
                printf("没有找到相应的记录!\n");/*未找到要查找的信息*/
}






void modify()/*自定义修改函数*/
{ 
    FILE *fp;
    int i,j,m=0,snum;
        char ch[2];

    if((fp=fopen("data","ab+"))==NULL)
    { 
        printf("不能打开文件!\n");
        return;
    }
    while(!feof(fp))  
        if(fread(&comm[m],LEN,1,fp)==1) 
            m++;
        if(m==0)
        {
            printf("没有记录!\n");
            fclose(fp);
            return;
        }
        printf("请输入要修改的记录信息的编号!\n");
        scanf("%d",&snum);
        for(i=0;i<m;i++)
            if(snum==comm[i].num)/*检索记录中是否有要修改的信息*/
                break;
            if(i<m)
            {	
                printf("已经找到该记录，是否修改?(y/n)\n");
                scanf("%s",ch);
                if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
                    
                {
                    printf("商品名:\n");
                    scanf("%s",comm[i].name);/*输入名字*/
                    printf("\n单价:");
                    scanf("%lf",&comm[i].price);/*输入商品单价*/
                    printf("\n数量:");
                    scanf("%lf",&comm[i].count);/*输入商品数量*/
                    comm[i].total = comm[i].price  * comm[i].count;
                    printf("保存成功!");
                }
                else
                    return;
                
            }
            else 
            {
                printf("没有找到!");
                getchar();
                return;
            }
            if((fp=fopen("data","wb"))==NULL)
            {
                printf("不能打开文件!\n");
                return;
            }
            for(j=0;j<m;j++)/*将新修改的信息写入指定的磁盘文件中*/
                if(fwrite(&comm[j] ,LEN,1,fp)!=1)
                { 
                    printf("不能保存!"); 
                    getch(); 
                }
                fclose(fp);
}





void insert()/*自定义插入函数*/
{ 
	FILE *fp;
	int i,j,k,m=0,snum;
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("不能打开文件!\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&comm[m],LEN,1,fp)==1)
			m++;
		if(m==0) 
		{
			printf("没有记录!\n");
			fclose(fp);
			return;
		}
		printf("请输入要插入的位置\n");
		scanf("%d",&snum);/*输入要插入的位置*/
		for(i=0;i<m;i++)
			if(snum == comm[i].num)
				break;
			for(j=m-1;j>i;j--)
				comm[j+1] = comm[j];/*从最后一条记录开始均向后移一位*/
			printf("现在输入新的信息.\n");
			printf("编号:");
			scanf("%d",&comm[i+1].num);
			for(k=0;k<m;k++)
				if(comm[k].num==comm[i+1].num && k!=i+1)
				{
					printf("已经存在该编号，按任意键继续!");
					getch();
					fclose(fp);
					return;
				}
			
				printf("商品名:");
				scanf("%s",comm[i+1].name);
				printf("单价:");
				scanf("%lf",&comm[i+1].price);
				printf("数量:");
				scanf("%lf",&comm[i+1].count);
		    	comm[i+1].total = comm[i+1].price * comm[i+1].count;
				if((fp=fopen("data","wb"))==NULL)
				{ 
					printf("不能打开文件\n");
					return;
				}
				for(k=0;k<=m;k++)
					if(fwrite(&comm[k] ,LEN,1,fp)!=1)/*将修改后的记录写入磁盘文件中*/
					{
						printf("不能保存!"); 
						getch(); 
					}
					fclose(fp);
}









void total()    /* 统计*/
{ 
    FILE *fp;
    int m=0;
    if((fp=fopen("data","ab+"))==NULL)
    {         
        printf("不能打开记录!\n");
        return;
    }
    while(!feof(fp))  
        if(fread(&comm[m],LEN,1,fp)==1) 
            m++;/*统计记录个数即记录个数*/
        if(m==0)
        {
            printf("没有记录!\n");
            fclose(fp);
            return;
        }
        printf("一共有 %d 条记录!\n",m);/*将统计的个数输出*/
        fclose(fp);
}
