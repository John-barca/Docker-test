#include <stdio.h>
#include <dirent.h>

// 模拟实现 Linux ls命令
int main(int argc, char* argv[]) {
  DIR *dp;
  struct dirent *dirp;
  if (argc != 2) {
    printf("usage: ls directory_name\n");
    return 0;
  }
  if ((dp = opendir(argv[1])) == NULL) {
    printf("can't open %s\n", argv[1]);
    return 0;
  }
  while ((dirp = readdir(dp)) != NULL) {
    printf("%s\n", dirp->d_name);
  }

  closedir(dp);
  return 0;
}
