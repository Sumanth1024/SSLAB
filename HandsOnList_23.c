#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
  if(!fork()){
  //child
  printf("I am child and my pid is %d \n",getpid());
  }
  else{
   printf("I am parent and my pid is %d \n",getpid());
   sleep(30);
   wait(0);
  }
 }
