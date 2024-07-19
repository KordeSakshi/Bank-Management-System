#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;


class Bank
{
	private:
		int pin_code;
		float balance;
		string pass,id,First_name,Middle_name,Last_name,Address,phone;
		
		
	public:
		void menu();
		void Bank_management();
		void ATM_management();
		void New_User();
		void Already_User();
		void Withdraw();
		void Deposite();
		void Tranfer();
		void Payment();
		void Search_User_Records();
		void Edit();
		void Delete();
};
////////////////////////////////////////////

void Bank :: menu()
{
	start_over:
	int choice;
	char character,character1;
	string pass,pin,email;
	system("cls");
	cout<< "\n\n\t\t\tControl Panel";
	cout<< "\n\n 1. Bank management";
	cout<< "\n 2. ATM management";
	cout<< "\n 3. Exit";
	cout<<"\n\nEnter your choice : ";
	cin>> choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\n\nLogin Account";
			cout<<"\n\nEnter your Email : ";
			cin>>email;
			
			cout<<"\n\nEnter Pin : ";
			for(int i=1;i<=5;i++)
			{
				character= getch();
				pin=pin+character;
				cout<<"*";	
			}
			
			cout<<"\n\nEnter Password : ";
			for(int j=1;j<=5;j++)
			{
				character1= getch();
				pass=pass+character1;
				cout<<"*";	
			}
			
			
			if(email == "gaurav" && pin == "12345" && pass == "54321")
			{
				Bank_management();
			}
			else
			{
				cout<<"\n\n Your Email / pin / password is wrong...";
			}
			break;
			
		case 2:
			ATM_management();
			break;
			
		case 3:
			exit(0);
			
		default:
			cout<< "Invalid value... Please try again... ";			
	}
	getch();
	goto start_over;
}




void Bank::Bank_management()
{
	start_over:
	system("cls");
	int choice;
	cout<<"\n\n\t\t\tBANK Management System";
	cout<<"\n\n1. New User";
	cout<<"\n2. Already User";
	cout<<"\n3. Deposite Option";
	cout<<"\n4. Withdraw Option";
	cout<<"\n5. Tranfer Option";
	cout<<"\n6. Payment Option";
	cout<<"\n7. Search User Records";
	cout<<"\n8. Edit User Records";
	cout<<"\n9. delete User Records";
	cout<<"\n10. Show All records";
	cout<<"\n11. Payment All Records";
	cout<<"\n12. Go Back";
	cout<<"\n\nEnter your choice : ";
	cin>> choice;
	
	switch(choice)
	{
		case 1:
			New_User();
			break;
			
		case 2:
			Already_User();
			break;
			
		case 3:
			Deposite();
			break;
			
		case 4:
			Withdraw();
			break;
			
		case 5:
			Tranfer();
			break;
			
		case 6:
			Payment();
			break;
			
		case 7:
			Search_User_Records();
			break;
			
		case 8:
			Edit();
			break;
			
		case 9:
			Delete();
			break;
			
		case 10:
			break;
			
		case 11:
			break;								
			
		case 12:
			menu();
			break;
			
		default:
			cout<< "Invalid value... Please try again... ";
							
	}
	getch();
	goto start_over;
	
}



void Bank::ATM_management()
{
	start_over:
	system("cls");
	int choice;
	cout<<"\n\n\t\t\tATM Management System";
	cout<<"\n\n1. User Login & check balance";
	cout<<"\n2. Withdraw Amount";
	cout<<"\n3. Account Details";
	cout<<"\n4. Go Back";
	cout<<"\nEnter your choice : ";
	cin>> choice;
	
	switch(choice)
	{
		case 1:
			break;
			
		case 2:
			break;
			
		case 3:
			break;
			
		case 4:
			menu();
			break;
			
		default:
			cout<< "Invalid value... Please try again... ";
							
	}
	getch();
	goto start_over;
	
	
}

//////////////////-----Methods----//////////////////////////

void Bank::New_User()
{
	start:
	system("cls");
	fstream file;   //// Declare a file stream object
	int pin_code1;
	float balance1;
	string pass1,id1,First_name1,Middle_name1,Last_name1,Address1,phone1;
	
	cout<<"\n\nAdd New User";
	cout<<"\n\nUser ID : ";
	cin>>id;
	cout<<"\n First Name : ";
	cin>>First_name;
	cout<<"\nMiddle Name : ";
	cin>>Middle_name;
	cout<<"\nLast Name : ";
	cin>>Last_name;
	cout<<"\nEnter your address : ";
	cin>>Address;
	cout<<"\nEnter your pin code : ";
	cin>>pin_code;
	cout<<"\nEnter Password : ";
	cin>>pass;
	cout<<"\nEnter Phone Number : ";
	cin>>phone;
	cout<<"\nCurrent Balance : ";
	cin>>balance;
	
	file.open("Bank.txt",ios::in);  // Attempt to open the file for input
	if(!file)
	{
		file.open("Bank.txt",ios::app|ios::out);   // Open the file for appending and output
		file<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
		file.close();
		
	}
	else
	{
		file>>id1>>First_name1>>Middle_name1>>Last_name1>>Address1>>pin_code1>>pass1>>phone1>>balance1;
		while(!file.eof())
		{
			if(id1 == id)
			{
				cout<<"\n\nUser ID Already Exists...";
				getch();
				goto start;
			}
			file>>id1>>First_name1>>Middle_name1>>Last_name1>>Address1>>pin_code1>>pass1>>phone1>>balance1;

		}
		file.close();
		file.open("Bank.txt",ios::app|ios::out); 
		file<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
		file.close();
	}
	cout<<"\n\nNew User Account Created Successfully...!";	
}





void Bank::Already_User()
{
	system("cls");
	fstream file;
	string test_id;
	int found=0;
	cout<<"\n\nAlready User Account";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout<<"\nFile opening error...";
	}
	else
	{
	    cout << "\n\nUser ID : ";
	    cin >> test_id;
	
	    bool userFound = false; // Initialize a flag to track if the user is found
	
	    // Read the file line by line until the end
	    //file.open("Bank.txt",ios::in);
	    file>>id>>First_name>>Middle_name>>Last_name>>Address>>pin_code>>pass>>phone>>balance;
	    while (!file.eof())
	    {
	    	
	        if (test_id == id)
	        {
	            system("cls");
	            cout << "\n\nAlready User Account";
	            cout << "\n\nUser ID : " << id << "   Pin Code : " << pin_code << "    Password : " << pass;
	            userFound = true; // Set the flag indicating the user is found
	            break; // No need to continue searching, exit the loop
	        }
	        file>>id>>First_name>>Middle_name>>Last_name>>Address>>pin_code>>pass>>phone>>balance;
	    }
	
	    file.close(); // Close the file after reading
	
	    if (!userFound)
	    {
	        cout << "\nUser ID Not Found... ";
	    }
	}
}




void Bank::Deposite()
{
	fstream file,file1;
	string test_id;
	float deposite;
	int found=0;
	system("cls");
	cout<<"\n\nDeposite Amount Option";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout << "Error opening file!";
	}
	else
	{
	    cout << "\n\nUser ID : ";
	    cin >> test_id;
	
	    file1.open("Bank1.txt",ios::app|ios::out);
	    file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
	   
	    while (!file.eof())
	    {
	        if (test_id == id)
	        {
	        	cout<<"\nAmount to be Deposited";
	        	cin>>deposite;
	        	balance=balance+deposite;
	    		file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
	            found++;
	            cout<<"\n\nYour amount : "<<deposite<<"Successfully Deposited"; 
	        }
	        else
	        {
	     		file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
			}
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
	    }
	
	    file.close(); // Close the file after reading
	    file1.close(); 
	    remove("Bank.txt");
	    rename("Bank1.txt","Bank.txt");
		
		if(found == 0)
		{
			cout<<"\n\nUser ID can't Found...";
		}
	}
}


void Bank::Withdraw()
{
	fstream file,file1;
	string test_id;
	float withdraw;
	int found=0;
	system("cls");
	cout<<"\n\nWithdraw Amount Option";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout << "Error opening file!";
	}
	else
	{
	    cout << "\n\nUser ID : ";
	    cin >> test_id;
	
	    file1.open("Bank1.txt",ios::app|ios::out);
	    file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
	   
	    while (!file.eof())
	    {
	        if (test_id == id)
	        {
	        	cout<<"\nAmount to be Withdraw";
	        	cin>>withdraw;
	        	if(withdraw<=balance)
	        	{
	        		balance=balance-withdraw;
	        		file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
	            	cout<<"\n\nYour amount : "<<withdraw<<"Successfully Withdraw"; 
				}
	        	else
	        	{
	        		cout<<"\nYour current balance"<<balance<<"is less..";
				}
	        	found++;
	            
	        }
	        else
	        {
	       		file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
			}
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
	    }
	
	    file.close(); // Close the file after reading
	    file1.close(); 
	    remove("Bank.txt");
	    rename("Bank1.txt","Bank.txt");
		
		if(found == 0)
		{
			cout<<"\n\nUser ID can't Found...";
		}
	}
}


void Bank::Tranfer()
{
	fstream file,file1;
	string s_id,r_id;
	float amount;
	int found = 0,crt_amt=0;
	system("cls");
	cout<<"\n\nPayment Tranfer Option";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout<<"\nFile Opening Error";
	}
	else
	{
		cout<<"\nEnter  Sender's user ID for transaction";
		cin>>s_id;
		cout<<"\nEnter Receiver's user ID for transaction";
		cin>>r_id;
		cout<<"\n\nEnter Amount to be transfer : ";
		cin>>amount;
		//file.open("Bank.txt",ios::in);
		file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		while(!file.eof())
		{
			if(s_id == id)
			{
				found++;
				if(amount<=balance)
				{
					crt_amt++;
					break;
				}
				break;
			}
//			else if(r_id == id )//&& amount<=balance)
//			{
//				found++;
//			}
			
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		}
		file.close();
		
		file.open("Bank.txt",ios::in);
		file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		while(!file.eof())
		{
			if(r_id == id)
			{
				found++;
				break;
			}
//			else if(r_id == id )//&& amount<=balance)
//			{
//				found++;
//			}
			
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		}
		file.close();
		if(found == 2)
		{
			file.open("Bank.txt",ios::in);
			file1.open("Bank1.txt",ios::app|ios::out);
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
			while(!file.eof())
			{
				if(s_id == id )
				{
					balance = balance - amount;
					file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				}
				else if(r_id == id)
				{
					balance = balance + amount;
					file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				}
				else
				{
					file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				}
				file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
				
			}
			file.close(); // Close the file after reading
		    file1.close(); 
		    remove("Bank.txt");
		    rename("Bank1.txt","Bank.txt");
		    cout<<"Amount Transfered Successfully";
		}
		else
		{
			if(found==1)
				cout<<"Either sender or receiver is not valid";
			else if(found==0)
				cout<<"Both sender and receiver is not valid";
			if(crt_amt==1)
				cout<<"Insufficient balance";
		}
	}
}




void Bank::Payment()
{
	system("cls");
	fstream file,file1;
	int found = 0;
	string test_id,bill;
	SYSTEMTIME t;
	float bill_amount;
	cout<<"\n\nBills Payment Option";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout<<"\nFile Opening Error";
	}
	else
	{
		cout<<"\n\nUser ID : ";
		cin>>test_id;
		cout<<"\nBill Name : ";
		cin>>bill;
		cout<<"\n\nBill Amount : ";
		cin>>bill_amount;
		file1.open("Bank1.txt",ios::app|ios::out);
		file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		while(!file.eof())
		{
			if(test_id == id && bill_amount<=balance)
			{
				balance=balance-bill_amount;
				file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				found++;
			}
			else
			{
				file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
			}
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
			
			
		}
		file.close(); // Close the file after reading
		file1.close(); 
	    remove("Bank.txt");
	    rename("Bank1.txt","Bank.txt");
		if(found ==1 )
		{
			GetSystemTime(&t);
			file.open("Bill.txt",ios::app|ios::out);
			file<<test_id<<","<<bill<<","<<bill_amount<<t.wDay<<"/"<<t.wMonth<<"/"<<t.wYear<<"\n";
			file.close();
			cout<<"\n\n\t\t"<<bill<<"Bill paid successfully";			
		}
		else
		{
			cout<<"\n\nUser ID / Amount Invalid....";
		}
		
	}
}



void Bank::Search_User_Records()
{
	system("cls");
	fstream file;
	string test_id;
	int found = 0;
	cout<<"\n\nSearch User Records ";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout<<"\nFile Opening Error";
	}
	else
	{
		cout<<"\n\nUser ID : ";
		cin>>test_id;
		file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		while(!file.eof())
		{
			if(test_id == id)
			{
				system("cls");
				cout<<"\n\nSearch User Records ";
				cout<<"\n\n"<<"User ID : "<<id<<"  Name: "<<First_name<<"  Middle Name : "<<Middle_name;
				cout<<"\n"<<"  Address : "<<Address<<"  Pin : "<<pin_code<<"  Password : "<<pass;
				cout<<"\n"<<"Phone : "<<phone<<"  Current Balance : "<<balance;
				found++;
				
			}
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		}
		file.close();
		if(found == 0 )
		{
			cout<<"\n\nUser Not Found...";
		}
		
	}
	
}




void Bank::Edit()
{
	system("cls");
	fstream file,file1;
	string test_id,Fname,Mname,Lname,Add,pin,pass1,phone1;
	int found = 0;
	cout<<"\n\nEdit User Records";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout<<"\nFile Opening Error";
	}
	else
	{
//		cout<<"\nUser ID : ";
//		cin>>test_id;
		Search_User_Records();
		cout<<"\nUser ID : ";
		cin>>test_id;
		file1.open("Bank1.txt",ios::app|ios::out);
		file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin >> pass >> phone >> balance;
		while(!file.eof())
		{
			if(test_id == id)
			{
				cout<<"\n First Name : ";
				cin>>Fname;
				cout<<"\nMiddle Name : ";
				cin>>Mname;
				cout<<"\nLast Name : ";
				cin>>Lname;
				cout<<"\nEnter your address : ";
				cin>>Add;
				cout<<"\nEnter your pin code : ";
				cin>>pin;
				cout<<"\nEnter Password : ";
				cin>>pass1;
				cout<<"\nEnter Phone Number : ";
				cin>>phone1;
				
				file1<<id<<" "<<Fname<<" "<<Mname<<" "<<Lname<<" "<<Add<<" "<<pin<<" "<<pass1<<" "<<phone1<<" "<<balance<<"\n";
				cout<<"\n\n\t\t\tRecord Successfully updated";
				found++;
			}
			else
			{
				file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
			}
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin >> pass >> phone >> balance;
		}
		file.close();
		file1.close();
		remove("Bank.txt");
	    rename("Bank1.txt","Bank.txt");
		if(found == 0)
		{
			cout<<"\n\nUser Not Found...";
		}
	}
}




void Bank::Delete()
{
	system("cls");
	fstream file,file1;
	string test_id;
	int found = 0;
	cout<<"\n\nEdit User Records";
	file.open("Bank.txt",ios::in);
	if(!file)
	{
		cout<<"\nFile Opening Error";
	}
	else
	{
		cout<<"\nUser ID : ";
		cin>>test_id;
		file1.open("Bank1.txt",ios::app|ios::out);
		file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		while(!file.eof())
		{
			if(test_id == id)
			{
				
				cout<<"\n\n\t\t\tRecord Successfully Deleted";
				found++;
			}
			else
			{
				file1<<id<<" "<<First_name<<" "<<Middle_name<<" "<<Last_name<<" "<<Address<<" "<<pin_code<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
			}
			file >> id >> First_name >> Middle_name >> Last_name >> Address >> pin_code >> pass >> phone >> balance;
		}
		file.close();
		file1.close();
		remove("Bank.txt");
	    rename("Bank1.txt","Bank.txt");
		if(found == 0)
		{
			cout<<"\n\nUser Not Found...";
		}
	}
}


////////////////////////////////////////////
int main()
{
	Bank obj;
	obj.menu();
}

