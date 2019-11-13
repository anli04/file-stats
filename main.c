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
  printf("File size: %ld\n", data.st_size);
  printf("Permissions: %o\n", data.st_mode);
  printf("Last accessed: %s\n", ctime(&data.st_atime));
  return 0;
}
