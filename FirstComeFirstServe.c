#include <stdio.h>
#include <conio.h>
int main(){
	int bt[10],wt[10],tat[10],i,n;
	float wtavg,tatavg;
	printf("Enter no of Process : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter the Burst time for process %d--",i);
		scanf("%d",&bt[i]);
	}
	wt[1]=wtavg=0;
	tat[1]=tatavg=bt[1];
	for(i=2;i<=n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg+=wt[i];
		tatavg+=tat[i];
	}
	printf("PROCESS\t BURST TIME \t WAITING TIME \t  TURN AROUND TIME\n");
	for(i=1;i<=n;i++){
		printf("p%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
	}
	printf("The Average Waiting Time is -- %f\n",wtavg/n);
	printf("The Average Turn Around Time is -- %f",tatavg/n);
	return 0;
}