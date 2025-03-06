// Copyright 2025 Isaac White

#include <fstream>
#include <iostream>
#include <string>
#include "word_search_functions.h"
using std::cout;
using std::endl;
using std::find;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::string;

bool ReadWordSearch(string f, char wordsearch[][kSize]) {
  int count = 0;
  ifstream in_file(f);
  if (!in_file) {
    return false;  //  Check if file opened successfully
  }
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      in_file >> wordsearch[i][j];
      count++;
    }
  }

  in_file.close();  //  Close the file explicitly
  return count >= kSize * kSize;
}

void PrintWordSearch(const char wordSearch[][kSize]) {
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      cout << setw(3) << wordSearch[i][j];
    }
    cout << endl;
  }
}

bool FindWordRight(const char word_search[][kSize], string to_find,
int &row, int &col) {
  for (int i = 0; i < kSize; ++i) {
    for (int c = 0; c < kSize; ++c) {
      char curr = word_search[i][c];
      if (curr == to_find[0]) {
        string match = "";
        match += curr;  //  adds first character
        for (int k = 1; k < to_find.length(); k++) {
          if (c + k >= kSize)  //  check bound
            break;
          match += word_search[i][c + k];
        }

        if (match == to_find) {
          row = i;
          col = c;
          return true;
        }
      }
    }
  }
  return false;
}

bool FindWordLeft(const char word_search[][kSize], string to_find,
int &row, int &col) {
  for (int i = kSize - 1; i >= 0; --i) {
    for (int c = kSize - 1; c >= 0; --c) {
      char curr = word_search[i][c];
      if (curr == to_find[0]) {
        string match = "";
        match += curr;  //  adds first character

        for (int k = 1; k < to_find.length(); k++) {
          if (c - k < 0)  //  check bound
            break;
          match += word_search[i][c - k];
        }

        if (match == to_find) {
          row = i;
          col = c;
          return true;
        }
      }
    }
  }
  return false;
}

bool FindWordDown(const char word_search[][kSize], string to_find,
int &row, int &col) {
  for (int i = 0; i < kSize; ++i) {
    for (int c = 0; c < kSize; ++c) {
      char curr = word_search[i][c];
      if (curr == to_find[0]) {
        string match = "";
        match += curr;  //  adds first character

        for (int k = 1; k < to_find.length(); k++) {
          if (i + k >= kSize)  //  check bound
            break;
          match += word_search[i + k][c];
        }
        if (match == to_find) {
          row = i;
          col = c;
          return true;
        }
      }
    }
  }
  return false;
}

bool FindWordUp(const char word_search[][kSize], string to_find,
int &row, int &col) {
  for (int i = 0; i < kSize; ++i) {
    for (int c = 0; c < kSize; ++c) {
      char curr = word_search[i][c];
      if (curr == to_find[0]) {
        string match = "";
        match += curr;  //  adds first character
        for (int k = 1; k < to_find.length(); k++) {
          if (i - k < 0)  //  check bound
            break;
          match += word_search[i - k][c];
        }
        if (match == to_find) {
          row = i;
          col = c;
          return true;
        }
      }
    }
  }
  return false;
}

bool FindWordDiagonal(const char word_search[][kSize], string to_find,
int &row, int &col) {
  for (int i = 0; i < kSize; ++i) {
    for (int c = 0; c < kSize; ++c) {
      char curr = word_search[i][c];
      if (curr == to_find[0]) {
        string match = "";
        match += curr;  //  adds first character
        for (int k = 1; k < to_find.length(); k++) {
          if (i + k >= kSize || c + k >= kSize)  //  check bound
            break;
          match += word_search[i + k][c + k];
        }
        if (match == to_find) {
          row = i;
          col = c;
          return true;
        }
      }
    }
  }
  return false;
}
