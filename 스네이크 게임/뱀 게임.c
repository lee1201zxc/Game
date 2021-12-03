#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	system("cls");
	srand(time(NULL));
	int gb[10][10],l=3,g=0;
	char a,d='d';
	int sl[100][2]={{4,2},{4,1},{4,0}};
	for(int i=0; i<10; i++)
	{
		for(int z=0; z<10; z++)
			gb[i][z]=1;
	}
	for(int i=0; i<3; i++)
		gb[4][i]=0;
	int ap[2]={4,7};
	gb[4][7]=8;
	while(1)
	{
		for(int i=0; i<10; i++)
		{
			for(int z=0; z<10; z++)
			{
				printf("%d",gb[i][z]);
			}
			printf("\n");
		}
		a=getch();
		if(a=='a'||a=='s'||a=='d'||a=='w')
		{
			if(d=='a'&&a=='d'){}
			else if(d=='d'&&a=='a'){}
			else if(d=='w'&&a=='s'){}
			else if(d=='s'&&a=='w'){}
			else
				d=a;
		}
		for(int i=l-1; i>=0; i--)
		{
			sl[i+1][0]=sl[i][0];
			sl[i+1][1]=sl[i][1];
		}
		if(d=='a')
			sl[0][1]--;
		else if(d=='d')
			sl[0][1]++;
		else if(d=='w')
			sl[0][0]--;
		else if(d=='s')
			sl[0][0]++; 
		if(ap[0]==sl[0][0]&&ap[1]==sl[0][1])
		{
			l++;
			gb[ap[0]][ap[1]]=0;
			int ss=1;
			while(ss>0)
			{
				ss=1;
				ap[0]=rand()%10;
				ap[1]=rand()%10;
				for(int i=0; i<l; i++)
				{
					if(ap[0]==sl[i][0]&&ap[1]==sl[i][1])
						ss++;
				}
				if(ss==1)
					break;
			}
		}
		for(int i=0; i<10; i++)
		{
			for(int z=0; z<10; z++)
				gb[i][z]=1;
		}
		for(int i=0; i<l; i++)
		{
			gb[sl[i][0]][sl[i][1]]=0;
		}	
		gb[ap[0]][ap[1]]=8;
		if(sl[0][0]>9||sl[0][1]>9||sl[0][0]<0||sl[0][1]<0)
			g=1;

		for(int i=1; i<l; i++)
		{
			if(sl[0][0]==sl[i][0]&&sl[0][1]==sl[i][1])
				g=1;
		}
		if(g==1)
			break;
		system("cls");
	}
	system("cls");
	if(g==1)
		printf("Game Over\n");
	else if(g==0)
		printf("Game Clear\n");
	printf("게임을 다시하려면 'y'키를 눌러주세요.\n");
	a=getch();
	if(a=='y')
		main();
	else
		printf("프로그램 종료");
	return 0;
}
//gb(게임화면) sl(뱀위치) d(방향) a(입력) l(길이)
//ap(사과위치) g(게임결과) 
 
