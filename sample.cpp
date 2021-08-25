#include<iostream>
using namespace std;

struct Date{
int yy,mm,dd;
};
struct Address{
int house_no;
int phone;
};

struct Admin{
string password,user_name;
};

// to recored a book details that found in library
struct Book{
string book_id,title,author,shelf_no,catagory;
int quantity,isbn,edition;
Date date_of_pub;
float rate;// the rate given by readers, based on thier satisfaction on the book.
int read_freq;
bool issued;
}book[1000];

//to recored any library users information / or to recored library member informaion.
struct User{
string name, user_id;
int age;
Address user_address;
int num_issued_book;
Book issued_book[2];// the user can only borrow 2 books at the same time( this is why it is array).
};
int main(){
  


return 0;
}
