// Copyright 2025 csce240
// define Book class functionality
#include"book.h"
#include<iostream>
using std::cout;
using std::endl;

namespace csce240_book_project {

Book::Book(string t, string a, int y) : title_("Untitled"), author_("Unknown"),
                                        year_(1900), num_chapters_(0),
                                        chapters_(nullptr) {
  SetTitle(t);
  SetAuthor(a);
  SetPublicationYear(y);
}

Book::Book(const Book& tocopy) : title_(tocopy.title_),
                                 author_(tocopy.author_),
                                 year_(tocopy.year_), num_chapters_(0),
                                 chapters_(nullptr) {
  SetNumChapters(tocopy.num_chapters_, tocopy.chapters_);
}

Book& Book::operator = (const Book& tocopy) {
  title_ = tocopy.title_;
  author_ = tocopy.author_;
  year_ = tocopy.year_;
  SetNumChapters(tocopy.num_chapters_, tocopy.chapters_);
  return *this;
}


void Book::SetNumChapters(int n, const string * s) {
  if ( n < 0 )
    return;
  if ( n != num_chapters_ ) {
    num_chapters_ = n;
    // if chapters_ is currently pointing somewhere, we'll free up that memory
    if ( chapters_ != nullptr )
      delete [] chapters_;
    if ( n == 0 )
      chapters_ = nullptr;
    else
      chapters_ = new string[num_chapters_];
  }
  if ( s != nullptr ) {
    for ( int i = 0; i < n; ++i )
      chapters_[i] = s[i];
  }
}

string Book::GetChapterName(int n) const {
  if ( n > 0 && n <= num_chapters_ )
    return chapters_[n - 1];
  return "Invalid Chapter Number";
}

void Book::SetChapterName(int n, string newname) {
  if ( n > 0 && n <= num_chapters_ )
    chapters_[n - 1] = newname;
}




void Book::SetTitle(const string& t) {
  if ( t.length() > 0 )
    title_ = t;
}

void Book::SetAuthor(const string& a) {
  if ( a.length() > 0 )
    author_ = a;
}

void Book::SetPublicationYear(int y) {
  if ( y > 0 )
    year_ = y;
}

void Book::Print() const {
  cout << title_ << " written by " << author_ << " published " << year_
       << endl;

  if ( num_chapters_ > 0 ) {
    cout << "Chapters: " << chapters_[0];
    for ( int i = 1; i < num_chapters_; ++i )
      cout << ", " << chapters_[i];
    cout << endl;
  }
}


}  // end namespace csce240_book_project
