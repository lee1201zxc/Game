#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
void menu(void);
void read(void);
typedef struct list
{
	char e[16];
	char k[63];
}list;
typedef struct line
{
	struct list *adrs;
	struct line *next;
}line;
typedef struct line *link;
void read(void)
{
	link az,head,juso;
	FILE *f;
	f=fopen("dic.txt","r");
	int i=0;
	while(1)
	{
		head=(line*)malloc(sizeof(line));
		head->adrs=(list*)malloc(sizeof(list));
		if(fscanf(f,"%s %s",head->adrs->e,head->adrs->k)==EOF)
		{
			break;
		}
		if(i==0)
		{
			juso=head;
			i++;
		}
		else
		{
			az->next=head;
		}
		az=head;
	}
	link k=juso;
	while(k->next!=NULL)
	{
		link j=k;
		while(j->next!=NULL)
		{
			if(strcmp(k->adrs->e,j->adrs->e)>0)
			{
				list *kan=k->adrs;
				k->adrs=j->adrs;
				j->adrs=kan;
			}
			j=j->next;
		}
		k=k->next;
	}
	az=juso;
	int correct=0,incorrect=0,m=0;
	char answer[63];
	do
	{
		printf("%s -> ",az->adrs->k);
		scanf("%s",answer);
		if(strcmp(answer,az->adrs->e)==0)
		{
			correct++;
			printf("correct!\n");
		}
		else
		{
			printf("incorrect!\n");
			incorrect++;
		}
		az=az->next;
		m++;
		if(strcmp(answer,".quit")==0)
			incorrect--;
	}while(strcmp(answer,".quit")!=0&&az->next!=NULL);
	printf("당신의 점수는%.2f점입니다.",(double)100*(correct)/(correct+incorrect));
	char r;
	getchar();
	r=getchar();
	if(r=='\n')
		menu();
	fclose(f);
}
void  menu(void)
{
	system("cls");
	link h;
	int n;
	printf(">> dd 단어 맞추기 프로그램 <<\n");
	printf("1.영어 단어 맞추기\t2. 프로그램 종료\n");
	printf("\n번호를 선택하세요:");
	scanf("%d",&n);
	if(n==1)
	{
		read();
	
	}
	else if(n==2)
	{
		system("cls");
	}
}
int main(void)
{
	menu();
	return 0;
}
