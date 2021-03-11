gcc -w client_libevent.c -o client -L. -levent -levent_core
gcc -w server_libevent.c -o server -L. -levent -levent_core
