#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

int main(){
  struct stat data;
  printf("Makefile data.\n");
  stat("makefile", &data);
  if (errno) printf("Error: %d - %s\n", errno, strerror(errno));
  printf("File size: ");
  if (data.st_size > 1000000000000) printf("%ld TB\n", data.st_size / 1000000000000);
  else if (data.st_size > 1000000000) printf("%ld GB\n", data.st_size / 1000000000);
  else if (data.st_size > 1000000) printf("%ld MB\n", data.st_size / 1000000);
  else if (data.st_size > 1000) printf("%ld KB\n", data.st_size / 1000);
  else printf("%ld B\n", data.st_size);
  printf("Permissions: %o\n", data.st_mode);
  printf("Permissions (reformatted): ");
  char p[7];
  sprintf(p, "%o", data.st_mode);
  strcpy(p, &p[strlen(p) - 3]);
  int i = 0;
  for (; i < 3; i++){
    switch (p[i] - 48){
      case 0:
        printf("---");
        break;
      case 1:
        printf("--x");
        break;
      case 2:
        printf("-w-");
        break;
      case 3:
        printf("-wx");
        break;
      case 4:
        printf("r--");
        break;
      case 5:
        printf("r-x");
        break;
      case 6:
        printf("rw-");
        break;
      case 7:
        printf("rwx");
        break;
    }
  }
  printf("\n");
  printf("Last accessed: %s\n", ctime(&data.st_atime));
  return 0;
}
