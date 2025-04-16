// CopyRight Isaac White 2025

#include"textbook.h"
#include"book.h"

namespace bookEx{
                                            // calls the base(parent) call constrructor
Textbook::Textbook(string t, string a, int y) : Book(t, a, y) {

}

void Textbook::Print() const {
    cout << "Textbook: ";
}


















} // end namespace