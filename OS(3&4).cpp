/*
#include<stdio.h>
#include<unistd.h>
int main (){
int x = fork();
printf("Orphan Condition -");
if(x == 0){
sleep(5);
printf("Child : %d\n",getpid());
printf("Parent(using ppid) : %d\n",getppid());
}
else{
printf("Parent : %d\n",getpid());
}
}
*/
#include<stdio.h>
#include<unistd.h>
int main (){
int x = fork();
printf("Zombie Condition -");
if(x == 0){
printf("Child : %d\n",getpid());
printf("Parent(using ppid) : %d\n",getppid());
}
else{
sleep(5);
printf("Parent : %d\n",getpid());
}
}

