#include "pipe_networking.h"


int main() {
  signal(SIGINT,sighandler);

  int to_client;
  int from_client;

  while(1){
    from_client = server_handshake( &to_client );

    char message[BUFFER_SIZE];
    while(read(from_client,message,sizeof(message))){
      printf("[server] received: %s\n", message);

      int i;
      for (i = 0; i < strlen(message); i++)
        message[i] += 2;

      write(to_client,message,sizeof(message));
    }
  }
}

static void sighandler(int signo){
  if(signo == SIGINT){
    remove("mario");
    printf("\nremoved wkp\n");
    exit(0);
  }
}
