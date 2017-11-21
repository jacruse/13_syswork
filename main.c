#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main() {
  int fd1[2];
  int fd2[2];
  int pnum, cnum, total;

  pipe(fd1);
  pipe(fd2);

  if (fork()) {
    close(fd1[1]);
    read(fd1[0], &cnum, sizeof(cnum));
    printf("Michael Dapaah [child]: Who you calling child bruv. This ain't no joke ting. Received %d\n", cnum);
    cnum *= 8;
    printf("Michael Dapaah [child]: Did some quik mafs and multiplied by 8 to get %d\n", cnum);
    
    printf("Michael Dapaah [child]: Sending %d back to Big Shaq. Not gonna call you parent bruv that's weird\n\n", cnum);
    close(fd2[0]);
    write(fd2[1], &cnum, sizeof(cnum));
    exit(0);
  }
  pnum = 2;
  close(fd1[0]);
  printf("Big Shaq [parent]: Boom! Prrrah! Sending 2 to child\n\n");
  write(fd1[1], &pnum, sizeof(pnum));

  close(fd2[1]);
  read(fd2[0], &total, sizeof(total));
  printf("Big Shaq [parent]: Skyaaahhh. Received %d from Michael\n", total);
}
  
