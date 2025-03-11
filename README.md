# Project: Two-Dimensional Parity Bits and CRC (Cyclic Redundancy Check)

## General Description
This project consists of two major sections implementing data integrity checking methods. The first section implements two-dimensional parity bits, and the second section implements CRC (Cyclic Redundancy Check). These techniques are used to detect errors in a message transmitted over a computer network.

The project includes a menu selection system that allows the user to choose between the two methods and follow the necessary steps for each technique. The implementation aims to educate users about how these error-checking techniques work and simulate message corruption to demonstrate the error detection and correction process.

## Features
### Two-Dimensional Parity Bits:

Input a binary message of length multiple of 7.

Display the message in a matrix with 7 columns.

Calculate parity bits for each row and column.

Display the matrix with added parity bits.

Simulate message corruption by randomly changing a binary bit.

Detect the corrupted bit and display its position.

### CRC (Cyclic Redundancy Check):

Input a binary message and a generator polynomial.

Verify the validity of the inputs (binary message and message length relative to the generator polynomial).

Extend the message with zeros.

Perform successive XOR operations between the extended message and the polynomial coefficients.

Display the intermediate results of the XOR operations.

Calculate the final remainder and apply an additional XOR between the extended message and the final remainder.

Display the final result.

## Steps
### Two-Dimensional Parity Bits:

Input a binary message of length multiple of 7.

Choose the calculate parity bits option.

The system will display the completed matrix with calculated parity bits.

Select the simulate message corruption option to introduce a random error.

The system will recalculate the parity bits and identify the corrupted bit.

### CRC:

Input a binary message and a generator polynomial.

Choose the calculate CRC option.

The system will perform XOR operations and display the intermediate steps and the final result.

Preconditions and Validations

The message input for two-dimensional parity bits must be a binary string (containing only 0s and 1s) and must have a length that is a multiple of 7.

The message input for CRC must be a valid binary string and must be longer than the number of coefficients in the generator polynomial.

The generator polynomial must be a binary string, and its highest degree coefficient will be used for extending the message.

```
Menu
1: Two-Dimensional Parity Bits.
2: CRC.
3: Exit (to close the program).
```

### Example
Let's choose the first option:

![image](https://github.com/user-attachments/assets/7c175b65-4f31-4a6a-8743-65dd549a851f)

For the input ``101011001001101010101`` it will be:

![image](https://github.com/user-attachments/assets/181e4465-ce52-4cd5-8cad-bcb9e01153fd)

And if we choose the second option.

First with input ``110100101010110`` for the message and ``1011`` for the polynomial.

![image](https://github.com/user-attachments/assets/2fe1e871-2487-4c4c-8633-34505dec1f64)


And after with the `1101001010101101` for the message and `1011` for the polynomial, to see what happen when we have 0 for the rest.

![image](https://github.com/user-attachments/assets/4ed31922-cbeb-4f97-8c76-03def354d237)






