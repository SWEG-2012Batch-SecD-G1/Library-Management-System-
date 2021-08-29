#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<string>
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
}user[1000];//array of structure for the user.

//Declaration of Functions
void welcome();
char user_option();
void main_menu();
void memberRegistration();
void search1 (char a);


int main(){

 welcome();
main_menu();
do{

switch(choose){
	case 1:
		admin_option();
	break;
	case 2:
		user_option();
	break;

	 default :{
	 	cout<<"You entered the wrong number. ";

}
}

}
while(choose!=3);



return 0;
}

//This function is used to generate a welcome page
void welcome(){
 system("cls");
  cout<<"\t%%      %%      ";
       cout<<"\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
       cout<<"\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";


       cout<<"\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
       cout<<"\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
       cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
       cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
       cout<<"\n\t\t\t           $$     $   $      ";
       cout<<"\n\t\t\t           $$     $$$$$    ";

       cout<<"\n\n\n\t\t\t  (******** 5M LIBERARY  *******)";
        cout<<"\n\n\n --->  Made By: Group 1 ";
        cout<<"\n --->  AASTU 2021 All right reserved  ";

cout<<"\n\n\n";

}

//This is a function that enables the person who access is whether a user or admin
void main_menu(){
system ("cls");
 int choice;
       cout <<"\n\n\n\n"<<endl;
        cout << setw(15)<< char(176);      for(int i=0; i<90; i++){cout << char(205);} cout << char(176)<< endl;
        cout << setw(10)<< char(176)<<"select User or Admin to from the following  "<<endl;
        cout << setw(15)<< char(176)<<"1. User"<<endl;
        cout << setw(15)<< char(176)<<"2. Admin"<<endl;
        cout << setw(15)<< char(176)<<"3. Exit"<<endl;
        cout << setw(15)<< char(176);      for(int i=0; i<90; i++){cout << char(205);} cout << char(176)<< endl;
        cin>>choice;

         switch (choice){
    case 1:
      user_option();
        break;
    case 2:
    admin_option ();
        break;
    case 3:
        cout<<"\n\n\nThank You For Using Our Program...Bye!\n";
        exit (EXIT_SUCCESS);
    }

}
//This function lists the services that the user will get in the library
char user_option(){

Clrscr();

 char choice;
       cout <<"\n\n\n\n"<<endl;
        cout << setw(15)<< char(176);      for(int i=0; i<90; i++){cout << char(205);} cout << char(176)<< endl;
        cout << setw(15)<< char(176)<<"search books by"<<endl;
        cout << setw(20)<< char(176)<<"a, Title"<<endl;
        cout << setw(20)<< char(176)<<"b, Author"<<endl;
        cout << setw(20)<< char(176)<<"c, ISBN"<<endl;
        cout << setw(15)<< char(176)<<"List books by"<<endl;
        cout << setw(20)<< char(176)<<"d, category"<<endl;
        cout << setw(20)<< char(176)<<"e, Most read"<<endl;
        cout << setw(20)<< char(176)<<"f, Rating "<<endl;
         cout << setw(20)<< char(176)<<"g, Recent books"<<endl;
          cout << setw(20)<< char(176)<<"h, All books"<<endl;
         cout<<setw(20)<<char(176)<<"i,back to menu"<<endl;
        cout << setw(15)<< char(176)<<endl;
        cout << setw(15)<< char(176);      for(int i=0; i<90; i++){cout << char(205);} cout << char(176)<< endl;
        cin>>choice;
   switch(choice)
{
   case a: Clrscr();
           Title ();
           break;
 case b:Author ();
       break;
case c:ISBN();
       break;
case d: category();
       break;
 case e:Most read();
        break;
case f:Rating();
      break;
case g:Recent book();
       break;
case h:All book();
      break;
case i:return;
default:{
cout<<"you enterd inappropriate character.please try again!!"}

}
        return choice;
}
 // This is a function to register multiple members at once
void memberRegistration(){

        addanother: // to register multiple members at once


         cout<<"Enter Name : "; getline(cin,user[Ucounter].name);
         cout<<"Enter ID : " ; getline(cin,user[Ucounter].user_id);
         cout<<"Enter Age : ";  cin>>user[Ucounter].age;
         cout<<"Enter House no. : "; cin>>user[Ucounter]. user_address.house_no;
         cout<<"Enter Phone no. : ";  cin>>user[Ucounter]. user_address.phone;

         cout<<"Member added successfully !"<<endl;
         Ucounter++;
         int choice ;

    cout<<"Do you want to Add another member 1(yes ) or 2(NO) "; cin>>choice;
    cin.ignore();
       system ("cls");

       if (choice==1)
        goto addanother;


}
void search1 (char a){
int Num_search[Bcounter],counter=0;
switch (a){
case 'a':{cin.ignore();
system ("cls");
cout<<"\n\n\n"<<"           "<<"Please insert the title of the book"<<endl;
string searchName,temp_title;
getline (cin, searchName);
 transform (searchName.begin(),searchName.end(),searchName.begin(),:: tolower);
for (int i=0;i<Bcounter;i++){
    temp_title=book[i].title;
transform (temp_title.begin(),temp_title.end(),temp_title.begin(),:: tolower);
        if (temp_title==searchName){
      Num_search[counter]=i;
      counter++;
            }
        }
if (counter>0){
   display (Num_search,counter);
}
else{

  cout<<"NO Search Result found...!\n";
   system("pause");
   user_option();
}
   break;
    }
case 'b':{cin.ignore();
system ("cls");
cout <<"\n\n\n"<<"           "<<"Please insert the Author of the book"<<endl;
string searchName,temp_autohr;
getline (cin, searchName);
 transform (searchName.begin(),searchName.end(),searchName.begin(),:: tolower);

for (int i=0;i<Bcounter;i++){
    temp_autohr=book[i].author;
transform (temp_autohr.begin(),temp_autohr.end(),temp_autohr.begin(),:: tolower);
        if (temp_autohr==searchName){
      Num_search[counter]=i;
      counter++;
        }
    }
if (counter>0){
   display (Num_search,counter);
}
else{

  cout<<"NO Search Result found...!\n";
   system("pause");
   user_option();
    }
break;
}
case 'c':{;
system ("cls");
cout <<"\n\n\n"<<"           "<<"Please insert the ISBN of the book"<<endl;
int isbn;
cin >>isbn;
for (int i=0;i<=Bcounter;i++){
if (isbn==book[i].isbn){
        Num_search[counter]=i;
    counter++;
                }
            }
if (counter>0){
   display (Num_search,counter);
}
else{

  cout<<"NO Search Result found...!\n";
  system("pause");
  user_option();
}
break;
        }
    }

}

