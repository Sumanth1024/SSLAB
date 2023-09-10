#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char* argv[]){
  if(argc!=4){
   printf("restart it with correct arguments\n");
   return 0;
  }
  char buff[10]="abcdefghij";
  int fd1=open(argv[1],O_WRONLY|O_APPEND);
  if(fd1==-1){
      printf("error in opening 1st file\n");
      return 0;
  }
 int  dup1=dup(fd1);
  if(dup1==-1){
      printf("dup error\n");
      return 0;
  }
  write(dup1,buff,10);
  int fd2=open(argv[2],O_WRONLY|O_APPEND);
  if(fd2==-1){
      printf("error in opening 2st file\n");
      return 0;
  }
  int dp2=dup2(fd2,6);
  if(dp2==-1){
      printf("dup2 error\n");
      return 0;
  }
  write(dp2,buff,10);
  
  int fd3=open(argv[3],O_WRONLY|O_APPEND);
  if(fd3==-1){
      printf("error in opening 3rd file\n");
      return 0;
  }
  int dup3=fcntl(fd3,F_DUPFD);
  if(dup3==-1){
      printf("fcntl error\n");
      return 0;
  }
  write(dup3,buff,10);
  close(fd1);
  close(fd2);
  close(fd3);
  return ;
  }
