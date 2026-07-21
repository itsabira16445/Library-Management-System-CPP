#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Book
{
    private:
    int BookID;
    string BookName;
    int bookQuantity;
    string authorName;
    public:
    void addBook()
    {
        int option;
        do{
        cout<<"Enter Book ID:"<<endl;
        cin>>BookID;
        cin.ignore();
        cout<<"Enter Book Name:"<<endl;
        getline(cin,BookName);
        cout<<"Enter Book Quantity:"<<endl;
        cin>>bookQuantity;
        cin.ignore();
        cout<<"Enter Author Name:"<<endl;
        getline(cin,authorName);
        cout<<"\nBooks Added Successfully!\n";
        cout<<endl;
        ofstream fout("books.txt",ios::app);
        fout<<"-------------"<<endl;
        fout<<"Book ID      :"<<BookID<<endl;
        fout<<"Book Name    :"<<BookName<<endl;
        fout<<"Book Quantity:"<<bookQuantity<<endl;
        fout<<"Author Name  :"<<authorName<<endl;
        fout<<"--------------"<<endl;
        fout.close();
        cout << "\nDo you want to add another Book?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter Choice: ";
        cin >> option;
        }while(option==1);

    }
    void displayBook()
    {
        string line;
        ifstream fin("books.txt",ios::in);
       if(!fin)
        {
            cout<<"File Not Found!"<<endl;
            return ;
        }
        if(fin.peek()==EOF)
        {
            cout<<"No Books Found!"<<endl;
            return;
        }
         while(getline(fin,line))
        {
            cout<<line<<endl;
        }
        fin.close();


    }
    void searchBook()
    {
        string line;
        bool found=false;
       ifstream fin("books.txt");
       if(!fin)
       {
        cout<<"File Not Found!"<<endl;
        return;
       }
       cout<<"Enter Book ID:"<<endl;
       cin>>BookID;
       while(getline(fin,line))
       {
        if(line.find(to_string(BookID))!=string::npos)
        {
            cout<<"\nBook Found Successfully!"<<endl<<endl;
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            found=true;
            break;
        }
       }
       if(!found)
       {
        cout<<"Book Not Found!"<<endl;
       }
       fin.close();

    }
    void borrowBook()
    {
        string line;
        int borrowQ;
        cout<<"Enter Book ID:"<<endl;
        cin>>BookID;
        bool found=false;
        ifstream fin("books.txt");
        if(!fin)
        {
            cout<<"File Not Found!"<<endl;
            return;
        }
        while(getline(fin,line))
        {
        if(line.find(to_string(BookID))!=string::npos)
        {
         cout<<"\nBook Found Successfully!"<<endl<<endl;
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            cout<<"\nEnter Quantity to Borrow"<<endl;
            cin>>borrowQ;
            if(borrowQ>0)
            {
                cout<<"Book Borrowed Successfully!"<<endl<<endl;
            }
            else
            {
                cout<<"Invalid Quantity!"<<endl;
            }
            found=true;
            break;
        }
        }
    if(!found)
       {
        cout<<"Book Not Found!"<<endl;
       }
       fin.close();
        }
       
    void returnBook()
    {
        string line;
        int returnQ;
        cout<<"Enter Book ID:"<<endl;
        cin>>BookID;
        bool found=false;
        ifstream fin("books.txt");
        if(!fin)
        {
           cout<<"File Not Found!"<<endl;
           return;
        }
        while(getline(fin,line))
        {
        if(line.find(to_string(BookID))!=string::npos)
        {
         cout<<"\nBook Found Successfully!"<<endl<<endl;
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            
            getline(fin,line);
            cout<<line<<endl;
            cout<<"\nEnter Quantity to Return"<<endl;
            cin>>returnQ;
            if(returnQ>0)
            {
                cout<<"Book Returned Successfully!"<<endl<<endl;
            }
            else
            {
                cout<<"Invalid Quantity!"<<endl;
            }
            found=true;
            break;
        }
        }
    if(!found)
       {
        cout<<"Book Not Found!"<<endl;
       }
       fin.close();
        }

};

int main()
{
    int choice;
    Book b;
    do
    {
    cout<<"========================="<<endl;
    cout<<"Library Management System"<<endl;
    cout<<"========================="<<endl;
    cout<<"1.Add Book       :"<<endl;
    cout<<"2.Display Book   :"<<endl;
    cout<<"3.Search Book    :"<<endl;
    cout<<"4.Borrow Book    :"<<endl;
    cout<<"5.Return Book    :"<<endl;
    cout<<"6.Exit           :"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Enter Your Choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        b.addBook();
        break;
        case 2:
        b.displayBook();
        break;
        case 3:
        b.searchBook();
        break;
        case 4:
        b.borrowBook();
        break;
        case 5:
        b.returnBook();
        break;
        case 6:
        cout<<"Thank you for using Library Management System!"<<endl;
        break;
        default:
        cout<<"Invalid Choice! Please Try Again."<<endl;
    }
     }while(choice!=6);
    return 0;
}