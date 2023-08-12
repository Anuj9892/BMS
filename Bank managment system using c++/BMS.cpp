/*My name is Anuj Rajput
i have made the bank maganment system using c++
with my friend in Turbo c++
Date - 10 -02-2023*/

///Admin pass = 9009

#include <iostream.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include<graphics.h>
#include<dos.h>

static int ac_op,loan_op,in_op,mng_op;       //global variable
int cid;
/////////////////////  User class ////////////////////////////////////

class user
{
    public:
    int cust_id;
    //protected:
      char name[50];
      char dob[12];
      char mobile_no[11];

public:

user()
{
    strcpy(name,"Abc");
    strcpy(dob,"11-06-1996");
    strcpy(mobile_no,"9999999999");
   
}
 void getuser();
 void loading();

};


void user::loading()
{

    clrscr();
   int i,gm,gd=DETECT;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   setcolor(3);
 for(i=0;i<=10;i++)
	  {
	   setcolor(i);
	   outtextxy(280,200,"Please wait...");
	   delay(300);
	  }

	closegraph();
}

void user::getuser()
   {
     clrscr();
    cout<<"\n\t\tEnter Name  :  ";
    cin.ignore();
    cin.getline(name,50);
    do
    {
    cout << "\n\t\tEnter DOB (01-01-1999) :  ";
    cin >> dob;
    if(strlen(dob)!=10)
    cout<<"Enter Correct Input :";
    }while(strlen(dob)!=10);

    do
    {
    cout << "\n\t\tEnter Mobile No :  ";
    cin >>mobile_no;
    if(strlen(mobile_no)!=10)
    cout<<"Enter Correct Input :";
    }while(strlen(mobile_no)!=10);
    srand(999);
	cust_id = rand () + cid++;


  }
 /////////////////////  Account class ////////////////////////////////////

class account:virtual public user
{

  public:
  int acc_no;
  double balance;
  char type[8];
  protected:
  int cardno[4];
  int cvv;
  double trans[5];
  int pass;

public:

    account()
    {
     
  balance=0;
  trans[0]=0;
   
    }
  void open (int a);

  int withdraw (int account_no,double amount);

  void deposit (int account_no);

  void passbook(int);
  void card(int);

  void users(int ,int);
  void acc_search();

/*    int verification(int account_no)
    {



    }
*/

}b[5];

///////////////  // /* Account functions */ //  ////////


void account::acc_search()
{
    int m_menu=0,temp_ac,i;
    char temp[50];
	    while(m_menu!=4)
	      {
	      clrscr();

	     cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\t\t\t   Welcome to Managment pannel"<<endl;
	      cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\n\n\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t1. By Name\t\t\t2. By Mobile No"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t3. By Account No\t\t4. Back"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\n                                        ";
	      cin>>m_menu;
	      if(cin.fail())
	      {
		  cin.clear();
		  cin.ignore();
		  clrscr();
		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
		  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
		  getch ();
	      }
	      else
		switch(m_menu)
		{

		    case 1:
			    cout<<"Enter Name :"<<endl;
			    cin>>temp;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=ac_op;i++)
			    {
    				if(strcmp(temp,b[i].name)==0)
				{
    
    				 cout<<b[i].name<<"\t\t"<<b[i].dob<<"\t\t"<<b[i].acc_no<<"\t\t"<<endl;
    				 
    				}
            
			    }
			    if((strcmp(temp,b[i].name)!=0)&&(i>ac_op))
			    {
			        cout<<"No Record Found:"<<endl;
			        
			    }
			    getch();
		    break;


		    case 2:
			    cout<<"Enter Mobile No :"<<endl;
			    cin>>temp;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=ac_op;i++)
			    {
			     if(strcmp(b[i].mobile_no,temp)==0)
			     {
    
    				 cout<<b[i].name<<"\t\t"<<b[i].dob<<"\t\t"<<b[i].acc_no<<"\t\t"<<endl;
    				 
    				}
            
			    }
			    if((strcmp(temp,b[i].name)!=0)&&(i>ac_op))
			    {
			        cout<<"No Record Found:"<<endl;
			        
			    }
			    getch();
		    break;


		    case 3:
			    cout<<"Enter Account No :"<<endl;
			    cin>>temp_ac;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=ac_op;i++)
			    {
			     if(temp_ac==b[i].acc_no)
			     {

				 cout<<b[i].name<<"\t\t"<<b[i].dob<<"\t\t"<<b[i].acc_no<<"\t\t"<<endl;

				}

			    }
			    if((strcmp(temp,b[i].name)!=0)&&(i>ac_op))
			    {
				cout<<"No Record Found:"<<endl;

			    }
			    getch();
		    break;


		    case 4:
			    users(11,1);
		    break;


		    default:
			    cout<<"Invalid Choice";
		    break;

		}


	    }


}





void account::passbook (int i)                  //passbook function
    {

		clrscr();
		int t;
		cout<<"====================================================================="<<endl;
		cout << "Customer id:\t";
		cout << b[i].cust_id<<endl;
		cout <<"Account No:\t";
		cout << b[i].acc_no<<endl;
		cout <<"\n=Name:\t";
		cout << b[i].name<<"\nDOB:\t";
		cout << b[i].dob<<endl;
		cout<<"====================================================================="<<endl;
		cout <<"Balance :\t\t"<<b[i].balance<<endl;
		cout<<"Transactions :\t";
		 for(t=0;t<5;t++)
		   {
		    cout<<b[i].trans[t]<<"\t";

		}
		//cout<<"--------------------------------------------------------------------"<<endl;
		getch();


    }

int account::withdraw (int account_no ,double amount)           //withdraw function
  {
      int i,t=0;
    for(i=0;i<=5;i++) ////////for saving account
	{
	    if(account_no==b[i].acc_no)
	    {
		 if(b[i].balance>=amount)
		     {
			while(b[i].trans[t]!=0)
			{
				t++;
			    }
			b[i].trans[t] = -amount;
			b[i].balance -= amount;
		 clrscr();
		 cout<<"\n\n\t\t\t-----------------------"<<endl  ;
		cout<<"\t\t\tTransaction Succesfull"<<endl;
		cout<<"\t\t\t------------------------";
		cout<<"\n\n\t\t\tSaving Account Balance:\t"<<b[i].balance;
		getch();
		return 0;
		break;

		     }
		     else
		     {
		     cout<<"\n\n\t\t-----------------------------"<<endl;
		     cout<<"\t\tInsufficent fund in account\n";
		     cout<<"\n\t\t-----------------------------"<<endl;
		     getch();
		     return 1;
		     }
	    }

	}

     }


   void account::deposit(int account_no)            //deposit function
   {
      int i,t=0;
    for(i=0;i<=5;i++) ////////for saving account
	{
	    if(account_no==b[i].acc_no)
	    {
		double amount;
		do
		{
		cout << "Enter Amount:" << endl ;
		cin >> amount;
	    }while((amount<0) || (amount>10000000));
		while(b[i].trans[t]!=0)
			{
				t++;
			    }
		b[i].trans[t] = +amount;
		b[i].balance += amount;
		clrscr();
		cout<<"\n\n\t\t\t-----------------------"<<endl  ;
		cout<<"\t\t\tTransaction Succesfull"<<endl;
		cout<<"\t\t\t------------------------";
		cout<<"\n\n\t\t\tSaving Account Balance:\t"<<b[i].balance;
		getch();
		break;
	    }

	}

     }


void account::open (int i)                  //open function (account open)
{
  int s_typ;


    do{  clrscr();
      cout << "\n\n\n\t\t\t\tSelect Account Type" << endl;
      cout << "\t\t\t\t1.Saving" << endl;
      cout << "\t\t\t\t2.Current" << endl;
      cout << "\t\t\t\t" ;
      cin >> s_typ;
       if(cin.fail())
	  {
	      cin.clear();
	      cin.ignore();
	      clrscr();
	      cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
	      cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
	      getch ();
	  }
	  else
	  {
	    if(s_typ==1 || s_typ==2)
	    continue;
	    else
	    {
	    clrscr();
			 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
			 cout<<"\t\t\t\tInvalid Choice"<<endl;
			 cout<<"\t\t\t\t----------------"<<endl;
			 getch();
	    }
	  }
	  }while(s_typ<0 || s_typ>2);
  clrscr();
  do

  {
    clrscr();
    cout<<"\n\n\n\t\t\t\tCreate 4-digit PIN :"<<endl;
    cout<<"\t\t\t\t";
    cin>>b[i].pass;
    if(cin.fail())
	  {
	      cin.clear();
	      cin.ignore();
	      clrscr();
	      cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
	      cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
	      getch ();
	  }
    else
    {
	if((b[i].pass>999) && (b[i].pass<9999))
	{
	    cout<<"\n\n\n    \t\t\tPIN Created Succesfull";
	    getch();
	}
	else
	{
	    cout<<"Enter Correct Input :";
	    getch();

	}
    }
  }while(b[i].pass<999 || b[i].pass>9999);





  switch (s_typ)
    {
    case 1:
      strcpy (b[i].type, "saving");
      break;

    case 2:
      strcpy (b[i].type, "current");
      break;
    default:
      cout << "Enter valid inputs" << endl;
      break;
    }
  b[i].acc_no = 1000 + rand () +i;
  ////Debit card
  int c;
       srand(9999);
       for(c=0; c<4; c++)
       {
	b[i].cardno[c]=rand();

       }
       srand(999);
       b[i].cvv=rand();
}


void account::card (int i)
{
    int c;
    ///////////////////////front card///////////////
    cout<<"\t\t\n\n\n______________________________________________________\n\n";
    cout<<"\t\t\t\t\tAAA_Bank\n";
    cout<<"\t\t\t\t\tDebit cards\n\n";
    cout<<"|!#!|\t\t\t\t\t\t>))\n";
    cout<<"|!#!|\n\n\t";
    for(c=0; c<4; c++)
    {
    cout<<b[i].cardno[c];
    }
    cout<<"\n\n\tvalid\t\t\t\tvalid\n";
    cout<<"\tfrom ";
    cout<<"06/22";
    cout<<"\t\t\tthru ";
    cout<<"06/29\n\n\n";
    cout<<"\t"<<b[i].name;
    cout<<"\t\t\tGolden";
    cout<<"\t\t\n\n\n_______________________________________________________\n";
    cout<<"\n\n\nPress Enter to flip Card..\n";
    getch();
    clrscr();
    ///////////////card back//////////////////
    cout<<"\tEnter 4 Digit Password\n";
    int pass;
    cin>>pass;
    if(b[i].pass==pass)
    {
     clrscr();
    cout<<"\t\t\n\n\n______________________________________________________\n";
     cout<<"\t\t\t\twww.AAA_Bank.com\n";
     for(c=1;c<=54;c++)
     cout<<"!";
     cout<<"\nAuthorized Signature";
     cout<<"\n\n\n\t%c",1;

     for(c=1;c<=15;c++)
     cout<<"#";
     cout<<"\t\t\t"<<b[i].cvv;
     cout<<"\n\n\n\t\t\t\t\t\t#plus";

     cout<<"\n\n______________________________________________________\n\n";

    }
    else
    cout<<"\nWrong Password......\n";


getch();
}





void account::users(int acc_no,int pass)            // user function
{
  int menu_opt=0,i;
  for(i=0;i<=5;i++)
  {
     if(acc_no==b[i].acc_no && pass==b[i].pass)
     {
	while (menu_opt != 7)
	{
	  clrscr ();
	   cout<<"\t\t\t----------------------------"<<endl;
	      cout<<"\t\t\t     Welcome Back  "<<b[i].name<<endl;
	      cout<<"\t\t\t----------------------------"<<endl;
	      cout<<"\n\n\t\t---------------------\t\t---------------------\n";
	      cout<<"\t\t1. Create New Account\t\t2. Withdraw"<<endl;
	      cout<<"\t\t---------------------\t\t---------------------\n";
	      cout<<"\t\t---------------------\t\t---------------------\n";
	      cout<<"\t\t3. Deposite\t\t\t4. Last 5 Transaction"<<endl;
	      cout<<"\t\t---------------------\t\t---------------------\n";
	      cout<<"\t\t---------------------\t\t--------------------\n";
	      cout<<"\t\t5. Passbook\t\t\t6. Card"<<endl;
	      cout<<"\t\t---------------------\t\t---------------------\n";
	      cout<<"\n\t\t\t\t   --------\n";
	      cout<<"\t\t\t\t   7. Exit"<<endl;
	      cout<<"\t\t\t\t   --------\n";
          cout<<"                                   ";
	  cin >> menu_opt;
	  if(cin.fail())
	  {
	      cin.clear();
	      cin.ignore();
	      clrscr();
	      cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
	      cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
	      getch ();
	  }
	  else

	  switch (menu_opt)
	{
	case 1:

	    b[ac_op].getuser();
	    b[ac_op].open(ac_op);
	    b[ac_op].passbook(ac_op);
	    ac_op++;
		  getch ();
	  break;


	case 2:
		    double amount;
		    do
	    {
	       clrscr();
			   cout << "Enter Amount:" << endl ;
			   cin >> amount;
			  if(cin.fail())
	      {
		  cin.clear();
		  cin.ignore();
		  clrscr();
		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
		  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
		  getch ();
	      }
		  else
			  withdraw(acc_no,amount);
	    }while((amount<0) || (amount>10000000));


	    break;

	case 3:///
		    deposit(acc_no);
	  break;

	case 4:
		    int t;
		    clrscr();
		    cout<<"Transactions :\t";
		  for(t=0;t<5;t++)
		  {
		    cout<<b[i].trans[t]<<"\t";

		  }
		    getch();
	    break;

	case 5:
		b[i].passbook(i);


	  break;

	  case 6:
		b[i].card(i);


	  break;

	  case 7:
		users(1111111,1);


	  break;



	default:
	  cout << "invalid inputs"<<endl;
	  break;


	}

	}
     }
   /*  else if(pass!=b[i].pass && i==5)
     {
     cout<<"\n\n\n\t\t\tWrong Password"<<endl;
     getch();
     } */

   }


}


/////////////////////Loan Class/////////////////////////

  class loan:virtual public account
     {
	 public:
	 int acc_no;
	 char type[16];
	 int l_tenure;
	 public:
	 double payable;
	 double princ_amt;
	 int rate;
	 protected:
	 double emi;
	 int debit_acc;
	 double trans[];


     public:
     loan()
     {
      trans[0]=0;
     }

     void getloan(int);
     double cal_emi(double,double,int);
     void payemi(int);
     void loanstatement(int);
     void loan_search();

     }l[5];

///////////////        /* loan functions */     ////////

void loan::loan_search()
{
    int m_menu=0,temp_ac,i;
    char temp[50];
	    while(m_menu!=4)
	      {
	      clrscr();
	       cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\t\t\t   Welcome to Managment pannel"<<endl;
	      cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\n\n\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t1. By Name\t\t\t2. By Mobile No"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t3. By Account No\t\t4. Back"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\n                                        ";
	      cin>>m_menu;
	      if(cin.fail())
	      {
		  cin.clear();
		  cin.ignore();
		  clrscr();
		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
		  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
		  getch ();
	      }
	      else
		switch(m_menu)
		{

		    case 1:
			    cout<<"Enter Name :"<<endl;
			    cin>>temp;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=loan_op;i++)
			    {
				if(strcmp(temp,l[i].name)==0)
				{

				 cout<<l[i].name<<"\t\t"<<l[i].dob<<"\t\t"<<l[i].acc_no<<"\t\t"<<endl;
				 break;
				}

			    }
			    if((strcmp(temp,l[i].name)!=0)&&(i>loan_op))
			    {
				cout<<"No Record Found:"<<endl;

			    }
			    getch();
		    break;


		    case 2:
			    cout<<"Enter Mobile No :"<<endl;
			    cin>>temp;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=loan_op;i++)
			    {
			     if(strcmp(l[i].mobile_no,temp)==0)
			     cout<<l[i].name<<"\t\t"<<l[i].dob<<"\t\t"<<l[i].acc_no<<"\t\t"<<endl;
			    }
			    if((strcmp(temp,l[i].name)!=0)&&(i>loan_op))
			    {
				cout<<"No Record Found:"<<endl;

			    }
			    getch();
		    break;


		    case 3:
			    cout<<"Enter Account No :"<<endl;
			    cin>>temp_ac;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=loan_op;i++)
			    {
			     if(temp_ac==l[i].acc_no)
			     cout<<l[i].name<<"\t\t"<<l[i].dob<<"\t\t"<<l[i].acc_no<<"\t\t"<<endl;
			    }
			    if((strcmp(temp,l[i].name)!=0)&&(i>loan_op))
			    {
				cout<<"No Record Found:"<<endl;

			    }
			    getch();
		    break;


		    case 4:
			    //goto menu;
		    break;


		    default:
			    clrscr();
			 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
			 cout<<"\t\t\t\tInvalid Choice"<<endl;
			 cout<<"\t\t\t\t----------------"<<endl;
			 getch();
		    break;

		}


	    }

    getch();
}












void loan::getloan(int a)                  //open function (loan account open)
{
  int s_typ;

    clrscr();
  cout << "\n\n\n\n\n\t\t\tSelect Loan Type" << endl;
  cout << "\t\t\t1.Home Loan\t-Rate of interest -8%" << endl;
  cout << "\t\t\t2.Personal Loan\t-Rate of interest -14%" << endl;
  cout << "\t\t\t3.Gold Loan\t-Rate of interest -11%" << endl;
  cout<<"\t\t\t";
  cin >> s_typ;
  clrscr();
    double amount,int_amt,loan_amt,emi;

     do
    {
      cout<<"\n\t\t\t\tloan Amount : "<<endl;
      cout<<"\t\t\t\t";
      cin>>amount;
    }while((amount<0) || (amount>10000000));

    do
    {
     cout<<"\t\t\t\tTenure in Months:"<<endl;
      cout<<"\t\t\t\t";
      cin>>l_tenure;
    }while((l_tenure<0)||(l_tenure>180));

  switch (s_typ)
    {
    case 1:
      strcpy (l[a].type, "Home_loan");
     emi=l[a].cal_emi(amount,8,l_tenure);
     rate=8;
      break;

    case 2:
      strcpy (l[a].type, "Personal_loan");
     emi=l[a].cal_emi(amount,14,l_tenure);
     rate=14;
      break;

    case 3:
       strcpy (l[a].type, "Gold_loan");
     emi=l[a].cal_emi(amount,11,l_tenure);
     rate=11;
       break;

    default:
      cout << "Enter valid inputs" << endl;
    }

    int_amt=emi*l_tenure-amount;
    loan_amt=emi*l_tenure;
    clrscr();
   cout<<"\n\n\n\n\t\t\tPrincipal Amount:\t "<<amount<<endl;
    cout<<"\t\t\tInterset Amount\t:\t"<<int_amt<<endl;
    cout<<"\t\t\tPayable Amount\t:\t"<<loan_amt<<endl;
    cout<<"\t\t\tEMI\t\t:\t"<<emi<<endl;
    cout<<"\t\t\tRate of interst\t:\t"<<rate;
    cout<<"\n\n\n\n\n\n\n\n\n\nEnter '1' to confirm loan....\n";
    cout<<"\nEnter '2' to Exit.."<<endl;
    int confirm,t=0;
    cin>>confirm;
    if(confirm==1)
	{
	  cout<<"thnx\n\n";
	  l[a].getuser();
	  int set_acc,i;
	  do
	  {
	  cout<<"\n\nEnter Account No. for Installment Deduction :";
	  cin>>set_acc;
	  for(i=0;i<=5;i++) ////////for saving account
		{
	     if(set_acc==b[i].acc_no)
	     {
		  l[a].debit_acc=set_acc;
		  l[a].payable=loan_amt;
		  l[a].emi=emi;
		  l[a].l_tenure=l_tenure;
		  l[a].princ_amt=amount;
		  l[a].rate=rate;
		  l[a].acc_no = 1100 + rand () +a;
		  clrscr();
		  cout<<"\n\n\t\t\tYour Loan is Approved \n\n";
		  cout<<"\t\t\t------------------------------"<<endl;
		  cout<<"\t\t\tLoan Account No:\t"<<l[a].acc_no<<endl;
		  cout<<"\t\t\t------------------------------"<<endl;
		  cout<<"\n\n\n\n\n\nPress any key to Continue......."<<endl;
		  getch();
		 while(l[a].trans[t]!=0)
		     {
		       t++;
		     }
		     l[a].trans[t]=amount;
		    loanstatement(a);/////Statement
		    break;
	     }
	     else if(set_acc!=b[i].acc_no && i==5)
		{
		clrscr();
		cout<<"\n\n\tAccount Does not Belong to your bank"<<endl;

		}
	}
     }while(set_acc!=b[i].acc_no);



  }
}

double loan::cal_emi(double princ_amt,double interest ,int tenure)        ///emi function
{

     double r;
     r=1+(interest/1200);
     emi=princ_amt*(interest/1200)*pow(r,tenure)/(pow(r,tenure)-1);
     return emi;
}

void loan::payemi(int acc_no)
{

   int i,t=0,r;
    for(i=0;i<=6;i++) ////////for saving account
	{
	    if(acc_no==l[i].acc_no)
	    {
		double amount;
		 amount=l[i].emi;
		 r=withdraw(l[i].debit_acc,amount);
	 if(r==0)
	 {
		while(l[i].trans[t]!=0)
			{
				t++;
			    }
		l[i].trans[t] = +amount;
		l[i].payable -= amount;
		l[i].l_tenure-=1;
		clrscr();
		cout<<"\n\n\t\t\t----------------------------------------"  ;
		cout<<"\n\t\t\t       EMI Deposited Succesfully"<<endl;
		cout<<"\n\t\t\t----------------------------------------"  ;
		cout<<"\n\n\t\t\tRemaining Loan Amount:\t"<<l[i].payable<<endl;
		cout<<"\n\t\t\tTenure Left:\t"<<l[i].l_tenure;
		getch();
	 }
	 else
	 cout<<"\n\n\n\t\t\tEMI Bounced"<<endl;

	    }
	    else if(acc_no!=l[i].acc_no && i==6)
	    {
	      cout<<"Account Not Found"<<endl;
	    }


	}
}

	void loan::loanstatement(int i)
	{
	     int t;
	     clrscr();
		cout<<"AAA_Bank"<<endl;
		cout <<"\n\n\tName:\t";
		cout << l[i].name<<endl;
		cout << "\tCustomer id:\t";
		cout << l[i].cust_id<<endl;
		cout <<"\tAccount No:\t";
		cout << l[i].acc_no<<endl;

		cout<<"______________________________________________________________________________"<<endl;
		cout <<"\tSanction Amt \t:\t"<<l[i].princ_amt;
		cout<<"\t\t\tRate:\t"<<l[i].rate<<endl;
		cout<<"______________________________________________________________________________\n"<<endl;
		cout<<"\nFuture Instl.\t:\t"<<l[i].l_tenure;
		cout<<"\tFuture Instl Amt \t:\t"<<l[i].payable;
		cout<<"\n\nCurrent EMI \t\:\t"<<l[i].emi;
		cout<<"\n\nRepayment Mode\t:\t"<<"ECS A/C "<<l[i].debit_acc;
		cout<<"\n\n\t----------------------------------------------------------------"<<endl;
		cout<<"\n\tTransactions\t:\t";

		//int size = sizeof(l[i].trans)/sizeof(l[i].trans[0]);

		 for(t=1;t<=5;t++)
		   {
		    cout<<l[i].trans[t]<<"\t";

		}
	
		getch();

	}
////////////////invest class////////////////

     class invest :virtual public user
     {
	 public:
	 int acc_no;
	 char type[8];
	 public:
	 double invst_amt;
	 double maturity_amt;
	 int tenure;
	 protected:
	 double premium_amt;
	 double trans[];

	public:
	void fd(int a);
	void sip(int);
	void paypremiun(int);
	void investstatement(int);
	void invst_search();

     }in[5];
     
    void invest::invst_search()
    {
    int m_menu=0,temp_ac,i;
    char temp[50];
	    while(m_menu!=4)
	      {
	      clrscr();
	       cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\t\t\t   Welcome to Managment pannel"<<endl;
	      cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\n\n\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t1. By Name\t\t\t2. By Mobile No"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t3. By Account No\t\t4. Back"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\n                                        ";
	      cin>>m_menu;
	      if(cin.fail())
	      {
		  cin.clear();
		  cin.ignore();
		  clrscr();
		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
		  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
		  getch ();
	      }
	      else
		switch(m_menu)
		{

		    case 1:
			    cout<<"Enter Name :"<<endl;
			    cin>>temp;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=in_op;i++)
			    {
    				if(strcmp(temp,in[i].name)==0)
    				{
    
				 cout<<in[i].name<<"\t\t"<<in[i].dob<<"\t\t"<<in[i].acc_no<<"\t\t"<<endl;
    				}

			    }
			    if((strcmp(temp,in[i].name)!=0)&&(i>in_op))
			    {
			        cout<<"No Record Found:"<<endl;

			    }
			    getch();
		    break;


		    case 2:
			    cout<<"Enter Mobile No :"<<endl;
			    cin>>temp;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=in_op;i++)
			    {
			     if(strcmp(in[i].mobile_no,temp)==0)
    			     cout<<in[i].name<<"\t\t"<<in[i].dob<<"\t\t"<<in[i].acc_no<<"\t\t"<<endl;
			    }
			    if((strcmp(temp,in[i].name)!=0)&&(i>in_op))
			    {
			        cout<<"No Record Found:"<<endl;
			        
			    }
			    getch();
		    break;


		    case 3:
			    cout<<"Enter Account No :"<<endl;
			    cin>>temp_ac;
			    clrscr();
			    cout<<"Name\t\t"<<"DOB\t\t"<<"Account No\t\t"<<endl;
			    for(i=0;i<=in_op;i++)
			    {
			     if(temp_ac==in[i].acc_no)
			     cout<<in[i].name<<"\t\t"<<in[i].dob<<"\t\t"<<in[i].acc_no<<"\t\t"<<endl;
			    }
			    if((strcmp(temp,in[i].name)!=0)&&(i>in_op))
			    {
			        cout<<"No Record Found:"<<endl;
			        
			    }
			    getch();
		    break;


		    case 4:
			    //goto menu;
		    break;


		    default:
			    clrscr();
    			 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
    			 cout<<"\t\t\t\tInvalid Choice"<<endl;
			 cout<<"\t\t\t\t----------------"<<endl;
    			 getch();
		    break;

		}


	    }

    getch();
}








	void invest::sip(int a)
	{
	    double amount;
	    int t=0;


		 do
		{
		  cout<<"\n\n\t\t\tAmount (per Month) : "<<endl;
		  cout<<"\t\t\t";
		  cin>>amount;
		}while((amount<0) || (amount>10000000));

		do
		{
		 cout<<"\n\t\t\tTenure in Months:"<<endl;
		  cout<<"\t\t\t";
		  cin>>tenure;
		}while((tenure<0)||(tenure>180));

		    maturity_amt=amount*((pow(1.01,tenure)-1)/0.01)*(1.001);
		    invst_amt=amount*tenure;
		    double int_amt=maturity_amt-invst_amt;
		    clrscr();
		    cout<<"\n\n\n\n\t\t\tPremium Amount\t:\t\t"<<amount<<endl;
		    cout<<"\t\t\tPrincipal Amount ("<<tenure<<"Months):\t"<<tenure*amount<<endl;
		    cout<<"\t\t\tInterset Amount\t:\t"<<int_amt<<endl;
		    cout<<"\t\t\tMaturity Amount\t:\t"<<maturity_amt<<endl;
		    cout<<"\n\n\n\n\n\n\n\n\nEnter '1' to confirm loan....\n";
		    cout<<"\nEnter '2' to Exit.."<<endl;
		    int confirm;
		    cout<<"\t\t\t";
		    cin>>confirm;
		    if(confirm==1)
			{
			  cout<<"thnx\n\n";
			  in[a].getuser();
			  in[a].maturity_amt=maturity_amt;
			  in[a].premium_amt=amount;
			  in[a].tenure=tenure;
			  in[a].invst_amt=amount;
			  in[a].acc_no = 1200 + rand () +a;
		     cout<<"\n\n\t\t\tYour money is safe with us."<<endl;
			 cout<<"\n\t\t\t------------------------------"<<endl;
			 cout<<"\t\t\tAccount No:\t"<<in[a].acc_no;
			 cout<<"\t\t\t------------------------------"<<endl;
			 while(in[a].trans[t]!=0)
			     {
			       t++;
			     }
			     in[a].trans[t]=amount;
			     investstatement(a);
			     in_op++;
                    
			 getch();

			}
			else
			{
			cout<<"exit"<<endl;

			}



	}

	void invest::fd(int a)
	{

	    double amount;
	    int t=0;
	    do
		{
		  cout<<"\n\n\t\t\tAmount : "<<endl;
		  cout<<"\t\t\t";
		  cin>>amount;
		}while((amount<0) || (amount>10000000));

		do
		{
		 cout<<"\n\t\t\tTenure in Months:"<<endl;
		  cout<<"\t\t\t";
		  cin>>tenure;
		}while((tenure<0)||(tenure>180));

		    maturity_amt=amount+(amount*7*tenure/1200);
		    invst_amt=amount;
		    double int_amt=maturity_amt-invst_amt;
		    clrscr();
		    cout<<"\n\n\t\t\tPremium Amount\t:\t\t"<<amount<<endl;
			    cout<<"\t\t\tPrincipal Amount ("<<tenure<<"Months):\t"<<amount<<endl;
			    cout<<"\t\t\tInterset Amount\t:\t\t"<<int_amt<<endl;
		    cout<<"\t\t\tMaturity Amount\t:\t\t"<<maturity_amt<<endl;
		    cout<<"\n\n\n\n\n\n\n\nEnter '1' to confirm loan....\n";
		    cout<<"\nEnter '2' to Exit.."<<endl;
		    int confirm;
		    cin>>confirm;
		    if(confirm==1)
			{
			  cout<<"thnx\n\n";
			  in[a].getuser();
			  in[a].maturity_amt=maturity_amt;
			  in[a].tenure=tenure;
			  in[a].invst_amt=amount;
			  in[a].acc_no = 1200 + rand () +a;
			  clrscr();
			  cout<<"\n\n\t\t\tYour money is safe with us."<<endl;
			cout<<"\n\t\t\t------------------------------"<<endl;
			cout<<"Account No:\t"<<in[a].acc_no;
			cout<<"\t\t\t------------------------------"<<endl;
			 while(in[a].trans[t]!=0)
			     {
			       t++;
			     }
			     in[a].trans[t]=amount;
                 investstatement(a);
			     in_op++;
			 getch();

			}
			else
			{
			cout<<"exit"<<endl;

			}
	}

	void invest::paypremiun(int acc_no)
	{

	   int i,t=0;
	    for(i=0;i<=5;i++) ////////for saving account
		{
		    if(acc_no==in[i].acc_no)
		    {
			double amount;
			do
			{
			cout << "Enter Amount:" << endl ;
			cin >> amount;
			}while(amount==in[i].premium_amt);
			while(in[i].trans[t]!=0)
				{
					t++;
				    }
			in[i].trans[t] = +amount;
			in[i].invst_amt+= amount;
			in[i].tenure-=1;
			cout<<"Transaction Succesfull"<<endl;
			cout<<"Balance:\t"<<in[i].invst_amt;
			getch();
		    }

		}
	}

	void invest::investstatement(int i)
	{
	    int t;
	    clrscr();
	    cout<<"====================================================================="<<endl;
		cout << "=Customer id:\t";
		cout << in[i].cust_id<<endl;
		cout <<"=Account No:\t";
		cout << in[i].acc_no<<endl;
		cout <<"\n=Name:\t";
		cout << in[i].name<<"\nDOB:\t";
		cout << in[i].dob<<endl;
		cout<<"====================================================================="<<endl;
		cout <<"Balance :\t\t"<<in[i].invst_amt<<endl;
		cout<<"Transactions :\t";
		 for(t=0;t<5;t++)
		   {
		    cout<<in[i].trans[t]<<"\t";

		}
		//cout<<"--------------------------------------------------------------------"<<endl;
		getch();

	}

///////////////////////management class/////////

     class management:public loan,public invest
     {
	public:
	int mng_id;
	protected:
	int pass;
	char name[100];
     public:

     void display();
     void modify();
     void viewstaff();
     void mng_login(int ,int);
     void mngdata(int id, int pass,int i);
     }mng[3];

///////////////   /*management class functions */  /////////////
 void management::mngdata(int id, int pass,int i)
     {
	 mng[i].mng_id=id;
	 mng[i].pass=pass;
	 cout<<"Enter Name :"<<endl;
	 cin.ignore();
	 cin.getline(name,100);
	 clrscr();
	cout<<"\n\n\t---------------------------------------------------------------\n\n";
	cout<<"\t\tName :\t"<<mng[i].name;
	cout<<"\t\tStaff ID :\t"<<mng[i].mng_id;
	cout<<"\n\n\t\tPassword : "<<mng[i].pass;
	cout<<"\n\n\n\n\t---------------------------------------------------------------\n\n";
	cout<<"\t\tYour are Now a Part of AAA_Bank"<<endl;
	cout<<"\n\t---------------------------------------------------------------\n\n";
	getch();

     }



 void management::mng_login(int id,int pass)
 {
     int i;
    for(i=0;i<=mng_op;i++)
    {
	if(id==mng[i].mng_id && pass==mng[i].pass)
	{
	    int login=0,pass,ac_n;
	    while(login!=4)
	    {
	      mngmenu:
	      clrscr();
		cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\t\t\t   Welcome to Managment pannel"<<endl;
	      cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\n\n\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t1. Account Record Sheet\t\t2. Search Account"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t3. Modify Detail\t\t4. Exit"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\n                                        ";
	      cin>>login;
	      if(cin.fail())
	      {
		  cin.clear();
		  cin.ignore();
		  clrscr();
		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
		  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
		  getch ();
	      }
	      else
		switch(login)
		{
////////////////////// account record sheet///////////////////
		 case 1:
		    clrscr();
		    display();
		    break;
///////////////////////// search account/////////////////////
		 case 2:
		    clrscr();


		     int sr_menu=0,ac_n;
		      while(sr_menu!=4)
		      {

		      clrscr();
			   cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\t\t\t   Welcome to Managment pannel"<<endl;
	      cout<<"\t\t\t  -----------------------------"<<endl;
	      cout<<"\n\n\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t1. Account\t\t\t2. Loan"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\t\t3. Investment\t\t\t4. Back"<<endl;
	      cout<<"\t\t-----------------------\t\t----------------\n";
	      cout<<"\n                                        ";
			  cin>>sr_menu;
			  if(cin.fail())
			  {
			      cin.clear();
			      cin.ignore();
			      clrscr();
			      cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
			      cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
			      getch ();
			  }
			  else
			    switch(sr_menu)
			    {
			     case 1:
				    clrscr();
				    acc_search();
				    break;

			     case 2:
				    clrscr();
				    loan_search();
				    break;

			     case 3 :
				  clrscr();
				  invst_search();
				      break;

				 case 4 :
				  goto mngmenu;
				      break;

			    default :
				clrscr();
    			 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
    			 cout<<"\t\t\t\tInvalid Choice"<<endl;
    			 cout<<"\t\t\t\t----------------"<<endl;
    			 getch();
				break;

			    }

			  }

		    break;
//////////////////////// modify account//////////////////////////////
		 case 3 :
		      clrscr();
		      modify();
		      break;
/////////////////////////exit////////////////////////////
		 case 4 :
		      mng_login(1,1);
		      break;

		 default :
		clrscr();
			 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
			 cout<<"\t\t\t\tInvalid Choice"<<endl;
			 cout<<"\t\t\t\t----------------"<<endl;
			 getch();
		break;



		}

	    }

	}
    }

 }

void management::display()
{
    int i;
    cout<<"\n\n\t-------------------------------------------------------------\n";
    cout<<"\t Customer ID\t\t"<<"Account NO\t\t"<<"Balance\t\t"<<endl;
    cout<<"\t-------------------------------------------------------------\n";
    for(i=0;i<=--ac_op;i++)
	{
	  cout<<"\t"<<b[i].cust_id<<"\t\t\t"<<b[i].acc_no<<"\t\t"<<b[i].balance<<"\t\t\t"<<endl;
	}
	ac_op++;
	for(i=0;i<=--loan_op;i++)
	{
	  cout<<"\t"<<l[i].cust_id<<"\t\t\t"<<l[i].acc_no<<"\t\t"<<l[i].payable<<"\t\t\t"<<endl;
	}
	loan_op++;
	for(i=0;i<=--in_op;i++)
	{
	  cout<<"\t"<<in[i].cust_id<<"\t\t\t"<<in[i].acc_no<<"\t\t"<<in[i].invst_amt<<"\t\t\t"<<endl;

	}
	in_op++;
    getch();

}

void management::viewstaff()
{
    int i;
    clrscr();
    cout<<"\n\n\t--------------------------------------------------------\n";
    cout<<"\t Staff ID\t\t"<<"Name\t\t\t"<<"Password\t\t"<<endl;
    cout<<"\t--------------------------------------------------------\n";
    for(i=0;i<=mng_op;i++)
	{
	  cout<<"\t"<<mng[i].mng_id<<"\t\t\t"<<mng[i].name<<"\t\t"<<mng[i].pass<<"\t\t"<<endl;
	}
    getch();
}


void management::modify( )
{

       int option,sr,i;
       char mod[50];
       cout<<"Enter Account no.\n";
       cin>>sr;
       for(i=0; i<=ac_op; i++)
       {
	     
	      if(sr==b[i].acc_no)
	      {
            passbook(i);
    		clrscr();
    		do
		{
        		cout<<"\n1.Edit Name\n";
        		cout<<"\n2.Edit Mobile No.\n";
        		cout<<"\n3.<<-Back To Menu\n";
        		cin>>option;
    		 if(cin.fail())
    	      {
    		  cin.clear();
    		  cin.ignore();
    		  
    		  clrscr();
		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
    		  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
    		  getch ();
    		 
    	      }
    	      else
        		switch(option)
        		{
        		    case 1:
			    clrscr();
        				    cout<<"\nEnter Name you want to change : ";
        				    cin.ignore();
                            cin.getline(mod,50);
        				strcpy(b[i].name,mod);
        				cout<<"\n\n\t\t Data Edited Successfull\n\n";
        				getch();
        				break;
        
        		     case 2 :
        				    do
					     {
        					clrscr();
        					cout<<"Enter Mobile No :\n";
        					cin.ignore();
                            cin.getline(mod,50);
        					if(strlen(mod)!=10)
        					cout<<"Enter Correct Input\n";
        
        				      }while(strlen(mod)!=10);

        				strcpy(b[i].mobile_no,mod);
        				cout<<"\n\n\t\t Data Edited Successfull\n\n";
        				getch();
        				    break;
        
        		    case 3 :
        				break;
        
        		   default :
        				    clrscr();
					 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
                			 cout<<"\t\t\t\tInvalid Choice"<<endl;
                			 cout<<"\t\t\t\t----------------"<<endl;
                			 getch();
        				    break;
        	       }
    	   }while(option!=3);
    
    	  break;
	 }
    	 else if(i>ac_op && sr!=b[i].acc_no)
    	  {
    	     cout<<"\n\n\n\n\n\t\t\t------Account Not Found-------\n";
    	     getch();
    	     break;
    	   }

       }


}


////////////////admin class ///////////////////

     class admin:public management
     {
     protected:
     int adim_id;
     int admin_pin;
     double bank_amount;
     double current_amount;

     public:

     void admin_l(int pin);
     void reports();
     void addstaff(int);

     }adm1;

///////////////        /* admin functions */     ////////

    void admin::addstaff(int i)
    {
	clrscr();
	int id,pass;
	cout<<"Create Staff Login PIN :"<<endl;
	cin>>pass;
	id=19+rand()+i;
	mng[i].mngdata(id,pass,i);

    }



   void admin::reports()
    {
	int i,t;
	invst_amt=0;
	princ_amt=0;
	payable=0;
	balance=0;
	maturity_amt=0;
	tenure=0;
	current_amount=0;
	bank_amount=0;

      for(i=0;i<=ac_op;i++)
	{
	  balance+=b[i].balance;
	}
	for(i=0;i<=loan_op;i++)
	{
	  princ_amt+=l[i].princ_amt;
	  payable+=l[i].payable;
	}
	for(i=0;i<=in_op;i++)
	{
	  invst_amt+=in[i].invst_amt;
	  maturity_amt+=in[i].maturity_amt;
	  tenure+=in[i].tenure;

	}
    tenure=tenure/12;

	clrscr();
	cout<<"\t\t\t\t--------------\n";
	cout<<"\t\t\t\tBalance Sheet\n";
	cout<<"\t\t\t\t--------------\n\n\n";
	cout<<"\n\tDeposits from saving:\t\t"<<balance;
	cout<<"\n\tNet Investment :\t\t"<<invst_amt;
	cout<<"\n\tLoan distriutions:\t\t"<<princ_amt;
	cout<<"\n\n\t-------------------------------------------------------------------\n\n";
	cout<<"\t\t\t\t-----------------\n";
	cout<<"\t\t\t\tAccount Holdings\n";
	cout<<"\t\t\t\t-----------------\n\n\n";
	cout<<"\tSaving & current accounts:\t"<<ac_op<<endl;
	cout<<"\tLoan accounts:\t\t\t"<<loan_op<<endl;
	cout<<"\tInvestment accounts:\t\t"<<in_op<<endl;
	getch();
	clrscr();


	 current_amount=(balance+ balance*0.041/100)+(invst_amt+invst_amt*0.13)-princ_amt+(princ_amt*0.03/100)-(maturity_amt*0.0027);    ///daily return
     bank_amount=(balance+ balance*15/100)+(invst_amt+invst_amt*40/100)-(princ_amt-payable)-(maturity_amt*0.0027/tenure);

	cout<<"\t\t\t\t-------------\n";
	cout<<"\t\t\t\t Bank Report\n";
	cout<<"\t\t\t\t-------------\n\n\n";
	cout<<"\t\t Current Amount:\t\t"<<current_amount<<endl;
	cout<<"\n\n\t\t Bank Amount After 1 year:\t"<<bank_amount<<endl;
	double profit,cust_amt;
	profit=bank_amount-balance-maturity_amt-princ_amt+payable;
	cust_amt=balance+maturity_amt;
	cout<<"\n\n\t\t User Amount\t\t\t";
	cout<<cust_amt;
	cout<<"\n\n\n\t\t----------------------------------------------"<<endl;
    cout<<"\t\t Financial Year Profit:\t\t";
    cout<<profit;
    cout<<"\n\t\t----------------------------------------------"<<endl;

      getch();
    }

    void admin::admin_l(int pin)
     {
	if(pin==9009)
	{



	      int menu_opt1=0,pass,acc_no;
	      while(menu_opt1!=7)
	      {
		adm_menu:
	      clrscr();
	      cout<<"\t\t\t----------------------------"<<endl;
	      cout<<"\t\t\t   Welcome to admin pannel"<<endl;
	      cout<<"\t\t\t----------------------------"<<endl;
	      cout<<"\n\n\t\t--------------\t\t\t-------------\n";
	      cout<<"\t\t1. Accounts\t\t\t2. Loans"<<endl;
	      cout<<"\t\t--------------\t\t\t-------------\n";
	      cout<<"\t\t--------------\t\t\t-------------\n";
	      cout<<"\t\t3. Investments\t\t\t4. Report"<<endl;
	      cout<<"\t\t--------------\t\t\t-------------\n";
	      cout<<"\t\t--------------\t\t\t-------------\n";
	      cout<<"\t\t5. Add Staff\t\t\t6. View Staff"<<endl;
	      cout<<"\t\t--------------\t\t\t-------------\n";
	      cout<<"\n\t\t\t\t   --------\n";
	      cout<<"\t\t\t\t   7. Exit"<<endl;
	      cout<<"\t\t\t\t   --------\n";
	      cin>>menu_opt1;

	      if(cin.fail())
	      {
		  cin.clear();
		  cin.ignore();
		  clrscr();
		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
		  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
		  getch ();
	      }
	      else
		switch(menu_opt1)
		{

/////////////////////////////////////////case 1 Accounts ////////////////////////

		    case 1:
			    clrscr();

			    int menu_opt2=0 ;
			    while (menu_opt2 != 6)
			    {
			      clrscr ();


	      cout<<"\t\t\t\t\t-------"<<endl;
	      cout<<"\t\t\t\t\t MENU"<<endl;
	      cout<<"\t\t\t\t\t-------"<<endl;
	      cout<<"\n\n\t\t---------------------\t\t-------------\n";
	      cout<<"\t\t1. Create New Account\t\t2. Withdraw"<<endl;
	      cout<<"\t\t---------------------\t\t-------------\n";
	      cout<<"\t\t---------------------\t\t-------------\n";
	      cout<<"\t\t3. Deposite\t\t\t4. Passbook"<<endl;
	      cout<<"\t\t---------------------\t\t-------------\n";
	      cout<<"\t\t---------------------\t\t-------------\n";
	      cout<<"\t\t5. Search\t\t\t6. Back"<<endl;
	      cout<<"\t\t---------------------\t\t-------------\n";
			      cin >> menu_opt2;
			      if(cin.fail())
			      {
				  cin.clear();
				  cin.ignore();
				  clrscr();
				  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
				  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
				  getch ();
			      }
			      else
				  switch (menu_opt2)
				  {
				    case 1:
					clrscr();
					b[ac_op].getuser();
					b[ac_op].open(ac_op);
					b[ac_op].passbook(ac_op);
					ac_op++;

					  break;


					case 2:
					  clrscr();
					  double amount;
					  cout<<"Enter account No."<<endl;
					  cin>>acc_no;
                       do
                       {
			   clrscr();
					   cout << "Enter Amount:" << endl ;
					   cin >> amount;
					  if(cin.fail())
            	      {
            		  cin.clear();
            		  cin.ignore();
            		  clrscr();
            		  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
			  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
            		  getch ();
            	      }
	                  else
					   withdraw(acc_no,amount);
                       }while((amount<0) || (amount>10000000));
  
				    break;

					case 3:
						   clrscr();
						   cout<<"Enter account No."<<endl;
						   cin>>acc_no;
						   deposit(acc_no);
					break;

				    case 4:
					      clrscr();
					      int i;
					      cout<<"Enter account No."<<endl;
						  cin>>acc_no;
						  for(i=0;i<=5;i++)
						  {
						 if(acc_no==b[i].acc_no)
						 {
						    passbook(i);
						    break;
						 }
						  }
					break;

					case 5:
						 acc_search();

					break;

					case 6:
						  goto adm_menu;

					break;

					default:
						cout<<"Exited";
					  break;


				    }

			    }
		    break;

//////////////////////////////////////////////case 2 loan////////////////////////

		    case 2:

			    clrscr();

			    int menu_opt3=0;
			    while (menu_opt3 != 6)
			    {
			      clrscr ();

		cout<<"\t\t\t\t\t-------"<<endl;
	      cout<<"\t\t\t\t\t MENU"<<endl;
	      cout<<"\t\t\t\t\t-------"<<endl;
	      cout<<"\n\n\t\t----------------------\t\t-------------\n";
	      cout<<"\t\t1. Create Loan Account\t\t2. Pay EMI"<<endl;
	      cout<<"\t\t-----------------------\t\t-------------\n";
	      cout<<"\t\t--------------\t\t\t-------------\n";
	      cout<<"\t\t3. Deposite\t\t\t4. Statement"<<endl;
	      cout<<"\t\t--------------\t\t\t-------------\n";
	      cout<<"\t\t-----------------\t\t-------------\n";
	      cout<<"\t\t5. Close Account\t\t6. Back"<<endl;
	      cout<<"\t\t-----------------\t\t-------------\n";
	      cin >> menu_opt3;
			      if(cin.fail())
			      {
				  cin.clear();
				  cin.ignore();
				  clrscr();
				  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
				  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
				  getch ();
			      }
			      else
				  switch (menu_opt3)
				  {
				    case 1:
					clrscr();
					adm1.getloan(loan_op);
					loan_op++;

					  break;


					case 2:
					  clrscr();
					  cout<<"Enter Loan account No."<<endl;
					  cin>>acc_no;
					  adm1.payemi(acc_no);

				    break;

					case 3:
						   clrscr();
						   cout<<"Enter account No."<<endl;
						   cin>>acc_no;
						   adm1.deposit(acc_no);
					break;

				    case 4:
						  clrscr();
					      int i;
					      cout<<"Enter account No."<<endl;
						  cin>>acc_no;
						  for(i=0;i<=loan_op;i++)
						  {
						 if(acc_no==l[i].acc_no)
						 {
						    loanstatement(i);
						    break;
						 }
						  }
					break;


					case 5:
					cout<<"coming soon";
						break;

					case 6:

					      goto adm_menu;

					break;


					default:
						clrscr();
			             cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
				     cout<<"\t\t\t\tInvalid Choice"<<endl;
			             cout<<"\t\t\t\t----------------"<<endl;
			             getch();
					  break;


				    }

			    }


		    break;
//////////////////////////////////////////////case 3 Investment//////////////////

		    case 3 :

			    clrscr();

			    int menu_opt4=0;
			    while (menu_opt4 != 4)
			    {
			      clrscr ();
				cout<<"\t\t\t\t-------"<<endl;
	      cout<<"\t\t\t\t MENU"<<endl;
	      cout<<"\t\t\t\t-------"<<endl;
	      cout<<"\n\n\t\t-------------\t\t-------------\n";
	      cout<<"\t\t1. Create FD\t\t2. Create SIP"<<endl;
	      cout<<"\t\t-------------\t\t-------------\n";
	      cout<<"\t\t--------------\t\t-------------\n";
	      cout<<"\t\t3. Pay Premium\t\t4. Statement"<<endl;
	      cout<<"\t\t--------------\t\t-------------\n";
	      cout<<"\n\t\t\t\t-----------\n";
	      cout<<"\t\t\t\t5. Back"<<endl;
	      cout<<"\t\t\t\t-----------\n";

			      cin >> menu_opt4;
			      if(cin.fail())
			      {
				  cin.clear();
				  cin.ignore();
				  clrscr();
				  cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
				  cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
				  getch ();
			      }
			      else
				  switch (menu_opt4)
				  {
				    case 1:
					clrscr();
					adm1.fd(in_op);

					  break;


					case 2:
					  clrscr();
					  adm1.sip(in_op);

				    break;



				    case 3:
						  clrscr();
						   cout<<"Enter account No."<<endl;
						   cin>>acc_no;
						   adm1.paypremiun(acc_no);

					break;

					case 4:
                            clrscr();
					      int i;
					      cout<<"Enter account No."<<endl;
						  cin>>acc_no;
						  for(i=0;i<=in_op;i++)
						  {
						 if(acc_no==in[i].acc_no)
						 {
						    investstatement(i);
						    break;
						 }
						  }
					      
					break;
					
                    case 5:
                             goto adm_menu;
                    break;
                    
					default:
						cout<<"Exited";
					  break;


				    }

			    }
		    break;
//////////////////////////////////////////////case 4 reports//////////////////
		    case 4:
			reports();
		    break;
//////////////////////////////////////////////case 5 add staff//////////////////
		    case 5:
			    addstaff(mng_op);
			    mng_op++;

			 break;
//////////////////////////////////////////////case 6 viewstaff//////////////////
		    case 6:
			   viewstaff();

			 break;
//////////////////////////////////////////////case 6 Exit//////////////////
		    case 7:
			   admin_l(1111);

			 break;

/////////////////////////////////////default/////////////////////////////////////

		    default :

			 clrscr();
			 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
			 cout<<"\t\t\t\tInvalid Choice"<<endl;
			 cout<<"\t\t\t\t----------------"<<endl;
			 getch();
		    break;

		}

	      }

	}
       /* else
	{
	clrscr();
	cout<<"\n\n\n\t\t\tInvalid pin"<<endl;
	getch();

	} */


     }




/////////////////////////main////////////////////////////


int main ()
{


  clrscr();
   int gm,gd=DETECT;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   
   
   setcolor(3);
   setfillstyle(SOLID_FILL,3);
   circle(310,200,70);
   floodfill(310,200,3);
   //////left side line
   line(70,220,223,220);
   line(50,200,220,200);
   line(70,180,223,180);
   ////////////right side lines
   line(395,220,548,220);
   line(400,200,570,200);
   line(395,180,548,180);

    setcolor(BLACK);
   setfillstyle(SOLID_FILL,BLACK);
   circle(310,200,60);
   floodfill(310,200,BLACK);
   setcolor(3);


   outtextxy(280,200,"AAA_Bank");
   getch();
   closegraph();

 int login,pass,ac_n,i;
  while(login!=4)
  {

    clrscr();
   int gm,gd=DETECT;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   setcolor(3);
   setfillstyle(SOLID_FILL,3);
   rectangle(140,140,500,350);
   //arc(130,240,90,270,100);
   floodfill(130,240,3);//bgcolor
   floodfill(140,140,3);
   setcolor(3);
   outtextxy(250,180,"1. Admin Login");
   outtextxy(250,220,"2. Management Login");
   outtextxy(250,260,"3. User Login");
   outtextxy(250,300,"4. Exit");
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   cin>>login;
   closegraph();
  if(cin.fail())
  {
      cin.clear();
      cin.ignore();
      clrscr();
      cout<<"\n\n\n\t\t\tEnter Integer Value"<<endl;
      cout<<"\n\n\n\n\n\npress Any key to Continue........"<<endl;
      getch ();
  }
  else
    switch(login)
    {
     case 1:
	    clrscr();
	     int i,gm,gd=DETECT;
	     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	    setcolor(3);
	    setfillstyle(SOLID_FILL,3);
	    circle(310,200,70);
	    floodfill(310,200,3);
	    setcolor(BLACK);
	    setfillstyle(SOLID_FILL,BLACK);
	    circle(310,200,50);
	    floodfill(310,200,BLACK);
	    setcolor(3);
	    outtextxy(280,200,"AAA_Bank");
	    outtextxy(260,280,"Enter Password");
	     line(260,290,380,290);
	    line(260,330,380,330);
	    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    ";
	    cin>>pass;
	    closegraph();
	    adm1.loading();
	    adm1.admin_l(pass);
	    break;


    case 2:

	    clrscr();
	     cout<<"\n\n\n\n\t\t\t__________________________"<<endl;
	    cout<<"\t\t\tEnter Staff ID :  ";
	    cin>>ac_n;
	     cout<<"\n\t\t\t__________________________"<<endl;
	    cout<<"\n\n\n\n\t\t\t__________________________"<<endl;
	    cout<<"\t\t\tEnter Password:  ";
	    cin>>pass;

	    for(i=0;i<=mng_op;i++) ////////for saving account
	   {
	    if(ac_n==mng[i].mng_id)
	    {

		     adm1.loading();
		     mng[i].mng_login(ac_n,pass);

	    }
	    else if(ac_n!=mng[i].mng_id && i==1+mng_op)
	    {
	    adm1.loading();
	    cout<<"\n\n\n\t\t\tNo Record Found"<<endl;
	    getch();
	    }
	}
	break;



     case 3:
	    clrscr();
	    cout<<"\n\n\n\n\t\t\t__________________________"<<endl;
	    cout<<"\t\t\tEnter Account No.  ";
	    cin>>ac_n;
	    cout<<"\n\t\t\t__________________________"<<endl;
	    cout<<"\n\n\n\n\t\t__________________________"<<endl;
	    cout<<"\t\t\tEnter Password  ";
	    cin>>pass;
	     cout<<"\n\t\t__________________________"<<endl;

	    for(i=0;i<=5;i++) ////////for saving account
	{
	    if(ac_n==b[i].acc_no)
	    {

		     b[i].users(ac_n,pass);

	    }
	    else if(ac_n!=b[i].acc_no && i==5)
	    {
	    adm1.loading();
	    cout<<"\n\n\n\t\t\tNo Record Found"<<endl;
	    getch();
	    }
	}
	    break;

     case 4 :
	  exit(0);
	      break;

     default :
		clrscr();
			 cout<<"\n\n\n\n\n\n\n\t\t\t\t----------------"<<endl;
			 cout<<"\t\t\t\tInvalid Choice"<<endl;
			 cout<<"\t\t\t\t----------------"<<endl;
			 getch();
	break;

    }

  }


return 0;
}
