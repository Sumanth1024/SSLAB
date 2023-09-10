#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
struct {
int train_no;
int ticket_no;
}db[3];
for(int i=0;i<3;i++){
  db[i].train_no=i+1;
  db[i].ticket_no=0;
 }
 int fd=open("train18.txt",O_RDWR|O_CREAT,0777);
 if(fd==-1){
  printf("you cant open file\n");
  return 1;
 }
 write(fd,db,sizeof(db));
 
 return 0;
 }
