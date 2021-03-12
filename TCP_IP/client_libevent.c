#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>

static const int PORT = 8080;
static char g_szWriteMsg[256] = {0};
static char g_szReadMsg[256] = {0};
static int g_iCnt = 0;
static void conn_writecb(struct bufferevent *, void *);
static void conn_readcb(struct bufferevent *, void *);
static void conn_eventcb(struct bufferevent *, short, void *);

int main(int argc, char **argv)
{
    struct event_base *base;

    struct sockaddr_in sin;

    base = event_base_new();
    if (!base) {
        fprintf(stderr, "Could not initialize libevent!\n");
        return 1;
    }

    memset(&sin, 0, sizeof(sin));
    sin.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    
    struct bufferevent* bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
    if (bev == NULL )
    {
        fprintf(stderr, "socket init failed\n");
        return 1;
    }
    bufferevent_setcb(bev, conn_readcb, conn_writecb, conn_eventcb, NULL);

    //Connect the server
    int flag = bufferevent_socket_connect(bev, (struct sockaddr*)&sin, sizeof(sin));
    if (-1 == flag )
    {
        fprintf(stderr, "connect failed\n");
        return 1;
    }
    bufferevent_enable(bev, EV_READ | EV_WRITE);

    event_base_dispatch(base);
    event_base_free(base);

    printf("done\n");
    return 0;
}

static void conn_writecb(struct bufferevent *bev, void *user_data)
{
  
}

static void conn_readcb(struct bufferevent *bev, void *user_data)
{
  int n;
  n=0;
  memset(g_szReadMsg, 0x00, sizeof(g_szReadMsg));
  struct evbuffer *input = bufferevent_get_input(bev);
  size_t sz = evbuffer_get_length(input);
  if (sz > 0)
    {
      bufferevent_read(bev, g_szReadMsg, sz);
      printf("server:>>\n\n");
      printf("%s\n", g_szReadMsg);
      memset(g_szWriteMsg, 0, sizeof(g_szWriteMsg));
      //snprintf(g_szWriteMsg, sizeof(g_szWriteMsg)-1, "hi server,this count is %d", g_iCnt);
      g_iCnt++;      
    }
  printf("Enter the string : "); 
  while (( g_szWriteMsg[n++] = getchar()) != '\n') 
    ;
  bufferevent_write(bev, g_szWriteMsg, strlen(g_szWriteMsg));
  if ((strncmp( g_szWriteMsg, "exit\n", 6)) == 0) { 
    printf("Client Exit...\n");
    bufferevent_free(bev);
  }
}

static void conn_eventcb(struct bufferevent *bev, short events, void *user_data)
{
    if (events & BEV_EVENT_EOF) {
        printf("Connection closed.\n");
    } else if (events & BEV_EVENT_ERROR) {
        printf("Got an error on the connection: %s\n",
            strerror(errno));
    }
    else if(events & BEV_EVENT_CONNECTED)
    {
        //Go here when the connection is successful, and the connection is really established only after the client triggers the read event for the first time.
        printf("connect success\n");
        const char* msg = "hi server how are you";
        bufferevent_write(bev, msg, strlen(msg));
        return;
    }
    bufferevent_free(bev);
}
