//Tower of Hanoi

#include<stdio.h>
int tower(int n, char s , char a , char d)        // s --> start , a --> auxiliary , d --> destination.
{
    if(n==1)
    {
        printf("Move disk 1 from tower %c to %c\n",a,d);
        return 0 ;
    }
    tower(n-1,s,d,a);
    printf("Move %d from tower %c to %c\n",n,s,a);
    tower(n-1,a,s,d);
}
int main ()
{
    int n ;
    
    printf("Enter the total number of disks you want : \n");
    scanf("%d",&n);
    printf("The sequence of disks transfer will be : \n\n");
    tower(n,'A','B','C');
    return 0 ;
    
}
