
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct user_enter_data // store receiver data
{
     int E_ac_no;
     int amount;
};
 struct user_enter_data user_enter ; // create receiver object

void money_transfer(char u_acc_no[10],char user_name[25])  // user define money_transfer function for send money one account  to another account no.
{


    int E_pin_code; // take user pin
    int user_pin_code; // actual user pin
    int receiver_acc; // receiver account number
    char check_password[15]; // user password
    char reciver_name[10]; // receiver name
    int user_acc_no; // store user acc no as int


    system("cls");

      printf("\nACCOUNT HOLDER NAME: %s",user_name);



  printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


    printf(" \n\n \t\t MONEY TRANSFER\n");

    printf("\n \n ENTER ACCOUNT NUMBER YOU WANT TO SEND MONEY\n\n \t\t\t\t\t");

    sscanf(u_acc_no,"%d",&user_acc_no);

        while(1)
        {
            user_enter.E_ac_no=valid_user_input_acc(); // take receiver acc no.

            if(user_enter.E_ac_no==user_acc_no)
            {
                printf("\n\n you can't send money to your own Account number\n");
                printf("\n send Another Bank Account\n\n Hit any key if you retry\n");
                getch();
                money_transfer(u_acc_no,user_name);

            }
            else
                break;
        }

    FILE *p;
    p=fopen("users_log_in.txt","r"); // open users_log_in file for receiver account no.
    if(p==NULL)
        printf("\n log in file not Exits");

    while(1)
    {
        fscanf(p,"\n%d\t\t%s\t\t%s\n",&receiver_acc,&check_password,&reciver_name);  // extract data from users_log_in file
                                                                                    // check receiver account no.

        if(user_enter.E_ac_no==receiver_acc)
        {
            printf("\nACCOUNT HOLDER NAME:%s",reciver_name); // print receiver name
            break;
        }
        else
           {
            if(feof(p)) // check file empty or not
            {
            printf("\n you are Entered Account number not in Bank database!\ncheck it.");
            printf("\n press any key");
            getchar();
            user_menu(u_acc_no,user_name);
            break;
            }
           }
    }
    fclose(p); // close users_log_in file


    char re_amt_file[25]; // for receiver amt file path
    int re_amt_bal;
    char receiver_acc_no[10];
    itoa(user_enter.E_ac_no,receiver_acc_no,10);
     strcpy(re_amt_file,receiver_acc_no);
    strcat(re_amt_file,"\\amount.txt");
    p=fopen(re_amt_file,"r");
    if(p==NULL)
        printf("\n file not exits");
    fscanf(p,"%d",&re_amt_bal); // extract receiver amt bal from file

    fclose(p); // receiver amt file close

    printf("\n\n ENTER AMOUNT BALANCE YOU WANT TO SEND        \n\n \t\t\t\t\t AMOUNT:$");
    scanf("%d",&user_enter.amount);

    char u_amt_file[25]; // user amt file path

    strcpy(u_amt_file,u_acc_no);
    strcat(u_amt_file,"\\amount.txt");

    p=fopen(u_amt_file,"r"); // open user amt file
    if(p==NULL)
        printf("\n amount file not exits");

        int u_amt_bal;

        fscanf(p,"%d",&u_amt_bal); // extract user amount bal from file

        fclose(p); // close user amt file


        char user_pincode_file[25];  // store user pincode path
        strcpy(user_pincode_file,u_acc_no); // make user pincode path
        strcat(user_pincode_file,"\\user_pin.txt");

        p=fopen(user_pincode_file,"r"); // open user pincode file
        if(p==NULL)
            printf("\n user pin code file not Exits");

        fscanf(p,"%d",&user_pin_code); // extract pincode from user pincode file
        fclose(p); // close file

          int total_re_amt=0; // after transactions done receiver total amount bal
            int total_u_amt=0; // after transactions done user total amount bal

        if(u_amt_bal>=user_enter.amount) // check user have or not Enter amount bal
        {

               printf("\n\n ENTER PIN  \n\n  PIN CODE:  ");
                E_pin_code=input_valid_pin();

                 if(E_pin_code==user_pin_code)
                 {


            total_re_amt=re_amt_bal+user_enter.amount; // calculate total receiver account bal


            total_u_amt=u_amt_bal-user_enter.amount; // calculate total user account bal



               p=fopen(u_amt_file,"w"); // open user amt file
                if(p==NULL)
                    printf("\n user amount file not create");
            fprintf(p,"%d",total_u_amt); // save user account bal after transactions
            fclose(p); // close user amt file


             p=fopen(re_amt_file,"w");   // open receiver amt file
               if(p==NULL)
                  printf("\n receiver amt file not exits");

                  fprintf(p,"%d",total_re_amt); // save  receiver  amount bal after transactions
                  fclose(p); // close receiver amt file

                  int transaction_amt_data; // store transactions amount for transactions history

                  transaction_amt_data=user_enter.amount;
                 mk_trans_his(u_acc_no,receiver_acc_no,transaction_amt_data); // user define function for transaction history

                 }
                 else
                 {
                     printf("\n you Enter wrong pin code\n");
                    printf("\n press any key if you want to restart ");
                    getch();
                     money_transfer(u_acc_no,user_name); // again call
                     exit(1);
                 }


        }
        else
            {
                system("cls");

                    printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

                     printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");

                   printf("\nACCOUNT HOLDER NAME: %s",user_name); // transactions fall statements
                  printf("\n\n\n\t your transactions fall");
                  printf("\n\n\n you don't have sufficient amount \n ");
                   printf("\n\nyour current balance\n\t\t\t\t\tAMOUNT:$%d",total_u_amt); // print user current balance


                     printf("\n press any key if you want to go back ");
                   getch();
                    user_menu(u_acc_no); // user menu
            }





    system("cls");

                printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

                     printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


      printf("\nACCOUNT HOLDER NAME: %s",user_name); // print acc holder name
    printf("\n\n\n\t\t your transactions has been successfully done\n");
     printf("\n\n\t\t\tyour current balance\n\t\t\t\t\tAMOUNT:$%d",total_u_amt); // print user current bal

    printf("\n\n\n press Enter key if you want to go back ");
     if(getch()==13)
        user_menu(u_acc_no,user_name); // go to user menu
        else
            main(); // go to main menu


}



