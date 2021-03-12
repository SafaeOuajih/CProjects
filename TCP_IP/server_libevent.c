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
#define lenf 39
static const int PORT = 8000;

static char buffer[256] = {0};
static char bufferw[256] = {0};
static char file[500]= "/home/safae/Documents/CProjects/TCP_IP/";

static int g_iCnt = 0;
static void listener_cb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int socklen, void *);
static void conn_writecb(struct bufferevent *, void *);
static void conn_readcb(struct bufferevent *, void *);
static void conn_eventcb(struct bufferevent *, short, void *);




int main(int argc, char **argv)
{
    struct event_base *base;
    struct evconnlistener *listener;
    struct event *signal_event;

    struct sockaddr_in sin;

    base = event_base_new();
    if (!base) {
        fprintf(stderr, "Could not initialize libevent!\n");
        return 1;
    }

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);	
    sin.sin_port = htons(PORT);

    //Create, bind, and monitor socket s
    listener = evconnlistener_new_bind(base, listener_cb, (void *)base,
    LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, -1,(struct sockaddr*)&sin, sizeof(sin));

    if (!listener) {
        fprintf(stderr, "Could not create a listener!\n");
        return 1;
    }    

    event_base_dispatch(base);

    evconnlistener_free(listener);
    //event_free(signal_event);
    event_base_free(base);

    printf("done\n");
    return 0;
}







//Called when there is a connection
static void listener_cb(struct evconnlistener *listener, evutil_socket_t fd,
    struct sockaddr *sa, int socklen, void *user_data)
{
    struct event_base *base = (struct event_base*)user_data;
    struct bufferevent *bev;

    //Construct a bufferevent
    bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    if (!bev) {
        fprintf(stderr, "Error constructing bufferevent!");
        event_base_loopbreak(base);
        return;
    }

    //Binding Read Event Callback Function, Write Event Callback Function, Error Event Callback Function
    bufferevent_setcb(bev, conn_readcb, conn_writecb, conn_eventcb, NULL);

    bufferevent_enable(bev, EV_WRITE);
    bufferevent_enable(bev, EV_READ);

    const char *welcome = "Hello my dear client :) I am Safae's server\n";
    bufferevent_write(bev, welcome, strlen(welcome));
}

static void conn_writecb(struct bufferevent *bev, void *user_data)
{
}

static void conn_readcb(struct bufferevent *bev, void *user_data)
{
  //printf("touch conn_readcb\n");
  FILE *fptr;
  char ch;
  int n = 0;
  int lenb =0;
  memset(buffer, 0x00, sizeof(buffer));
  struct evbuffer *input = bufferevent_get_input(bev);
  size_t sz = evbuffer_get_length(input);
  if (sz > 0)
    {
      bufferevent_read(bev, buffer, sz);
      printf("client:>>\n\n");
      printf("%s\n", buffer);
      g_iCnt++;
      if ((strncmp( buffer, "show", 4)) == 0)
	{
	  lenb = strlen(buffer);
	  n = lenf;
	  file[lenf]='a';
	  for(int i =5;i<lenb-1;i++){
	    file[n]= buffer[i];
	    n++;
	  }
	  file[n+1]=0;
	  fptr = (fopen(file, "r"));
	  if(fptr == NULL)
	    {
	      printf("the file is : %snow\n",file);
	      printf("Error! Failed file");
	      // strcpy(bufferw,"Error openning file");
	      //bufferevent_write(bev, bufferw, strlen(bufferw));
	      exit(1);
	    }
	  n=0;
	  while ((ch = fgetc(fptr)) != EOF)
	    {
	      bufferw[n++]=ch;
	    }
	  bufferw[n+1]=0;
	  fclose(fptr);
	  bufferevent_write(bev, bufferw, strlen(bufferw));
	}
    }
  
}

static void conn_eventcb(struct bufferevent *bev, short events, void *user_data)
{
    if (events & BEV_EVENT_EOF) {
        printf("Connection closed.\n");
    } else if (events & BEV_EVENT_ERROR) {
        printf("Got an error on the connection: %s\n",
            strerror(errno));/*XXX win32*/
    }
    
    bufferevent_free(bev);
}
