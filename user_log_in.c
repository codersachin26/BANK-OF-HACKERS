#include<stdio.h>
#include<stdlib.h>
#include<string.h>



log_in()
{


   int Enter_acc;  // store invalid user acc_no
   int user_valid_acc; // store valid user acc_no
   int count=1;  // log in count

    char Enter_password[9];  // store invalid pass
    char user_pass[10];   // store user actual password
    char user_name[20];   // store user name
    char account_holder_name[25];  // store acc holder name

    system("cls");



  printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


     printf("\n Enter your account number"); // take user account no.

      Enter_acc=valid_user_input_acc();
     fflush(stdin);

    printf("\n Enter your password"); // take user password
    printf("\n       PASSWORD:  ");
    gets(Enter_password);

    FILE *p;    // make FILE pointer
    p=fopen("users_log_in.txt","r");  // open users_log_in file
    if(p==NULL)
        printf("\nfile not exits\n");


     while(1)
     {


     fscanf(p,"\n%d\t\t%s\t\t%s\n",&user_valid_acc,&user_pass,&user_name); // check valid user


         if(Enter_acc==user_valid_acc)
            {

              printf("\n your Account Number matched \n"); // check user account no. valid or not
              char user_acc[10];



               if(!strcmp(Enter_password,user_pass))
                {
                  printf("\nwelcome %s to your account\n",user_name); // if both are
                                                                      //correct then
                   itoa(user_valid_acc,user_acc,10);                   // execute these lines
                   strcpy(account_holder_name,user_name);
                    user_menu(user_acc,account_holder_name); // user define user_menu() only for log_in user
                     break;

                     }
        else
        {
             printf("\n but you are enter wrong password\n\ntry last time\n"); // both are incorrect
              printf("\n       PASSWORD:  ");                             // then execute ELSE block statement
                    gets(Enter_password);

                     if(!strcmp(Enter_password,user_pass))
                    {
                        printf("\nwelcome %s to your account\n",user_name); // if both are
                                                                      //correct then
                        itoa(user_valid_acc,user_acc,10);                   // execute these lines
                       strcpy(account_holder_name,user_name);
                       user_menu(user_acc,account_holder_name); // user define user_menu() only for log_in user
                        break;

                     }
                     else
                     {
                         printf("\n  you are enter wrong password\n\n Hit any key if want restart");
                         getch();
                         log_in();
                         break;

                    }


        }


     }
     else
     if(feof(p))  // check file is empty or not
     {
        printf("\n Enter account number not Exits in our bank database\n\n Hit any key if you want to go MAIN MENU");
        getch();
        main();
        break;
     }


     }

   fclose(p); // close users_log_in file

}

