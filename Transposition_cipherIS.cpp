#include <iostream>
#include <string>
#include <cmath>

// Function to encrypt the message
std::string encrypt(const std::string& message, int key) {
    int messageLength = message.length();
    int numRows = std::ceil(static_cast<double>(messageLength) / key);
    int numCols = key;

    // Create a 2D matrix to store the message characters
    char matrix[numRows][numCols];

    int messageIndex = 0;

    // Fill the matrix with the message characters
    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            if (messageIndex < messageLength) {
                matrix[row][col] = message[messageIndex];
                messageIndex++;
            } else {
                matrix[row][col] = ' '; // Pad extra spaces if needed
            }
        }
    }

    // Read the matrix column-wise to generate the encrypted text
    std::string encryptedText;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            encryptedText += matrix[row][col];
        }
    }

    return encryptedText;
}

// Function to decrypt the message
std::string decrypt(const std::string& encryptedText, int key) {
    int messageLength = encryptedText.length();
    int numRows = std::ceil(static_cast<double>(messageLength) / key);
    int numCols = key;

    // Create a 2D matrix to store the encrypted text characters
    char matrix[numRows][numCols];

    int encryptedIndex = 0;

    // Fill the matrix with the encrypted text characters
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (encryptedIndex < messageLength) {
                matrix[row][col] = encryptedText[encryptedIndex];
                encryptedIndex++;
            } else {
                matrix[row][col] = ' ';
            }
        }
    }

    // Read the matrix row-wise to generate the decrypted message
    std::string decryptedMessage;
    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            decryptedMessage += matrix[row][col];
        }
    }

    return decryptedMessage;
}

int main() {
    std::string message;
    int key;

    // Get the message and key from the user
    std::cout << "Enter the message: ";
    std::getline(std::cin, message);

    std::cout << "Enter the encryption key: ";
    std::cin >> key;

    // Encrypt the message
    std::string encryptedText = encrypt(message, key);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    // Decrypt the message
    std::string decryptedMessage = decrypt(encryptedText, key);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;

    return 0;
}
