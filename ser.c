#include<stdio.h>
int main(){
    int n,i,x[100],item,loc=0;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Enter the enter element:");

    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    printf("Ener the item:");
    scanf("%d",&item);
    for(i=0;i<n;i++)
    {
        if(x[i]==item){
            loc=i+1;
            break;
        }
    }
    if(loc==0){
        printf("search is not success full:");
    }
    else{
        printf("Serch is successful:%d\n",loc);
    }
    return 0;
}

