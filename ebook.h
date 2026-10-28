#ifndef EBOOK_H
#define EBOOK_H
#include <string>
#include "book.h"

class Ebook : public Book {
public:
    Ebook(std::string title, std::string author, int year, int pages, std::string url);

    string url() const;
    void download() const;
    string description() const override;

private:
    string url_;
};
#endif