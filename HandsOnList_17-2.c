#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct {
    int ticket_no;
} db;
int main(){
   int fd=open("database.txt",O_RDWR);
   if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("before entering critical section\n");
    struct flock lock;
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_len=0;
    lock.l_start=0;
    int fcn=fcntl(fd,F_SETLKW,&lock);
    if(fcn==-1){
    perror("Error locking file");
        close(fd);
        return 1;
    }
    printf("Inside the critical section\n");

    // Read current ticket number
    int rd=read(fd,&db,sizeof(db));
    if(rd==-1){
     perror("Error reading from file");
        close(fd);
        return 1;
    }
    printf("current ticketnum=%d\n",db.ticket_no);
    db.ticket_no++;
   int i= lseek(fd,0,SEEK_SET);
   if(i==-1){
perror("Error seeking to the beginning of file");
        close(fd);
        return 1;
    }
    int wr=write(fd,&db,sizeof(db));
    if(wr==-1){
    printf("error in writing\n");
    close(fd);
    return 1;
    }
    printf("press enter to unlock\n");
    getchar();
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error unlocking file");
        close(fd);
        return 1;
    }
    printf("Outside of the critical section\n");
    close(fd);

    return 0;
}

     
