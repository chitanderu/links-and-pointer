#include "stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h" //�����Ļ   
 struct travel{
	int num;//��� 
	int support;//������ 
	char name[10];//���� 
	double money;//����1
	int month;//��
	int day;//��
	struct travel *next;//ָ���¸����еĽ��1
};
struct travel * addrecord(struct travel*head,struct travel*p); //������μ�¼ ( 
void Print(struct travel*head);    //��ӡ���μ�¼ 
struct travel * search(struct travel*head,char name[]); //�������μ�¼ 
struct travel * del(struct travel*head,char name[]);    //ɾ�����μ�¼ 
 
struct travel * Modify(struct travel *head,struct travel *p); //�޸��������� 
struct travel * Modifysupport(struct travel *head,struct travel *p); // �޸ĵ����� 
void start_output(); //װ�β˵� 
void menue();//�˵� 
void end_output(); 
 
//���庯�� 


  struct travel * addrecord(struct travel*head,struct travel*p)
{    struct travel*q=head,*s;
	if(head==NULL)   {head=p;head->next=NULL;}//��������ǵ�һ�����μ�¼�����
	else{while( q->next!=NULL)q=q->next;//���������һ�����
	s=q->next;
	q->next=p;
	p->next=s;
	if(q->next==NULL){q->next=p;p->next=NULL;}}//���������β���μ�¼ �������
	return head;
	 




} 

  
  void Print(struct travel *head) /*����������Ϣ��������н�������*/
{
	char a[10];
	struct travel*q;
	q=head;
	if(q==NULL)printf("\n\t\t�����������μ�¼��\n");//û����� 
	else
	
    printf("  ���       ����      ��������     ������  \n");
    printf("\n");while(q!=NULL){	
		 
		printf("   %-10d  %-10s   %d.%d        %d\n",q->num,q->name,q->month,q->day,q->support);
		printf("\n");
	q=q->next;}
	printf("\n");
}



struct travel *Modify(struct travel *head,struct travel *p) 
{
	int i,choice,flag3,month,day,flag4,ch;
	for(i=0;i<18;i++)printf(" ");printf("1:����");printf("\n"); 
	for(i=0;i<18;i++)printf(" ");printf("2:��������");printf("\n"); 
	 
	for(i=0;i<18;i++)printf(" ");printf("0:�˳�");printf("\n");printf("\n");
			do{
			printf("ѡ��Ҫ�޸ĵ���Ŀ:");
			scanf("%d",&choice);
			switch(choice){
	    case 1:printf("����������:");	//�޸�����
			scanf("%s",p->name);break;
	    case 2:do{flag3=0;
			printf("��������סʱ��(��1��1��Ϊ:1.1):");	
		scanf("%d.%d",&month,&day);
		if(month<1||month>12||day<1||day>31);
		if(flag3==1)printf("\t\t�����ڴ��������������\n");}while(flag3==1);
		p->month=month;p->day=day;break;//
	    
		case 0:break;
		default:printf("\t\t���޴�ѡ������������\n");}
			printf("�Ƿ�����޸�?��(1)/��(0)");
			scanf("%d",&choice);
			}while(choice!=0);
        return head;
}
  
  struct travel *Modifysupport(struct travel *head,struct travel *p) 
     {
         char name[20]; int numsupport;
         	if(head==NULL)   printf("\n\t\t�����������μ�¼��\n");//û����� 
        else 
       printf("�������������е���");
           scanf("%d",&name);
           numsupport=p->support;
           numsupport++;
           p->support=numsupport;
		   
		   printf("���޳ɹ�"); 
		   
		   return head; 
           
           
           
           
		    
   
  	  
  	
  	
  }
  

 struct travel * search(struct travel *head,int number)
{	
	struct travel  *p;
        p=head;
		while(p!=NULL){if(p->num==number)return p;p=p->next;}
		return NULL;//��ͷ��㿪ʼ���ң��ҵ��󷵻�p�����߷���NULL


}


struct travel *del(struct travel *head,int number)/*��������ɾ�����Ϊnumber�Ŀͻ�*/
{
	struct travel *q,*p;
	q=head;
	p=q->next;
	if(head->num==number){head=head->next;return head;}//��ɾ������ͷ�������
	while(p!=NULL){
		if(p->num==number)
	{if(p->next==NULL)q->next=NULL;//��ɾ������β�������
	else q->next=p->next;//��ɾ�������м�������
	return head;}
	p=p->next;q=q->next;}//ָ�����
}


void end_output()//��βװ�ν���
{
	int i;
 
     
    for(i=0;i<20;i++)printf(" ");printf("�л����л������ʹ�����á��� \n");
     
    
}





void start_output()//��ӭװ�ν���
{
	int i;
	for(i=0;i<20;i++)printf(" ");printf("::����**�����**�\n");
 
	printf("\n");
    for(i=0;i<25;i++)printf(" ");printf("��ӭ����������ѯ����ϵͳ");
	printf("\n");
}

















void menue()//�˵�
 
{	
	int i;
	printf("\n");
		for(i=0;i<18;i++)printf(" ");for(i=0;i<8;i++)printf(" ^_^ ");printf("\n");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("1:������μ�¼");printf("             �����");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("2 �鿴���μ�¼");printf("   ���  �����");printf("\n"); 
	for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("3:�޸����μ�¼");printf("         �����");printf("\n"); 
	for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("4:�������μ�¼");printf("         �����");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("5:���ļ�");printf("             �����");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("6:�����ļ�");printf("     �����");printf("\n");
	for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("7:ɾ�����μ�¼");printf("             �����");printf("\n");
    for(i=0;i<18;i++)printf(" ");printf("�����     ");printf("0:�˳�");printf("             �����");printf("\n");
    for(i=0;i<18;i++)printf(" ");for(i=0;i<8;i++)printf(" ^_^ ");
	printf("\n");}
	
	
	
	
	
	
	
int main()
{
 
	char s[10];
	char name[10]; 
	struct travel *head=NULL,*p=NULL,*q=NULL;
	FILE *fp;//�����ļ�ָ��
	int way,num; int support;
	int b,k,choice,number,size=sizeof(struct travel),i,day,month,money,ch,j,count=0,count1=0,count2=0,flag1,flag2,flag3,flag4,flag5; 
	start_output();
  do{ 
	menue(); 
	printf("��ѡ��:");
	scanf("%d",&choice);//ѡ����
	switch(choice){
	
	   case 1:system("cls");
        printf("\n");count2=0;
		count=0;p=head;while(p!=NULL){p=p->next;count2++;}
		if(count2==8){printf("\t\t���������μ�¼�Ѿ�������\n");break;}//�����μ�¼count2==8ʱ����ʾ
		else{
		printf("���������8�����μ�¼\n");
	 
				printf("\n\n");// 
			do{
		do{flag1=0;flag2=0;
			printf("��������:");		  
		  scanf("%d",&number);flag1=1;
	 
		p=head;
		while(p!=NULL){if(p->num==number)flag2=1;p=p->next;}
		if(flag2==1)printf("\t\t�������ŵ����μ�¼�Ѿ���ӡ�\n");}while(flag1==0||flag2==1);
		printf("����������:");	
		scanf("%s",&name);
		 
		 
		 
		 
		do{flag3=0;
			printf("���������ʱ��(��1��1��Ϊ:1.1):");	
		scanf("%d.%d",&month,&day);
		if(month<1||month>12||day<1||day>31) flag3=1;
		if(flag3==1)printf("\t\t�����ڴ��������������\n");}while(flag3==1);
		
		  do{flag4=0;
			 
		  printf("�����������:"); 
          scanf("%d",&ch);
		  if(ch<1||ch>999)flag4=1;
		 if(flag4==1) printf("\t\t�����������쳣�����������\n");} while(flag4==1);
	 	
		
	    
		 
		  p=(struct travel*)malloc(size);		  //���䶯̬�ڴ� 
		  p->num=number;
		  strcpy(p->name,name);
		  p->month=month;
		  p->day=day;
		  p->support=ch;
		  head=addrecord(head,p);//��p���뵽������
		  printf("�Ƿ�������?  ��:1����:0\n");
		  scanf("%d",&b);}while(b==1);system("cls");break;   }
		  
		  
		case 2: system("cls");  Print(head);
		printf("�밴�س������ء�");
		getchar();
		getchar();
		system("cls");
		break;
		 
		case 3:system("cls");
		if(head==NULL)printf("\t\t����������ӡ�\n");//��head==NULLʱ�� 
		else{
		printf("\n");
		printf("����ӵı����:");
		for(p=head;p;p=p->next)printf("%6d",p->num);
		printf("\n");
		printf("������Ҫ�޸ĵ�:\n");	
		scanf("%d",&number);
		p=search(head,number);//���ұ��Ϊnumber�ķ���
		if(p==NULL)printf("\t\t���˱��δ��Ӽ�¼��\n");
		else head=Modify(head,p);}//�޸�p��ָ��������Ϣ
		printf("\n");
		printf("�밴�س������ء���");
		getchar();
		getchar();
		system("cls");break;
		 
		case 4:system("cls");
		
	    if(head==NULL)printf("\t\t����������ӡ�\n");//��head==NULLʱ��ʾ����� 
		 
		printf("\n");
		printf("����ӵı��:");
		for(p=head;p;p=p->next)printf("%6d",p->num);
		printf("\n");
		printf("������Ҫ���޵ı��:\n");	
		scanf("%d",&number);
		 p=search(head,number); 
		 if(p==NULL)printf("\t\t���˱��δ��Ӽ�¼��\n");
		else head=Modifysupport(head,p);//�޸�p��ָ��������Ϣ
		printf("\n");
		printf("�밴�س������ء���");
		getchar();
		getchar();
		system("cls");break;
		 
		 
		 
	     case 5:
		system("cls");
	if((fp=fopen("file.txt","r"))==NULL){
		printf("\t\t���ļ��򿪴����\n");
		exit(0);
	}//���ļ�����
    printf("  ���       ����      ��ס����     ������ \n");
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
		  head=addrecord(head,p);//���ļ������ݣ�����¼��p�У��ٲ��뵽head��
	};
	if(fclose(fp)){
		printf("\t\t���ر��ļ������\n");
		exit(0);
	}//�ر��ļ�����
	printf("�밴�س������ء���");
	getchar();
	getchar();
	system("cls");
	break;  
	 
	 
	case 6: 
    if((fp=fopen("file.txt","w"))==NULL) 
	{ 
    printf("\t\t���޷�������ļ�����"); 
    system("pause"); 
	} //���ļ�����1
	p=head;
     while(p!=NULL) 
	 {
    fprintf(fp,"%d %s %d.%d %d\n",p->num,p->name,p->month,p->day,p->support); 
	p=p->next;//ָ�����
	 } //д������
     fclose(fp); 
    printf("�ѳɹ��������ݣ�"); 
	choice=0;
	printf("\n");
	printf("\n");
	printf("�밴�س����˳�����");
	getchar();
	getchar(); break;
	 
		
		
	case 7:
		printf("��������:");	
		scanf("%d",&number);
		  	head=del(head,number); 
		printf("\n");
		printf("�밴�س������ء���");
		getchar();
		getchar();
		system("cls");break;
		
		
	case 0:system("cls");
    end_output();
    printf("\n");
     
	printf("�밴�س������ء���");
	getchar();
	getchar();	
	system("cls");
	break;}
		
		
		
		
		
		
	
	
	}while(choice!=0);
	return 0; }
 
