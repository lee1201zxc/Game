#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	srand(time(NULL));
	int win=0,draw=0,lose=0,me,com;
	char *a[3]={"바위","가위","보"};
	while(1)
	{
		printf("바위는 1, 가위는 2, 보는 3:");
		scanf("%d",&me);
		com=rand()%3+1;
		if(me==com)
			printf("당신은 %s선택, 컴퓨터는 %s선택, 비겼습니다.\n",a[me-1],a[com-1]),draw++;
		else if((me<com && com-me==1)||me>com && com-me==-2)
			printf("당신은 %s선택, 컴퓨터는 %s선택, 이겼습니다.\n",a[me-1],a[com-1]),win++;
		else
		{
			printf("당신은 %s선택, 컴퓨터는 %s선택, 졌습니다.\n",a[me-1],a[com-1]); 
			lose=1;
		}
		if(lose==1)
			break;
	}
	printf("\n게임의 결과 : %d승, %d무",win,draw);
}
