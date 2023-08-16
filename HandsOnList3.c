#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
//create file with file1.txt with read and write permissions
	 int fileDescriptor=creat("file1.txt",S_IRUSR | S_IWUSR);
	 if(fileDescriptor==-1){
                perror("Error creating file");
                return 1;
          }
          printf("File created successfully. File descriptor: %d\n", fileDescriptor);

    // Close the file
         close(fileDescriptor);

          return 0;
}
