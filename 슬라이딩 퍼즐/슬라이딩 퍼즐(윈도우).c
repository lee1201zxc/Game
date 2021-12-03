#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
int q[2],r=0,a[4][4];
void print(void)
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	for(int i=0; i<4; i++)
	{
		printf("\t\t\t");
		for(int z=0; z<4; z++)
		{
			if(a[i][z]!=0)
				printf("%d",a[i][z]);
			else
				printf(" ");
			printf("       ");
			if(a[i][z]==0)
			{
				q[0]=i;
				q[1]=z;
			}	
		}
		printf("\n\n\n\n");
	}
}
void game(char s)
{
	int zc=0;
	if(s=='k')
	{
		if(q[0]>0 && q[0]<4)
		{
			int op=a[q[0]][q[1]];
			a[q[0]][q[1]]=a[q[0]-1][q[1]];
			a[q[0]-1][q[1]]=op;
			q[0]--;
			zc=1;
		}
	}
	else if(s=='j')
	{
		if(q[1]>=0 && q[1]<3)
		{
			int op=a[q[0]][q[1]];
			a[q[0]][q[1]]=a[q[0]][q[1]+1];
			a[q[0]][q[1]+1]=op;
			q[1]++;
			zc=1;
		}	
	}
	else if(s=='i')
	{

		if(q[0]<3 && q[0]>=0)
		{
			int op=a[q[0]][q[1]];
			a[q[0]][q[1]]=a[q[0]+1][q[1]];
			a[q[0]+1][q[1]]=op;
			q[0]++;
			zc=1;
		}
	}
	else if(s=='l')
	{
		if(q[1]>0 && q[1]<4)
		{
			int op=a[q[0]][q[1]];
			a[q[0]][q[1]]=a[q[0]][q[1]-1];
			a[q[0]][q[1]-1]=op;
			q[1]--;
			zc=1;
		}
	}	
	else if(s=='q')
	{
		r=2;
	}
	int zx=0;
	for(int i=0; i<4; i++)
	{
		for(int z=0; z<4; z++)
		{
			if(a[i][z]==4*i+1+z)
				zx++;
		}
	}
	if(zx>14&& zc==1)
		r=1;

}
int main(void)
{
	char qq[2];
	srand(time(NULL));
	printf("1=정렬, 2=랜덤:");
	scanf("%s",&qq);
	if(strcmp(qq,"1")==0)
	{
		printf("ss");
		for(int i=1; i<=16; i++)
		{
			a[(i-1)/4][(i-1)%4]=i;
			if(i==16)
				a[3][3]=0;
		}	
		q[0]=q[1]=3;
		print();
	}
	else if(strcmp(qq,"2")==0)
	{
		int w[16]={0,},e=1,s;
		while(e<=16)
		{
			s=rand()%16;
			if(w[s]==0)
			{
				w[s]=1;
				a[(e-1)/4][(e-1)%4]=s;
				if(s==0)
				{
					q[0]=(e-1)/4;
					q[1]=(e-1)%4;
				}
			}
			else
				continue;
			e++;
		}
	}
		print();
	while(r==0)
	{
		char s=getch();
		game(s);
		print();
	}
	if(r==1)
	{
		system("cls");
		printf("축하합니다.\n");
		Sleep(3000);
		return 0;
	}
	else if(r==2)
	{
		system("cls");
		printf("종료.");
		return 0;
	}
}
