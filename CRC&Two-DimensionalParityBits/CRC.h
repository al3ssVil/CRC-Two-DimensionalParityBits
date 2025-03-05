#pragma once
#include <iostream>
#include <vector>

bool IsValid(std::string message)
{
	for (int i = 0; i < message.length(); i++)
		if (message[i] != '1' && message[i] != '0')
			return false;
	return true;
}

void Validation(std::string& message, std::string& polynomial)
{
	do {
		std::cout << "\nPlease input the binary message(characters 1 or 0) : ";
		std::cin >> message;
		if (IsValid(message) == false)
		{
			while (IsValid(message) == false)
			{
				std::cout << "\nInvalid message! Please input the binary message: ";
				std::cin >> message;
			}
		}
		std::cout << "\nPlease input the polynomial generator: ";
		std::cin >> polynomial;
		if (IsValid(polynomial) == false)
		{
			while (IsValid(polynomial) == false)
			{
				std::cout << "\nInvalid message! Please input the polynomial generator: ";
				std::cin >> polynomial;
			}
		}
		if (message.length() < polynomial.length())
			std::cout << "\nThe message must be bigger then the polynomial generator!\n";
	} while (message.length() < polynomial.length());
}

void CRC(std::string message, std::string polynomial)
{
	for (int i = 0; i < polynomial.size() - 1; i++)
		message = message + '0';
	std::cout << "\nMessage after concatenation: \n" << message << '\n';
	int totalPos = 0;
	std::string copy = message;
	while (message.length() >= polynomial.length())
	{
		for (int i = 0; i < polynomial.length(); i++)
		{
			if (message[i] == polynomial[i])
				message[i] = '0';
			else
				message[i] = '1';
		}
		int pos = 0;
		while (pos < message.length() && message[pos] == '0')
		{
			pos++;
		}
		message = message.substr(pos);
		for (int i = 0; i < pos + totalPos; i++)
			std::cout << ' ';
		std::cout << message << '\n';
		totalPos += pos;
	}
	if ((message.length() == 1 && message == "0") || message.length() == 0)
		std::cout << "\nThe rest is 0\n";
	else
	{
		std::cout << '\n' << copy << " XOR \n";
		for (int i = 0; i < copy.length() - message.length(); i++)
			std::cout << ' ';
		std::cout << message << '\n';
		for (int i = 0; i < copy.length(); i++)
			std::cout << '-';
		std::cout << '\n';
		for (int i = 0; i < message.length(); i++)
			if (message[i] == copy[copy.length() - message.length() + i])
				copy[copy.length() - message.length() + i] = '0';
			else
				copy[copy.length() - message.length() + i] = '1';
		std::cout << copy;
	}
}