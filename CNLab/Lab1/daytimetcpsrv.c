#include	"unp.h"
#include <stdio.h> 
#include <string.h> 

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	struct sockaddr_in	servaddr;
	FILE                *sentFile;
	char				buff[MAXLINE],line[MAXLINE],fileName[MAXLINE],in[MAXLINE],out[MAXLINE];

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(13);	/* daytime server */

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);
	
	for ( ; ; ) {
		connfd = Accept(listenfd, (SA *) NULL, NULL);
		   
            while( out != "bye" ) 
            { 
                 fgets(out, MAXLINE, stdin);
                 snprintf(buff, sizeof(buff), "%s",out);
                 Write(connfd, buff, strlen(buff));
                 
                 if(read(connfd, in, MAXLINE) > 0);
                    {
                        printf( "%d >>> %s",connfd,in);
                    }
             } 
		Close(connfd);
	}
}
