#include<stdio.h>
#include<stdlib.h>


int create_ac_no() // this function create user account number
{

     const int bank_code=19980000; // bank code
      int serial_no; // store series no.
      int new_serial_no; // new series no.
      int u_new_acc; //new user account no.


    system("cls");

    int increment_no=1;// add acc no. at the last bank acc no.
    FILE *p; // file pointer
    p=fopen("user_serial_no.txt","r"); // open user no file for creating new user acc no.
    if(p==NULL)
        printf("\n user serial no. file not open");

     fscanf(p,"%d",&serial_no); // extract serial no. from file

         fclose(p); // close file

     new_serial_no=serial_no+increment_no;   //make new serial no.
     u_new_acc=bank_code+new_serial_no; // make new user account no.




     p=fopen("user_serial_no.txt","w"); // open user user no. file for saving total users

     fprintf(p,"%d",new_serial_no); // save serial no in file

     fclose(p); // close file



    return(u_new_acc); // return new user account number





}
