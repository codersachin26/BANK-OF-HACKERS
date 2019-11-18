
#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>


 int main_menu_interface() // main interface
 {

  system("cls"); // clear console screen



   printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


   printf(" \n\n \t\t  what do you want?\n");  // these is main menu

   printf("\n 1-> Create new bank account\n ");  // these is main menu functions
   printf("\n 2-> Log in\n");
   printf("\n 3-> Add bank balance\n");
   printf("\n 4-> Update your bank account\n");
   printf("\n 5-> Close\n");

   printf("\n\n ENTER A NO. ACCORDING TO SERIES\n \n what do you want to do\n\n");

   printf("\n \t\t\t ENTER>> ");

   fflush(stdin);

 }

   int main_menu_choice() // take user choice
 {



      int u_choice; // return user choice as int
      char Enter_choice[3]; // take user choice as string
       int count; // indexing no.

    while(1) // take valid user choice
    {

        main_menu_interface(); // call main menu interface
         fflush(stdin);

         count=0;

        gets(Enter_choice); // take choice

       if(Enter_choice[count]==NULL) // user something Entered or not
         {
             printf("\n\n you are not Enter anything\n try again\n Hit any key ");
                getch();
               continue;
         }

            int index=0;
         for( index=0;Enter_choice[index];index++); // check input values
         if(index>=2) // if digits greater than 2
         {
                printf("\n wrong choice\n try Again\n Hit any key");
                 getch();
                  continue;
         }

     if(Enter_choice[count]>=49&&Enter_choice[count]<=53) // only 1 to 5 int no.
       {

            sscanf(Enter_choice,"%d",&u_choice); // convert char to int

            return(u_choice); // return value

       }
       else // user Enter invalid data
       {

               printf("\n wrong choice\n try Again\n Hit any key");
                 getch();
                continue;

       }

    }

 }





 void user_functions(int u_choice) // this function take only one arg according to user
{

       switch(u_choice)  // switch have 5 cases
   {
   case 1:

     user_registration_form(); // user define function for user registration
     break;  // break case 1

   case 2:

    log_in();  // for user log in
    break;

   case 3:

       add_amt(); // add amount in user account balance
       break;

   case 4:

       update_user_acc();  // this function update user account profile data
       break;

   case 5:

    exit(1); // end program
     break;

   }
}
