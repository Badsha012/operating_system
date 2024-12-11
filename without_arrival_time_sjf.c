#include<stdio.h>
int main(){
    int i, j, n, temp, bt[20], wt[20], tat[20], p[20];
    float avg_tat=0, avg_wt=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter the burst time of %d process: \n", i+1);
        scanf("%d", &bt[i]);
        p[i]=i+1;
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(bt[i]>bt[j]){
                temp=bt[j];
                bt[j]=bt[i];
                bt[i]=temp;

                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1; i<n; i++){
        wt[i]=bt[i-1]+wt[i-1];
        avg_wt=avg_wt+wt[i];
        tat[i]=tat[i-1]+bt[i];
        avg_tat=avg_tat+tat[i];
    }
    avg_tat=avg_tat+tat[0];
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;

    printf("Process\t BT\tWT\tTAT\n");
    for(i=0; i<n; i++){
        printf("P%d\t %d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("Average turn_around_time: %.2f\nAverage waiting time: %.2f", avg_tat, avg_wt);
    return 0;
}