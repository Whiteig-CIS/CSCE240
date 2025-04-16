// Copyright 2025 csce240
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"textbook.h"
#include"book.h"
using csce240_book_project::Book;
using csce240_book_project::Textbook;

int main() {

Textbook b;
b.Print();
b.SetNumChapters(3);
b.Print();
string s[] = {"One", "two", "three", "four"};
b.SetNumChapters(4,s);

b.SetChapterName(1, "Review", true);
b.Print();

}




/*

int main() {
  Book b;
//  b.Print();
  Textbook t("Absolute C++", "Walter Savitch");
//  t.Print();

  Book * ptr = &b;
  ptr->Print();
  ptr = &t;
  ptr->Print();  // redefined function uses static binding

  return 0;
}

*/

/*
int main() {
  const Book kFavorite("Green Eggs and Ham", "Dr. Seuss", 1960);
  kFavorite.Print();

  Textbook b;
  b.Print();
  b.SetTitle("Absolute C++");
  b.SetAuthor("Walter Savitch");
  b.SetPublicationYear(2016);
  b.SetNumChapters(10);

  string chs[] = {"Intro","Stuff","Conclusion"};
  b.SetNumChapters(3, chs);
  b.Print();

  b.SetChapterName(1, "Preface");
  b.SetChapterName(5, "Index");
  b.Print();

  Book b2 = b;  // Book b2(b);
  b2.SetChapterName(3, "Glossary");
  cout << "\n\nAfter copy constructor and change to one\n";
  b2.Print();
  b.Print();
  b2 = b;
  b.SetNumChapters(0);

  cout << "\n\nAfter assignment and change to one\n";
  b.Print();
  b2.Print();

  Book some_books[3] = { kFavorite, b2 };
  cout << "My array of books:\n";
  for ( int i = 0; i < 3; ++i )
    some_books[i].Print();

  return 0;
}
*/



