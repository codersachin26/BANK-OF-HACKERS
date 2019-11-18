#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void add_amt()  // this function add amount bal in user account
{
   int Enter_acc_no;  // store user Enter account no.
   int Enter_amt; // store user Enter amount bal
   char E_name[15]; // store user Enter name

   int validate_acc;  // store actual account no.
   char validate_pass[15]; // store valid user password
   char user_name[10];  // store valid user name


      system("cls"); // clear console screen

     printf("\nACCOUNT HOLDER NAME: %s",user_name); // print account user name

     printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");



    printf(" \n\t\t\t HERE YOU CAN UPDATE YOUR  BANK BALANCE AMOUNT\n\nENTER YOUR ACCOUNT NUMBER\n\n  \t\t\t ENTER A/C NO.>> ");

      Enter_acc_no=valid_user_input_acc(); // this function return bank format account no.


    FILE *p; // create file type pointer
      p=fopen("users_log_in.txt","r");  // open log_in file for checking valid user or not
       if(p==NULL)
         printf("\n users_log_in file not Exits");

        while(1)
        {

         fscanf(p,"\n%d\t\t%s\t\t%s\n",&validate_acc,&validate_pass,&user_name); // Extract data from file for checking valid user or not


         if(Enter_acc_no==validate_acc)  // this statements execute when user is valid_user
         {
            printf("\n\n\t\t\t your account ready for updating bank balance\n\n ");
             break;
         }
         else
            if(feof(p)) // file empty or not
         {
             printf("\n\t\t you are Enter wrong account number\n check it!");
             break;
         }
        }

        fclose(p); // close users_log_in file

        char user_acc[10]; // store user account no as a string
        itoa(validate_acc,user_acc,10); // convert int to char

     fflush(stdin); // refresh buffer space
     printf("\n\n ENTER YOUR NAME\n\n \t\t\t NAME>> ");

     int enter_count=0; // store attempt time

    while(1)
    {

    gets(E_name);  // take user name

    if(!strcmp(E_name,user_name)) // check user_name exits or not
        break;
    else
        if(2==enter_count)  // only user 2 time attempt
           main();

          printf("\n you enter wrong name\n try again!\n\n \t\t\t NAME: ");
        enter_count++; // increase attempt time
    }


    printf(" \n\n  \t\t\t ENTER AMOUNT:$ "); // take amt bal

    Enter_amt=user_input_amt(); // this function take amt bal

    char amt_file[25]; // user amt file path container
    int user_old_amt;
    int user_new_amt;

    strcpy(amt_file,user_acc); // make user amt file path
    strcat(amt_file,"\\amount.txt");

    p=fopen(amt_file,"r"); // open user amount file  in read mode
    if(p==NULL)
        printf("\n amount file not create");

        fscanf(p,"%d",&user_old_amt); // extract user old amount
          fclose(p);  // close file

        user_new_amt=user_old_amt+Enter_amt; // calculate user new account balance



         p=fopen(amt_file,"w");   // open user amount file  in write mode
             if(p==NULL)
                 printf("\n amount file not create");

     fprintf(p,"%d", user_new_amt); // save user total amt into user amt file
     fclose(p);   // close user amount file

  printf("\n your Amount balance successfully updated \n  \tyour current balance\n\t\t\t\t\t\tamount:$%d ",user_new_amt); // show user current balance after transactions done

  printf("\n\n\n\n press any key if you want to go MAIN MENU\n"); // go to main menu
  getch();

  system("CLS"); // clear

  main(); //  main menu

}
