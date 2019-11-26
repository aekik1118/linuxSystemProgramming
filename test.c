#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

extern int errno;

int main(){

    int fd;
    ssize_t ret;
    size_t len = 14;

    char buf[BUFSIZ];
    char * buf2 = buf;

    fd = open("aa",O_RDONLY);

    if(fd == -1){
	printf("file open error\n");
    }


    while(len != 0 && (ret = read(fd, buf2, len)) != 0){

	if(ret == -1){
	    if(errno == EINTR)
		continue;
	    perror("read");
	    break;
	}
	len -= ret;
	buf2 += ret;
    }
	
    printf("%s",buf2);	
    printf("%s",buf);

    return 0;
}

