#include<stdio.h>
int main(){
    int x[100],i,loc=0,item,n;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Enter the Element:");
    for(i=0;i<n;i++)
{
    scanf("%d",&x[i]);
}
printf("Enter item:");
scanf("%d",&item);
for(i=0;i<n;i++){
    if(x[i]==item){
        loc=i+1;
        break;
    }
}
if(loc==0){
    printf("Serching is not successful");
}else{
    printf("Serching is sucessful:%d",loc);
}
return 0;

}
