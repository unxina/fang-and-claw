#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	int sktfd;
	int len;
	struct sockaddr_in adrs;
	int result;
	char ch='A';
	sktfd=socket(AF_INET,SOCK_STREAM,0);
	adrs.sin_family=AF_INET;
	adrs.sin_addr.s_addr=inet_addr("127.0.0.1")
	adrs.sin_port=htons(9734);
	len=sizeof(adrs);
	result=connect(sktfd,(struct sockaddr*)&adrs,len);
	if(result==-1){
		perror("oops:client");
		exit(1);
	}
	write(sktfd,&ch,1);
	read(sktfd,&ch,1);
	printf("char from server=%c\n",ch);
	close(sktfd);
	exit(0);
}
