#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> 
#include<unistd.h>
int main(int argc, char* argv[]){
		if(argc!=2){
			printf("restart\n");
			return 0;
		}
		char buff1[]="0123456789";
		char buff2[]="abcdefhjhi";
		int fd1=open(argv[1],O_RDWR|O_CREAT|O_EXCL,0777);
		if(fd1==-1){
			printf("file open error");
			return 0;
		}
		int writeb=write(fd1,buff1,10);
		if(writeb==-1){
				printf("write unsuccessful\n");
		}
		int offset=lseek(fd1,10,SEEK_CUR);
		printf("offset is %d",offset);
		int wr2=write(fd1,buff2,10);
		
		if(wr2==-1){
				printf("write 2 unsuccessful\n");
		}
		 int c=close(fd1);
 if(c==0)
 {
  printf("Close successful");
 }
 else
 {
   printf("Close unsuccessful");
 }
 return 0;
 }
