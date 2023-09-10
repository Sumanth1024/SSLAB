#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
  if(argc!=2)
  { 
    printf("Run it again");
    exit(1);
  }
  int fd=open(argv[1],O_RDWR);
  if(fd==-1){
  printf("open error");
   return 0;
   	}
   int fc=fcntl(fd,F_GETFL);
    int mode=fc & O_ACCMODE;
    if(mode==O_RDONLY)
      printf("readonly");
      if(mode==O_WRONLY)
      printf("WRonly");
      if(mode==O_RDWR)
      printf("RWBOTH");
      close(fd);
      return;
      
  }  
