///***************************************************************
///                   HEADER FILES USED IN PROJECT
///****************************************************************

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <windows.h>
#include<conio.h>
#include<fstream>
#include<sstream>
using namespace std;

///***************************************************************
///                   STRUCTS  USED IN PROJECT
///****************************************************************
struct Date{
int yy,mm,dd;
};
struct Address{
int house_no;
string phone;
};

struct Admin{
string password,user_name;
};
// to recored a book details that found in library
struct Book{

string book_id,title,author,shelf_no,catagory;
int quantity,isbn,edition;
Date date_of_pub;
float rate;   // the rate given by readers, based on their satisfaction on the book.
int read_freq;
bool issued;
};

//to recored any library users information / or to recored library member information.
struct User{
string name, user_id;
int age;
Address user_address;
int num_issued_book;
Book issued_book;   // we connect the two structs by creating the object of one struct in the other struct
Date issue_date,return_date;
};

///***************************************************************
///                   FUNCTIONS USED IN PROJECT
///****************************************************************
//Declaration of Functions
void welcome();
void main_menu();
void user_option();
void admin_option();
void display(int[],int,string);
void listbook (char a);
void search1 (char a,char b);
void list_by_catagory();
void most_read_book();
void by_rating();
void recent_books();
void all_books(char);
void Backoption(char);
void sampleData();
void isueOrReturnbook(char);
int userChecker();
void addbook();
void ModifyBookDetail();
int bookChecker();
void deleteBook();
void memberRegistration();
void ModifyMemberDetail();
void deleteMember();
void password();
void all_users();
void unreturned_books();
void search_specific_user();
void display1(int x[],int,string);
void display2(int x[],int,string);
void decreaseCatg(int i,int );
void increaseCatg(int ,int );
void statistics();
void thankyou();
void counter_updater(char);
void Read();
void Write(char);



///***************************************************************
///   Global Variables And Dynamic Pointers USED IN PROJECT
///****************************************************************


int i,j,Bcounter,Ucounter,bid,uid;
bool stop=false;

//User *user = new User[Ucounter];
//Book *book= new Book[Bcounter];
User user[1000];// = new User[Ucounter];
Book book[1000];

 int Fiction, Science ,Art ,Self_help, Religious ,Social_science, Amharic  ,Research_book,Programing,other; // declaration and initialization
//for number of books that currently exist in each category



///***************************************************************
///            FUNCTION DEFINITION STARTS HERE
///****************************************************************


int main(){

welcome();
counter_updater('s');
Read();

while(!stop){
   main_menu();
}
counter_updater('e');
return 0;
}


void welcome(){
 system("cls");
 HANDLE a= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(a,10);

  cout<<"\t%%      %%      ";
       cout<<"\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
       cout<<"\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
       cout<<"\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
       cout<<"\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
       cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
        HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,14);
       cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
       cout<<"\n\t\t\t           $$     $   $      ";
       cout<<"\n\t\t\t           $$     $$$$$    ";


       cout<<"\n\n\n\t\t\t  (******** 5M LIBERARY  *******)";
        HANDLE c= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c,12);
        cout<<"\n\n\n\t\t --->  Made By: SEC D G1 ";
        cout<<"\n\t\t --->  AASTU 2021 All right reserved  ";

cout<<"\n\n\n";
system ("pause");
  HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
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


void main_menu(){
system ("cls");
 int choice;

string str="Main Menu";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
       cout <<"\n\n\n\n"<<endl;
        cout << setw(15)<< char(176);      for(int i=0; i<90; i++){cout << char(205);} cout << char(176)<< endl;
        cout << setw(10)<< char(176)<<"ARE YOU A USER OR AN ADMIN? "<<endl;
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
        password();
        break;
    case 3:
        counter_updater('e');
        thankyou();
        exit (EXIT_SUCCESS);
    }


}


void user_option(){

system ("cls");
 char choice;

string str="USER OPTIONS";
HANDLE J= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(J,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
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
        cout << setw(15)<< char(176)<<endl;
        cout << setw(15)<< char(176)<<endl;
        cout << setw(15)<< char(176);      for(int i=0; i<90; i++){cout << char(205);} cout << char(176)<< endl;
        cout << setw(15)<< char(176);cout << setw(20)<< char(176)<<"i, Back to Main Menu"<<endl;

 cin.clear();
 cin.ignore(1000,'\n');
        cin>>choice;

          char b=choice;
        if('a'==b || b=='b'||b=='c'){
            search1(b,'u');

         }
        else if(b=='d'||b=='e'||b=='f'||b=='g' ||b=='h'){
            listbook(b);}

else if(b=='i')
    main_menu();


}

void display(int x[],int sizee,string str){
   system("cls");
   if(str!="0"){
    HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
   }
cout <<"\n\n\n"<<endl;cout << char(201);  for(int i=0; i<4; i++){cout << char(205);}cout << char(203); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*5*/for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*6*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*7*/for(int i=0; i<18; i++){cout << char(205);}cout << char(203); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*10*/cout << char(187) << endl;

cout << char(186) <<setw(4)<<"No"<<char(186)  /*1*/ <<setw(8)<<"book_id"<< char(186);/*2*/
cout<<setw(15)<<"title"<<char(186)/*3*/<<setw(15)<<"author"<<char (186);/*4*/
cout<<setw(15)<<"category"<<char(186)/*5*/<<setw(8)<<"rate"<<char (186);/*6*/
cout<<setw(8)<<"quantity"<<char(186);/*7*/
cout<<setw(18)<<"publication date"<<char (186);/*11*/
cout<<setw(15)<<"shelf_no"<<char (186)/*8*/<<setw(8)<<"edition"<<char(186)/*9*/<<setw(8)<<"isbn"<<char (186)/*10*/<< endl;

cout << char(200);  for(int i=0; i<4; i++){cout << char(205);}cout << char(206); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*5*/for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*6*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*7*/for(int i=0; i<18; i++){cout << char(205);}cout << char(206); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(206) /*10*/<< char(188)<<endl;


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

cout << char(200);  for(int i=0; i<4; i++){cout << char(205);}cout << char(202); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(202); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*5*/for(int i=0; i<8; i++){cout << char(205);}cout << char(186); /*6*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(186); /*7*/for(int i=0; i<18; i++){cout << char(205);}cout << char(186); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(186); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(186); /*10*/cout << char(188) << endl<<endl;;



}

}



void search1 (char a,char b){
int Num_search[Bcounter],counter=0;
switch (a){
case 'a':{
    if(b=='u')
    cin.ignore();
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
   display (Num_search,counter,"SEARCH RESULT...");
   Backoption(b);
}
else{

  cout<<"NO Search Result found...!\n";
   system("pause");
   if(b=='u')
   user_option();
   else if(b=='a')
    admin_option();
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
   display (Num_search,counter,"SEARCH RESULT...");
   Backoption('u');
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
   display (Num_search,counter,"SEARCH RESULT...");
   Backoption('u');
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

void listbook (char a){
switch(a){
case 'd': list_by_catagory();
    break;
case 'e': most_read_book();
    break;
case 'f': by_rating();
    break;
case 'g': recent_books();
    break;
case 'h': all_books('u');
break;
}
}
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

display (Num_search,counter,"FICTION BOOKS ONLY...");
Backoption('u');
break;
}

case 'b':{ for (int i=1;i<=Bcounter;i++){
    if ((book[i].catagory=="Science")){
     Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter,"SCIENCE BOOKS ONLY...");
Backoption('u');
break;
}

case 'c':
    {for (int i=1;i<=Bcounter;i++){
    if ((book[i].catagory=="Art")){
Num_search[counter]=i;
    counter++;
}
display (Num_search,counter,"ART BOOKS ONLY...");
Backoption('u');
break;
}

case 'd': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Self help")){
Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter,"SELF HELP BOOKS ONLY...");
Backoption('u');
break;
}

case 'e': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Religious")){
Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter,"RELIGIOUS BOOKS ONLY...");
Backoption('u');
break;
}
case 'f': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Social science")){
Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter,"SOCIAL SCIENCE BOOKS ONLY...");
Backoption('u');
break;
}
case 'g': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Amharic")){
    Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter,"AMHARIC BOOKS ONLY...");
Backoption('u');
break;
}

case 'h': {for (int i=0;i<Bcounter;i++){
    if ((book[i].catagory=="Research books")){
    Num_search[counter]=i;
    counter++;
    }
}
display (Num_search,counter,"RESEARCH PAPERS ONLY...");
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
display (Num_search,counter,"PROGRAMING BOOKS ONLY...");
Backoption('u');
break;
            }
case 'j':
    user_option();
    break;
        }
}


void most_read_book(){
    int Num_search[Bcounter],counter=0;
    for (int i=0;i<Bcounter;i++){
    if (book[i].read_freq>=2){
        Num_search[counter]=i;
    counter++;
                }
                }

    display (Num_search,counter,"MOST READ BOOKS");
    Backoption('u');

}
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

display (Num_search,counter,"SORTED BY RATING");
Backoption('u');
}

void recent_books(){
    int Num_search[Bcounter],counter=0;

            for (int j=0;j<Bcounter;j++){
        if (book[j].date_of_pub.yy>=2020){
            Num_search[counter]=j;
            counter++;
        }

    }

display (Num_search,counter,"RECENT BOOKS");
Backoption('u');
}

void all_books(char p){
    int Num_search[Bcounter];
    for (int i=0;i<Bcounter;i++){
        Num_search[i]=i;
    }

    display (Num_search,Bcounter,"ALL BOOKS");

        Backoption(p);

}



void addbook(){
system("cls");
string str="ADDING NEW BOOK...";
HANDLE o= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(o,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
    addanother:  // it gives the  the admin the chance to add multiple books ;
    cout<<"Add Book details "<<endl;

   cout<<"Enter book Title : ";    getline(cin,book[Bcounter].title);
   cout<<"Enter Author's Name   : ";  getline(cin,book[Bcounter].author);
   cout<<"Enter Shelf number : ";  getline(cin,book[Bcounter].shelf_no);
   bid++;
   book[Bcounter].book_id="b"+ to_string(bid);
   cout<<"Enter Book category  : ";  getline(cin,book[Bcounter].catagory);
   cout<<"Enter Book's Quantity : ";  cin>>book[Bcounter].quantity;
   cout<<"Enter Book's ISBN number : ";  cin>>book[Bcounter].isbn;
   cout<<"Enter Book's Edition  : ";  cin>>book[Bcounter].edition;
   cout<<"Enter Book's Date of publication(DD MM YY): ";  cin>>book[Bcounter].date_of_pub.dd>>book[Bcounter].date_of_pub.mm>>book[Bcounter].date_of_pub.yy;

   increaseCatg(book[Bcounter].quantity,Bcounter);  //calls a function to quantity in a given category
   ofstream write("Books.txt",ios::app);
write<<book[Bcounter].book_id<<","<<book[Bcounter].title<<","<<book[Bcounter].author<<","
<<book[Bcounter].shelf_no<<","<<book[Bcounter].catagory<<","<<book[Bcounter].quantity<<","<<book[Bcounter].isbn<<","
<<book[Bcounter].edition<<","<<book[Bcounter].date_of_pub.yy<<","<<book[Bcounter].date_of_pub.mm<<","<<book[Bcounter].date_of_pub.dd<<","
<<book[Bcounter].rate<<","<<book[Bcounter].read_freq<<","<<book[Bcounter].issued<<"\n";
write.close();
   cout<<"Book added successfully"<<endl;
    Bcounter++;
     int choice ;
    cout<<"Do you want to Add another book 1(yes ) or 2(NO) "; cin>>choice;
    cin.ignore();

       if (choice==1)
        goto addanother;

else
    Backoption('a');

}



void ModifyBookDetail(){

      string str="MODIFIYING BOOK DETAILS...";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
           i=bookChecker();
       // then display the existing details
          int g[1]={};
          g[0]=i;
          display(g,1,str);

        cout<<"Enter the New book Details "<<endl;
        cout<<"Enter book Title : ";    getline(cin,book[i].title);
        cout<<"Enter Author's Name   : ";  getline(cin,book[i].author);
        cout<<"Enter Shelf number : ";  getline(cin,book[i].shelf_no);
        cout<<"Enter Book category  : ";  getline(cin,book[i].catagory);
        cout<<"Enter Book's Quantity : ";  cin>>book[i].quantity;
        cout<<"Enter Book's ISBN number : ";  cin>>book[i].isbn;
        cout<<"Enter Book's Edition  : ";  cin>>book[i].edition;
        cout<<"Enter Book's Date of publication  : ";  cin>>book[i].date_of_pub.dd>>book[i].date_of_pub.mm>>book[i].date_of_pub.yy;

      Write('b');
cout<<"Book Info Updated Successfully!!\n";
system("pause");
admin_option();

}

 // function to check if book exists or not and if the book exists it returns the index

int bookChecker(){
       string ID;
       if(Bcounter==0)
        cout<<setw(53)<<"No Book has been Added Yet"<<endl;
        else{
        reenter: cout<<"\n"<<setw(25)<<"Enter Book Id : ";   cin>>ID;
        cin.clear(); cin.ignore(1000,'\n');


         for(int i=0;i<Bcounter;i++){

                if(ID==book[i].book_id){
                   return i;
                  break;
               }

                else if(i==Bcounter-1) {
                cout<<"The Book has either been Deleted or Doesn't Exist "<<endl;

                // choice for going back to the main menu
                goto reenter;
              }
         }
        }
}



void deleteBook()
{
    string str="DELETING BOOK...";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
i=bookChecker();
decreaseCatg(book[i].quantity,i);  // calls a function that  decrease the number from a given category

for(int j=i;j<Bcounter;j++){
book[j].title=book[j+1].title;
book[j].author =book[j+1].author ;
book[j].shelf_no=book[j+1].shelf_no;
book[j].book_id=book[j+1].book_id;
book[j].catagory=book[j+1].catagory;

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
Write('b');
cout<<"Book Deleted Successfully!!\n";
system("pause");
admin_option();

}


void memberRegistration(){
string str="REGISTERING NEW USER...";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);

        addanother: // to register multiple members at once

        cout<<"Enter Name : "; getline(cin,user[Ucounter].name);
        uid++;
        user[Ucounter].user_id="u"+ to_string(uid);
         cout<<"Enter Age : ";  cin>>user[Ucounter].age;
         cout<<"Enter House no. : "; cin>>user[Ucounter]. user_address.house_no;
         cout<<"Enter Phone no. : ";  cin>>user[Ucounter]. user_address.phone;

          ofstream write("Users.txt",ios::app);
write<<user[Ucounter].name<<","<<user[Ucounter].user_id<<","<<user[Ucounter].age<<","<<user[Ucounter]. user_address.house_no<<","
<<user[Ucounter]. user_address.phone<<","<<user[Ucounter].num_issued_book<<","
<<user[Ucounter].issue_date.yy<<","<<user[Ucounter].issue_date.mm<<","<<user[Ucounter].issue_date.dd<<","
<<user[Ucounter].return_date.yy<<","<<user[Ucounter].return_date.mm<<","<<user[Ucounter].return_date.dd<<","<<user[j].issued_book.issued<<"\n";
write.close();

         cout<<"Member added successfully !"<<endl;
         Ucounter++;

         int choice ;

    cout<<"Do you want to Add another member 1(yes ) or 2(NO) "; cin>>choice;
    cin.ignore();
       system ("cls");

       if (choice==1)
        goto addanother;
else
admin_option();

}


void ModifyMemberDetail(){
string str="MODIFIYING USER DETAILS...";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);

          i=userChecker(); // we check for the account
           int g[1]={};
          g[0]=i;
          display2(g,1,str);
       // then display the existing details
       cout<<"\nEnter The New Details for the member  "<<endl;

       cout<<"Enter Name : "; getline(cin,user[i].name);
         cout<<"Enter Age : ";  cin>>user[i].age;
         cout<<"Enter House no. : "; cin>>user[i]. user_address.house_no;
         cout<<"Enter Phone no. : ";  cin>>user[i]. user_address.phone;

          Write('u');
         cout<<"Member info updated Successfully!!\n";
system("pause");
admin_option();
}

void deleteMember(){
            string str="DELETING A USER...";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
       i=userChecker();
       for(int j=i; j<Ucounter;j++){  // this loop is to move the accounts forward
             user[j].name=user[j+1].name;
             user[j].user_id=user[j+1].user_id;
             user[j].age=user[j+1].age;
             user[j].user_address.house_no=user[j+1].user_address.house_no;
             user[j].user_address.phone=user[j+1].user_address.phone;
       if(j==Ucounter-2)
                break;

           }
          Ucounter--;

          Write('u');
    cout<<"Member Deleted Successfully!!";
system("pause");
admin_option();
}



void isueOrReturnbook(char opreation ){
system("cls");
cout<<"\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
if(opreation=='i')
cout<<"\t\t       ^^^^^^^^^^^^^ ISSUE Book....  ^^^^^^^^^^^^^"<<endl;
else if(opreation=='r')
cout<<"\t\t       ^^^^^^^^^^^^^ Deposit Book....  ^^^^^^^^^^^^^"<<endl;
cout<<"\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;

int bindex,uindex,timedifference,fine;

bindex=bookChecker();
uindex=userChecker();

if(opreation=='i'){
if(book[bindex].quantity>1){

book[bindex].quantity--;
book[bindex].read_freq++;
book[bindex].issued=1;

user[uindex].num_issued_book++;
user[uindex].issued_book=book[bindex];

cout<<"Enter issued date(DD-MM-YY): ";
cin>>user[uindex].issue_date.dd>>user[uindex].issue_date.mm>>user[uindex].issue_date.yy;
}
else{
    cout<<"Sorry this book can't be borrowed...not enough quantity exist!\n\n";
    system("Pause");
    goto last;
}

}


if(opreation=='r')
{
 if (user[uindex].issued_book.issued==1){

book[bindex].quantity++;
book[bindex].issued=0;
user[uindex].issued_book.issued=0;
user[uindex].num_issued_book--;

cout<<"Enter return date(DD-MM-YY): ";
cin>>user[uindex].return_date.dd>>user[uindex].return_date.mm>>user[uindex].return_date.yy;
cout<<"\nPlease rate this book out of 5: ";
int r;
cin>>r;
book[bindex].rate=(book[bindex].rate+r)/2;

int yydifference=365*(user[uindex].return_date.yy - user[uindex].issue_date.yy);

int mmdifference=30*(user[uindex].return_date.mm - user[uindex].issue_date.mm);
int dddifference=(user[uindex].return_date.dd - user[uindex].issue_date.dd);
 timedifference=yydifference+mmdifference+dddifference;
 fine= (timedifference-5) *2;
}
else
{
    cout<<"The book hasn't been taken or This user didn't take this book!!\n\n";
    system("pause");
    goto last;
}

}



cout<<"\n\n";
cout<<"BOOK"<<endl;
cout<<"___________________"<<endl;
cout<<"Book_ID: "<<book[bindex].book_id<<endl;
cout<<"BOOk Title: "<<book[bindex].title<<endl;
cout<<"Author: "<<book[bindex].author<<endl;
cout<<"______________";

cout<<"\n\n Issued By "<<endl;
cout<<"______________"<<endl;
cout<<"User Id: "<<user[uindex].user_id<<endl;
cout<<"Name: "<<user[uindex].name<<endl;
cout<<"Phone NO: "<<user[uindex].user_address.phone<<endl;
cout<<"______________\n\n";
if(opreation=='i'){
cout<<" Date(DD-MM-YY) "<<endl;
cout<<"______________"<<endl;
cout<<"Issued Date: "<<user[uindex].issue_date.dd<<"-"<<user[uindex].issue_date.mm<<"-"<<user[uindex].issue_date.yy<<endl;
cout<<"Should be returned: ";
if(user[uindex].issue_date.dd+5-30>0){
    cout<<user[uindex].issue_date.dd+5-30<<"-"<<user[uindex].issue_date.mm+1<<"-"<<user[uindex].issue_date.yy<<endl;
}
else{
 cout<<user[uindex].issue_date.dd+5<<"-"<<user[uindex].issue_date.mm<<"-"<<user[uindex].issue_date.yy<<endl;
}

cout<<"______________\n\n";
cout<<"Book issued successfully...\n\n";
cout<<"Note: Submit within 5 days, you will pay 2 Birr for each day after 5 day period.\n\n";
system("pause");
}

if(opreation=='r'){

  cout<<"The book returned after "<<timedifference<<" days\n\n";
  cout<<"Fine has to be deposited "<<fine<<" Birr\n\n";
  cout<<"\t\tBook Deposited Successfully...\n\n";system("pause");
}
last:
Write('b');
Write('u');
admin_option();

}


int userChecker(){
       string ID;
       if(Bcounter==0)
        cout<<setw(25)<<"No User has been Added Yet"<<endl;
        else{
        reenter: cout<<"\n"<<setw(25)<<"Enter Member_Id: ";   cin>>ID;
        cin.clear(); cin.ignore(1000,'\n');


         for(int i=0;i<Ucounter;i++){

                if(ID==user[i].user_id){
                   return i;
                  break;
               }

                else if(i==Ucounter-1) {
                cout<<"The Book has either been Deleted or Doesn't Exist "<<endl;

                // choice for going back to the main menu
                goto reenter;
              }
         }
        }
}



void Backoption(char pa){
    char rchoice;

  cout<<"\n\n\n"<<"Main menu [M]      Back [B]            Exit [E]   "<<endl;
   reenter:
  cin>>rchoice ;

  if(rchoice=='M'||rchoice=='m')

     main_menu();
  else if(rchoice=='B'||rchoice=='b')
{
    if(pa=='a')
    admin_option();
      else
      user_option();

}


  else if(rchoice=='E'||rchoice=='e'){

     stop=true;
     thankyou();
     counter_updater('e');
exit (EXIT_SUCCESS);
  }
  else
    goto reenter;


}




void admin_option (){
    system ("cls");
system ("color 04");
        int choice;
    cout <<"\n\n\n\n\n\n\n\n"<<endl;
    cout << setw(40)<< char(176);
    for(int i=0; i<90; i++){cout << char(205);}
    cout << char(176)<< endl;
    system ("color F");
    cout << setw(40)<< char(176);
    cout <<setw(55)<<"Administrator option ?"<< setw(61)<< char(176)<<endl;
    HANDLE u= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(u,2);
     cout << setw(40)<< char(176)<<setw(20)<<""<<"Books"<<endl;
    cout << setw(40)<< char(176)<<setw(5)<<"1, "<<"Book issue"<<endl;
    cout << setw(40)<< char(176)<<setw(5)<<"2,"<<"Book deposit"<<endl;
     cout << setw(40)<< char(176)<<setw(5)<<"3,"<<"Add book"<<endl;;
      cout << setw(40)<< char(176)<<setw(5)<<"4,"<<"Modify book"<<endl;
       cout << setw(40)<< char(176)<<setw(5)<<"5,"<<"Delete Book"<<endl;
        cout << setw(40)<< char(176)<<setw(5)<<"6,"<<"Search specific book"<<endl;
      cout << setw(40)<< char(176)<<setw(5)<<"7,"<<"Display all books"<<endl;
      cout << setw(40)<< char(176)<<setw(5)<<"8,"<<"Display unreturned books"<<endl;
       cout << setw(40)<< char(176)<<setw(20)<<"User "<<endl;;
       cout << setw(40)<< char(176)<<setw(5)<<"9,"<<"Add user record"<<endl;
      cout << setw(40)<< char(176)<<setw(5)<<"10,"<<"Modify user record"<<endl;
       cout << setw(40)<< char(176)<<setw(5)<<"11,"<<"Delete user record"<<endl;
        cout << setw(40)<< char(176)<<setw(5)<<"12,"<<"Search specific user record"<<endl;
      cout << setw(40)<< char(176)<<setw(5)<<"13,"<<"Display all user record"<<endl;
      cout << setw(40)<< char(176)<<setw(5)<<"14,"<<"Statics "<<endl;
       cout << setw(40)<< char(176)<<setw(5)<<"15,"<<"Back to Main Menu "<<endl;
        cout << setw(40)<< char(176)<<setw(50)<<" "<<endl;
        cout << setw(40)<< char(176)<<setw(50)<<" "<<endl;
        cout << setw(40)<< char(176)<<setw(30)<<" "<<"please your choice--> "; cin >>choice;
    cout << setw(40)<< char(176);for(int i=0; i<90; i++){cout << char(205);}
    cout << char(176)<< endl;
    cout << setw(40)<< char(176);system ("cls");
    cout << setw(91)<< char(176);
HANDLE v= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(v,7);
cin.clear();
 cin.ignore(1000,'\n');

switch(choice){
case 1:
isueOrReturnbook('i');
    break;
case 2:
isueOrReturnbook('r');
    break;
case 3:
addbook();
    break;
case 4:
ModifyBookDetail();
    break;
case 5:
deleteBook();
    break;
case 6:
search1('a','a');
    break;
case 7:
all_books('a');
    break;
case 8:
unreturned_books();
    break;
case 9:
memberRegistration();
    break;

case 10:
ModifyMemberDetail();
    break;
case 11:
deleteMember();
    break;
case 12:
search_specific_user();
    break;
case 13:
all_users();
    break;
case 14:
statistics();
    break;

 case 15:
 main_menu();
    break;

}

}


void password(){

int attempt=0,ch;
    next_attempt:
   string userName,password;
         system("cls");
         string str="Login/Sign in ";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
cout<<" \n\n\n\t\t    Enter User Name -->  ";
  cin>>userName;
  cout<<" \n\n\n\t\t    Enter Password -->  " ;
  ch=getch();
  while(ch!=13){
    password.push_back(ch);
    cout<<'*';
    ch=getch();

  }

if(userName=="5m" && password=="lib123")
{
 admin_option ();
}
else{
  attempt++;
  cout<<" \n\n\n\t\t    Wrong Password or User name,  Try Again ";
  cout<<" \n\n\n\t\t    You have "<<3-attempt <<" attempts left\n\n ";
system("pause");
  if(attempt<3)
  goto next_attempt;
  else
   {
   counter_updater('e');
   exit (EXIT_SUCCESS);
   }
}

}



void unreturned_books(){

int unreturned[Ucounter],counter=0;
for (int i=0;i<Ucounter;i++){
        if (user[i].num_issued_book > 0){
      unreturned[counter]=i;
      counter++;
    }
}
if(counter>0)
display1(unreturned,counter,"LIST OF UNRETURNED BOOKS");
else
cout<<"\nThere is no unreturned book currently!!!\n";
system("pause");

}


void display1(int x[],int sizee,string str){
system("cls");
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
cout <<"\n\n\n"<<endl;cout << char(201);  for(int i=0; i<4; i++){cout << char(205);}cout << char(203); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*5*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(203); /*11*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(203); /*8*/
cout << char(187) << endl;

cout << char(186) <<setw(4)<<"No"<<char(186)  /*1*/ <<setw(8)<<"book_id"<< char(186);/*2*/
cout<<setw(15)<<"Title"<<char(186)/*3*/<<setw(15)<<"user id"<<char (186);/*4*/
cout<<setw(15)<<"Borrower"<<char(186);/*5*/
cout<<setw(18)<<"Issued date"<<char (186);/*11*/
cout<<setw(18)<<"Return date"<<char (186);/*8*/
cout<< endl;


for (int i=0;i<sizee;i++){
cout << char(201);  for(int i=0; i<4; i++){cout << char(205);}cout << char(206); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*5*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(206); /*11*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(206); /*8*/
cout << char(187) << endl;


cout << char(206) <<setw(3)<<i+1<<"."<<char(206)  /*1*/ <<setw(8)<<user[x[i]].issued_book.book_id<< char(206);/*2*/
cout<<setw(15)<<user[x[i]].issued_book.title<<char(206)/*3*/<<setw(15)<<user[x[i]].user_id<<char (206);/*4*/
cout<<setw(15)<<user[x[i]].name<<char(206);/*5*/
cout<<setw(5)<<user[x[i]].issue_date.dd<<"-"<<setw(5)<<user[x[i]].issue_date.mm<<"-"<<setw(6)<<user[x[i]].issue_date.yy<<char (186);/*11*/
if(user[i].issue_date.dd+5-30>0){
    cout<<setw(5)<<user[i].issue_date.dd+5-30<<"-"<<setw(5)<<user[i].issue_date.mm+1<<"-"<<setw(6)<<user[i].issue_date.yy<<char (186)<<endl;/*8*/
}
else{
 cout<<setw(5)<<user[i].issue_date.dd+5<<"-"<<setw(5)<<user[i].issue_date.mm<<"-"<<setw(6)<<user[i].issue_date.yy<<endl;
}
cout << char(200);  for(int i=0; i<4; i++){cout << char(205);}cout << char(202); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(202); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*5*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(186); /*11*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(186); /*8*/
cout << char(188) << endl<<endl;;

}
    Backoption('a');
}




void display2(int x[],int sizee,string str){
   system("cls");
   if(str!="0"){

    HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
   }

cout <<"\n\n\n"<<endl;cout << char(201);  for(int i=0; i<4; i++){cout << char(205);}cout << char(203); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*5*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(203); /*11*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(203); /*8*/
cout << char(187) << endl;

cout << char(186) <<setw(4)<<"No"<<char(186)  /*1*/ <<setw(8)<<"user_id"<< char(186);/*2*/
cout<<setw(15)<<"Name"<<char(186)/*3*/<<setw(15)<<"age"<<char (186);/*4*/
cout<<setw(15)<<"phone number"<<char(186);/*5*/
cout<<setw(18)<<"house number"<<char (186);/*11*/
cout<<setw(18)<<"No of issued book"<<char (186);/*8*/cout<< endl;


for (int i=0;i<sizee;i++){
cout << char(201);  for(int i=0; i<4; i++){cout << char(205);}cout << char(206); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*5*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(206); /*11*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(206); /*8*/
cout << char(187) << endl;



cout << char(206) <<setw(3)<<i+1<<"."<<char(206)  /*1*/ <<setw(8)<<user[x[i]].user_id<< char(206);/*2*/
cout<<setw(15)<<user[x[i]].name<<char(206)/*3*/<<setw(15)<<user[x[i]].age<<char (206);/*4*/
cout<<setw(15)<<user[x[i]].user_address.phone<<char(206);/*5*/
cout<<setw(15)<<user[x[i]].user_address.house_no<<char (186);/*11*/
cout<<setw(5)<<user[i].issued_book.quantity<<char (186)<<endl;/*8*/

cout << char(200);  for(int i=0; i<4; i++){cout << char(205);}cout << char(202); /*1*/ for(int i=0; i<8; i++){cout << char(205);}cout << char(202); /*2*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*3*/for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*4*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(186); /*5*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(186); /*11*/
for(int i=0; i<18; i++){cout << char(205);}cout << char(186); /*8*/
cout << char(188) << endl<<endl;;

}

}


void search_specific_user(){
int counter=0;
again:
system ("cls");
    char by;
    cout<<"search By---->[N] Name\tOR\t[I]ID\n";
    cin>>by;

if(by=='n'||by=='N'){

   cout<<"\n\n\n"<<"           "<<"Please Enter the Name of the User: "<<endl;
}

else if(by=='i'||by=='I'){

   cout<<"\n\n\n"<<"           "<<"Please Enter the ID of the User: "<<endl;
}

else
{
    cout<<"Wrong Input!!\n";
    system("pause");
    goto again;
}

int Num_search[Ucounter];
string searchName,temp_title;
cin.ignore();
getline (cin, searchName);
 transform (searchName.begin(),searchName.end(),searchName.begin(),:: tolower);

 if(by=='n'||by=='N'){

 for (int i=0;i<Ucounter;i++){
    temp_title=user[i].name;
transform (temp_title.begin(),temp_title.end(),temp_title.begin(),:: tolower);
        if (temp_title==searchName){
      Num_search[counter]=i;
      counter++;
    }
}


 }


 if(by=='i'||by=='I'){

 for (int i=0;i<Ucounter;i++){
    temp_title=user[i].user_id;
transform (temp_title.begin(),temp_title.end(),temp_title.begin(),:: tolower);
        if (temp_title==searchName){
      Num_search[counter]=i;
      counter++;
    }
}


 }




if (counter>0){
   display2 (Num_search,counter,"SEARCH RESULT...");
   Backoption('a');
}
else{

  cout<<"NO Search Result found...!\n";
   system("pause");

}

}


void all_users(){
int Num_search[Ucounter];
    for (int i=0;i<Ucounter;i++){
        Num_search[i]=i;
    }

    display2(Num_search,Ucounter,"LIST OF ALL USERS");
    Backoption('a');

}



void statistics(){

      string str="STATISTICAL DATA";
HANDLE b= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b,11);
cout<<"\n\t\t***************************************************************\n";
cout<<"\t\t*                   "<<str;
cout<<"\n\t\t***************************************************************\n";
cout<<"\n\n";
HANDLE d= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(d,7);
	int total=0;
       cout<<endl<<endl<<endl<<"-->"<<setw(45)<<"Number of books which currently exist in stalk with each Catagory "<<endl;

       for(int i=0;i<Bcounter;i++)
        total+=book[i].quantity;


cout << char(201);  for(int i=0; i<9; i++){cout << char(205);}cout << char(203); /*1*/ for(int i=0; i<9; i++){cout << char(205);}cout << char(203); /*2*/
for(int i=0; i<6; i++){cout << char(205);}cout << char(203); /*3*/for(int i=0; i<11; i++){cout << char(205);}cout << char(203); /*4*/
for(int i=0; i<11; i++){cout << char(205);}cout << char(203); /*5*/for(int i=0; i<16; i++){cout << char(205);}cout << char(203); /*6*/
for(int i=0; i<9; i++){cout << char(205);}cout << char(203); /*7*/for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*10*/cout << char(187) << endl;

cout << char(186) <<setw(4)<<" Fiction "<<char(186)  /*1*/ <<setw(8)<<" Science "<< char(186);/*2*/
cout<<setw(6)<<" Art "<<char(186)/*3*/<<setw(10)<<" Self help "<<char (186);/*4*/
cout<<setw(10)<<" Religious "<<char(186)/*5*/<<setw(8)<<" Social science "<<char (186);/*6*/
cout<<setw(8)<<" Amharic "<<char(186);/*7*/
cout<<setw(10)<<" Research Book "<<char (186);/*11*/
cout<<setw(15)<<" Programming "<<char (186)/*8*/<<setw(8)<<" Other "<<char(186)/*9*/<<setw(8)<<" Total "<<char (186)/*10*/<< endl;

cout << char(200);  for(int i=0; i<9; i++){cout << char(205);}cout << char(206); /*1*/ for(int i=0; i<9; i++){cout << char(205);}cout << char(206); /*2*/
for(int i=0; i<6; i++){cout << char(205);}cout << char(206); /*3*/for(int i=0; i<11; i++){cout << char(205);}cout << char(206); /*4*/
for(int i=0; i<11; i++){cout << char(205);}cout << char(206); /*5*/for(int i=0; i<16; i++){cout << char(205);}cout << char(206); /*6*/
for(int i=0; i<9; i++){cout << char(205);}cout << char(206); /*7*/for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(206) /*10*/<< char(188)<<endl;


// first row for a display

cout << char(201);  for(int i=0; i<9; i++){cout << char(205);}cout << char(203); /*1*/ for(int i=0; i<9; i++){cout << char(205);}cout << char(203); /*2*/
for(int i=0; i<6; i++){cout << char(205);}cout << char(203); /*3*/for(int i=0; i<11; i++){cout << char(205);}cout << char(203); /*4*/
for(int i=0; i<11; i++){cout << char(205);}cout << char(203); /*5*/for(int i=0; i<16; i++){cout << char(205);}cout << char(203); /*6*/
for(int i=0; i<9; i++){cout << char(205);}cout << char(203); /*7*/for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(203); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(203); /*10*/cout << char(187) << endl;



cout << char(206) <<setw(9)<<Fiction<<char(206)  /*1*/ <<setw(9)<<Science<< char(206);/*2*/
cout<<setw(6)<<Art<<char(206)/*3*/<<setw(11)<<Self_help<<char (206);/*4*/
cout<<setw(11)<<Religious<<char(206)/*5*/<<setw(16)<<Social_science<<char (206);/*6*/
cout<<setw(9)<<Amharic<<char(206);/*7*/
cout<<setw(15)<<Research_book<<char (186);/*11*/
cout<<setw(15)<<Programing<<char (206)/*8*/<<setw(8)<<other<<char(206)
/*9*/<<setw(8)<<total<<char (206)/*10*/<< endl;



cout << char(200);  for(int i=0; i<9; i++){cout << char(205);}cout << char(206); /*1*/ for(int i=0; i<9; i++){cout << char(205);}cout << char(206); /*2*/
for(int i=0; i<6; i++){cout << char(205);}cout << char(206); /*3*/for(int i=0; i<11; i++){cout << char(205);}cout << char(206); /*4*/
for(int i=0; i<11; i++){cout << char(205);}cout << char(206); /*5*/for(int i=0; i<16; i++){cout << char(205);}cout << char(206); /*6*/
for(int i=0; i<9; i++){cout << char(205);}cout << char(206); /*7*/for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*11*/
for(int i=0; i<15; i++){cout << char(205);}cout << char(206); /*8*/
for(int i=0; i<8; i++){cout << char(205);}cout << char(206); /*9*/for(int i=0; i<8; i++){cout << char(205);}cout << char(206) /*10*/<< char(188)<<endl;


Backoption('a');
       // system("pause");




}

void decreaseCatg(int x,int i ){

	 // below code segments decrease number of quantity in a group when a book is deleted

      if(book[i].catagory=="Fiction")
         Fiction-=x;
        else if(book[i].catagory=="Science")
            Science-=x;
        else if(book[i].catagory=="Art")
               Art-=x;
        else if(book[i].catagory=="Self help")
              Self_help-=x;
        else if(book[i].catagory=="Religious")
             Religious-=x;
        else if(book[i].catagory=="Social science")
            Social_science-=x;
        else if(book[i].catagory=="Amharic")
             Amharic-=x;
        else if(book[i].catagory=="Research book")
              Research_book-=x;
        else if(book[i].catagory=="Programming")
                Programing-=x;
        else
             other-=x;

             Write('s');

	}
void increaseCatg(int x ,int i){

 // the below statement increases quantity of books in each category;

    if(book[Bcounter].catagory=="Fiction")
         Fiction+=x;
        else if(book[Bcounter].catagory=="Science")
            Science+=x;
        else if(book[Bcounter].catagory=="Art")
               Art+=x;
        else if(book[Bcounter].catagory=="Self help")
              Self_help+=x;
        else if(book[Bcounter].catagory=="Religious")
             Religious+=x;
        else if(book[Bcounter].catagory=="Social science")
            Social_science+=x;
        else if(book[Bcounter].catagory=="Amharic")
             Amharic+=x;
        else if(book[Bcounter].catagory=="Research book")
              Research_book+=x;
        else if(book[Bcounter].catagory=="Programming")
                Programing+=x;
        else
             other+=x;


          Write('s');
}


void thankyou(){

 system("cls");

  HANDLE c= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c,6);
     system("color 3F");
cout<<"\n\t\t    %%%%%%%%%%%% %%   %%       %%        %%%%     %%   %%     %%          ";
       cout<<"\n\t\t\t %%      %%   %%     %%  %%      %% %%    %%   %%   %%            ";
       cout<<"\n\t\t\t %%      %%%%%%%    %%    %%     %%   %%  %%   %% %%             ";
       cout<<"\n\t\t\t %%      %%   %%    %% %% %%     %%    %% %%   %%   %%            ";
       cout<<"\n\t\t\t %%      %%   %%    %%    %%     %%     %%%%   %%     %%           ";


cout<<"\n\n\n\n";

cout<<"\n\t\t\t           %%     %%        %%%%         %%    %%                 ";
       cout<<"\n\t\t\t\t    %%  %%        %%    %%       %%    %%               ";
       cout<<"\n\t\t\t\t      %%%        %%      %%      %%    %%            ";
       cout<<"\n\t\t\t\t      %%          %%    %%       %%    %%            ";
       cout<<"\n\t\t\t\t      %%            %%%%         %%%%%%%%                ";
}


void counter_updater(char c){
if(c=='s'){
  ifstream coin("Bcounter.txt");
if(!coin.fail()){
  coin>>Bcounter;
coin.close();

coin.open("Ucounter.txt");
coin>>Ucounter;
coin.close();

coin.open("bid.txt");
coin>>bid;
coin.close();

coin.open("uid.txt");
coin>>uid;
coin.close();

}
else
{
    cerr<<"File not Exist!!";
    getch();
    exit(1);
}


}

if(c=='e'){

ofstream out;

out.open("Bcounter.txt");
out<<Bcounter;
out.close();

out.open("Ucounter.txt");
out<<Ucounter;
out.close();

out.open("bid.txt");
out<<bid;
out.close();

out.open("uid.txt");
out<<uid;
out.close();
}

}

void Read(){
string line,tempstr;
ifstream read;
///********************** BOOK DATA ******************//
read.open("Books.txt");
if(!read.fail()){
   int l=0;
  while(getline(read,line)){
    stringstream ss(line);
    getline(ss,book[l].book_id,',');
     getline(ss,book[l].title,',');
     getline(ss,book[l].author,',');
     getline(ss,book[l].shelf_no,',');
     getline(ss,book[l].catagory,',');
      getline(ss,tempstr,',');
    book[l].quantity = stoi(tempstr);
     getline(ss,tempstr,',');
    book[l].isbn= stoi(tempstr);
     getline(ss,tempstr,',');
    book[l].edition= stoi(tempstr);

    getline(ss,tempstr,',');
    book[l].date_of_pub.yy = stoi(tempstr);
     getline(ss,tempstr,',');
    book[l].date_of_pub.mm = stoi(tempstr);
     getline(ss,tempstr,',');
    book[l].date_of_pub.dd = stoi(tempstr);
     getline(ss,tempstr,',');
    book[l].rate = stof(tempstr);
     getline(ss,tempstr,',');
    book[l].read_freq = stoi(tempstr);

     getline(ss,tempstr,',');
        if(tempstr=="1")
        book[l].issued = 1;

    l++;
   }

}
else
{
    cerr<<"File not Exist!!";
}

read.close();

///**************** USER DATA ****************************///

read.open("Users.txt");
if(!read.fail()){
  int l=0;
  while(getline(read,line)){
    stringstream ss(line);
     getline(ss,user[l].name,',');
     getline(ss,user[l].user_id,',');
getline(ss,tempstr,',');
    user[l].age= stoi(tempstr);

    getline(ss,tempstr,',');
    user[l].user_address.house_no= stoi(tempstr);
    getline(ss,user[l].user_address.phone,',');

     getline(ss,tempstr,',');
    user[l].num_issued_book= stoi(tempstr);

    getline(ss,tempstr,',');
    user[l].issue_date.yy= stoi(tempstr);
    getline(ss,tempstr,',');
    user[l].issue_date.mm= stoi(tempstr);
    getline(ss,tempstr,',');
    user[l].issue_date.dd= stoi(tempstr);

     getline(ss,tempstr,',');
    user[l].return_date.yy= stoi(tempstr);
     getline(ss,tempstr,',');
    user[l].return_date.mm= stoi(tempstr);
     getline(ss,tempstr,',');
    user[l].return_date.dd= stoi(tempstr);

     getline(ss,tempstr,',');
    if(tempstr=="1")
    user[l].issued_book.issued=1;

    getline(ss,user[l].issued_book.book_id,',');
getline(ss,user[l].issued_book.title,',');


    l++;
  }

}

else
    cerr<<"File not Exist!!";

read.close();

///**************** STASTICAL DATA ****************************///

read.open("stastics.txt");
read>>Fiction>>Science>>Art>>Self_help>>Religious>>Social_science>>Amharic>>Research_book>>Programing>>other;
read.close();

}
void Write(char c){
ofstream write;
if(c=='b'){
   write.open("Books.txt");
for(int i=0; i<Bcounter; i++){
  write<<book[i].book_id<<","<<book[i].title<<","<<book[i].author<<","
<<book[i].shelf_no<<","<<book[i].catagory<<","<<book[i].quantity<<","<<book[i].isbn<<","
<<book[i].edition<<","<<book[i].date_of_pub.yy<<","<<book[i].date_of_pub.mm<<","<<book[i].date_of_pub.dd<<","
<<book[i].rate<<","<<book[i].read_freq<<","<<book[i].issued<<"\n";

}

}

       if(c=='u'){
        write.open("Users.txt");
    for(int j=0; j<Ucounter;j++){
        write<<user[j].name<<","<<user[j].user_id<<","<<user[j].age<<","<<user[j]. user_address.house_no<<","
<<user[j]. user_address.phone<<","<<user[j].num_issued_book<<","
<<user[j].issue_date.yy<<","<<user[j].issue_date.mm<<","<<user[j].issue_date.dd<<","
<<user[j].return_date.yy<<","<<user[j].return_date.mm<<","<<user[j].return_date.dd<<","
<<user[j].issued_book.issued<<","<<user[j].issued_book.book_id<<","<<user[j].issued_book.title<<"\n";

}

}

 if(c=='s'){
        write.open("stastics.txt");
        write<<Fiction<<" "<<Science<<" "<<Art<<" "<<Self_help<<" "<<Religious<<" "<<Social_science<<" "
        <<Amharic<<" "<<Research_book<<" "<<Programing<<" "<<other;
 }

  write.close();

}
