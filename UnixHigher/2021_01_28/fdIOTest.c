/**
 * Linux 系统文件相关的系统调用
 * 
*/
// 不带缓冲的I/O
// 函数 open、read、write、lseek以及close
#include <stdio.h>
#include <unistd.h>
#define BUFFSIZE 4096

// STDIN_FILENO 标准输入宏 指定标准输入文件描述符 0
// STDOUT_FILENO 标准输出宏 指定标准输出文件描述符 1
//int main(void) {
//  int n;
//  char buf[BUFFSIZE];
//  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
//    if (write(STDOUT_FILENO, buf, n) != n) {
//      printf("write error!\n");
//      return -1; 
//    }
//  }
//
//  if (n < 0) {
//    printf("read error!\n");
//    return -1;
//  }
//  return 0;
//}

#include <error.h>
// 标准 I/O 
// 标准 I/O 函数提供带缓冲的接口，使用标准I/O函数无需选取最佳的缓冲区大小
//int main(void) {
//  int c;
//  while ((c = getc(stdin) != EOF)) {
//    if (putc(c, stdout) == EOF) {
//      printf("output error!\n");
//      return -1;
//    }
//  }
//  return 0;
//}

#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void) {
  char buf[4096];
  __pid_t pid;
  int status;

  printf("%% ");
  while (fgets(buf, sizeof(buf), stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') 
      buf[strlen(buf) - 1] = 0;
    if ((pid = fork()) < 0) {
      printf("fork error!\n");
      return -1;
    } else if (pid == 0) {
      execlp(buf, buf, (char*)0);
    }
  }
  return 0;
}