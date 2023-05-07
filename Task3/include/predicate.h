bool isWhitespace(char character) {
	return character == 0 || character == 10 || character == 32;
	//space, tab, newline
}

bool isDigit(char character) {
	return character >= 48 && character <= 57;
}

bool isAlpha(char character) {
	return (character >= 65 && character <= 90) || (character >= 97 && character <= 122);
}
bool isUpperCase(char character) {
	return character >= 65 && character <= 90;
}

bool isLowerCase(char character) {
	return character >= 97 && character <= 122;
}

