#pragma once
#include <iostream>
#include <string>


class Encryption
{
public:

	static char LoadEncrypted();
	static void LoadMessage();
	//overload (one for each type of encryption)
	static void SaveMessage(std::string line);
	//overload (one for each type of encryption this one is for rsa)
	static void SaveMessage(char line, std::string eType);

	static void PrimeCheck();

private:
	static bool checkPrimeNumber(int n);
	static int errorCheck(int);


};

