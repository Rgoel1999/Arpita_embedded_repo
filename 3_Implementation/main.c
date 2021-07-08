#include "my_libraries.h"
#include "std_libs.h"
int main ()
{
      usr_dtls *head_usr = NULL;
      train_dtls *head_train = NULL; 
      int k;
      head_usr = load_userdata(head_usr);
      head_train = load_traindata(head_train);
      
      int ch;
      printf("\nEnter Choice\n");
      printf("1 New User Signup\n2 Admin Login\n3 User Login\n");
      scanf("%d",&ch);
      switch(ch)
      {
            case 1:
                  head_usr = new_user_signup(head_usr);
            break;

            case 2:
                  head_train = admin_login(head_train);
            break;

            case 3:
            {
                  k = user_login(head_usr,head_train);
                  if(k == 1)
                        printf("user logged in ");
                  else
                        printf("Username or password mismatch");
            }
            break;
      }

      Reload_traindata(head_train);
      Reload_userdata(head_usr);
     
      while(head_usr!=NULL){
            usr_dtls* temp = head_usr;
            head_usr=head_usr->next;
            free(temp);
      }

      while(head_train!=NULL){
            train_dtls* temp = head_train;
            head_train=head_train->next;
            free(temp);
      }
}