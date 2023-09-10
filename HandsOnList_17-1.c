#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct{
  int ticketno;
  }db;
int main(){
   int fd;
   db.ticketno=10;
   fd=open("database.txt",O_RDWR|O_CREAT,0777);
   if(fd==-1){
   printf("you dont have guts to open\n");
   return 0;
   }
   int a=write(fd,&db,sizeof(db));
   if(a==-1){
   printf("write unsuccesful\n");
   return 0;
   }
   close(fd);
   fd=open("database.txt",O_RDONLY);
   read(fd,&db,sizeof(db));
   printf("Ticketno is :%d\n",db.ticketno);
   close(fd);
   return 0;
  }
   
   
   
