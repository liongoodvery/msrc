
#ifndef  MSG_MSG_H
#define MSG_MSG_H
#define MAX_LEN 1024
typedef struct {
    long type;
    char msg[MAX_LEN];
} Msg;
#endif//MSG_MSG_H