#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Create variables to iterate//
int i,j;
//create an integer varable called exit, to help exit out of a function//
int exit;
//Prototype functions//
//Menu will display the options//
void menu();
//Create a class that holds the date//
struct date {
    int month, day, year;
};
struct {
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date desposit;
    struct date withdraw;

    
}add, upd, check, rem, transaction;

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate*t*amount) /100.0;
    return (SI);

}
//Delay the request when a option is selected//
void fordelay();
///When someone want to make a new account//
void new_acc();
//Create a new list for the 
void new_list();
//Edit anyt changes to the system//
void edit();
///Have a transaction history for the user//
void transact(void);
//delete option if a client has been removed fromt he system//
void delete(void);
//View option to see how many users we chave//
void view(void);
///close out of any statement//
void close(void);

int main(void)
{
    ///store a password with a length of 10 characters//
    char pass[10], password[10] = "codewithc";
    //integer set to 0//
    int i = 0;
    ///User enters the password and it gets stored into pass//
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s", pass);
//use strcmp to comapre the password if it matches, we are goign to load the password, and use
//the fordelay function to delay it by a couple of seconds, then show the menu////
    if(strcmp(pass,password) == 0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for(i =0; i <=6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    } 
    else 
    ///else wrong password and try again by pressing 1 to validate yourself or 0 to exit///
    {
        printf("\n\nWrong password! \a\a\a");
        //try to login again///
        printf("\nEnter 1 to rtry again and 0 to exit:");
        scanf("%d", &exit);
        if(exit == 1)
        {
            system("cls");
            main();
        }
        else if (exit == 0)
        {
            system("cls");
            close();
        }
        else 
        ///if the user enters 0, then exit//
        {
            printf("\nInvalid!");
            fordelay(100000000);
            system("cls");
            
        }
        return 0;
    }
}