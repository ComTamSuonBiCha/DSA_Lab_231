#include<iostream>
#include<cstring>
class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        publishingYear = 0;
        title = nullptr;
        authors=nullptr;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        // Dynamically allocate memory for title and authors
        this->title = new char[strlen(title) + 1]; // +1 for the null terminator
        this->authors = new char[strlen(authors) + 1]; // +1 for the null terminator

        // Copy the provided data into the allocated memory
        strcpy(this->title, title);
        strcpy(this->authors, authors);

        // Assign the publishingYear
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        this->title = new char[strlen(title) + 1];
        this->authors = new char[strlen(authors) +1];
        strcpy(this->title, book.title);
        strcpy(this->authors , book.authors); //the title member variable is private within the Book class, and the copy constructor is a member of the same class. In C++, member functions (including constructors) of a class have access to the private members of other instances of the same class.
        this->publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] title;
        delete[] authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};
