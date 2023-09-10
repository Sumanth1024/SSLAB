#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{ 
 struct stat ans;
 if(stat(argv[1],&ans)==-1)
 {
   printf("Can't proceed further");
   exit(1);
 }
  printf("Inode Number %d",ans.st_ino);
  printf("\nNumber of hard links %d",ans.st_nlink);
  printf("\nUID %d",ans.st_uid);
  printf("\nGID %d",ans.st_gid);
  printf("\nSize %d",ans.st_size);
  printf("\nBlock size %d",ans.st_blksize);
  printf("\nNumber of blocks %d",ans.st_blocks);
  printf("\nTime of last access %s",ctime(&ans.st_atime));
  printf("\nTime of last modification %s",ctime(&ans.st_mtime));
  printf("\nTime of last changes %s",ctime(&ans.st_ctime));

}
