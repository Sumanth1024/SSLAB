#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
   int f=fork();
   if(f==0){
   // sleep(10);
    printf("child process id=%d\n",getpid());
    printf("my parent is  %d \n", getppid());
    //sleep(10);
   // printf("my parent is  %d \n", getppid());
    exit(0);
   }
   else{
     printf("parent process id=%d\n",getpid());
     exit(0);
    }
    return 0;
    
 }
