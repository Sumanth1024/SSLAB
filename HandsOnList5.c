#include<stdio.h>
#include<fcntl.h>
int main(){
	creat("file1", 0666);
	creat("file2", 0666);
	creat("file3", 0666);
	creat("file4", 0666);
	creat("file5", 0666);
	while(1);
	return 0;
}
