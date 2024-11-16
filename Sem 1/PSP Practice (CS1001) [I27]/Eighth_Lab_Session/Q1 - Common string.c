#include<stdio.h>
#include<string.h>
void main() {
    int l,m=100,n=0;
   
    printf("enter the number of strings: ");
    scanf("%d",&l);
   
    char a[l][50],b[50];
    printf("Enter the strings:");
    for(int i=0;i<l;i++){
        scanf("%s",a[i]);
    }
     for(int i=0;i<l;i++) {
         int j=0;
          while(a[i][j]!='\0')
             j++;
             if(j<m)
             m=j;
         }
         for(int j=0;j<m;j++) {
             char k=a[0][j];
             int f=1;
             for (int i=1;i<l;i++) {
                 if(a[i][j]!=k) {
                     f=0;
                     break;
                 }
             }
             if(f) {
                 b[n]=k;
                 n++;
             }
             else
             break;
         }
         b[n]='\0';
         printf("the common string is %s \n",b);
         
}
