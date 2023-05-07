
#include <iostream>
#include <string>
#include <ctype.h>

std::string shiftAlphabet(int&);
std::string decode(std::string&, std::string&);
std::string encode(std::string&, std::string&);

int main() {
	int shift;
	std::string encodedAlphabet;
	std::string decodedPhrase;
	std::string encodedPhrase;
	
	int selection;

	std::cout << "Shift: ";
	std::cin >> shift;
	encodedAlphabet = shiftAlphabet(shift);

	std::cout << "Choose An Option\n"
		<< "\t1. Encode\n"
		<< "\t2. Decoden\n";
	std::cin >> selection;
	std::cin.ignore();

	switch (selection) {
	case 1:
		std::cout << "Phrase: ";
		std::getline(std::cin, decodedPhrase);
		encodedPhrase = encode(decodedPhrase, encodedAlphabet);
		std::cout << decodedPhrase << "  -->  " << encodedPhrase << std::endl << std::endl;
		break;

	case 2:
		std::cout << "Encoded Phrase: ";
		std::getline(std::cin, encodedPhrase);
		decodedPhrase = decode(encodedPhrase, encodedAlphabet);
		std::cout << encodedPhrase << "  -->  " << decodedPhrase << std::endl << std::endl;
		break;

	}

	return 0;

}

std::string shiftAlphabet(int& shift) {
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string encoding = "";

	int alphabetLength = alphabet.length();
	shift %= alphabetLength;
	for (int i = 0; i < alphabetLength; i++)
		encoding += (i + shift) < alphabetLength ? alphabet[i + shift] : alphabet[(i - alphabetLength) + shift];

	return encoding;

}

std::string encode(std::string& phrase, std::string& encodedAlphabet) {
	std::string encoding = "";
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	// Ensure Phrase Is Lowercase#####
	for (int i = 0; i < phrase.length(); i++) {
		if (islower(phrase[i]))
			continue;

		char temp = phrase[i];
		phrase[i] = tolower(temp);

	}

	int phraseLength = phrase.length();
	int alphabetLength = alphabet.length();
	for (int i = 0; i < phraseLength; i++) {
		if (phrase[i] == ' ') {
			encoding += ' ';
			continue;

		}

		// Searching Phrase Character In Index In Alphabet Then Mathcing It To encodedAlphabet#####
		for (int j = 0; j < alphabetLength; j++)
			if (phrase[i] == alphabet[j]) {
				encoding += encodedAlphabet[j];

			}

	}

	return encoding;

}

std::string decode(std::string& phrase, std::string& encodedAlphabet) {
	std::string decoding = "";
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	// Ensure Phrase Is Lowercase#####
	for (int i = 0; i < phrase.length(); i++) {
		if (islower(phrase[i]))
			continue;

		char temp = phrase[i];
		phrase[i] = tolower(temp);

	}

	int phraseLength = phrase.length();
	int encodedAlphabetLength = encodedAlphabet.length();
	for (int i = 0; i < phraseLength; i++) {
		if (phrase[i] == ' ') {
			decoding += ' ';
			continue;

		}

		// Searching Phrase Character In Index In encodedAlphabet Then Mathcing It To Alphabet#####
		for (int j = 0; j < encodedAlphabetLength; j++)
			if (phrase[i] == encodedAlphabet[j])
				decoding += alphabet[j];

	}

	return decoding;

}