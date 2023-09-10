#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char* argv[]){
 int priority ,new_priority;
 if(argc!=2){
 printf("enter 2 arguments else dont try to execute again\n");
 return 1;
 }
 else{
    new_priority=atoi(argv[1]);
    priority=nice(0);
    printf("current priority=%d\n",priority);
    priority=nice(new_priority);
     printf("After changing  priority=%d\n",priority);
     return 0;
  }
 }
