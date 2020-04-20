#include "stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h" //清除屏幕   
 struct travel{
	int num;//编号 
	int support;//点赞数 
	char name[10];//姓名 
	double money;//费用1
	int month;//月
	int day;//日
	struct travel *next;//指向下个旅行的结点1
};
struct travel * addrecord(struct travel*head,struct travel*p); //添加旅游记录 ( 
void Print(struct travel*head);    //打印旅游记录 
struct travel * search(struct travel*head,char name[]); //查找旅游记录 
struct travel * del(struct travel*head,char name[]);    //删除旅游记录 
 
struct travel * Modify(struct travel *head,struct travel *p); //修改旅游数据 
struct travel * Modifysupport(struct travel *head,struct travel *p); // 修改点赞数 
void start_output(); //装饰菜单 
void menue();//菜单 
void end_output(); 
 
//定义函数 


  struct travel * addrecord(struct travel*head,struct travel*p)
{    struct travel*q=head,*s;
	if(head==NULL)   {head=p;head->next=NULL;}//当插入的是第一个旅游记录的情况
	else{while( q->next!=NULL)q=q->next;//当插入的是一般情况
	s=q->next;
	q->next=p;
	p->next=s;
	if(q->next==NULL){q->next=p;p->next=NULL;}}//当插入的是尾旅游记录 结点的情况
	return head;
	 




} 

  
  void Print(struct travel *head) /*浏览等相关信息，输出所有结点的数据*/
{
	char a[10];
	struct travel*q;
	q=head;
	if(q==NULL)printf("\n\t\t※现在无旅游记录※\n");//没有添加 
	else
	
    printf("  编号       姓名      出发日期     点赞数  \n");
    printf("\n");while(q!=NULL){	
		 
		printf("   %-10d  %-10s   %d.%d        %d\n",q->num,q->name,q->month,q->day,q->support);
		printf("\n");
	q=q->next;}
	printf("\n");
}



struct travel *Modify(struct travel *head,struct travel *p) 
{
	int i,choice,flag3,month,day,flag4,ch;
	for(i=0;i<18;i++)printf(" ");printf("1:姓名");printf("\n"); 
	for(i=0;i<18;i++)printf(" ");printf("2:出发日期");printf("\n"); 
	 
	for(i=0;i<18;i++)printf(" ");printf("0:退出");printf("\n");printf("\n");
			do{
			printf("选择要修改的项目:");
			scanf("%d",&choice);
			switch(choice){
	    case 1:printf("请输入姓名:");	//修改姓名
			scanf("%s",p->name);break;
	    case 2:do{flag3=0;
			printf("请输入入住时间(如1月1号为:1.1):");	
		scanf("%d.%d",&month,&day);
		if(month<1||month>12||day<1||day>31);
		if(flag3==1)printf("\t\t※日期错误，请重新输入※\n");}while(flag3==1);
		p->month=month;p->day=day;break;//
	    
		case 0:break;
		default:printf("\t\t※无此选项，请重新输入※\n");}
			printf("是否继续修改?是(1)/否(0)");
			scanf("%d",&choice);
			}while(choice!=0);
        return head;
}
  
  struct travel *Modifysupport(struct travel *head,struct travel *p) 
     {
         char name[20]; int numsupport;
         	if(head==NULL)   printf("\n\t\t※现在无旅游记录※\n");//没有添加 
        else 
       printf("请输入姓名进行点赞");
           scanf("%d",&name);
           numsupport=p->support;
           numsupport++;
           p->support=numsupport;
		   
		   printf("点赞成功"); 
		   
		   return head; 
           
           
           
           
		    
   
  	  
  	
  	
  }
  

 struct travel * search(struct travel *head,int number)
{	
	struct travel  *p;
        p=head;
		while(p!=NULL){if(p->num==number)return p;p=p->next;}
		return NULL;//从头结点开始查找，找到后返回p，否者返回NULL


}


struct travel *del(struct travel *head,int number)/*在链表中删除编号为number的客户*/
{
	struct travel *q,*p;
	q=head;
	p=q->next;
	if(head->num==number){head=head->next;return head;}//当删除的是头结点的情况
	while(p!=NULL){
		if(p->num==number)
	{if(p->next==NULL)q->next=NULL;//当删除的是尾结点的情况
	else q->next=p->next;//当删除的是中间结点的情况
	return head;}
	p=p->next;q=q->next;}//指针后移
}


void end_output()//结尾装饰界面
{
	int i;
 
     
    for(i=0;i<20;i++)printf(" ");printf("☆　谢　☆　☆　谢　☆　　☆　使　☆　☆　用　☆ \n");
     
    
}





void start_output()//欢迎装饰界面
{
	int i;
	for(i=0;i<20;i++)printf(" ");printf("::∴★∵**☆．∴★∵**☆．\n");
 
	printf("\n");
    for(i=0;i<25;i++)printf(" ");printf("欢迎来到旅游咨询管理系统");
	printf("\n");
}

















void menue()//菜单
 
{	
	int i;
	printf("\n");
		for(i=0;i<18;i++)printf(" ");for(i=0;i<8;i++)printf(" ^_^ ");printf("\n");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("1:添加旅游记录");printf("             ◇◆◇");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("2 查看旅游记录");printf("   ●●  ◇◆◇");printf("\n"); 
	for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("3:修改旅游记录");printf("         ◇◆◇");printf("\n"); 
	for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("4:点赞旅游记录");printf("         ◇◆◇");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("5:打开文件");printf("             ◇◆◇");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("6:保存文件");printf("     ◇◆◇");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("7:删除旅游记录");printf("             ◇◆◇");printf("\n");
    for(i=0;i<18;i++)printf(" ");printf("◇◆◇     ");printf("0:退出");printf("             ◇◆◇");printf("\n");
    for(i=0;i<18;i++)printf(" ");for(i=0;i<8;i++)printf(" ^_^ ");
	printf("\n");}
	
	
	
	
	
	
	
int main()
{
 
	char s[10];
	char name[10]; 
	struct travel *head=NULL,*p=NULL,*q=NULL;
	FILE *fp;//定义文件指针
	int way,num; int support;
	int b,k,choice,number,size=sizeof(struct travel),i,day,month,money,ch,j,count=0,count1=0,count2=0,flag1,flag2,flag3,flag4,flag5; 
	start_output();
  do{ 
	menue(); 
	printf("请选择:");
	scanf("%d",&choice);//选择功能
	switch(choice){
	
	   case 1:system("cls");
        printf("\n");count2=0;
		count=0;p=head;while(p!=NULL){p=p->next;count2++;}
		if(count2==8){printf("\t\t※所有旅游记录已经添加完※\n");break;}//当旅游记录count2==8时，提示
		else{
		printf("您可以添加8条旅游记录\n");
	 
				printf("\n\n");// 
			do{
		do{flag1=0;flag2=0;
			printf("请输入编号:");		  
		  scanf("%d",&number);flag1=1;
	 
		p=head;
		while(p!=NULL){if(p->num==number)flag2=1;p=p->next;}
		if(flag2==1)printf("\t\t※这个编号的旅游记录已经添加※\n");}while(flag1==0||flag2==1);
		printf("请输入姓名:");	
		scanf("%s",&name);
		 
		 
		 
		 
		do{flag3=0;
			printf("请输入出发时间(如1月1号为:1.1):");	
		scanf("%d.%d",&month,&day);
		if(month<1||month>12||day<1||day>31) flag3=1;
		if(flag3==1)printf("\t\t※日期错误，请重新输入※\n");}while(flag3==1);
		
		  do{flag4=0;
			 
		  printf("请输入点赞数:"); 
          scanf("%d",&ch);
		  if(ch<1||ch>999)flag4=1;
		 if(flag4==1) printf("\t\t※点赞数字异常请重新输入※\n");} while(flag4==1);
	 	
		
	    
		 
		  p=(struct travel*)malloc(size);		  //分配动态内存 
		  p->num=number;
		  strcpy(p->name,name);
		  p->month=month;
		  p->day=day;
		  p->support=ch;
		  head=addrecord(head,p);//将p插入到链表中
		  printf("是否继续添加?  是:1，否:0\n");
		  scanf("%d",&b);}while(b==1);system("cls");break;   }
		  
		  
		case 2: system("cls");  Print(head);
		printf("请按回车键返回…");
		getchar();
		getchar();
		system("cls");
		break;
		 
		case 3:system("cls");
		if(head==NULL)printf("\t\t※现在无添加※\n");//当head==NULL时显 
		else{
		printf("\n");
		printf("已添加的编号有:");
		for(p=head;p;p=p->next)printf("%6d",p->num);
		printf("\n");
		printf("请输入要修改的:\n");	
		scanf("%d",&number);
		p=search(head,number);//查找编号为number的房间
		if(p==NULL)printf("\t\t※此编号未添加记录※\n");
		else head=Modify(head,p);}//修改p所指向链表信息
		printf("\n");
		printf("请按回车键返回……");
		getchar();
		getchar();
		system("cls");break;
		 
		case 4:system("cls");
		
	    if(head==NULL)printf("\t\t※现在无添加※\n");//当head==NULL时显示无添加 
		 
		printf("\n");
		printf("已添加的编号:");
		for(p=head;p;p=p->next)printf("%6d",p->num);
		printf("\n");
		printf("请输入要点赞的编号:\n");	
		scanf("%d",&number);
		 p=search(head,number); 
		 if(p==NULL)printf("\t\t※此编号未添加记录※\n");
		else head=Modifysupport(head,p);//修改p所指向链表信息
		printf("\n");
		printf("请按回车键返回……");
		getchar();
		getchar();
		system("cls");break;
		 
		 
		 
	     case 5:
		system("cls");
	if((fp=fopen("file.txt","r"))==NULL){
		printf("\t\t※文件打开错误※\n");
		exit(0);
	}//打开文件出错
    printf("  编号       姓名      入住日期     点赞数 \n");
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %d.%d %d\n",&num,name,&month,&day,&support);
		printf("   %-10d  %-10s   %d.%d        %-2d\n",num,name,month,day,support);
		p=(struct travel*)malloc(size);		  
		  p->num=num;
		  strcpy(p->name,name);
		  p->month=month;
		  p->day=day;
		  p->support=support;
		  head=addrecord(head,p);//从文件读数据，并记录到p中，再插入到head中
	};
	if(fclose(fp)){
		printf("\t\t※关闭文件错误※\n");
		exit(0);
	}//关闭文件出错
	printf("请按回车键返回……");
	getchar();
	getchar();
	system("cls");
	break;  
	 
	 
	case 6: 
    if((fp=fopen("file.txt","w"))==NULL) 
	{ 
    printf("\t\t※无法打开这个文件！※"); 
    system("pause"); 
	} //打开文件出错1
	p=head;
     while(p!=NULL) 
	 {
    fprintf(fp,"%d %s %d.%d %d\n",p->num,p->name,p->month,p->day,p->support); 
	p=p->next;//指针后移
	 } //写入数据
     fclose(fp); 
    printf("已成功保存数据！"); 
	choice=0;
	printf("\n");
	printf("\n");
	printf("请按回车键退出程序");
	getchar();
	getchar(); break;
	 
		
		
	case 7:
		printf("请输入编号:");	
		scanf("%d",&number);
		  	head=del(head,number); 
		printf("\n");
		printf("请按回车键返回……");
		getchar();
		getchar();
		system("cls");break;
		
		
	case 0:system("cls");
    end_output();
    printf("\n");
     
	printf("请按回车键返回……");
	getchar();
	getchar();	
	system("cls");
	break;}
		
		
		
		
		
		
	
	
	}while(choice!=0);
	return 0; }
 
