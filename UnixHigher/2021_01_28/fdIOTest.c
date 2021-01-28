/**
 * Linux 系统文件相关的系统调用
 * 
*/
// 不带缓冲的I/O
// 函数 open、read、write、lseek以及close
#include <stdio.h>
#include <unistd.h>
#define BUFFSIZE 4096

int main(void) {
  int n;
  char buf[BUFFSIZE];
  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      printf("write error!\n");
      return -1; 
    }
  }

  if (n < 0) {
    printf("read error!\n");
    return -1;
  }
  return 0;
}