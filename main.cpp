// Still completing code only done the first two choices .
// fix bugs in print by id and print by name function the order is not working good so run to remember where is the problem
// just for commit
#include <iostream>
#include <string>
using namespace std ;

int added = 0 ;
const int MAX_BOOKS = 10 ;
const int MAX_USERS = 10 ;
struct Book{
    int id , total_quantity , total_borrowed ;
    string name ;
    Book(){
        total_borrowed = 0 ;
        total_quantity = 0 ;
        id = -1 ;
        name = "" ;
    }
    void read(){
        cout<<"Enter book info : id & name & total quantity :" ;
        cin>> id >> name >> total_quantity;
    }
    void display_book(){
        cout<<"id = " << id << "\tname = " << name << "\tTotal quantity = " << total_quantity << "\tTotal borrowed = " << total_borrowed << "\n" ;
    }
};

struct User{
    string name ;
    int id ;
//    int borrowed_books ids[MAX_BOOKS] ;
//    User(){
//        cout<<"Enter user name & national id : " ;
//        cin>> name >> id ;
//    }

};
struct Library{
    int total_books ;
    int total_users ;
    Book books[MAX_BOOKS] ;
//    User users[MAX_USERS] ;

    Library(){
        total_books = 0 ;
        total_users = 0 ;
    }
    void add_book( ){
        if(total_books < MAX_BOOKS){
            books[total_books++].read();
        }else{
            cout<<"The library is filled of books no additional places available\n" ;
        }
    }

    void search_by_prefix(){
        cout<<"Enter book name prefix :" ;
        string pre ; cin>> pre ;
        for(int i = 0 ; i< total_books ;i++){
            if(books[i].name.substr(0,pre.size()) == pre){
                cout<<books[i].name << "\n" ;
            }
        }
    }
    void print_by_id(){
        Book by_id[total_books] ;
        for(int i = 0 ; i < total_books ; i++){
            by_id[i] = books[i] ;
        }
        for(int i = 0 ; i < total_books ;i++){
            int j = i ;
            while(j > 0 && by_id[i].id < by_id[i-1].id){
                Book temp = by_id[i] ;
                by_id[i] = by_id[i-1] ;
                by_id[i-1] = temp ;
            }
        }
        for(int i = 0 ; i< total_books ; i++){
            by_id[i].display_book() ;
        }
    }
    void print_by_name(){
        Book by_name[total_books] ;
        for(int i = 0 ; i < total_books ; i++){
            by_name[i] = books[i] ;
        }
        for(int i = 0 ; i < total_books ;i++){
            int j = i ;
            while(j > 0 && by_name[i].name.compare(by_name[i-1].name) < 0){
                Book temp = by_name[i] ;
                by_name[i] = by_name[i-1] ;
                by_name[i-1] = temp ;
            }
        }
        for(int i = 0 ; i< total_books ; i++){
            by_name[i].display_book() ;
        }
    }
};


void choices(){
    cout<<"Library Menu: \n" ;
    cout<<"1) Add Book\n" ;
    cout<<"2) Search books by prefix \n" ;
    cout<<"3) Print who borrowed book by name\n" ;
    cout<<"4) Print library by id \n" ;
    cout<<"5) Print library by name \n" ;
    cout<<"6) Add user \n" ;
    cout<<"7) User borrow book \n" ;
    cout<<"8) User return book \n" ;
    cout<<"9) Print users \n" ;
    cout<<"10) Exit \n" ;
}
void library_system(){
    choices();
    Library lib ;
    while(true){
        cout << "Enter your menu choice [1 - 10] : \n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            lib.add_book();
        } else if (choice == 2) {
            lib.search_by_prefix();
        }
//        else if (choice == 3) {
//            print_borrow_users();
//        }
        else if (choice == 4) {
            lib.print_by_id();
        }
        else if (choice == 5) {
            lib.print_by_name();
        }
//        else if (choice == 6) {
//            add_user();
//        } else if (choice == 7) {
//            borrow_book();
//        } else if (choice == 8) {
//            return_book();
//        } else if (choice == 9) {
//            print_users();
//        }
        else {
            return;
        }
    }
}
int main() {
    library_system() ;
    return 0;
}
