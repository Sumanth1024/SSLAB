#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
if(argc!=3){
printf("not enough arguments\n");
return -1;
}

int fd1=open(argv[1],O_RDONLY);
int fd2=open(argv[2],O_WRONLY|O_CREAT);
if(fd1==-1||fd2==-1)
printf("can't open files\n");
//return -1;

while(1){
char buff;
int read_byte=read(fd1,&buff,1);
if(read_byte==0)
break;
int write_byte=write(fd2,&buff,1);
}

int closefd1=close(fd1);
int closefd2=close(fd2);
if(closefd1==-1 || closefd2==-1)
                printf("Your system is useless, coz it can't even close a file\n");

return 0;

}

