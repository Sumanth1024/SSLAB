#include<stdio.h>
#include<unistd.h>
int main(){
        char Buffer[10];
        int size;
        while((size=read(STDIN_FILENO,Buffer,sizeof(Buffer)))>0){
                        if(write(STDOUT_FILENO,Buffer,size)!=size){
                        printf("write error");
                        return 1;
                        }
        }
        if(size<0){
        printf("read error");
        return 1;
        }
        return 0;
}

