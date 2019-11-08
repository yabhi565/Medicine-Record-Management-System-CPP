// ---------------------------------------------->>>   MEDICINE  RECORD  MANAGEMENT  SYSTEM   <<<------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<iomanip>   // richa.17688@lpu.co.in
#include<string.h>
#include<conio.h>

using namespace std;

//

class login;
struct date;
class medicine;

void add_med();                        // adds a new set of medicine details
void disp_med();                       // displays medicine details
void modify_med();                     // modifies medicine details
void delete_med();                     // deletes medicine details
void find_med();                       // searches for a particular medicine
void setup(int);                       // sets up account
void foster();                         // provides tools to work with data
bool access();                         // creates Id & checks for login details
void clear();                          // clears database(s)
void trash();                          // shows and restores deleted records
bool check_date(int,int,int);          // checks for the validity of entered date
bool operator > (date,date);           // compares two dates 


class login
{
	char user[10], pass[10];

	public:

		login()                                                                              //
		{
		   strcpy(user,"qwerty");
		   strcpy(pass,"abc123");
		}

		void show_id()
		{
			cout<<"\nUserId   : "<<user;          
			cout<<"\nPassword : "<<pass;
		}
        
        void set_id();
        friend bool access();

};

                                                                   //
struct date
{
	int dd, mm, yyyy;
};


class medicine
{
	char medname[30], batch[10];
	int qty;
	float mrp;
	date mfg, exp;
	
	public:
		
		medicine()
		{
			strcpy(this->medname, "NIL"); 
			strcpy(this->batch, "NIL") ; 
			mfg.dd = mfg.mm = mfg.yyyy = 0; 
			exp.dd = exp.mm = exp.yyyy = 0;
			this->qty = 0 ; 
			this->mrp = 0.0 ;
		}
	
		void show()                                                                                                     //
		{                                                                                                                           
			cout<<"\n\n"<<setw(30)<<medname<<setw(16)<<batch<<setw(13)<<mfg.dd<<"-"<<mfg.mm<<"-"<<mfg.yyyy
			    <<setw(12)<<exp.dd<<"-"<<exp.mm<<"-"<<exp.yyyy<<setw(13)<<qty<<setw(14)<<mrp;
		}
		
		void getmed();
		
		friend void modify_med();
		friend void delete_med();
		friend void find_med();
	
};


int main()            // the DRIVER function
{
	system("color F4");
	
	cout<<"\n------------------------------------------->>>>>  ///    WELCOME   ///   <<<<<-----------------------------------------\n\n\n"
	    <<"\n\t\t\t\t                     ________________"
	    <<"\n\t\t\t\t                    |       __       |"
	    <<"\n\t\t\t\t                    |      |  |      |"
	    <<"\n\t\t\t\t                    |   ___|  |___   |"
	    <<"\n\t\t\t\t                    |  |___    ___|  |"
	    <<"\n\t\t\t\t                    |      |  |      |"
	    <<"\n\t\t\t\t                    |      |__|      |"
	    <<"\n\t\t\t\t                    |________________|\n\n\n"
	    
	    <<"\n\t   %%%%%%%      %%%%%%%%    %%       %%    %%%%%%%%    %%%%%%%       %%%%%%%   %%%%%%%%%%    %%%%%%%"
        <<"\n\t   %%     %%    %%     %%   %%       %%   %%      %%   %%     %%    %%     %%      %%       %%     %%"
        <<"\n\t   %%      %%   %%     %%   %%       %%   %%           %%      %%   %%     %%      %%       %%     %%"
        <<"\n\t   %%      %%   %%%%%%%     %%       %%   %%           %%      %%   %%%%%%%%%      %%       %%%%%%%%%"
        <<"\n\t   %%      %%   %%   %%     %%       %%   %%   %%%%%   %%      %%   %%     %%      %%       %%     %%"
        <<"\n\t   %%     %%    %%    %%     %%     %%    %%      %%   %%     %%    %%     %%      %%       %%     %%"
        <<"\n\t@  %%%%%%%      %%     %%     %%%%%%%      %%%%%%%%    %%%%%%%      %%     %%      %%       %%     %%"
	    <<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...";
	    
	    getch();
	
	system("color 0F");
	
	if ( access() )
	foster();

return 0;

}


void foster()
{
	int n;
	
	label:
		
	system("cls");
		
	disp_med();
	
    cout<<"\n________________________________________________________________________________________________________________________";	
	
	cout<<"\n\n\n # MENU --->>>"
	    <<"\n\n 1.SEARCH"<<"\t2.ADD"<<"\t\t3.MODIFY"<<"\t4.DELETE"
        <<"\t5.RESTORE record(s)"<<"\n 6.CLEAR ALL"<<"\t7.LOG OUT"
		<<"\n\n You Chose : ";
	    
	cin>>n;    
	
	switch(n)
	{
		case 1 :  find_med();
		          break;
		          
		case 2 :  add_med();
		          break;
		          
		case 3 :  modify_med();
		          break;
		          
		case 4 :  delete_med();
		          break;
		          
		case 5 :  trash();
		          break;
				            
		case 6 :  clear();
		          break;
		          
		case 7 :  cout<<"\nLOGGED OUT successfully";
		          exit(0);
		
		default:  cout<<"\nInvalid choice!!!"
		              <<"\nPress any key to try again";
		          getch();
				  goto label;
				  	  		  		            
	}
	
	goto label;
}


void login::set_id()
{
	fflush(stdin);
	cout<<"\nEnter new UserId   : ";
	cin.getline(user,10);
	
	cout<<"\nEnter new password : ";
	cin.getline(pass,10); 
}


void medicine::getmed()
{
	fflush(stdin);
	
	cout<<"\nEnter Medicine Name                   :  ";   cin.getline(medname,30);
	cout<<"\nEnter 7-digit Batch number            :  ";   cin.getline(batch,10);

	f_mfg:
		
	cout<<"\nEnter Manufacturing date (dd,mm,yyyy) :  ";   cin>>mfg.dd>>mfg.mm>>mfg.yyyy;
	
	if( !( check_date ( mfg.dd, mfg.mm, mfg.yyyy ) ) )
	{
		cout<<"\nInvalid !"; goto f_mfg;
	}
	
	f_exp:
	cout<<"\nEnter Expiry Date (dd,mm,yyyy)        :  ";   cin>>exp.dd>>exp.mm>>exp.yyyy;
	
	if( !( check_date ( exp.dd, exp.mm, exp.yyyy ) ) || !( exp > mfg ) )
	{
		cout<<"\nInvalid !"; goto f_exp;
	}
	
	cout<<"\nEnter Quantity                        :  ";   cin>>qty;
	cout<<"\nEnter Price                           :  ";   cin>>mrp;
	        
}


bool operator > (date tmp1, date tmp2)
{
	 if ( tmp1.yyyy > tmp2.yyyy ) return true;
	 
	 if ( tmp1.yyyy < tmp2.yyyy ) return false;
	 
	 if ( tmp1.yyyy == tmp2.yyyy)
	 {
	 	if ( tmp1.mm > tmp2.mm ) return true;
	    if ( tmp1.mm < tmp2.mm ) return false;
	 }
	 
	 if ( tmp1.mm == tmp2.mm)
	 {
	 	if ( tmp1.dd > tmp2.dd ) return true;
	    if ( tmp1.dd <= tmp2.dd ) return false;
	 }
}


bool access()
{
	int choice, attempt=3;
	char u[10];
	login login;

    fflush(stdin);

	fstream f("_login.dat",ios::in);

	if(!f)
	{
		f.close();
		fflush(stdin);
        flag_1:
		system("cls");

		cout<<"--------------->>> Sign Up <<<---------------"
		    <<"\n\n1. Continue with default account credentials "
		    <<"\n2. Continue setup "
		    <<"\n3. Exit "
		    <<"\n\nEnter your choice : ";

		cin>>choice;

		switch(choice)
		{
			case 1 : setup(0);
			         break;

			case 2 : setup(1);
			         cout<<"\nId created successfully\n";
			         getch();
			         break;
			         
			case 3 : exit(0);        

			default: cout<<"\nInvalid choice!!!"
			             <<"\nPress any key to try again";
			         getch();    
			         goto flag_1;
		}
		
		system("cls");
		
		ifstream fin("_login.dat");
        fin.read( (char*) &login , sizeof(login) );
	    login.show_id();
	    getch();
	    
	    fin.close();
	    
	    goto flag;
	}
	
	else
	{ flag:
		
		f.read( (char*) &login , sizeof(login) );
		
		flag_6:
		system("cls");
		fflush(stdin);
		
	    cout<<"------->>> Login <<<-------"
		    <<"\n\nEnter User Id : ";
		    
		cin.getline(u,10);
		
		if ( strcmpi(u,login.user) == 0 )
		{
			flag_7:
				
			system("cls");
			
			cout<<"------->>> Login <<<-------"
			    <<"\n\nEnter password : ";
		    
			int i=0;
			char pwd[20];
   
            while(1)
           {
    	       char p = getch();
    	       if( p !=13 )
    	       {
		          pwd[i] = p;
		          cout<<"*";
	           }
    	       else break;
    	
    	       i++;
           }
           
		    if ( strcmp(pwd,login.pass) == 0 )
		    {
		        f.close();
		    	return true;
			}
			else
			{
				cout<<"\n\aPassword Incorrect "
				    <<"\n'"<<attempt<<"' attemps left";
				if(attempt)
				{
					attempt--;
					cout<<"\n\nPress any key to try again";
					getch();
					goto flag_7;
				}
				else
				{   system("cls");
					cout<<"\n\nAttempt limit exceeded ! Exiting...";
					f.close();
					return false;
				}
			}
	    }
	    
	    else
		{
			cout<<"\nEntered Id doesn't exist"
				<<"\nPress any key to try again";
			getch();	
			goto flag_6;
		}
		
	}
	
}


void setup( int i )
{
	login login;
	fstream fsetup("_login.dat",ios::out);

	if(i) login.set_id();
	
	fsetup.write( (char*)&login , sizeof(login) );
	
	fsetup.close();
	
}


void add_med()
{
	char choice;
	medicine med;
	
	fstream f("1mg.dat",ios::binary | ios::out | ios::app );
	
	do
	{   system("cls");
	
	    med.getmed();
	    f.write( (char*)&med, sizeof(med) );
	    
	    cout<<"\n\nDo you Want to Enter more (y/n) : ";
	    cin>>choice;
	    
    } while(choice=='y' || choice=='Y');
    
    f.close();
}


void disp_med()
{
	system("cls");
	
	fstream f;
	medicine med;
	
	f.open("1mg.dat", ios::binary | ios::in);
	f.seekg(0,ios::end);

    cout<<endl<<setw(30)<<"MEDICINE NAME"<<setw(17)<<"BATCH NO."<<setw(19)<<"MFG. DATE"<<setw(18)
	    <<"EXP. DATE"<<setw(15)<<"QUANTITY"<<setw(11)<<"MRP"<<endl;
		
	cout<<"\n________________________________________________________________________________________________________________________\n";	
    
    if(!f || !( f.tellg() ) )
    {
    	cout<<"\n                                           *** No Records to display ***\n";
	}
	
	f.seekg(0);
			    
    while( f.read((char*)&med, sizeof(med)) )
    {
      med.show();
    }
    
    cout<<endl;
    f.close();

}


void modify_med()
{
	medicine med;
	char m[30],choice;
	int n, pos;
	int track = 1;
	
	fstream f;
	
	flag_7:
	system("cls");	
	cout<<"----- Medicine Particulars -----\n"
	    <<"\n1. Medicine name"
	    <<"\n2. Batch no."
	    <<"\n3. Manufacture date"
	    <<"\n4. Expiry date"
	    <<"\n5. Quantity"
	    <<"\n6. MRP";
	
	fflush(stdin);
	f.open("1mg.dat" , ios::in | ios::out | ios::ate | ios::binary);
	
	if(!f || !( f.tellg() ) )
    {
    	cout<<"\n                                           *** No Records in database ***\n";
    	getch();
    	
    	return;
	}
	
	f.seekg(0);
	
	cout<<"\n\nEnter medicine name whose data is to be modified : ";
	cin.getline(m,30);
	
	f.read((char*)&med, sizeof(med));
	
	while(f)
	{
	   if( strcmpi(med.medname,m)==0 )
	   {
		flag_8:
		track = 0;
		cout<<"\nEnter serial no. of data to be modified : ";
		cin>>n;
		
		fflush(stdin);                                                                                                                                                                                                                                            //by @bhi11803754#yadav
		
		pos = f.tellg();
		
		if(n==1)
		{
			cout<<"\nEnter new name : "; cin.getline(med.medname,30);
			
			f.seekp( pos-sizeof(medicine) );
			f.write((char*)&med,sizeof(medicine));
			
			cout<<"\n\nData updated successfully...."
			    <<"\n\nWant to modify more particulars (y/n) ?  ";
			    
			cin>>choice;
			
			if(choice=='y' || choice=='Y') goto flag_8; 
			else break;
		}
		
		else if(n==2)
		{
			cout<<"\nEnter new batch no. : "; cin.getline(med.batch,10);
			
			f.seekp( pos-sizeof(medicine) );
			f.write((char*)&med,sizeof(medicine));
			
			cout<<"\n\nData updated successfully...."
			    <<"\n\nWant to modify more particulars (y/n) ?  ";
			    
			cin>>choice;
			
			if(choice=='y' || choice=='Y') goto flag_8;
			else break;
		}
		
		else if(n==3)
		{
			cout<<"\nEnter new manufacture date (dd,mm,yyyy) : "; cin>>med.mfg.dd>>med.mfg.mm>>med.mfg.yyyy;
			
			f.seekp( pos-sizeof(medicine) );
			f.write((char*)&med,sizeof(medicine));
			
			cout<<"\n\nData updated successfully...."
			    <<"\n\nWant to modify more particulars (y/n) ?  ";
			    
			cin>>choice;
			
			if(choice=='y' || choice=='Y') goto flag_8;
			else break;
		}
		
		else if(n==4)
		{
			cout<<"\nEnter new expiry date (dd,mm,yyyy): "; cin>>med.exp.dd>>med.exp.mm>>med.exp.yyyy;
			
			f.seekp( pos-sizeof(medicine) );
			f.write((char*)&med,sizeof(medicine));
			
			cout<<"\n\nData updated successfully...."
			    <<"\n\nWant to modify more particulars (y/n) ?  ";
			    
			cin>>choice;
			
			if(choice=='y' || choice=='Y') goto flag_8;
			else break;
		}
		
		else if(n==5)
		{
			cout<<"\nEnter new quantity : "; cin>>med.qty;
			
			f.seekp( pos-sizeof(medicine) );
			f.write((char*)&med,sizeof(medicine));
			
			cout<<"\n\nData updated successfully...."
			    <<"\n\nWant to modify more particulars (y/n) ?  ";
			    
			cin>>choice;
			
			if(choice=='y' || choice=='Y') goto flag_8;
			else break;
		}
		
		else if(n==6)
		{
			cout<<"\nEnter new MRP : "; cin>>med.mrp;
			
			f.seekp( pos-sizeof(medicine) );
			f.write((char*)&med,sizeof(medicine));
			
			cout<<"\n\nData updated successfully...."
			    <<"\n\nWant to modify more particulars (y/n) ?  ";
			    
			cin>>choice;
			
			if(choice=='y' || choice=='Y') goto flag_8;
			else break;
		}
		
		else
		{
			cout<<"\nInvalid choice!!!"
			    <<"\nEnter any key to try again";
			    
	        getch();
	        goto flag_8;
		}
		
	   }
	   
	   f.read((char*)&med, sizeof(med));
   }   
   
	if(track)
	{
	    cout<<"\nNo such medicine exists!"
	        <<"\nEnter any key to try again";
	        
	    getch();
	    f.close();
	    goto flag_7;
    }
    
    f.close();
   
}


void delete_med()
{
	char choice, m[30];
	medicine med;
	int tsize;

    ifstream fin;
    fin.open("1mg.dat",ios::ate | ios::binary );
	
	if(!fin || !( fin.tellg() ) )
    {
    	cout<<"\n\nError encountered!!!"
    	    <<"\nPossible causes :-"
    	    <<"\n1. File opening failed "
    	    <<"\n2. Database underflow";
    	    
    	return;
	}
	
	fin.close();
	
	label:
		
	system("cls");
	fin.open("1mg.dat",ios::binary );
	ofstream fout("_temp.dat", ios::app | ios::binary );
	ofstream fout2("_trash.dat",ios::binary | ios::app );
	
	tsize = fout2.tellp();
		
	do
	{
		fflush(stdin);
		
	    cout<<"\nEnter medicine name whose data is to be deleted : ";
	    cin.getline(m,20);
	
	    fin.read( (char*)&med, sizeof(med));
	    
	    while(!fin.eof() )
	    {
		     if( strcmpi(med.medname,m) != 0 )
	         fout.write( (char*)&med, sizeof(med) );
	    
	         else
			 fout2.write( (char*)&med, sizeof(med) );
          
             fin.read((char*)&med , sizeof(medicine));
        }
        
        if(fout2.tellp() == tsize)
        {
        	cout<<"\nNo such medicine exists"
        	    <<"\nEnter any key to try again ";	   
        	getch();
        	
        	fin.close();
            fout.close();
	        fout2.close();
	        
        	goto label;
		}
		
		if(fout2.tellp() != tsize )
		{
		   cout<<"\n\nRecord updated successfully ";
		   
           cout<<"\nDo you Want to Delete more record (y/n) :  ";
	       cin>>choice;
	    }
        
        fin.close();
        fout.close();
	    fout2.close();
        
	    remove("1mg.dat");
        rename("_temp.dat","1mg.dat");
        
    } while(choice=='y' || choice=='Y');
    
}


void find_med()
{
	medicine med;
	char m[30], ch;
	int track=0, count=0, i=0, size, choice;
	
	ifstream fin("1mg.dat", ios::ate | ios::binary);
	
	system("cls");
	
	if( !fin || !( fin.tellg() ) )
    {
    	cout<<"\n---------------------------------------------- Sorry! Empty database --------------------------------------------------\n";
    	getch();
    	
    	return;
	}
	
	else fin.seekg(0, ios::beg);
	
	fflush(stdin);
	
	cout<<"\n--- Search Criteria ---"
	    <<"\n\n1. Medicine Name"
	    <<"\n2. Record with MFG < this date"
	    <<"\n3. Record with MFG > this date"
	    <<"\n4. Record with EXP < this date"
	    <<"\n5. Record with EXP > this date"
	    <<"\n\nYour choice : ";
	    
	cin>>choice;
	
	fflush(stdin);
	
	  if (choice == 1)
	  {
		        cout<<"\nEnter medicine name : ";
	    
	            while(1)
	            {
		          cin.get(ch);
		
		          if( ch != '\n' )
		          {
		         	m[i]=ch;
			        size= i;
		          }
		          else break;
		
		          ++i;
	            }
	            
	            system("cls");
	            
	            cout<<endl<<setw(30)<<"MEDICINE NAME"<<setw(17)<<"BATCH NO."<<setw(19)<<"MFG. DATE"<<setw(18)
	                <<"EXP. DATE"<<setw(15)<<"QUANTITY"<<setw(11)<<"MRP"<<endl;
		
	            cout<<"\n_______________________________________________________________________________________________________________________\n";
	
	        	while( fin.read((char*)&med, sizeof(med)) )
	            {
		           for( i=0; i<=size; i++)
		           {
			          if( m[i] == med.medname[i] )
			          track = 1;
			
			          else 
			          {
				        track=0;
				        break;
			          }
		            }
		
		            if(track)
		            {
		               med.show();
		               count++;
	                }
		         }
      }
		        
	  if (choice == 2)
	  {
		 	     date tmpa;
		         cout<<"\nEnter date (dd,mm,yyyy) : ";
		         cin>>tmpa.dd>>tmpa.mm>>tmpa.yyyy;
		         
		         if( !( check_date ( tmpa.dd, tmpa.mm, tmpa.yyyy )) )
		         {
		         	cout<<"\nInvalid Input";
		         	getch();
		         	return;
				 }
		         
		         system("cls");
		         
	             cout<<endl<<setw(30)<<"MEDICINE NAME"<<setw(17)<<"BATCH NO."<<setw(19)<<"MFG. DATE"
				     <<setw(18)<<"EXP. DATE"<<setw(15)<<"QUANTITY"<<setw(11)<<"MRP"<<endl;
		
	             cout<<"\n_______________________________________________________________________________________________________________________\n";
	            
		         while( fin.read((char*)&med, sizeof(med)) )
		         {
				      if( (med.mfg) > (tmpa) )
				      {
					     med.show();
					     count++;
				      }
			     }
		}       
		    
      if (choice == 3) 
      {		 	
		 	     date tmpb;
		         cout<<"\nEnter date (dd,mm,yyyy) : ";
		         cin>>tmpb.dd>>tmpb.mm>>tmpb.yyyy;
		         
		         system("cls");
	             cout<<endl<<setw(30)<<"MEDICINE NAME"<<setw(17)<<"BATCH NO."<<setw(19)<<"MFG. DATE"<<setw(18)
	                 <<"EXP. DATE"<<setw(15)<<"QUANTITY"<<setw(11)<<"MRP"<<endl;
		
	             cout<<"\n_______________________________________________________________________________________________________________________\n";
		         
		         while( fin.read((char*)&med, sizeof(med)) )
		         {
				      if( tmpb > (med.mfg) )
				      {
					     med.show();
					     count++;
				      }
			     }
	  }
		    
	  if (choice == 4)
	  {
		 	     date tmpc;
		         cout<<"\nEnter date (dd,mm,yyyy) : ";
		         cin>>tmpc.dd>>tmpc.mm>>tmpc.yyyy;
		         
		         system("cls");
	             cout<<endl<<setw(30)<<"MEDICINE NAME"<<setw(17)<<"BATCH NO."<<setw(19)<<"MFG. DATE"<<setw(18)
	                 <<"EXP. DATE"<<setw(15)<<"QUANTITY"<<setw(11)<<"MRP"<<endl;
		
	             cout<<"\n_______________________________________________________________________________________________________________________\n";
		         
		         while( fin.read((char*)&med, sizeof(med)) )
		         {
				      if( (med.exp) > tmpc )
				      {
					     med.show();
					     count++;
				      }
			     }
      }
		    
	  if (choice == 5)
	  {
		         date tmpd;
		         cout<<"\nEnter date (dd,mm,yyyy) : ";
		         cin>>tmpd.dd>>tmpd.mm>>tmpd.yyyy;
		         
		         system("cls");
	             cout<<endl<<setw(30)<<"MEDICINE NAME"<<setw(17)<<"BATCH NO."<<setw(19)<<"MFG. DATE"<<setw(18)
	                 <<"EXP. DATE"<<setw(15)<<"QUANTITY"<<setw(11)<<"MRP"<<endl;
		
	             cout<<"\n_______________________________________________________________________________________________________________________\n";
		         
		         while( fin.read((char*)&med, sizeof(med)) )
		         {
				      if( tmpd > (med.exp) )
				      {
					     med.show();
					     ++count;
				      }
			     }
      }
		
	cout<<"\n_______________________________________*_________________*________________*____________________________________________"
	    <<"\n\n '"<<count<<"' record(s) found..."; 
	    
	fin.close();    
	getch();

}


void clear()
{
	char ch;
	int choice;
	
	cout<<"\n1. Medicine database"
	    <<"\n2. Trash database"
	    <<"\n3. All databases"
	    <<"\n\nYou chose : ";
	    
	cin>>choice;    
	
	switch(choice)
	{
		case 1 : cout<<"\nAre you sure (y/n) ? ";
	             cin>>ch;
	             
		         if( ch=='y' || ch=='Y')
		         {
		         	remove("1mg.dat");
		         	cout<<"\nMedicine database WIPED OUT successfully";
				 }
		         
		         else
	             cout<<"\nCleardata aborted ";
	             
		         break;
	   
	    case 2 : cout<<"\nAre you sure (y/n) ? ";
	             cin>>ch;
	             
		         if( ch=='y' || ch=='Y')
		         {
		         	remove("_trash.dat");
		         	cout<<"\nTrash database WIPED OUT successfully";
				 }
				 
		         else
	             cout<<"\nCleardata aborted ";
	
		         break;
		         
		case 3 : cout<<"\nAre you sure (y/n) ? ";
	             cin>>ch;
	             
		         if( ch=='y' || ch=='Y')
		         {
		         	remove("1mg.dat");
		         	remove("_trash.dat");
		         	cout<<"\nAll databases WIPED OUT successfully";
				 }
				 
				 else
	             cout<<"\nCleardata aborted ";
	
				 break;
				
	   default : cout<<"\nInvalid choice !";
	   
	             break;
    }
	
	getch();
}


void trash()
{
	medicine med;
	char choice;
	
	ifstream fin("_trash.dat",ios::binary );
	fin.seekg(0,ios::end);
	
	if( ( !fin.tellg() ) || (!fin) )
	{
	    cout<<"\nNo records in trash";
	    getch();
	    
	    return;
    }
    
    else fin.seekg(0);
	
	ofstream fout("1mg.dat",ios::binary | ios::app );
	fstream f("_t.dat",ios::out | ios::binary );
		
	while( fin.read((char*)&med, sizeof(medicine)) )
	{
		system("cls");
	    med.show();
	    cout<<"\n\nWanna restore this record ?  ";
	    cin>>choice;
    
	    if( choice == 'y' || choice == 'Y' )
	    {
	       fout.write((char*)&med, sizeof(medicine) );
	       cout<<"\nRecord restored...";
	       getch();
	    }
	    
	    else
	    {
	        f.write((char*)&med , sizeof(medicine));	
		}
		
    }
    
    f.close();
    fin.close();
    fout.close();
    
    remove("_trash.dat");
    rename("_t.dat","_trash.dat");
    
 	
}


bool check_date( int d, int m, int y )
{
	
	if( (y>2040) || ( y<2010 ) ) 
    return false; 

    if( (m<1) || (m>12) ) 
    return false; 

    if( (d<1) || (d>31) ) 
    return false; 

    if (m == 2) 
    { 
        if ( (y % 4 == 0) ) 
        return (d <= 29); 

        else
        return (d <= 28); 
    } 

    if( (m == 4) || (m == 6) || (m == 9) || (m == 11) ) 
    return (d <= 30); 

  return true; 
  
}
