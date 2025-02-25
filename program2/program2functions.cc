// Copyright 2025 Isaac White

#include "program2functions.h"

bool IsSquare(int n) {  // checks if n is a perfect square
  int i = 0;
  while (i * i < n) {
    i++;
  }
  return i * i == n;
}

bool IsPerfect(int n) {  // checks if n is a perfect number
  int sum = 0;
  for (int i = 1; i < n-1; i++) {
    if ((n % i == 0)&&(i != n)) {
        sum += i;
    }
  }
  return sum == n;
}

bool IsVowel(char c, bool y) {  // checks if c is a vowel
if (y) {
  if (c == 'y' || c == 'Y')
    return true;
}

  switch (c) {
    case 'a':
    case 'A':
      return true;
    case 'E':
    case 'e':
      return true;
    case 'I':
    case 'i':
      return true;
    case 'O':
    case 'o':
      return true;
    case 'U':
    case 'u':
      return true;
    default:
      return false;
  }
}

bool IsConsonant(char c, bool y) {  // checks if c is a consonant
  if (y) {
    if (c == 'y' || c == 'Y')
      return true;
    }
  switch (c) {
    case 'a':
    case 'A':
      return false;
    case 'E':
    case 'e':
      return false;
    case 'I':
    case 'i':
      return false;
    case 'O':
    case 'o':
      return false;
    case 'U':
    case 'u':
      return false;
    case 'y':
    case 'Y':
      return false;
    default:
      return (c >= 97 && c <= 122) || (c >= 65 && c <= 90);
    }
}

int ToDigit(char digit) {  // converts a char to an int
  switch (digit) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    default:
      return 0;
    }
}

int Range(int &x, int &y) {  // returns the difference between x and y
    if (x > y) {
      int temp = x;
      x = y;
      y = temp;
    }
    return y-x;
}

int DigitInPosition(double number, int place) {  // returns the digit at the
    int left_of_decimal = static_cast<int>(number);  // place in the number
    if (place > 0) {
      double right_of_decimal = number - left_of_decimal;
      int multiplier = 1;
      for (int i = 0; i < place; i++) {
        multiplier *= 10;
      }
      int ret = static_cast<int>(right_of_decimal*multiplier);
      return ret%10;
    } else if (place < 0) {
      place = place*-1;
      double div = left_of_decimal;
      for (int i = 0; i < place; i++) {
        div = div/10;
      }
      int ret = static_cast<int>(div);
      return ret % 10;
    } else {
      int to_int = static_cast<int>(number);
      return to_int % 10;
    }
}
