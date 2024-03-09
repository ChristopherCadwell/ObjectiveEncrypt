#include "C_Encrypt.h"
#include <iostream>
#include <string>


int ei;
int ex;
char estr[100];
int eshift;

void C_Encrypt::Caesar()
{
    
    std::cout << "Enter a number from 1-25\t";
    
    //store choice in string
    std::string sshift;
    getline(std::cin, sshift);
    //convert to int
    eshift = std::stoi(sshift);

    

    std::cout << "\nPlease choose following options:\n";
    std::cout << "1 = Input something to encrypt.\n";
    

    //get input
    std::string strx;
    getline(std::cin, strx);

    //convert string to int
    ex = std::stoi(strx);

    //using switch case statements
    switch (ex)
    {
        //first case for encrypting a string
    case 1:
        std::cout << "\nEnter message for encryption" << std::endl;
        //get message for encryption
        std::cin.getline(estr, 100);
        //encrypt message
        C_Encrypt::Encrypt();
        //display encrypted, then save to file
        std::cout << "\nEncrypted string: " << estr << std::endl;
        C_Encrypt::SaveMessage(estr);
        std::cout << "\nsaved to file." << std::endl;

        break;

        //second case Load file for encryption
    case 2:
        //still needs work, taken out for now
        return;
        C_Encrypt::LoadMessage();
        C_Encrypt::Encrypt();

    default:
        std::cout << "\nInvalid Input !!!\n";
    }
    return;
}

void C_Encrypt::Encrypt()
{
    //loop through
    for (ei = 0; (ei < 100 && estr[ei] != '\0'); ei++)
        //add shift key to ascii values of string
        estr[ei] = estr[ei] + eshift;
}
