#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	srand(time(NULL));
	int win=0,draw=0,lose=0,me,com;
	char *a[3]={"����","����","��"};
	while(1)
	{
		printf("������ 1, ������ 2, ���� 3:");
		scanf("%d",&me);
		com=rand()%3+1;
		if(me==com)
			printf("����� %s����, ��ǻ�ʹ� %s����, �����ϴ�.\n",a[me-1],a[com-1]),draw++;
		else if((me<com && com-me==1)||me>com && com-me==-2)
			printf("����� %s����, ��ǻ�ʹ� %s����, �̰���ϴ�.\n",a[me-1],a[com-1]),win++;
		else
		{
			printf("����� %s����, ��ǻ�ʹ� %s����, �����ϴ�.\n",a[me-1],a[com-1]); 
			lose=1;
		}
		if(lose==1)
			break;
	}
	printf("\n������ ��� : %d��, %d��",win,draw);
}
