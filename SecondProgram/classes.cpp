#include "classes.h"

////////////////////////////////////////////////////////////////
//                       class book                           //
////////////////////////////////////////////////////////////////
book::book() {
    name = "Undefined";
    author = "Undefined";
    publisher = "Undefined";
    pages = 0;
}
book::book(const string& name_, const string& author_, const string& publisher_, int pages_)
    : name(name_), author(author_), publisher(publisher_), pages(pages_) {}

void book::SetName(const string& name_) {
    name = name_;
}
void book::SetAuthor(const string& author_) {
    author = author_;
}
void book::SetPublisher(const string& publisher_) {
    publisher = publisher_;
}
void book::SetPages(int pages_) {
    pages = pages_;
}

string book::GetName()const {
    return name;
}
string book::GetAuthor()const {
    return author;
}
string book::GetPublisher()const {
    return publisher;
}
int book::GetPages()const {
    return pages;
}
string book::Get()const {
    return name + "\n"
        + author + "\n"
        + publisher + "\n"
        + to_string(pages) + "\n"
        + "#======#\n";
}


////////////////////////////////////////////////////////////////
//                       class techBook                       //
//////////////////////////////////////////////////////////////// 
techBook::techBook() {
    name = "Undefined";
    author = "Undefined";
    publisher = "Undefined";
    pages = 0;
    publisher = "Undefined";
    type = 0;
}

techBook::techBook(const string& name_, const string& author_, const string& publisher_, int pages_, const string& university_, int type_)
    : book(name_, author_, publisher_, pages_), university(university_), type(type_) {}

void techBook::SetUniversity(const string& university_) {
    university = university_;
}
void techBook::SetType(int type_) {
    type = type_;
}

string techBook::GetUniversity()const {
    return university;
}
int techBook::GetType()const {
    return type;
}

string techBook::Get()const {
    return name + "\n"
        + author + "\n"
        + publisher + "\n"
        + to_string(pages) + "\n"
        + "--tech--\n"
        + university + "\n"
        + to_string(type) + "\n"
        + "#======#\n";
}


void techBook::Show(){
    cout << "Book: " << name << " // Author: " << author << " // Publisher: " << publisher
        << " // Pages: " << pages << " // University: " << university << "// Type: " << type << endl;
}
