#include <iostream>
#include <string>
#include "Encryption.h"
#include "A_Encrypt.h"
#include "A_Decrypt.h"
#include "C_Encrypt.h"
#include "C_Decrypt.h"


//prototypes
void Title();
void Menu();
void Instructions();


//entry point
int main()
{
    //display title
    Title();
    //display instructions
    Instructions();
    //display menue
    Menu();

}

void Title()
{
    //an artistic title message
    std::cout << R"(
                             __                   
   ________  _____________  / /_                  
  / ___/ _ \/ ___/ ___/ _ \/ __/                  
 (__  )  __/ /__/ /  /  __/ /_                    
/____/\___/\___/_/___\___/\__/__ _____ ____  _____
  / __ `__ \/ _ \/ ___/ ___/ __ `/ __ `/ _ \/ ___/
 / / / / / /  __(__  |__  ) /_/ / /_/ /  __(__  ) 
/_/ /_/ /_/\___/____/____/\__,_/\__, /\___/____/  
                               /____/             
)" << std::endl;
}

void Menu()
{
    //menue display
    std::cout << "\n\n\t\tPlease make a selection" << std::endl;
    std::cout << R"(

1 - Prime Checker (Figure out some prime numbers for AES encryption)
2 - RSA Encrypt
3 - Caesar Encrypt
4 - Caesar Decrypt
5 - Quit

)" << std::endl;

    //used for determining if user still wants app to run
    bool taskComplete = false;

    //get response
    std::string input;
    getline(std::cin, input);

    

    //check what the user chose
    if (input == "1")
    {
        //Run Prime Checker
        Encryption::PrimeCheck();

        //back to menue
        Menu();
    }
    else if (input == "2")
    {
        //run RSA Encryption
        A_Encrypt::EncryptionProcess();
        //back to menue
        Menu();

    }
    
    else if (input == "3")
    {
        //Run Caesar Encryption
        C_Encrypt::Caesar();
        //back to menue
        Menu();
    }
    else if (input == "4")
    {
        //Run Caesar Decryption
        C_Decrypt::Caesar();
        //back to menue
        Menu();
    }
    else if (input == "5")
    {
        //quit
        return;
    }

    //invalid choice
    else
    {
        std::cout << "Invalid selection, Try again." << std::endl;
        //rerun menu function
        Menu();
    }

}







void Instructions()
{
    std::cout << "\n\nThis is a program to encrypt and decrypt text, messages will be saved to the files (Encrypted.txt and Decrypted.txt)" << std::endl;
}

