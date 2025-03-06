#include<stdio.h>
void quic(int number[100],int frist,int last){
    int i,j,povit,temp;
    if(frist<last){
        povit=frist;
        i=frist;
        j=last;
        while(i<j){
            while(number[i]<=number[povit]&&i<last)
            i++;
            while(number[j]>number[povit])
            j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
                
            }
        
            
        }
        temp=number[povit];
        number[povit]=number[j];
        number[j]=temp;
        quic(number,frist,j-1);
        quic(number,j+1,last);
    }
}
    
int main(){
    int number[100],n,i,j;
    printf("Enter number:");
    scanf("%d",&n);
    printf("enter the number of the elkement:");

    for(i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    quic(number,0,n-1);
    printf("Array is sort:");
    for(i=0;i<n;i++){
        printf("%d ",number[i]);
    }
    return 0;
}