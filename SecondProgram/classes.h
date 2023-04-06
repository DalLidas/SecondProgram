#pragma once

#include "pch.h"

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
    
    void SetName(const string& name_);
    void SetAuthor(const string& author_);
    void SetPublisher(const string& publisher_);
    void SetPages(int pages_);

    string GetName()const;
    string GetAuthor()const;
    string GetPublisher()const;
    int GetPages()const;

    string Get() const;

    void Show() {
        cout << "Book: " << name << " // Author: " << author << " // Publisher: " << publisher << " // Pages: " << pages << endl;
    }

};

////////////////////////////////////////////////////////////////
//                       class techBook                       //
////////////////////////////////////////////////////////////////
class techBook : public book {
protected:
    string university;
    int type;  //1 - hypothesis //2 - theorem //3 - practice

public:
    techBook();
    techBook(const string& name_, const string& author_, const string& publisher_, int pages_, const string& university_, int type_);
   
    virtual ~techBook() = default;

    void SetUniversity(const string& university_);
    void SetType(int type_);

    string GetUniversity()const;
    int GetType()const;

    string Get() const;

    void Show();
};
