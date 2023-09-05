#include <stdio.h>
#include <stdlib.h>
void main(){
	int buffer[10],bufsize=5,in=0,out=0,choice=0,produce,consume;
	while(1){
		printf("1.Produce\t2.Consume\t3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: if((in+1)%bufsize==out){
						printf("Buffer is full\n");	
					}else{
						printf("Enter the value: ");
						scanf("%d",&produce);
						buffer[in]=produce;
						in=(in+1)%bufsize;
					}
					break;
			case 2: if(in==out){
						printf("Buffer is Empty\n");
					}
					else{
						consume=buffer[out];
						printf("The consumed value is %d\n",consume);
						out=(out+1)%bufsize;
					}
					break;
			case 3: exit(0);
					break;
			default: printf("Invalid Option\n");
		}
	}
}