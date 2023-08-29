#include<stdio.h>
#include<conio.h>
int main(){
	int bt[10],wt[10],tat[10],ct[10],i,j,k,n,t,max;
	float tatavg=0,wtavg=0,temp=0;
	printf("Enter the no of process : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter the burst time for process %d -- ",i);
		scanf("%d",&bt[i]);
		ct[i]=bt[i];
	}
	printf("Enter time slice :");
	scanf("%d",&t);
	max=bt[1];
	for(i=2;i<=n;i++){
		if(max<bt[i]){
			max=bt[i];
		}
	}
	for(j=1;j<=(max/t)+1;j++){
		for(i=1;i<=n;i++){
			if(bt[i]!=0){
				if(bt[i]<=t){
					tat[i]=temp+bt[i];
					temp=temp+bt[i];
					bt[i]=0;
				}
				else{
					temp=temp+t;
					bt[i]=bt[i]-t;
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		wt[i]=tat[i]-ct[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("PROCESS\t BURST TIME \t WAITING TIME \t  TURN AROUND TIME\n");
	for(i=1;i<=n;i++){
		printf("p%d\t\t%d\t\t%d\t\t%d\n",i,ct[i],wt[i],tat[i]);
	}
	printf("The Average Waiting Time is -- %f\n",wtavg/n);
	printf("The Average Turn Around Time is -- %f",tatavg/n);
	return 0;
}