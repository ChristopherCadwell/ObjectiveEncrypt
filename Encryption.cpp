#include "Encryption.h"
#include <fstream>
#include <iostream>
#include <string>

void Encryption::LoadMessage()
{

    //open file in ifstream (read)
    std::ifstream readFile("Unencrypted.txt");

    //verify file is open
    if (readFile.is_open())
        //output buffer (should be the .txt file) to console
        std::cout << readFile.rdbuf();

    //close file
    readFile.close();
}

void Encryption::SaveMessage(std::string line)
{
    //create write file (ofstream)
    std::ofstream writeFile;


    //open file
    //ios base app  to append instead of over write
    writeFile.open("Encryptedcaesar.dat", std::ios_base::app);

    //verify file is open
    if (writeFile.is_open())
        //write a line (from passed in var)
        writeFile << line << std::endl;

    //display what was written
    std::cout << line << " has been written to file." << std::endl;

    //close file
    writeFile.close();
}
void Encryption::SaveMessage(char line, std::string eType)
{
    //create write file (ofstream)
    std::ofstream writeFile;


    //open file
    //ios base app  to append instead of over write
    writeFile.open("EncryptedRSA.dat", std::ios_base::app);

    //verify file is open
    if (writeFile.is_open())
        //write a line (from passed in var)
        writeFile << line << std::endl;

    //display what was written
    std::cout << line << " has been written to file." << std::endl;

    //close file
    writeFile.close();
}
bool Encryption::checkPrimeNumber(int n)
{
    bool isPrime = true;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        isPrime = false;

    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;

                break;
            }
        }
    }

    return isPrime;

}
int Encryption::errorCheck(int n)
{
    try
    {
        if (n == 0)
        {
            //probably a letter instead of a number

            throw(n);
        }
        else
        {
            //ok
        }

    }
    catch (int notInt)
    {
        std::cout << "Error: Did you put in a letter instead of a number?" << std::endl;
        return 1;
    }

    //check for under 100
    try
    {
        if (n >= 100)
        {
            //ok
        }
        else
        {
            //fail
            throw(n);

        }
    }
    catch (int badN)
    {
        std::cout << "Error " << badN << " is too small" << std::endl;
        return 2;
    }
    
    return 0;

}
void Encryption::PrimeCheck()
{
    std::string cont;
    bool primeComplete = false;
    int n;
    int p1 = 0;

    do
    {

        std::cout << "Prime number checker..." << std::endl;
        std::cout << "Enter a number greater than 100 " << std::endl;
        std::cin >> n;

        //if no errors caught
        if (Encryption::errorCheck(n) == 0)
        {
            

            //check for prime
            // 991 and 479 are 2 primes (for testing and demo instead of going through all the numbers)
            //if true
            if (Encryption::checkPrimeNumber(n))
            {
                std::cout << n << " is a prime number" << std::endl;
                if (p1 == 0)
                {
                    p1 = n;
                }
                
                std::cout << p1 << " is your first number" << std::endl;
            }
            //if not true
            else
            {
                std::cout << n << " is NOT a prime number" << std::endl;
            }
        }

        //determine if we are going again
        std::cout << "Continue? " << std::endl;
        std::cin >> cont;
        //if yes
        if (cont == "y" || cont == "Y")
        {
            primeComplete = false;
        }
        else
        {
            primeComplete = true;
        }
    } while (primeComplete == false);

}



