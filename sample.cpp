#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <windows.h>
#include<conio.h>
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
Date issue_date,return_date;// the user can only borrow 2 books at the same time( this is why it is array).
}user[1000];//array of structure for the user.

//Declaration of Functions
void welcome();
void user_option();
void main_menu();
void memberRegistration();
void search1 (char a);
void list_by_catagory();
void addbook();
void ModifyBookDetail();
void display(int x[],int sizee);
void sampleData();
int i,Bcounter=5,j;//  temporary declaration
int Ucounter;

//*************************************
bool stop=false;

int main(){

welcome();
sampleData();

while(!stop){
   main_menu();
}

return 0;

}

//This function creates sample data
void sampleData(){
//sample books

book[0]={"b100","c++","Mahri","A20","Programming",3,122,2,{2000,07,25},5,0,false};
book[1]={"b101","Luxury life","Mahi Tz","A10","Self help",5,1224,2,{2015,07,25},5,0,false};
book[2]={"b102","Tsom ","Mastewal","A20","Programming",8,4568,2,{2001,06,23},2,2,false};
book[3]={"b103","Java","Matiyas","A20","Fiction",6,7892,2,{2021,04,10},3,1,false};
book[4]={"b104","sql","Matiyas","A20","Religious",1,45587,2,{2020,04,15},4.5,3,false};

//sample user
user[0]={"Lebamlak","u100",20,{8040,"0942201994"},0};
user[1]={"Kidus","u101",50,{7030,"0911111111"},0};
user[2]={"Ibsa Berhanu","u102",60,{4564,"0922222222"},0};
user[3]={"Chere Lemma","u103",30,{1415,"0933333333"},0};
user[4]={"Jima Agaro","u104",13,{7856,"0944444444"},0};


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
//this function lists the books by there category.
void list_by_catagory(){
            system("cls");
       cout <<"\n\n\n\n"<<endl;
        cout << setw(15)<< char(176);      for(int i=0; i<90; i++){cout << char(205);} cout << char(176)<< endl;
        cout << setw(15)<< char(176)<<"choose category "<<endl;
        cout << setw(20)<< char(176)<<"a, Fiction "<<endl;
        cout << setw(20)<< char(176)<<"b, Science "<<endl;
        cout << setw(20)<< char(176)<<"c, Art"<<endl;
        cout << setw(20)<< char(176)<<"d, Self help"<<endl;
        cout << setw(20)<< char(176)<<"e, Religious"<<endl;
        cout << setw(20)<< char(176)<<"f, Social science "<<endl;
        cout << setw(20)<< char(176)<<"g, Amharic"<<endl;
        cout << setw(20)<< char(176)<<"h, Research book"<<endl;
        cout << setw(20)<< char(176)<<"i, Programing "<<endl;
        cout << setw(20)<< char(176)<<"j, Back "<<endl;
int counter=0;
char choice;
cin >>choice;
int Num_search[Bcounter];
switch (choice){
case 'a':{for (int i=0;i<=Bcounter;i++){
if ((book[i].catagory=="Fiction")){
     Num_search[counter]=i;
    counter++;
    }
}

display (Num_search,counter);
Backoption('u');
break;
}

case 'b':{ for (int i=1;i<=Bcounter;i++){
    if ((book[i].catagory=="Science")){
     Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter);
Backoption('u');
break;
}

case 'c':
    {for (int i=1;i<=Bcounter;i++){
    if ((book[i].catagory=="Art")){
Num_search[counter]=i;
    counter++;
}
display (Num_search,counter);
Backoption('u');
break;
}

case 'd': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Self help")){
Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter);
Backoption('u');
break;
}

case 'e': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Religious")){
Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter);
Backoption('u');
break;
}
case 'f': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Social science")){
Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter);
Backoption('u');
break;
}
case 'g': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Amharic")){
    Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter);
Backoption('u');
break;
}

case 'h': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Research books")){
    Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter);
Backoption('u');
break;
            }
        }
case 'i': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Programming")){
        Num_search[counter]=i;
    counter++;
        }
    }
display (Num_search,counter);
Backoption('u');
break;
            }
case 'j':
    user_option();
    break;
        }
}


  // this is a function that lists books depending on how often they are read
void most_read_book(){
    int Num_search[Bcounter],counter=0;
    for (int i=0;i<Bcounter;i++){
    if (book[i].read_freq>=2){
        Num_search[counter]=i;
    counter++;
                }
                }

    display (Num_search,counter);
    Backoption('u');

}

// this is a function that lists books depending on rating given to the book by users at time return after issuing
void by_rating(){
    int Num_search[Bcounter],counter=0,counterr=0;
    float arr[Bcounter];
    for (int i=0;i<Bcounter;i++)
      arr[i]=book[i].rate;
    int n = sizeof(arr) / sizeof(arr[0]);
    float arr1[Bcounter];
sort(arr, arr + n);

for(int i=0; i<n;i++){
       if(arr[i]!=arr[i+1])
            {
                arr1[counterr]=arr[i];
                counterr++;

            }
}

for(int i=counterr; i>=0;i--)
    for(int j=0;j<Bcounter;j++){
       if(arr1[i]==book[j].rate){
  Num_search[counter]=j;
            counter++;
}
    }

display (Num_search,counter);
Backoption('u');
}


// this function lists all the books that are recently published meaning it lists the newest books in the library
void recent_books(){
    int Num_search[Bcounter],counter=0;

            for (int j=0;j<Bcounter;j++){
        if (book[j].date_of_pub.yy>=2020){
            Num_search[counter]=j;
            counter++;
        }

    }

display (Num_search,counter);
Backoption('u');
}


  //this function  lists all the books that  currently exist in a library
void all_books(char p){
    int Num_search[Bcounter],count;
    for (int i=0;i<Bcounter;i++){
        Num_search[i]=i;
    }

    display (Num_search,Bcounter);

        Backoption(p);

}

//This is a function to add books to the library
void addbook(){
system("cls");
    addanother;
    cout<<"Add Book details "<<endl;

   cout<<"Enter book Title : ";    getline(cin,book[Bcounter].title);
   cout<<"Enter Author's Name   : ";  getline(cin,book[Bcounter].author);
   cout<<"Enter Shelf number : ";  getline(cin,book[Bcounter].shelf_no);
   cout<<"Enter Book Id : ";   getline(cin,book[Bcounter].book_id);
   cout<<"Enter Book category  : ";  getline(cin,book[Bcounter].catagory);
   cout<<"Enter Book's Quantity : ";  cin>>book[Bcounter].quantity;
   cout<<"Enter Book's ISBN number : ";  cin>>book[Bcounter].isbn;
   cout<<"Enter Book's Edition  : ";  cin>>book[Bcounter].edition;
   cout<<"Enter Book's Date of publication  : ";  cin>>book[Bcounter].date_of_pub.dd>>book[Bcounter].date_of_pub.mm>>book[Bcounter].date_of_pub.yy;


   cout<<"Book added succesfully"<<endl;
    Bcounter++;
     int choice ;
    cout<<"Do you want to Add another book 1(yes ) or 2(NO) "; cin>>choice;
    cin.ignore();
      // system ("cls");

       if (choice==1)
        goto addanother;

else
    Backoption('a');

}



void ModifyBookDetail(){

          i=bookChecker();

       // then display the existing details



        cout<<"Enter the New book Details "<<endl;
        cout<<"Enter book Title : ";    getline(cin,book[i].title);
        cout<<"Enter Author's Name   : ";  getline(cin,book[i].author);
        cout<<"Enter Shelf number : ";  getline(cin,book[i].shelf_no);
        cout<<"Enter Book Id : ";   getline(cin,book[i].book_id);
        cout<<"Enter Book category  : ";  getline(cin,book[i].catagory);
        cout<<"Enter Book's Quantity : ";  cin>>book[i].quantity;
        cout<<"Enter Book's ISBN number : ";  cin>>book[i].isbn;
        cout<<"Enter Book's Edition  : ";  cin>>book[i].edition;
        cout<<"Enter Book's Date of publication  : ";  cin>>book[i].date_of_pub.dd>>book[i].date_of_pub.mm>>book[i].date_of_pub.yy;

}
// Function to check book is exist or not
int bookChecker()
{
string ID;
if(Bcounter==0)
cout<<setw(53)<<"No book has been added yet"<<endl;
else{
reenter:cout<<setw(53)<<"enter the book Id ";
cin>>ID;
cin.clear();
cin.ignore(1000,'\n');
for(int i=0;i<Bcounter;i++)
{
if(ID==book[i].book_id){
return i;
break;
}
else if(i==Bcounter-1){
cout<<"The book has either been deleted or doesn't exist "<<endl;
go to reenter;
}
}
}
}
void deleteBook()
{
i=bookChecker();
for(int j=i;j<Bcounter;j++){
book[j].title=book[j].title;
book[j].author =book[j+1].author ;
book[j].shelf_no=book[j+1].shelf_no;
book[j].book_id=book[j+1].book_id;
book[j].category =book[j+1].book_id;

book[j].quantity =book[j+1].quantity ;
book[j].isbn=book[j+1].isbn;

book[j].edition =book[j+1].edition ;

book[j].date_of_pub.dd=book[j+1].date_of_pub.dd;
book[j].date_of_pub.mm=book[j+1].date_of_pub.mm;
book[j].date_of_pub.yy=book[j+1].date_of_pub.yy;
if(j==Bcounter-2)
break;

}
Bcounter--;
}
// function to display book information tabularly ***********************
void display(int x[],int sizee){
   system("cls");

cout << char(186) <<setw(4)<<"No"<<char(186)  /*1*/ <<setw(8)<<"book_id"<< char(186);/*2*/
cout<<setw(15)<<"title"<<char(186)/*3*/<<setw(15)<<"author"<<char (186);/*4*/
cout<<setw(15)<<"catagory"<<char(186)/*5*/<<setw(8)<<"rate"<<char (186);/*6*/
cout<<setw(8)<<"quantity"<<char(186);/*7*/
cout<<setw(18)<<"publication date"<<char (186);/*11*/
cout<<setw(15)<<"shelf_no"<<char (186)/*8*/<<setw(8)<<"edition"<<char(186)/*9*/<<setw(8)<<"isbn"<<char (186)/*10*/<< endl;

for (int i=0;i<sizee;i++){
cout << char(201);  for(int i=0; i<4; i++){cout << char(205);}cout << char(206); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*5*/for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*6*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*7*/for(int i=0; i<18; i++){cout << char(205);}cout << char(206); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*10*/cout << char(187) << endl;

cout << char(206) <<setw(3)<<i+1<<"."<<char(206)  /*1*/ <<setw(8)<<book[x[i]].book_id<< char(206);/*2*/
cout<<setw(15)<<book[x[i]].title<<char(206)/*3*/<<setw(15)<<book[x[i]].author<<char (206);/*4*/
cout<<setw(15)<<book[x[i]].catagory<<char(206)/*5*/<<setw(8)<<book[x[i]].rate<<char (206);/*6*/
cout<<setw(8)<<book[x[i]].quantity<<char(206);/*7*/
cout<<setw(5)<<book[x[i]].date_of_pub.dd<<"-"<<setw(5)<<book[x[i]].date_of_pub.mm<<"-"<<setw(6)<<book[x[i]].date_of_pub.yy<<char (186);/*11*/
cout<<setw(15)<<book[x[i]].shelf_no<<char (206)/*8*/<<setw(6)<<book[x[i]].edition<<"th"<<char(206)/*9*/<<setw(8)<<book[x[i]].isbn<<char (206)/*10*/<< endl;





