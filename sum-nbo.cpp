#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	FILE* fp;
	uint32_t buffer;
	int i = 0;
	int sum = 0;
	int buf;
	while(++i< argc){
		fp = fopen(argv[i], "rb");
		while(fread(&buffer, sizeof(uint32_t),1,fp)){
			buf = ntohl(buffer);
			printf("%u(0x%08x)", buf,buf);
			sum += 	buf;
		}
		fclose(fp);
		if(i < argc-1){
			printf(" + ");
		}
		else{
			printf(" = ");
		}
			
	}
	printf("%u(0x%08x)",sum,sum);
}
