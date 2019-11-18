#include<stdio.h>
#include<stdlib.h>




void user_menu_interface(char user_name[25])
{



   system("cls");





   printf("\nACCOUNT HOLDER NAME: %s",user_name);  // print Account user name

  printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


    printf(" \n\n \t WHAT DO YOU WANT TO DO?\n\n ");

    printf("\n 1-> see your profile\n"); // choice 1 for see own profile data
    printf("\n 2-> send money\n");     // choice 2 for send money to other user
    printf("\n 3-> check your bank balance\n"); // check bank balance
    printf("\n 4-> see transactions history\n"); // see transaction history
    printf("\n 5-> Main menu\n"); // go to main menu



}



int user_menu_choice(char user_name[25]) // this function return user choice as int
{
     int u_choice; // user choice as int
      char Enter_choice[3]; // user choice as char
       int count=0; // for index no.

    while(1) // return valid user choice
    {

       user_menu_interface(user_name); // call user_menu interface function
        printf("\n ENTER:"); // store user Enter choice
         fflush(stdin);

        gets(Enter_choice); // take choice

       if(Enter_choice[count]==NULL) // not Enter anything
         {
             printf("\n\n you are not Enter anything\n try again\n Hit any key ");
                getch();
               continue;
         }

            int i;
         for( i=0;Enter_choice[i];i++); // check how many characters
         if(i>=2) // grater than 2 character
         {
                printf("\n wrong choice\n try Again\n Hit any key");
                 getch();
                  continue;
         }

     if(Enter_choice[count]>=49&&Enter_choice[count]<=53) // only 1 to 5 allow
       {

            sscanf(Enter_choice,"%d",&u_choice);

            return(u_choice);

       }
         else // user Enter invalid choice
           {

               printf("\n wrong choice\n try Again\n Hit any key");
                 getch();
                continue;


           }
    }
}

void user_menu_functions(char user_acc[10],char user_name[25],int user_choice) // user_menu functions
{                                                                              // it take three arguments
                                                                                // 1- user account no
                                                                                // 2- user name
                                                                                 // 3- user choice
    switch(user_choice)
    {

    case 1:                                 //  user profile
        printf("\n YOUR PROFILE DATA\n\n");
        u_profile(user_acc,user_name);
        break;

    case 2:                                // send money other user
        printf("\n MONEY TRANSFER\n\n");
        money_transfer(user_acc,user_name);
        break;

    case 3:                                // check amt bals
        printf("\n AMOUNT BALANCE\n");
        see_amt_bal(user_acc,user_name);
        break;

    case 4:                                // see transactions history
        printf("\n ALL TRANSACTIONS HISTORY\n\n");
        transactions_history(user_acc,user_name);
        break;

    case 5:                   // go to main menu
        system("CLS");
        main();
        break;

    default:
        printf("\n you Enter wrong choice");
        getch();
        break;


    }
}



void user_menu(char user_acc[10],char user_name[25]) // this is user menu function
{

    int user_choice; // user choice

    user_choice=user_menu_choice(user_name); // return user choice according to user_interface
    user_menu_functions(user_acc,user_name,user_choice); // call user_menu function for user choice

}
