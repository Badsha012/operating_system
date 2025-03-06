#include<stdio.h>
int main(){
    int n,i,x[100],item,loc=0;
    printf("Enter the element :");
    scanf("%d",&n);
    printf("Entem number of element:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("Enter serching value:");
    scanf("%d",&item);
    for(i=0;i<n;i++){
    
        if(x[i]==item){
            loc=i+1;
            break;

    }
    }
    if(loc==0){
        printf("Serch is not success full:");
    }
    else{
        printf("Serch is successful:",loc);
    }

}
