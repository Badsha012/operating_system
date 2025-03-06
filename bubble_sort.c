#include<stdio.h>
int main(){
    int x[100],n,i,temp=0;
    printf("Enter the number of element:");
    scanf("%d",&n);
    printf("Enter the element:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[i]>x[j]){
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
        }
    }
    }
    printf("Enter the array is soted:");
    for(i=0;i<n;i++){
        printf("%d, ",x[i]);
    }
    return 0;

}
