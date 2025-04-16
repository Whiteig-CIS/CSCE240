// Copyright 2025 csce240
// implement the functionality of the Textbook class
#include<iostream>
using std::cout;
using std::endl;
#include"textbook.h"
#include"book.h"

namespace csce240_book_project {
                                              // call base class constructor
                                              // in the member initializer list
Textbook::Textbook(string t, string a, int y) : Book(t, a, y), has_problem_set_(nullptr){
}

Textbook::Textbook(const Textbook& tocopy) : Book(tocopy), has_problem_set_(nullptr) {
  if ( GetNumChapters() > 0) {
    has_problem_set_ = new bool [GetNumChapters()];
    for ( int i = 0; i < GetNumChapters(); ++i )
      has_problem_set_[i] = tocopy.has_problem_set_[i];
    
  }
}

Textbook& Textbook::operator = (const Textbook& tocopy) {

Book::operator =(tocopy); // calling he Book class' assignment operator

if ( has_problem_set_ != nullptr )
  delete [] has_problem_set_;
  if ( GetNumChapters() > 0) {
    has_problem_set_ = new bool [GetNumChapters()];
    for ( int i = 0; i < GetNumChapters(); ++i )
      has_problem_set_[i] = tocopy.has_problem_set_[i];
    
  } else {
    has_problem_set_[i] = nullptr;
  }

}

void Textbook::SetChapterName(int n, string t, bool p) {
  
  Book::SetChapterName(n,t);
  if ( n > 0 && n < GetNumChapters() )
    has_problem_set_[n-1] = p;

}

void Textbook::SetNumChapters(int n, const string * s) {
  if ( n < 0 )
    return;
  if ( n != GetNumChapters() ) {
    if ( has_problem_set_ != nullptr) {
        delete [] has_problem_set_;
    }
    if ( n == 0) {
      has_problem_set_ = nullptr;
  } else {
    has_problem_set_ = new bool[n];
  }
  for ( int i = 0; i < n; ++i) 
    has_problem_set_[i] = false;

  Book::SetNumChapters(n,s);
}
}

void Textbook::Print() const {
 cout << GetTitle() << GetAuthor() << GetPublicationYear() << endl;

 if ( GetNumChapters() == 0 )
   cout << "chapter: " << GetChapterName(0) << (has_problem_set_[0] ? "has" : "does not have") << " problem set)";

   for ( int i = 0; i < GetNumChapters(); ++i ) {
    cout << "chapter: " << GetChapterName(i) << (has_problem_set_[i] ? "has" : "does not have") << " problem set)";
   }

  
}


}  // end namespace csce240_book_project
