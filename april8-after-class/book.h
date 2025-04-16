// Copyright 2025 csce240
// define a Book class
#ifndef _BOOK_H_
#define _BOOK_H_

#include<string>
using std::string;

namespace csce240_book_project {

class Book {
 public:
  explicit Book(string t = "Untitled", string a = "Unknown", int y = 1900);

  Book(const Book& tocopy);
  ~Book() { delete [] chapters_; }
  Book& operator = (const Book& tocopy);

  void SetTitle(const string& t);
  void SetAuthor(const string& a);
  void SetPublicationYear(int y);
  void Print() const;

  // pre-condition: s points to a block of n strings OR the nullptr
  //                if s points to block of < n program will fail
  void SetNumChapters(int n, const string * s = nullptr);

  string GetChapterName(int n) const;
  void SetChapterName(int n, string newname);

  string GetTitle() const { return title_; }
  string GetAuthor() const { return author_; }
  int GetPublicationYear() const { return year_; }
  int GetNumChapters() const { return num_chapters_;}

 private:
  string title_;
  string author_;
  int year_;
  int num_chapters_;
  string * chapters_;
};

}  // end namespace csce240_book_project

#endif  // end _BOOK_H_
