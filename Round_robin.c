#include<stdio.h>
 void quic(int number[10],int fast,int last){
    int i,j,povit,temp;
    if(fast<last){
        povit=fast;
        i=fast;
        j=last;
        while(i<j){
            while(number[i]<=number[povit] && i<last)
            i++;
            while( number[j]>number[povit])
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
        quic(number,fast,j-1);
        quic(number,j+1,last);

    }
}
int main(){
    int number[10],i,j,n;
    
    printf("enter the number :");
    scanf("%d",&n);
    printf("Enter element:");
    for(i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    quic(number,0,n-1);
    printf("Array is sorted:");
    for(i=0;i<n;i++){
        printf("%d,",number[i]);
    }
    return 0;

}