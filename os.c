//fork function-

/*#include<stdio.h>
#include<unistd.h>
int main (){
fork();
fork();
printf("process id : %d\n",getpid());
return 0 ;
}*/

//write a program to create a child process in parallel to main process , define an array of numbers the child process has to calculate the sum of even number sand parent process has to calculate the sum of odd numbers.
/*
#include<stdio.h>
#include<unistd.h>
int main (){
int arr[10] = {1,3,5,4,6,4,2,7,9,1};
int a = fork() ;
int even_sum = 0, odd_sum = 0;

if (a != 0){
    for(int i = 0 ; i < 10 ; i++ ){
        if(arr[i] % 2 == 0){    even_sum += arr[i];  }
        }
        printf("The child id is : %d\n",getpid());
        printf("Sum of even numbers : %d\n",even_sum);
}

else{
    for(int i = 0 ; i < 10 ; i++ ){
        if(arr[i] % 2 != 0){    odd_sum += arr[i];   }
        }
        printf("The parent id is : %d\n",getpid());
        printf("Sum of odd numbers : %d",odd_sum);
}
} 
*/


