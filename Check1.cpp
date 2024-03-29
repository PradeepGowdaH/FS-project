#include<fstream>
#include<iostream>
#include<cstring>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

using namespace std;

fstream fp,fp1;
char username[15], password[10], phone[10], address[50];
char pizza1[]="Chicken-Fazita" ,pizza2[]="Chicken-Bar-BQ" ,pizza3[]="Peri-Peri" ,pizza4[]="Creamy-Max";
char roll1[]="Chicken-Chatni-Roll", roll2[]="Chicken-Mayo-Roll", roll3[]="Veg-Roll-With-Fries";
char bur1[]="Zinger-Burger",bur2[]="Chicken-Burger",bur3[]="Paneer-Burger";
char sand1[]="Club-Sandwich", sand2[]="Chicken-Crispy-Sandwich", sand3[]="Extream-Veg-Sandwich";
char bir1[]="Chicken-Biryani", bir2[]="Prawn-Biryani", bir3[]="Paneer-Biryani", gotostart;
int choice=0,quantity,pchoice,pchoice1;
class Order {
	private: 
		char name[30],phone[10],city[20],order[50],price[5];
	public:
		void search();
		void orderItem(char [],char []);
		bool validateLogin(char [],char []);
		void saveSignup(char[],char[],char[],char[]);
		void bill(int,int,char[],char[],char[]);
		void previousOrder(char [],char []);
};

void Order::previousOrder(char username[],char password[]){
	        fp1.open("Orders.txt",ios::in);
			char buffer1[300],buffer2[300],temp[300],temp2[300];
			char *t;
			char *p;
			strcpy(buffer1,username);
			strcat(buffer1,password);
			while(!fp1.fail())
	        {
			fp1>>buffer2;
			strcpy(temp,buffer2);
			strcpy(temp2,buffer2);
			t=strtok(temp,"|");
			if((strcmp(buffer1,t)==0))
			{
				p=strtok(temp2,"|");
				cout<<"Your previous order :\n";
				p=strtok(NULL,"|");
				cout<<"Quantity: "<<p<<endl;
				p=strtok(NULL,"|");
				cout<<"Total price: "<<p<<endl;
				p=strtok(NULL,"|");
				cout<<"Item name: "<<p<<endl;
			}
		    }
}

void Order::bill(int quantity, int choice, char fooditem[], char username[], char password[])
{
			cout<<"\t\t\t--------Your Order---------\n";
			cout<<""<<quantity<<" "<<fooditem;
			cout<<"\nYour Total Bill is "<<choice<<".00\nYour Order Will be delivered in 40 Minutes";
			cout<<"\n\nThank you For Ordering From Carl's Jr. Fast Food\n";		
			char buffer2[200];
			fp1.open("Orders.txt",ios::app);
            strcpy(buffer2,username);
            strcat(buffer2,password);
            strcat(buffer2,"|");
            char str1[10]={0};
			itoa(quantity,str1,10);
			char cstr1[10]={0};
			itoa(choice,cstr1,10);
			strcat(buffer2,str1);
			strcat(buffer2,"|");
			strcat(buffer2,cstr1);
			strcat(buffer2,"|");
			strcat(buffer2,fooditem);
			strcat(buffer2,"|");
			fp1<<buffer2;
			fp1<<"\n";
			fp1.close();
}

void Order::orderItem(char username[],char  password[])
{
	cout<<"\t\t\t----------Peter's Jr. Fast Food-----------\n\n";
	cout<<"Please Enter Your Name: (Blank spaces are not allowed)\n";
	cin>>name;
	beginning:
	cout<<"Hello "<<name<<", What would you like to order?\n\n";
	cout<<"\t\t\t\t--------Menu--------\n\n";
	cout<<"1) Pizzas\n";
	cout<<"2) Burgers\n";
	cout<<"3) Sandwich\n";
	cout<<"4) Rolls\n";
	cout<<"5) Biryani\n\n";
	cout<<"\nPlease enter your Choice: ";
	cin>>choice;
	
	if(choice==1)
	 {
		cout<<"\n1) "<<pizza1<<"\n";
		cout<<"2) "<<pizza2<<"\n";
		cout<<"3) "<<pizza3<<"\n";
		cout<<"4) "<<pizza4<<"\n";
		cout<<"\nPlease Enter which Flavour would you like to have?:";
		cin>>pchoice;
	 if(pchoice>=1 && pchoice<=4)
		{
			cout<<"\n1) Small Rs.250\n"<<"2) Regular Rs.500\n"<<"3) Large Rs.900\n";
			cout<<"\nChoose Size Please:";
			cin>>pchoice1;
			if(pchoice1>=1 && pchoice1<=3)
		   {
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 250*quantity;
			break;
			case 2: choice = 500*quantity;
			break;
			case 3: choice = 900*quantity;
			break;
			}
		   }
		   else
		   cout<<"Invalid Choice\n\n";
		switch (pchoice1)
		{
			 case 1:
			 bill(quantity,choice,(char *)"Chicken-Fazita",username,password);
			 break;
			 case 2:
			 bill(quantity,choice,(char *)"Chicken-Bar-BQ",username,password);
			 break;
			 case 3:
			 bill(quantity,choice,(char *)"Peri-Peri",username,password);
			 break;
			 case 4:
			 bill(quantity,choice,(char *)"Creamy-Max",username,password);
			 break;
			 default : cout<<"Invalid Choice\n\n";
		}
			cout<<"Would you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
			}
			else
			  return;
	}
	else
	{
		cout<<"Invalid Choice\n\n";
		goto beginning;
	}
}
	else if(choice==2)
	 {
		cout<<"\n1 "<<bur1<<" Rs.180"<<"\n";
		cout<<"2 "<<bur2<<" Rs.150"<<"\n";
		cout<<"3 "<<bur3<<" Rs.160"<<"\n";
		cout<<"\nPlease Enter which Burger you would like to have?: ";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 180*quantity;
			break;
			case 2: choice = 150*quantity;
			break;
			case 3: choice = 160*quantity;
			break;
			default : cout<<"Invalid Choice\n\n";
			}
			switch (pchoice1)
			{
			 case 1:
			 bill(quantity,choice,(char *)"Zinger-Burger",username,password);
			 break;
			 case 2:
			 bill(quantity,choice,(char *)"Chicken-Burger",username,password);
			 break;
			 case 3:
			 cout<<"\t\t--------Your Order---------\n";
			 bill(quantity,choice,(char *)"Paneer-Burger",username,password);
			 break;
			 default : cout<<"Invalid Choice\n\n";
			}
			cout<<"\nWould you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
			}
			else
			  return;
 			}
 			else
	{
		cout<<"Invalid Choice\n\n";
		goto beginning;
	}
	}
	else if(choice==3)
	 {
		cout<<"\n1  "<<sand1<<" Rs.240"<<"\n";
		cout<<"2  "<<sand2<<" Rs.160"<<"\n";
		cout<<"3  "<<sand3<<" Rs.100"<<"\n";
		cout<<"\nPlease Enter which Sandwich you would like to have?:";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 240*quantity;
			break;
			case 2: choice = 160*quantity;
			break;
			case 3: choice = 100*quantity;
			break;
			default : cout<<"Invalid Choice\n\n";
			}
			switch (pchoice1)
			{
			 case 1:
			 bill(quantity,choice,(char *)"Club-Sandwich",username,password);
			 break;
			 case 2:
			 bill(quantity,choice,(char *)"Chicken-Crispy-Sandwich",username,password);
			 break;
			 case 3:
			 bill(quantity,choice,(char *)"Extream-Veg-Sandwich",username,password);
			 break;
			 default : cout<<"Invalid Choice\n\n";
			}
			cout<<"Would you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
			}
			else
			  return;
			}
			else
	{
		cout<<"Invalid Choice\n\n";
		goto beginning;
	}
			}
		else if(choice==4)
	 {
		cout<<"\n1 "<<roll1<<" Rs.150"<<"\n";
		cout<<"2 "<<roll2<<" Rs.100"<<"\n";
		cout<<"3 "<<roll3<<" Rs.120"<<"\n";
		cout<<"\nPlease Enter which you would like to have?: ";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nHow Much Rolls Do you want: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 150*quantity;
			break;
			case 2: choice = 100*quantity;
			break;
			case 3: choice = 120*quantity;
			break;
			default : cout<<"Invalid Choice\n\n";
			}
			switch (pchoice1)
			{
			 case 1:
			 bill(quantity,choice,(char *)"Chicken-Chatni-Roll",username,password);
			 break;
			 case 2:
			 bill(quantity,choice,(char *)"Chicken-Mayo-Roll",username,password);
			 break;
			 case 3:
			 bill(quantity,choice,(char *)"Veg-Roll-With-Fries",username,password);
			 break;
			 default : cout<<"Invalid Choice\n\n";
			}
			cout<<"Would you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
			}
			else
			  return;
			}
			else
	{
		cout<<"Invalid Choice\n\n";
		goto beginning;
	}
        }
    else if(choice==5)
	 {
		cout<<"\n1 "<<bir1<<" Rs.160"<<"\n";
		cout<<"2 "<<bir2<<" Rs.220"<<"\n";
		cout<<"3 "<<bir3<<" Rs.140"<<"\n";
		cout<<"\nPlease Enter which Biryani you would like to have?:";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 160*quantity;
			break;
			case 2: choice = 220*quantity;
			break;
			case 3: choice = 140*quantity;
			break;
			default : cout<<"Invalid Choice\n\n";
			}
			switch (pchoice1)
			{
			 case 1:
			 bill(quantity,choice,(char *)"Chicken-Biryani",username,password);
			 break;
			 case 2:
			 bill(quantity,choice,(char *)"Prawn-Biryani",username,password);
			 break;
			 case 3:
			 bill(quantity,choice,(char *)"Paneer-Biryani",username,password);
			 break;
			 default : cout<<"Invalid Choice\n\n";
			}
			cout<<"Would you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
			}
			else
			  return;
			}
		}

			else
			{
				cout<<"Please Select Right Option: \n";
				cout<<"Would You like to Start the program again? Y / N: " ;
				cin>>gotostart;

				if(gotostart=='Y' || gotostart=='y')
				{
				  goto beginning;
		    	}
		    	else
			      return;
			}
     getch();
}

bool Order::validateLogin(char username[],char password[]) {
	fp.open("Customers.txt",ios::in);
	char buffer[143],temp[143];
	char *usr;
	char *pass;
	while(!fp.fail())
	{
		fp>>buffer;
		strcpy(temp,buffer);
 		usr=strtok(temp,"|");
 		pass=strtok(NULL,"|");
    if ( (strcmp(username,usr)==0) && (strcmp(password,pass)==0) ) {
        return true;
    }
  }
    return false;
}

void Order::saveSignup(char username[], char password[], char address[], char phone[]) {
    char buffer[143];
    cout << "Signup successful! Username: " << username << endl;
    fp.open("Customers.txt",ios::app);
    strcpy(buffer,username);
    strcat(buffer,"|");
    strcat(buffer,password);
    strcat(buffer,"|");
	strcat(buffer,phone);
    strcat(buffer,"|");
    strcat(buffer,address);
    strcat(buffer,"|");
    fp << buffer;
    fp << "\n";
    fp.close();
}
		
int main()
{
	Order O1;
	char loginpage;
	loginpage:
	cout<<"\n\t\t\t----------Welcome to Peter's Jr. Fast Food-----------\n\n";
	cout<<"Press 1> To Login\n";
	cout<<"Press 2> To Sign-up\n";
	cout<<"Press 3> To Exit\n";
	cout<<"Please enter your choice....  ";
	int ch;
	cin>>ch;
	if(ch==1)
	{
		cout << "Login System\n";
		cout<<"Username: (Blank spaces are not allowed)\n";
    	cin>>username;
    	cout<<"Password: ";
    	cin>>password;
    	if(O1.validateLogin(username,password)) 
		{
			int choice;
        	cout << "Login successful!\n";
        	cout << "Press 1 to view your previous order or Press 2 to place a new order\n";
        	cin>>choice;
        	if(choice==1)
        	{
        		O1.previousOrder(username,password);
			}
			else if(choice==2)
			{
				O1.orderItem(username,password);
			}
			else
			cout<<"Invalid input\n";
    	}
		else 
		{
        cout<<"Invalid username or password. Login failed.\n";
        cout<<"Please try again or Register as a new customer";
        goto loginpage;
    	}
	}
	else if(ch==2)
	{
		cout<<"Signup System\n";
    	cout<<"Username: (Blank spaces are not allowed)\n";
    	cin>>username;
    	cout<<"Password: ";
    	cin>>password;
    	cout<<"Phone: ";
    	cin>>phone;
    	cout<<"Delivery address: ";
    	cin>>address;
    	O1.saveSignup(username, password, address, phone);
		O1.orderItem(username,password);
	}
	else
	{
		cout<<"Exiting.....\n";
		return 0;
	}
}
