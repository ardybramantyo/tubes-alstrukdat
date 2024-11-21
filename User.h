#ifndef USER_H
#define USER_H

#define MAX_USER_NAME 128
#define MAX_USER_PASS 255

typedef struct user
{
    char name[MAX_USER_NAME];
    char password[255];
    int money;
} User;

void setName(User *user, const char *name);
void setPassword(User *user, const char *password);
// set be lgsung njir sbnernya mah
void setMoney(User *user, int money);
User createUser(const char *name, const char *password, int money);

#endif
