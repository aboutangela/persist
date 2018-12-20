#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char message[BUFFER_SIZE];
  while(1){
    printf("enter a message: ");
		fgets(message,sizeof(message),stdin);
		message[strlen(message) - 1] = 0;

    write(to_server,message,sizeof(message));

    read(from_server, message, sizeof(message));
    printf("[client] received: %s\n", message);
	}
}
