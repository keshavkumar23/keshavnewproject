#include<bits/stdc++.h>
using namespace std;
static int ind1=0;
   /* -------------------------------------------X------------------------------------------------------
    lavish program */
    class Library_database{
   vector<string>List_of_book{"AMAR CHITRA KATHA","BRITANNICA DISCOVERY LIBRARY","HARRY POTTER","ANIMAL ENCYCLOPEDIA","SCIENCE ENCYCLOPEDIA","THE WILD OF ANIMALS"};
    public:
    void Add(string str){
       List_of_book.push_back(str);
    }
    void Update(string newstr,string toupdate){
        for(int i=0;i<List_of_book.size();i++){
            if(List_of_book[i]==toupdate){
                  List_of_book[i]=newstr;
            }
        }
    }
    
    void Display(){
        for(int i=0;i<List_of_book.size();i++){
            cout<<"Book number "<<i+1<<" is "<<List_of_book[i]<<endl;
        }
    }
    void Search(string str){
         static int flag=0;
        for(int i=0;i<List_of_book.size();i++){
            if(List_of_book[i]==str){
                cout<<"Book "<<str<<" is in the database\n";
                flag=1;
            }
            
        }
        if(flag==0)
        {
            cout<<"Book"<<str<<"is not in the Database\n"<<endl;
        }
        flag=0;
      
    }
    void Delete(string str){
        for(int i=0;i<List_of_book.size();i++){
            if(str==List_of_book[i]){
            List_of_book.erase(List_of_book.begin()+i);
        }
    }
    }
    void show_details()
    {
        cout<<"The Book info is"<<List_of_book[ind1];
    }
};
//-------------------------------------------KANISHK------------------------------------------------------
class Book
{public:
vector<int>issue_date;
vector<int>due_date;
//   due_date.push_back();
int a,b;
	string feed,Title;
	vector<string>feed1;
	public:
			time_t now=time(0);
			tm *ltm=localtime(&now);
		void Show_duedt()
		{
			cout<<"enter your issue date of book"<<endl;
			cin>>a;
			issue_date.push_back(a);
			b=a+15;
			if(b>31)
			{
				b=b%31;
				if(b==0)
				{
					++b;
				}
			}
			
			cout<<"your due date of book is:"<<b<<endl;
			due_date.push_back(b);
		}
		void Reservation_status()
		{
			
			
			//cout<<"enter current date"<<endl;
			if(ltm->tm_mday>=a&&ltm->tm_mday<b)
			{
				cout<<"book is alloted to you"<<endl;
			}
			else
			{
				cout<<"please return the book,if done already ignore the message"<<endl;
			}
			    
	   }
	   void Feedback()
	   {
	   	cout<<"enter your valuable feedback"<<endl;
	    cin>>feed;
	   	cout<<"thank you"<<endl;
	   	
	   	feed1.push_back(feed);
	   	//cout<<feed<<endl;
	   
	   	if(ltm->tm_mday>=b||ltm->tm_mday<=a)
	   	   {
	   		cout<<"you may renew your book,if you want"<<endl;
		   }
		   else
		   {
		   	cout<<"no need for renewing"<<endl;
		   }
		   
	   }
	   void Book_request()
	   {
	   	cout<<"enter the book you want"<<endl;
	   	getline(cin,Title);
	   	transform(Title.begin(),Title.end(),Title.begin(),::toupper);
	   	Library_database lb1;
	   	lb1.Search(Title);
	   }
	    friend class Account;	
};
//-----------------------------------------------------------------------------Lagan---------------------------------------------------------------------------------------------------------------------
class Account{
      vector<int>no_borrowed_books={3,4};
      vector<int> no_reserved_books={1,2};
      vector<int> no_returned_books={2,1};
      vector<int> no_lost_books={0,1};
      int fine_amount;
      public:
     void Calculate_fine()
      {
          cout<<"Enter the present date"<<endl;
          int p_date;
          cin>>p_date;
          int j1;
          Book lavi1;
          fine_amount=((p_date) - (lavi1.due_date[ind1]))*50;
          cout<<"your fine amount is with charge of 5 per date"<<" "<<fine_amount<<endl;
      }
};

//-------------------------------------------KESHAV program-----------------------------------------------------

//staff is a user,student is a person
class User{
  vector <string> name={"Ram","Shyam"};
  vector <string> id={"101","102"};
    public:
    void verify(string un1,string ut1)
    {
        if(ut1=="STAFF")
        {
            for(int i =0;i<2;i++)
            {
              if(un1==name[i])
              {
                  cout<<"Your are succesully verified as a staff"<<endl;
                  ind1=1;
              }
            }
               
        }
        else if (ut1=="STUDENT")
        {
            for(int i=0;i<2;i++)
            {
              if(name[i]==un1)
              {
                 cout<<"Your are succesully verified as a student"<<endl;
                 ind1=i;
              }
         
            }
        }
    }
    void check_account()
    {
        Book b23;
        b23.Show_duedt();
        Account A23;
        A23.Calculate_fine();
    }
    void get_book_info()
    {
      Library_database LDB45;
      LDB45.show_details();
    }
    
};
class Student:public User {
  string Class="CS2";  
  public:

};
class Staff:public User{
    string dept="jhatu";
    public:

};
string encrypted(string e1){
    int j=0;
    while(j<e1.length()){
       e1.at(j)=e1.at(j)+3;
       j++;
    }
    return e1;
}
//--------------------------------------------divyansh-------------------------
class Librarian_{
    private:
    // static int lb_count;
    string name[2]={"JAI","JAGDISH"};
     int id[2]={111,120};
     string password[2]={"DEF","CBA"};
     public:
     bool verify_librarian(string uname,string pwd){
        int k;
      
         cout<<"Enter Your ID \n";
         cin>>k;
         for(int i =0;i<2;i++){
            if(name[i]==uname && pwd==password[i]){
               return true;
               break;
            }
         }
         return false;

     }
     bool Search(){
          return true;
     }

};
// int Librarian_::lb_count=2;
class Library_Management_System{
    private:
    string UserType,Username,password;
    public:
    void Login();
    void Register();
    void Logout();
   

};
void Library_Management_System::Login(){
        cout<<"Enter the user type(Staff,student or librarian) \n";
        cin>>UserType;
       transform(UserType.begin(),UserType.end(),UserType.begin(),::toupper);
        cout<<"Enter username \n";
        cin>>Username;
         transform(Username.begin(),Username.end(),Username.begin(),::toupper);
        cout<<"Enter Your Password \n";
        cin>>password;
        string p=password;
      p=encrypted(p);
      
       Librarian_ l1;
        if("LIBRARIAN"==UserType){
             if(l1.verify_librarian(Username,p)){
                cout<<"You are verified \n";
             }else{
                cout<<"May be one of this (ID ,User Name,Password) is wrong \n";
             }
             
        }else if("STUDENT"==UserType){
            Student st ;
             st.verify(Username,Username);
            
        }else if("STAFF"==UserType){
           
            
        }
    }
    void Library_Management_System::Register(){
        cout<<"Enter the name of user \n";
        cin>>Username;
        cout<<"Enter the id of user \n";
        cin>>password;
    }
int main()
{
//            time_t now=time(0);
//			tm *ltm=localtime(&now);
//	s		cout<<"day"<<ltm->tm_mday<<endl;

	Book b;
	Library_Management_System ll1;
        ll1.Login();
	return 0;
}
