#include<stdio.h>
int main(){
    int x[100],i,j,temp=0,n;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Enter the  the number of element:");
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);

    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(x[i]>x[j]){
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
        }
    }
    }
    printf("Array is sorted:");
    for(i=0;i<n;i++){
        printf("%d  ",x[i]);
    }
    return 0;
}