/******************************************************************************
 
 //
 // This program is designed to perform the operation of verifying the number entered by the user,
 // the digit number entered will be encrypted and this number will be checked to see if the correct number.
 //  Option 1 allows the user to enter 4 numbers each of 0 - 9
 //  Option 2 will encrypt the number entered by the user and will check if it is the correct number
 //  Option 3 to decrypt user's number
 //  Option 4 will show how many times the number entered by the user is correct or wrong
 //  Option 5 ends the program
 //
 //  Copyright © 2019 Rui Anselmo Dutra Ranito. All rights reserved.
 //
 
 *******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5 //Symbolic name to define the size of my array included the null character

// Functions prototypes


bool getCode(char[]);
bool Encrypt(char[]);
void Decrypt(char[]);
void CheckCode(char*,char*,int*,int*);


int main()
{
    int ch = 0;
    int option;
    int countWright = 0;
    int countWrong = 0;
    bool OK = false;
    bool sec = false;
    bool error = false;
    char user_Password[SIZE]="0000";
    
    
    do
    {
        char Wright_Password[SIZE]="1234";
        
        
        //printf to display the menu to the user
        printf("\n\n*********Welcome to the access control please enter the security code.*********\n");
        printf("\nPress 1 for insert your Security Code.\n");
        printf("\nPress 2 to Encrypt and verify your Security Code.\n");
        printf("\nPress 3 for Decrypt your Security Code.\n");
        printf("\nPress 4 if you want to see how many times you entered right and wrong the Security Code.\n");
        printf("\nPress 5 to Exit the program.\n");
        
        //scanf to receive the input from the user
        
        
        printf("\nPlease enter your option.\n");
        scanf("%d",&option);
        
        /*
         while loop to verify that the user input is a character
         to check if the user input and a character if yes shows an
         error message and asks the user to enter the Security Code again.
         */
        
        while ((ch = getchar()) && ch != '\n')
        {
            printf("\nSorry characters are not allowed.\n");
            printf("\nPlease enter a valid option\n");
            scanf("\n%d\n",& option);
        }
        
        //switch statement to run trough the menu
        switch (option)
        {
            case 1:
                
                OK = getCode(user_Password);
                error = false;
                break;
                
            case 2:
                
                if(OK==true)
                {
                    //call the function to encrypt the Security Code
                    
                    sec=Encrypt(Wright_Password);
                    sec=Encrypt(user_Password);
                    printf("The Security Code after Encrypt is: %s\n", user_Password);
                    CheckCode(Wright_Password,user_Password,&countWright,&countWrong);
                    OK=false;
                    error=true;
                }
               
                else
                {
                    printf("\n Please insert your Security Code first before Encrypt it.\n");
                }
                
                break;
                
            case 3:
                
                if(error == true)
                {
                    if(sec==true)
                    {
                      //call the function Decrypt
                        Decrypt(user_Password);
                        printf("\nThe Decrypt Security Code is %s\n",user_Password);
                    }
                }
                else
                {
                    printf("\n Please you have to Encrypt your Security Code before Decrypt it.\n");
                }
                
                break;
                
            case 4:
                printf("\nAmount of wright Security Code entered:  %d\n",countWright);
                printf("\nAmount of wrong Security Code entered:  %d\n ",countWrong);
                
                break;
                
            case 5:
                
                //Exit Program
                break;
                
                
            default:
                
                printf("\nPlease enter a valid option.\n");
                
                break;
                
        }//End switch statement
    }//end do
    
    while (option !=5);
    
    printf("\nThank you for use our system.\n\n");
    
    return 0;
    
    
}//end main




//implement functions

//Function that recieved the imput from the user

bool getCode(char *pin)
{
    
    char *ptr;
    
    //scanf to get the input from the user

    printf("Please enter your Security Code with 4 digits.\n");
    scanf("\n%s", pin);
    strtol(pin, &ptr, 10);  // converts the initial part of the string in a long int
    if (strlen(pin) == 4 && !(*ptr != '\0' || ptr == pin))   //if statement to check if the length not exceeding
    {
        printf("\nYour Security Code is acceptable.\n");
        
    }
    else
        
    {
        printf("\nSorry you can not enter more than 4 digits.\n");
    }
    return true;
}//end getCode

//implement the function that will Encrypt the Password entered from the user
bool Encrypt(char *pin)
{
    int i;
    int temp;
    
    //for loop to swap the positions
    for (i = 0; i < strlen(pin) - 2; i++)
    {
        temp = pin[i];
        pin[i] = pin[i + 2];
        pin[i + 2] = temp;
        
    }
    //for loop to add 1 to the numbers and case it is 9 change for the digit 0
    for (i = 0; i < strlen(pin); i++)
    {
        
        if (pin[i] == '9')
            
            pin[i] = '0';
        else
            
            pin[i] = pin[i] + 1;
        
    }
    return true;
}//end encrypt

//implement the function that Decrypt the Password
void Decrypt(char *pin)
{
    
    int i;
    int temp;
    
    //for loop that decrypt the password
    for (i = 0; i < strlen(pin) - 2; i++)
    {
        temp = pin[i];
        pin[i] = pin[i + 2];
        pin[i + 2] = temp;
    }
    for (i = 0; i < strlen(pin); i++) {
        
        if (pin[i] == '0')
            
            pin[i] = '9';
        else
            
            pin[i] = pin[i] - 1;
        
    }
    
}//end Decrypt

//implement the function that compare if the Security Code entered is equal or not the access code
void CheckCode(char* Password,char* user_Password,int* countWright,int* countWrong)       
{
    if (strcmp(Password, user_Password) == 0)
    {
        printf("\nThe Security Code is equal you have access.\n");
        (*countWright)++;
    }
    else
    {
        printf("\nThe Security Code is not equal.\n");
        (*countWrong)++;
    }
}//end CheckCode








