#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	srand(time(NULL));
	int com[3],coms[10]={0,},c,me[3],strike,ball,how=1;
	for(int i=0; i<3; i++)
	{
		while(1)
		{
			c=rand()%10;
			if(i==0||(com[i-1]!=c&&com[i-2]!=c))
			{
				com[i]=c;
				coms[c]=1;
				break;
			}
		}
	}
	printf("Start Game!\n");
	while(1)
	{
		printf("3개의 숫자 선택: ");
		scanf("%d %d %d",&me[0],&me[1],&me[2]);
		strike=(me[0]==com[0])+(me[1]==com[1])+(me[2]==com[2]);
		ball=((me[0]+1)&&coms[me[0]])+((me[1]+1)&&coms[me[1]])+((me[2]+1)&&coms[me[2]])-strike;
		printf("%d번째 도전 결과: %dstrike, %dball\n",how++,strike,ball);
		if(strike==3)
			break;
	}
	printf("\n\n%d번째 도전만에 성공!\n",how);
	printf("Game Over!");
	
}	
