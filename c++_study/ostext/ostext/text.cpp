#include <stdio.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/msg.h>

#include <sys/ipc.h>

#define MSGKEY 75

struct  msgform

{
    long  mtype;

    char  mtext[1024];

}msg;

int  msgqid;



void client()

{

    int i;

    msgqid = msgget(MSGKEY, 0666);   /*��75#��Ϣ����*/

    for (i = 10; i >= 1; i--)

    {

        msg.mtype = i;

        printf(��(client)sent\n��);

        msgsnd(msgqid, &msg, 1024, 0);     /*������Ϣ*/

    }

    exit(0);

}



main()

{

    client();

}