
/* print the combination of numbers required to produce inputted text message on t9 keypad.
   eg input - SWATI IS GOOD
      output - 7777928444 4447777 4666 6663
*/

#include<stdio.h>
int main(){
	char array[10][4]={{'0','0','0','0'},
			{'0','0','0','0'},
			{'A','B','C','0'},
			{'D','E','F','0'},
			{'G','H','I','0'},
			{'J','K','L','0'},
			{'M','N','O','0'},
			{'P','Q','R','S'},
			{'T','U','V','0'},
			{'W','X','Y','Z'}};
	//char input[100];
	char c;
	scanf("%c",&c);
	char prev=c;
	int flag=0,i,j,p;
	while(c!=EOF){
		if(c==prev && flag==1)
			printf(" ");
		prev=c;
		flag=1;
		if(c==' ')
			printf(" ");
		else{
			for(i=2;i<=9;i++){
				for(j=0;j<4;j++){
					if(c==array[i][j]){
						for(p=0;p<=j;p++)
							printf("%d",i);
					}
				}
			}
		}
			
		scanf("%c",&c);
	}
	return 0;
}
