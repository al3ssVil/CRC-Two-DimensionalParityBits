#pragma once
#include <iostream>
#include <vector>

bool Valid(const std::string& message)
{
	if (message.length() % 7 != 0)
		return false;
	for (int i = 0; i < message.length(); i++)
		if (message[i] != '1' && message[i] != '0')
			return false;
	return true;
}

void Validation(std::string& message)
{
	std::cout << "Please input the binary message(characters 0 and 1, the number of digits must be a multiple of 7): ";
	std::cin >> message;

	if (Valid(message) == false)
	{
		while (Valid(message) == false)
		{
			std::cout << "\nInvalid message! Please input the binary message: ";
			std::cin >> message;
		}
	}
}

void PopulateMatrix(const std::string& message, std::vector<std::vector<char>>& matrix)
{
	int position = 0, count = 0;
	int rows = message.length() / 7;
	matrix.resize(rows + 1, std::vector<char>(8, '0'));
	for (int i = 0; i < rows; i++)
	{
		count = 0;
		for (int j = 0; j <= 6; j++)
		{
			matrix[i][j] = message[position];
			if (matrix[i][j] == '1')
				count++;
			position++;
		}
		if (count % 2 == 0)
			matrix[i][7] = '0';
		else
			matrix[i][7] = '1';
	}
	for (int j = 0; j <= 7; j++)
	{
		count = 0;
		for (int i = 0; i < rows; i++)
		{
			if (matrix[i][j] == '1')
				count++;
		}
		if (count % 2 == 0)
			matrix[rows][j] = '0';
		else
			matrix[rows][j] = '1';
	}
}

void DisplayMatrix(const std::vector<std::vector<char>>& matrix)
{
	for (int i = 0; i < matrix.size() - 1; i++)
	{
		for (int j = 0; j < matrix[0].size() - 1; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << " | " << matrix[i][matrix[0].size() - 1];
		std::cout << '\n';
	}
	std::cout << "------------------\n";
	for (int j = 0; j < matrix[0].size() - 1; j++)
		std::cout << matrix[matrix.size() - 1][j] << ' ';
	std::cout << " | " << matrix[matrix.size() - 1][matrix[0].size() - 1];
}

void CoruptionOfMatrix(int randomNumber, std::vector<std::vector<char>>& matrix)
{
	if (matrix[randomNumber / 7][randomNumber % 7] == '1')
		matrix[randomNumber / 7][randomNumber % 7] = '0';
	else
		matrix[randomNumber / 7][randomNumber % 7] = '1';

	int count = 0;
	int row = -1, column = -1;
	for (int i = 0; i < matrix.size() - 1; i++)
	{
		count = 0;
		for (int j = 0; j <= 6; j++)
		{
			if (matrix[i][j] == '1')
				count++;
		}
		if (matrix[i][7] != (char)((count % 2) + '0'))
		{
			row = i;
			matrix[i][7] = (char)((count % 2) + '0');
		}
	}
	for (int j = 0; j <= 7; j++)
	{
		count = 0;
		for (int i = 0; i < matrix.size() - 1; i++)
		{
			if (matrix[i][j] == '1')
				count++;
		}
		if (matrix[matrix.size() - 1][j] != (char)((count % 2) + '0'))
		{
			if (j != 7)
				column = j;
			matrix[matrix.size() - 1][j] = (char)((count % 2) + '0');
		}
	}
	std::cout << "\nThe row corupted is " << (row + 1) << " and the column is " << (column + 1) << '\n';
}