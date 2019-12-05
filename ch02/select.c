#include<sys/select.h>
#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main(void){

    struct timeval tv;
    fd_set readfds;
    int ret;

    /*표준 입력에서 입력을 기다리기 위한 준비*/
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    /*입력 대기*/
    ret = select(STDIN_FILENO + 1,
            &readfds,
            NULL,
            NULL,
            &tv);
    
    if(ret == -1){
        perror("select");
        return 1;
    } else if(!ret){
        printf("%d seconds elapsed.\n",TIMEOUT);
        return 0;
    }

    /*여기 까지 오면 select가 0이 아닌 양수를 반환했다는 의미*/ 
    /*즉 파일 디스크립터에서 즉시읽기 가능*/

    if(FD_ISSET(STDIN_FILENO, &readfds)){
        char buf[BUF_LEN+1];
        int len;

        len = read(STDIN_FILENO, buf, BUF_LEN);
        if(len == -1){
            perror("read");
            return 1;
        }

        if(len){
            buf[len] = '\0';
            printf("read: %s\n", buf);
        }
        
        return 0;
    }

    fprintf(stderr, "this should not happen!\n");
    return 1;
}

