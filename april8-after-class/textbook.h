// Copyright 2025 csce240
// Define Textbook class
#ifndef _TEXTBOOK_H_
#define _TEXTBOOK_H_

#include<string>
using std::string;
#include"book.h"

namespace csce240_book_project {

class Textbook : public Book {
 public:
  Textbook(string t = "Untitled", string a = "Unknown", int year = 1900);


  Textbook(const Textbook& tocopy);
  Textbook& operator = (const Textbook& tocopy);
  ~Textbook() { delete [] has_problem_set_; }

  void SetNumChapters(int n, const string * s = nullptr);

  void SetChapterName(int num, string ch, bool problem_set);

  // redefining the Print function that we inherited from the Textbook class
  void Print() const;

  private:
    bool * has_problem_set_;
    
};


}  // end namespace csce240_book_project

#endif
