#include<stdio.h> 
#include<string.h>   
#include<sys/socket.h>   
#include<arpa/inet.h> 
#include<unistd.h>
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char server_reply[2000];
    char *message;
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
      message="....................I am client three , i give 'Extra-Topping' to icecreams .....................\n"; 
    //keep communicating with server
    int n=3;
    while(n!=0)
    {
        
       if(n==2)
       { //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
        } 
        //Receive a reply from the server
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(server_reply);
     printf("\n ");
n--;
    }
     sleep(2);
    close(sock);
    return 0;
}
