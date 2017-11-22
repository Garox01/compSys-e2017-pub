#include "csapp.h"

#define BUFSIZE 1024

int main(void)
{
    char c;

    int n;
    rio_t rio;
    char buf[BUFSIZE];

    Rio_readinitb(&rio, STDIN_FILENO);
    while((n = Rio_readnb(&rio, buf, BUFSIZE)) != 0)
      Rio_writen(STDOUT_FILENO, buf, n);
    exit(0);
}

