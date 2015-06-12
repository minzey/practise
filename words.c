//input a string dynamically. print each word of the string on separate line.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *ptr;
	int i=0,lastspace,j,p,k;
	char* word;
	ptr=(char*)malloc(sizeof(char));
	*ptr=getchar();
	while(*(ptr+i) != '\n'){
		ptr=realloc(ptr,1);
		printf(" mem allocated\n");
		i++;
		*(ptr+i)=getchar();
		//getch();
	}
	printf("Dynamically inputted string is: %s\n",ptr);
	printf("Length of string is: %d\n",i++);
	
	*(ptr+i)=' ';
	word=(char*)malloc(i*sizeof(char));
	lastspace=0;
	printf("Words are:\n");
	for(j=0;j<=i;j++){
		
		if(*(ptr+j)==' '){
			
			strncpy(word,"",i); // STRCPY copies string till trailing '\0' is found. since in this case '\0' does not end string
				            //strcpy does not copy properly
			                    //memset(word, '\0', sizeof(word)); // could work in lieu of strncpy
			k=0;
			for(p=lastspace;p<j+1;p++){
				*(word+k)=*(ptr+p);
				k++;
			}	
			
			lastspace=j+1;
			printf("%s\n",word);
		}
	}
	return 0;
}
	
