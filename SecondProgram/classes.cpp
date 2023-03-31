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

inline string book::SetName(const string& name_) {
    name = name_;
}
inline string book::SetAuthor(const string& author_) {
    author = author_;
}
inline string book::SetPublisher(const string& publisher_) {
    publisher = publisher_;
}
inline int book::SetPages(int pages_) {
    pages = pages_;
}

inline string book::GetName()const {
    return name;
}
inline string book::GetAuthor()const {
    return author;
}
inline string book::GetPublisher()const {
    return publisher;
}
inline int book::GetPages()const {
    return pages;
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

inline string techBook::SetUniversity(const string& university_) {
    university = university_;
}
inline int techBook::SetType(int type_) {
    type = type_;
}

inline string techBook::GetUniversity()const {
    return university;
}
inline int techBook::GetType()const {
    return type;
}
