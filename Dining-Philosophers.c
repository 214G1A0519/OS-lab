#include <stdio.h>
#include <stdlib.h>
void one();
void two();
int philname[10],hu[10],tph,howhung,cho;
void main(){
	int i;
	printf("DINING PHILOSOPHER PROBLEM\n");
	printf("Enter how many no of Philosophers: ");
	scanf("%d",&tph);
	for(i=0;i<tph;i++){
		philname[i]=i+1;
	}
	printf("How many are hungry: ");
	scanf("%d",&howhung);
	if(tph==howhung){
		printf("All are hungry... which leads to deadlock \n");
		printf("Exiting\n");
	}
	else{
		for(i=0;i<howhung;i++){
			printf("Enter philosopher %d position :",i+1);
			scanf("%d",&hu[i]);
		}
		while(1){
			printf("1.One can eat at a time\t 2.Two can eat at a time\t 3. Exit\nEnter your choice: ");
			scanf("%d",&cho);
			switch(cho){
				case 1: one();
						break;
				case 2: two();
						break;
				case 3: exit(0);
						break;
				default: printf("Invalid Option\n");
			}
		}
	}	
}
void one(){
	int i,pos=0,x;
	printf("From all Philosophers One can eat at any time\n");
	for(i=0;i<howhung;i++,pos++){
		printf("P%d is granted to eat\n",philname[hu[pos]]);
		for(x=pos;x<howhung;x++){
			printf("P%d is waiting\n",philname[hu[x]]);
		}
	}
}
void two(){
	int i,x,j,t,r,s=0;
	printf("Any two philosophers can eat a time\n");
	for(i=0;i<howhung;i++){
		for(j=i+1;j<howhung;j++){
			if(abs(hu[i]-hu[j])>=1 && abs(hu[i]-hu[j])!=4){
				printf("\n\nCombination %d\n",++s);
				printf("P%d and P%d are granted to eat\n",philname[hu[i]],philname[hu[j]]);
				t=hu[i];
				r=hu[j];
				for(x=0;x<howhung;x++){
					if(hu[x]!=t && hu[x]!=r){
						printf("P%d is waiting\n",philname[hu[x]]);
					}
				}
			}
		}
	}
}