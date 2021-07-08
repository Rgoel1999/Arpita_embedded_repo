#ifndef __MY_LIBRARIES_H__
    #define __MY_LIBRARIES_H__
    typedef struct users_details
    {
        char username[100];
        char password[100];
        int PNR;
        int train_no;
        int no_of_seats;
        int status;
        struct users_details *next;
    }usr_dtls;
    typedef struct train_details
    {
        char name[100];
        int train_no;
        char start_place[100];
        char destination[100];
        int capacity;
        int booked;
        struct train_details *next;
    }train_dtls;


    void user(usr_dtls*, train_dtls*);
    train_dtls* admin(train_dtls*);
    void book_ticket(usr_dtls*,train_dtls*);
    void cancel_ticket(usr_dtls*,train_dtls*);
    train_dtls* create_train(train_dtls*);
    void printTrain(train_dtls*);
    void print_Ticket(usr_dtls*,train_dtls*);
    train_dtls* admin_login(train_dtls*);
    train_dtls* load_traindata(train_dtls*);
    usr_dtls* load_userdata(usr_dtls *);
    void Reload_traindata(train_dtls*);
    void Reload_userdata(usr_dtls*);
    usr_dtls* new_user_signup(usr_dtls*);
    int user_login(usr_dtls *,train_dtls*);

#endif