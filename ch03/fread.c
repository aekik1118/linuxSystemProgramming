#include <stdio.h>

int main(void){

	FILE * stream;
	stream = fopen("abc","r");

	if(!stream){
		printf("fopen error\n");
	
	}

	char buf[64];
	size_t nr;
	nr = fread(buf, sizeof(buf),1,stream);
	if(nr == 0){
		if(ferror(stream)){
			printf("ferror error\n");
		}

		if(feof(stream)){
			printf("feof\n");
		}


	}

	printf("%s\n",buf);
	return 0;
}
