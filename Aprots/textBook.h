// CopyRight Isaac White 2025

#ifndef _TEXTBOOK_H_
#define _TEXTBOOK_H_

#include"book.h"


namespace bookEx {

class Textbook : public Book { // makes textbook inherit from book
 public:
  Textbook(string t = "Untitled", string a = "Unknown", int year = 1990);
  void Print() const;















};





} // end namespace