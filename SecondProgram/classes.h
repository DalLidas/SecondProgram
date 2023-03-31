#pragma once

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////
//                       class book                           //
////////////////////////////////////////////////////////////////
class book {
protected:
    string name;
    string author;
    string publisher;
    int pages;

public:
    book();
    book(const string& name_, const string& author_, const string& publisher_, int pages_);

    virtual ~book() = default;

    inline string SetName(const string& name_);
    inline string SetAuthor(const string& author_);
    inline string SetPublisher(const string& publisher_);
    inline int SetPages(int pages_);

    inline string GetName()const;
    inline string GetAuthor()const;
    inline string GetPublisher()const;
    inline int GetPages()const;
    virtual inline void Show() {
        cout << "Book: " << name << " // Author: " << author << " // Publisher: " << publisher << " // Pages: " << pages << endl;
    }

};

////////////////////////////////////////////////////////////////
//                       class techBook                       //
////////////////////////////////////////////////////////////////
class techBook : public book {
private:
    string university;
    int type;  //1 - hypothesis //2 - theorem //3 - practice

public:
    techBook();
    techBook(const string& name_, const string& author_, const string& publisher_, int pages_, const string& university_, int type_);
   
    virtual ~techBook() = default;

    inline string SetUniversity(const string& university_);
    inline int SetType(int type_);

    inline string GetUniversity()const;
    inline int GetType()const;

    virtual inline void Show() override final {
        cout << "Book: " << name << " // Author: " << author << " // Publisher: " << publisher
            << " // Pages: " << pages << " // University: " << university << "// Type: " << type << endl;
    }
};
