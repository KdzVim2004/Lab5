#include "ebook.h"
#include <iostream>
#include <stdexcept>
#include <string>

Ebook::Ebook(string title, string author, int year, int pages, string url)
    : Book(title, author, year, pages), url_(url) {
    if (url_.empty()) {
        throw std::invalid_argument("Ссылка на книгу не может быть пустой");
    }
}

string Ebook::url() const
{
    return url_;
}

void Ebook::download() const
{
    cout << "Загрузка электронной книги: "
        << title() << '\n';
    cout << "Ссылка: " << url_ << '\n';
}

string Ebook::description() const
{
    return Book::description() + " [Ссылка: " + url_ + "]";
}