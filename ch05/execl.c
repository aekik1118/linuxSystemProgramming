#include <unistd.h>
#include <stdio.h>

int main(){

    int ret;

    ret = execl("/usr/bin/vi", "vi", "/home/won/test.txt", NULL);
    if(ret == -1){
	perror("execl");
	return 1;
    }

    return 0;
}
