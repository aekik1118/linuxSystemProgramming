#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main(){

    const char *buf = "My Ship is solid!";
    const char *file_name = "wr_test";
    ssize_t nr;

    int fd;

    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    /*buf에 들어 있는 문자열을 'fd'에 기록한다!!!*/
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

