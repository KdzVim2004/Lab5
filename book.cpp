#include <iostream>
#include <stdexcept>
#include "book.h"
#include "ebook.h"
using namespace std;

void print_description(const Book& book)
{
    cout << book.description() << '\n';
}

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        cout << "=== 1. Электронная книга ===\n";

        Ebook eb("1984", "Д. Оруэлл", 1949, 328, "http://example.com/1984");

        cout << eb.description() << '\n';
        eb.download();

        cout << "\n=== 2. Проверка названия ===\n";

        cout << "До обновления: " << eb.description() << '\n';

        eb.updateTitle("Новое название");

        cout << "После обновления: " << eb.description() << '\n';

        cout << "\n=== 3. Проверка LSP и предусловий ===\n";

        Book b("Nineteen Eighty-Four", "Д. Оруэлл", 1949, 328);
        Ebook eb2("Nineteen Eighty-Four", "Д. Оруэлл", 1949, 328, "http://example.com/1984");

        b.updateTitle("1984");
        cout << "Обычная книга: " << b.description() << '\n';

        eb2.updateTitle("1984");
        cout << "Электронная книга: " << eb2.description() << '\n';

        cout << "\n=== 4. Описание книги ===\n";

        cout << "Обычная книга: " << b.description() << '\n';
        cout << "Электронная книга: " << eb2.description() << '\n';

        cout << "\n=== 5. Полиморфизм ===\n";

        print_description(b);
        print_description(eb2);

        cout << "\n=== Проверка некорректных данных ===\n";

        try {
            eb.updateTitle("");
        }
        catch (const invalid_argument& e)
        {
            cout << "Ошибка: " << e.what() << '\n';
        }

        cout << "Программа не падает\n";
    }
    catch (const invalid_argument& e)
    {
        cout << "Ошибка: " << e.what() << '\n';
    }
    return 0;
}