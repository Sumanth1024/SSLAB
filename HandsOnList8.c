#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc ,char* argv[]){
	if(argc!=2)
	{
	printf("arguments not passed correctly\n");
	return -1;
	}
	int fd1=open(argv[1],O_RDONLY);
	if(fd1==-1){
	printf("bye, you cant open\n");
	}
	char read_buff[1024];
	char ans_buff[1024];
	while(1){
		int read_fd=read(fd1,&read_buff,1024);
		if(read_fd==0)
			break;
	        if(read_fd==-1)
	        	printf("not successful read");
	        int k=0;
	        for(int i=0;i<read_fd;i++){
	        	if(read_buff[i]=='\n'){
	        	   ans_buff[k]='\0';
	        	   printf("%s\n",ans_buff);
	        	   k=0;
	        	  }
	        	  else{
	        	    ans_buff[k++]=read_buff[i];
	        	    }
	       }
	       
	}
	
	int closefd1=close(fd1);
	if(closefd1==-1){
	printf("not closed properly");}
	else{
		printf("closed properly\n");
	}
	return 0;
}
