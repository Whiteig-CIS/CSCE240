//  Copyright Isaac White 2025
//  define a book class

#ifndef _BOOK_H_
#define _BOOK_H_
#include<string>
using std::string;

namespace bookEx {

class Book{
 public:
  Book();
  void setTitle(const string& t);
  void setAuthor(const string& a);
  void SetPubYear(int y);
  void Print();

  string GetTitle() const { return title_; }
  string GetAuthor() const { return author_; }
  int GetPubYear() const { return pub_year_; }

 private:
  string title_;
  string author_;
  int pub_year_;

};


} // end bookEx namespace

#endif