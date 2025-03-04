#include <random>
#include "BidimensionalPartyBits.h"
#include "CRC.h"

int main()
{
	std::cout << "MENU\n";
	std::cout << "\n1. BIDIMENSIONAL PARTY BITS\n";
	std::cout << "\n2. CYCLIC REDUNDANCY CHECK (CRC)\n";
	std::cout << "\n3. EXIT\n";
	std::cout << "\nWhat is your choice? \n\n";
	int decision = 0, final = 0;
	std::cin >> decision;
	while (final == 0)
	{
		switch (decision)
		{
		case 1:
		{
			std::cout << "\nYou selected: BIDIMENSIONAL PARTY BITS\n\n";
			std::string message;
			std::vector<std::vector<char>> matrix;
			srand(time(NULL));
			Validation(message);

			PopulateMatrix(message, matrix);
			std::cout << "\nThe matrix for the message is:\n";
			DisplayMatrix(matrix);

			int randomNumber = rand() % message.length();
			std::cout << "\n\nThe random position is: " << randomNumber + 1 << '\n';
			message[randomNumber] ^= 1;//xor
			std::cout << "\nThe message after coruption is: " << message << '\n';
			CoruptionOfMatrix(randomNumber, matrix);
			std::cout << "\nThe Matrix after the coruption:\n";
			DisplayMatrix(matrix);
			break;
		}
		case 2:
		{
			std::cout << "\nYou selected: CYCLIC REDUNDANCY CHECK (CRC)\n\n";
			std::string message, polynomial;
			Validation(message, polynomial);
			CRC(message, polynomial);
			break;
		}
		case 3:
		{
			final = 1;
			break;
		}
		default:
		{
			std::cout << "Not a valid choice! Enter again.\n\n";
		}
		}
		if (final != 1)
		{
			std::cout << "\nDo you want another choice?\n\n";
			std::cin >> decision;
		}
	}
	return 0;
}