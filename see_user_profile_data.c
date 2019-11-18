#include<stdio.h>
#include<stdlib.h>


 typedef struct  // this is structure for user profile data
{
 char f_name[15];
 char s_name[10];

 int age;
 char address[20];
 int mo_no;
 char E_mail_id[20];
 int national_id;
 char relationship[10];
 char gender[9];

}u_profile_data;

void u_profile(char u_acc_no[10],char user_name[25]) // user define function  which take two arguments
{
    u_profile_data u_data; // create object for user profile data



       char f_name[25]; // store profile file path

    strcpy(f_name,u_acc_no);

    strcat(f_name,"\\profile.txt");

    FILE *p; // create file pointer
    p=fopen(f_name,"r"); // open user profile name
    if(p==NULL)
        printf("\nProfile file not exits\n");
                                                     // fetch all data from profile file
    fscanf(p,"%s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%s",&u_data.f_name,&u_data.s_name,&u_data.age,&u_data.address,&u_data.mo_no,&u_data.E_mail_id,&u_data.national_id,&u_data.gender,&u_data.relationship);
     fclose(p); // close profile file

     system("cls");

        printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

         printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");

         printf("\n\n ACCOUNY HOLDER NAME:%s",user_name); // print Account holder name

    printf("\n\n\n\t\t\tFIRST NAME:\t\t%s\n\t\t\tLAST NAME:\t\t%s\n\t\t\tAGE:\t\t\t%d\n\t\t\tADDRESS:\t\t%s\n\t\t\tMOBILE NO.:\t\t%d\n\t\t\tE-mail ID:\t\t%s\n\t\t\tNATIONAL ID:\t\t%d\n\t\t\tGENDER:\t\t\t%s\n\t\t\tRELATIONSHIP STATUS:\t%s\n",u_data.f_name,u_data.s_name,u_data.age,u_data.address,u_data.mo_no,u_data.E_mail_id,u_data.national_id,u_data.gender,u_data.relationship);
                                                    // print all user data
     printf("\n\n\n press any key if you want to go back user menu\n");

       getch();
        user_menu(u_acc_no,user_name); // go to user menu


}
