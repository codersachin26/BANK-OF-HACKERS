#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>




void main()
{




    system("cls"); // clear console screen

   int u_choice; // user choice



   printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


    u_choice=main_menu_choice(); // this main menu_interface_choice function return user choice no.



    user_functions(u_choice); // this is user_functions for users
                                // which take one argument as a user choice






    }






