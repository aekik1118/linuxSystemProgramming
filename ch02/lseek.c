#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


extern int errno;

int main(){

    const char *buf = "My Ship is solid!";
    const char *file_name = "lseek_test";
    ssize_t nr;

    int fd;

    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    off_t ret;

    ret = lseek(fd, (off_t)100, SEEK_END);

    if(ret == (off_t)-1){
        printf("error\n");
    }

    nr = write(fd, buf, strlen(buf));

    if(nr == -1){
        printf("error\n");
        perror("write");
    }
    else{
        printf("success\n");
    }

    if(close(fd) == -1){
        perror("close");
    }

    return 0;
}

