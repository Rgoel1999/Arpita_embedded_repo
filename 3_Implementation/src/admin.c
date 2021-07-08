#include "my_libraries.h"
#include "std_libs.h"
train_dtls* admin_login(train_dtls* head_train)
{
      char username[]="a",un[100];
      char password[]="s",pw[100];

      printf("Enter Admin username\n");
      scanf("%s",un);

      printf("Enter Admin password\n");
      scanf("%s",pw);

      if(strcmp(un,username)==0 && strcmp(pw,password)==0)
            {
                  printf("admin Logged In\n");
                  head_train= admin(head_train);
            }
      else
            printf("Enter proper username or password\n");
      return head_train;
}

train_dtls* admin(train_dtls* head_train)
{
     int ch;
      printf("\t \tWelcome to Berhampur Railways\n");
      printf("1. create Train \n2. View Trains\n");
      printf("Enter choice\n");
      scanf("%d",&ch);

      switch(ch)
      {
            case 1:
              head_train = create_train(head_train);
            break;

            case 2:
                  printTrain(head_train);

      }
      return head_train;
}