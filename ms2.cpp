#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

// HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//   SetConsoleTextAttribute(hConsole,1);

void clearScreen();
void mainHeader();
void subMenu(string menuName);
int adminMenu(int chose);
string who(string usernameB[], string passwordB[], string rolesB[], int max_rec, string lusername);
void addUser(string username, string password, string role, int record, int u_count, string usernameC[], string passwordC[], string rolesC[]);
void addproducts(int count_pro, string product_nameC[], float product_priceC[], string company_nameC[]);
void addproductsIntoArray(string productname, float productprice, string companyname, int c_product, string product_nameB[], float product_priceB[], string company_nameB[]);
void viewAllproducts(string product_nameD[], float product_priceD[], string company_nameD[], int cou_pro);
void addNewUser(int REC, int usercounts, string usernameD[], string passwordD[], string rolesD[]);
bool deleteproduct(string product_nameE[], float product_priceE[], string company_nameE[], int count_product);
int EmployerMenu();
int sortingMenu();
void addDiscount(int count_product, string product_nameF[], float product_priceF[], string company_nameF[], float dis[], float dis_price[]);
void descending_sorting(int count_product, string product_nameG[], float product_priceG[], string company_nameG[], float dis_price[]);
void ascending_sorting(int count_product, string product_nameH[], float product_priceH[], string company_nameH[], float dis_price[]);
int CustomerMenu();
void updateproduct(string product_nameI[], float product_priceI[], string company_nameI[], int count_product, float discount_price[]);
void addbooking(int c_booking, char bookingC[]);
void addBookingIntoArray(char book, int count_booking, char bookingB[]);
void calculateBill(string productA[],int count_product,string company_nameA[],float product_priceA[],float discount[],float discount_price[],string product_nameA[],int count_customer,string customerA[],int date[],string nameA[],string modelA[],int cwp,int bwp);
void addcustomerIntoArray(string customer,int datte, string modell, string namee, string productt, int count_customer, string customerC[],int date[], string modelC[], string nameC[], string productC[], int CUSTOMER);
void addcustomer(string customerA[],int date[],string modelA[],string nameA[],string productA[],int count_customer,int CUSTOMER);
void addAmountIntoArray(float tamount, float AmountB[], int count_amount, int CUSTOMER);
void addamount(float AmountC[], int count_amount, int CUSTOMER);
void addEmployeUser(int REC, int usercounts, string usernameA[], string passwordA[], string rolesA[]);
void gotoxy(int x, int y);
int RatelistGenerator();
void customerBill(int count_customer, string customerA[], string loginusername, string nameA[], string modelA[], int cwp, int bwp, string productA[], int count_amount, float AmountA[], string usernameA[], int usercount);
string parsedata(string s, int field);
void store(string product_nameA[], float product_priceA[], string company_nameA[], int count_product);
int load(string product_nameA[], float product_priceA[], string company_nameA[], int count_product);

main()
{
  const int MAX_RECORDS = 20;
  string usernameA[MAX_RECORDS];
  string passwordA[MAX_RECORDS];
  string rolesA[MAX_RECORDS];
  string loginusername = " ";
  int userCount = 0;
  int count_product = 0;
  string product_nameA[MAX_RECORDS];
  float product_priceA[MAX_RECORDS];
  string company_nameA[MAX_RECORDS];
  float discount[MAX_RECORDS];
  float discount_price[MAX_RECORDS];
  
  int choose;
  int cwp = 1500;
  int bwp = 500;
  int sortingOption = 0;
  int listOption = 0;
  int count_booking = 0;
  char bookingA[MAX_RECORDS];
  const int CUSTOMER = 20;
  string customerA[CUSTOMER];
  int date[CUSTOMER];
  string modelA[CUSTOMER];
  string nameA[CUSTOMER];
  int count_customer = 0;
  int count_amount = 0;
  string product;
  float AmountA[CUSTOMER];
  string productA[CUSTOMER];
 
  string w = " ";
 
  count_product = load(product_nameA, product_priceA, company_nameA, count_product);

  while (true)
  {
    addUser("admin", "123", "ADMIN", MAX_RECORDS, userCount, usernameA, passwordA, rolesA);
    system("CLS");
    w = who(usernameA, passwordA, rolesA, MAX_RECORDS, loginusername);

    if (w == "ADMIN")
    {
      // clearScreen();
      cout << endl;
      cout << "***|***    Welcome Admin    ***|***" << endl;
      cout << endl;
      int adminOption = 0;

      while (true)
      {
        mainHeader();
        adminOption = adminMenu(choose);
        if (adminOption == 1)
        {
          mainHeader();
          subMenu("ADD NEW PRODUCT");
          addproducts(count_product, product_nameA, product_priceA, company_nameA);
          count_product = count_product + 1;
          store(product_nameA, product_priceA, company_nameA, count_product);
          cout << endl;
          clearScreen();
        }

        else if (adminOption == 2)
        {
          mainHeader();
          subMenu("RECORD OF PRODUCTS");
          viewAllproducts(product_nameA, product_priceA, company_nameA, count_product);
          cout << endl;
          clearScreen();
        }

        else if (adminOption == 3)
        {
          while (true)
          {
            mainHeader();
            listOption = RatelistGenerator();
            if (listOption == 1)
            {
              mainHeader();
              subMenu("Change Rate List Generator");
              gotoxy(0,9);
              cout << "Car Wash Price:";
              gotoxy(0,10);
              cin >> cwp;
              gotoxy(22,9);
              cout << "Bike Wash Price:";
              gotoxy(22,10);
              cin >> bwp;
              cout << endl;
              clearScreen();
            }

            else if (listOption == 2)
            {
              cwp = 1500;
              bwp = 500;
              mainHeader();
              subMenu("Old Rate List Generator");
              gotoxy(0,9);
              cout << "Car Wash Price:";
              gotoxy(0,10);
              cout << cwp << endl;
              gotoxy(22,9);
              cout << "Bike Wash Price:" ;
              gotoxy(22,10);
              cout << bwp << endl;
              cout << endl;
              clearScreen();
            }
            else if (listOption == 3)
            {
              break;
            }

            else
            {
              cout << "YOU ENTERED WRONG OPTION." << endl;
            }
          }
        }

        else if (adminOption == 4)
        { // Discount and Sorting
          while (true)
          {
            mainHeader();
            sortingOption = sortingMenu();
            if (sortingOption == 1)
            { // Discount
              mainHeader();
              subMenu("Discounts");
              addDiscount(count_product, product_nameA, product_priceA, company_nameA, discount, discount_price);
              clearScreen();
            }

            else if (sortingOption == 2)
            { // Sorting in Ascending order
              mainHeader();
              subMenu("Ascending Order Sorting");
              ascending_sorting(count_product, product_nameA, product_priceA, company_nameA, discount_price);
              clearScreen();
            }

            else if (sortingOption == 3)
            { // sorting in Descending order
              mainHeader();
              subMenu("Descending Order Sorting");
              descending_sorting(count_product, product_nameA, product_priceA, company_nameA, discount_price);
              clearScreen();
            }

            else if (sortingOption == 4)
            {
              break;
            }

            else
            {
              cout << "YOU ENTERED WRONG OPTION." << endl;
            }
          }
        }

        else if (adminOption == 5)
        {
          // Update product
          mainHeader();
          subMenu("Update Product");
          updateproduct(product_nameA, product_priceA, company_nameA, count_product, discount_price);
          cout << endl;
          clearScreen();
        }

        else if (adminOption == 6)
        {
          // Delete product
          mainHeader();
          subMenu("Delete Product");
          if (deleteproduct(product_nameA, product_priceA, company_nameA, count_product) == true)
          {
            count_product--;
          }
          else
          {
            gotoxy(14, 11);
            cout << "Invalid Company name." << endl;
          }
          cout << endl;
          clearScreen();
        }

        else if (adminOption == 7)
        {
          // ADD NEW USER
          if (userCount <= MAX_RECORDS)
          {
            mainHeader();
            subMenu("ADD USER");
            addNewUser(MAX_RECORDS, userCount, usernameA, passwordA, rolesA);
            userCount = userCount + 1;
            cout << endl;
            clearScreen();
          }
        }

        else if (adminOption == 8)
        {
          // logout
          break;
        }

        else if (adminOption >= 9 || adminOption <= 0)
        {
          cout << "YOU CHOOSE WRONG OPTION." << endl;
        }
      }
    }

    else if (w == "EMPLOYER")
    {
      cout << endl;
      cout << "***|***    Welcome Employer    ***|***" << endl;
      cout << endl;
      int employerOption = 0;
      while (true)
      {
        mainHeader();
        employerOption = EmployerMenu();
        if (employerOption == 1)
        {
          mainHeader();
          subMenu("Records of Products");
          viewAllproducts(product_nameA, product_priceA, company_nameA, count_product);
          clearScreen();
        }

        else if (employerOption == 2)
        {
          mainHeader();
          subMenu("RATE LIST GENERATOR");
          gotoxy(0,9);
          cout << "Car Wash Price:";
          gotoxy(0,10);
          cout << cwp << endl;
          gotoxy(22,9);
          cout << "Bike Wash Price:" ;
          gotoxy(22,10);
          cout << bwp << endl;
          cout << endl;
          clearScreen();
        }

        else if (employerOption == 3)
        { // Discount and Sorting
          while (true)
          {
            mainHeader();
            sortingOption = sortingMenu();
            if (sortingOption == 1)
            { // Discount
              mainHeader();
              subMenu("Discounts");
              addDiscount(count_product, product_nameA, product_priceA, company_nameA, discount, discount_price);
              clearScreen();
            }

            else if (sortingOption == 2)
            { // Sorting in Ascending order
              mainHeader();
              subMenu("Ascending Order Sorting");
              ascending_sorting(count_product, product_nameA, product_priceA, company_nameA, discount_price);
              clearScreen();
            }

            else if (sortingOption == 3)
            { // sorting in Descending order
              mainHeader();
              subMenu("Descending Order Sorting");
              descending_sorting(count_product, product_nameA, product_priceA, company_nameA, discount_price);
              clearScreen();
            }

            else if (sortingOption == 4)
            {
              break;
            }

            else
            {
              cout << "YOU ENTERED WRONG OPTION." << endl;
            }
          }
        }

        else if(employerOption == 4)
        {
            mainHeader();
            subMenu("Add Customer");
            addcustomer(customerA,date,modelA,nameA,productA,count_customer,CUSTOMER);
            count_customer = count_customer + 1;
            clearScreen();
        }

        else if (employerOption == 5)
        {
          // Booking of Services
          mainHeader();
          subMenu("Add Booking");
          addbooking(count_booking, bookingA);
          count_booking = count_booking + 1;
          cout << endl;
          clearScreen();
        }

        else if (employerOption == 6)
        {
          // Calculate Bill
          mainHeader();
          subMenu("Calculate Bill");
          calculateBill(productA,count_product,company_nameA,product_priceA,discount,discount_price,product_nameA,count_customer,customerA,date,nameA,modelA,cwp,bwp);
          addamount(AmountA,count_amount, CUSTOMER);
          count_amount=count_amount+1;
        
          clearScreen();
        }

        else if(employerOption == 7)
        {
          mainHeader();
          subMenu("Add Customer User");
          addEmployeUser(MAX_RECORDS,userCount,usernameA,passwordA,rolesA);
          userCount = userCount + 1;
          clearScreen();
        }
        
        else if (employerOption == 8)
        { // Logout
          break;
        }

        else
        {
          cout << "YOU CHOOSE WRONG OPTION." << endl;
        }
      }
    }

    else if (w == "CUSTOMER")
    {
      string customername;
      cout << endl;
      cout << "***|***    Welcome Customer    ***|***" << endl;
      cout << endl;
      int customerOption = 0;
      while (true)
      {
        mainHeader();
        customerOption = CustomerMenu();

        if (customerOption == 1)
        { // View your profile
          
          mainHeader();
          subMenu("YOUR PROFILE");
          
          cout << "Enter your name:";
          cin >> customername;
          for(int x=0; x<count_customer; x++)
          {
            if(customerA[x] == customername)
            {
              //cout << "Customer Name:" << customerA[x] << endl;
              cout << "Welcome to the Profile menu." << endl;
              
            } 
          }
          clearScreen();
        }

        else if (customerOption == 2)
        { // Records of products
          mainHeader();
          subMenu("RECORDS OF PRODUCTS");
          viewAllproducts(product_nameA, product_priceA, company_nameA, count_product);
          clearScreen();
        }

        else if (customerOption == 3)
        { // Rate List Generator
          mainHeader();
          subMenu("RATE LIST GENERATOR");
          gotoxy(0,9);
          cout << "Car Wash Price:";
          gotoxy(0,10);
          cout << cwp << endl;
          gotoxy(22,9);
          cout << "Bike Wash Price:" ;
          gotoxy(22,10);
          cout << bwp << endl;
          cout << endl;
          clearScreen();
        }

        else if (customerOption == 4)
        { // Booking
          mainHeader();
          subMenu("BOOKING");
          
          for(int x=0; x<count_customer; x++)
          {
            if(customerA[x] == customername)
            {
              cout << "Customer Name:" << customerA[x] << endl;
              cout << "Model:" << modelA[x] << endl;
              cout << "Booking:" << bookingA[x] << endl;
            } 
          }
  
          clearScreen();
        }

        else if (customerOption == 5)
        { // Bill
          //customerBill(count_customer, customerA, loginusername, nameA, modelA, cwp, bwp, productA, count_amount, AmountA, usernameA, userCount);
          mainHeader();
          subMenu("Customer Bill");
          for(int x=0; x<count_customer; x++)
          {
            if(customerA[x] == customername)
            {
              cout << "Customer Name: " << customerA[x] << endl;
              cout << "Date: " << date[x] << endl;
              cout << "Car/Bike Service: " << nameA[x] << endl;
              cout << "Car/Bike Model: " << modelA[x] << endl;
              cout << "Product: " << productA[x] << endl;
              cout << "Total Amount: " << AmountA[x] << endl;
            } 
          }
          clearScreen();
        }

        else if (customerOption == 6)
        { // Logout
          break;
        }

        else
        {
          cout << "YOU CHOOSE WRONG OPTION." << endl;
        }
      }
    }

    else
    {
      gotoxy(15,0);
      cout << "****Login to System****" << endl;
      cout << endl;
      cout << "You entered wrong username or password! " << endl;
      clearScreen();
    }
  }
}

void gotoxy(int x, int y)
{
  COORD coordinates; // coordinates is declared as COORD
  coordinates.X = x; // defining x-axis
  coordinates.Y = y; // defining  y-axis
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void clearScreen()
{ //____clear screen_____
  cout << "Press any key to continue " << endl;
  getch();
  system("CLS");
}

void mainHeader()
{ // Header
  cout << "*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*" << endl;
  cout << "* Service Station Management System *" << endl;
  cout << "*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*" << endl;
  cout << "                                     " << endl;
}

void subMenu(string menuName)
{
  cout << "                                     " << endl;
  cout << "Main menu > " << menuName << endl;
  cout << "___________" << endl;
}

string who(string usernameB[], string passwordB[], string rolesB[], int max_rec, string lusername)
{
  gotoxy(15,0);
  cout << "****Login to System****" << endl;
  cout << endl;
  string username, password;
  cout << "__________________            __________________" << endl;
  gotoxy(0, 3);
  cout << "Enter username: " << endl;
  cout << "__________________            __________________" << endl;

  gotoxy(30, 3);
  cout << "Enter Password:" << endl;
  gotoxy(0, 6);
  cin >> username;
  gotoxy(30, 6);
  cin >> password;

  cout << endl;
  cout << endl;
  cout << endl;
  cout << "               ---------------" << endl;
  cout << "               |   Login     |" << endl;
  cout << "               ---------------" << endl;
  clearScreen();

  for (int i = 0; i < max_rec; i++)
  {
    if (usernameB[i] == username && passwordB[i] == password)
    {
      lusername = username;
      return rolesB[i];
    }
  }
  lusername = " ";
  return "Wrong";
}

void addUser(string username, string password, string role, int record, int u_count, string usernameC[], string passwordC[], string rolesC[])
{ //___________Add User___________--
  if (u_count <= record)
  {
    usernameC[u_count] = username;
    passwordC[u_count] = password;
    rolesC[u_count] = role;
    // u_count = u_count + 1;
  }
  else
  {
    cout << "No more space to add new users" << endl;
  }
}

int adminMenu(int chose)
{ // Admin Menu

  subMenu("ADMIN");
  cout << "Select one of the following options:" << endl;
  cout << "1.	Add new product." << endl;
  cout << "2.	Records of all products." << endl;
  cout << "3.	Add rate list generator of services." << endl;
  cout << "4.	Add discounts and sorting." << endl;
  cout << "5.	Update product." << endl;
  cout << "6.	Delete product." << endl;
  cout << "7.	Add User." << endl;
  cout << "8.	Exit." << endl;

  // char chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

void addproducts(int count_pro, string product_nameC[], float product_priceC[], string company_nameC[])
{ //_________________Add Product________________
  string pname, cname;
  float pprice;
  gotoxy(0, 8);
  cout << "_____________" << endl;
  gotoxy(0, 9);
  cout << "Product Name:";
  gotoxy(0, 10);
  cout << "_____________" << endl;

  gotoxy(31, 8);
  cout << "______________" << endl;
  gotoxy(31, 9);
  cout << "Product Price:";
  gotoxy(31, 10);
  cout << "______________" << endl;
 
  gotoxy(63, 8);
  cout << "_____________" << endl;
  gotoxy(63, 9);
  cout << "Company Name:";
  gotoxy(63, 10);
  cout << "_____________" << endl;

  gotoxy(0, 12);
  cin >> pname;

  while (true)
  {
    gotoxy(31, 8);
    cout << "______________" << endl;
    gotoxy(31, 9);
    cout << "Product Price:";
    gotoxy(31, 10);
    cout << "______________" << endl;
    gotoxy(31, 12);
    cin >> pprice;
    if (pprice <= 0)
    {
      gotoxy(31, 13);
      cout << "Again enter the Price." << endl;
    }
    else
    {
      break;
    }
  }
  
  gotoxy(63, 12);
  cin >> cname;

  addproductsIntoArray(pname, pprice, cname, count_pro, product_nameC, product_priceC, company_nameC);
}

void addproductsIntoArray(string productname, float productprice, string companyname, int c_product, string product_nameB[], float product_priceB[], string company_nameB[])
{ //______Store product data into array____each time addProduct() function is called. it will store into array
  product_nameB[c_product] = productname;
  product_priceB[c_product] = productprice;
  company_nameB[c_product] = companyname;
}

void viewAllproducts(string product_nameD[], float product_priceD[], string company_nameD[], int cou_pro)
{ //_____________View All product________________
  cout << endl;
  cout << "------------    -----    -------" << endl;
  cout << "Product name\tPrice\tCompany" << endl;
  cout << "------------    -----    -------" << endl;
  for (int i = 0; i < cou_pro; i++)
  {
    cout << product_nameD[i] << " \t" << product_priceD[i] << " \t" << company_nameD[i] << endl;
  }
}

int RatelistGenerator()
{
  subMenu("Rate List Generator");
  cout << "1. Change Rate List Generator." << endl;
  cout << "2. Old Rate List Generator." << endl;
  cout << "3. Exit." << endl;

  int chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

int sortingMenu()
{
  subMenu("Discount and Sorting");
  cout << "1. Discounts on Products." << endl;
  cout << "2. Soritng in Ascending Order." << endl;
  cout << "3. Sorting in Descending Order." << endl;
  cout << "4. Exit." << endl;

  int chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

void addDiscount(int count_product, string product_nameF[], float product_priceF[], string company_nameF[], float dis[], float dis_price[])
{ //___________Add Discount____________

  for (int x = 0; x < count_product; x = x + 1)
  {
    if (product_priceF[x] < 1500)
    {
      dis[x] = product_priceF[x] * 5 / 100;
      dis_price[x] = product_priceF[x] - dis[x];
      // cout << "Discount price is" << "[" << x+1 << "]" << ":" << dis_price[x] << endl;
    }

    else
    {
      dis[x] = product_priceF[x] * 10 / 100;
      dis_price[x] = product_priceF[x] - dis[x];
      // cout << "Discount price is" << "[" << x+1 << "]" << ":"  << dis_price[x] << endl;
    }
  }
  cout << "------------    -----   ------- -------------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----   ------- -------------" << endl;
  cout << endl;
  for (int i = 0; i < count_product; i++)
  {
    cout << product_nameF[i] << " \t" << product_priceF[i] << " \t" << company_nameF[i] << " \t" << dis_price[i] << endl;
  }
}

void ascending_sorting(int count_product, string product_nameH[], float product_priceH[], string company_nameH[], float dis_price[])
{ //__________Ascending Order Sorting_________
  for (int i = 0; i < count_product; i++)
  {
    for (int j = i + 1; j < count_product; j++)
    {
      if (product_priceH[i] > product_priceH[j])
      {
        float temp = product_priceH[i];
        product_priceH[i] = product_priceH[j];
        product_priceH[j] = temp;

        string temp_company = company_nameH[i];
        company_nameH[i] = company_nameH[j];
        company_nameH[j] = temp_company;

        string temp_product = product_nameH[i];
        product_nameH[i] = product_nameH[j];
        product_nameH[j] = temp_product;

        float temp_discount = dis_price[i];
        dis_price[i] = dis_price[j];
        dis_price[j] = temp_discount;
      }
    }
  }

  cout << "------------    -----   ------- -------------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----   ------- -------------" << endl;
  cout << endl;
  for (int i = 0; i < count_product; i++)
  {
    cout << product_nameH[i] << " \t" << product_priceH[i] << " \t" << company_nameH[i] << " \t" << dis_price[i] << endl;
  }
}

void descending_sorting(int count_product, string product_nameG[], float product_priceG[], string company_nameG[], float dis_price[])
{ //__________Descending Order Sorting_________
  for (int i = 0; i < count_product; i++)
  {
    for (int j = i + 1; j < count_product; j++)
    {
      if (product_priceG[i] < product_priceG[j])
      {
        float temp = product_priceG[i];
        product_priceG[i] = product_priceG[j];
        product_priceG[j] = temp;

        string temp_company = company_nameG[i];
        company_nameG[i] = company_nameG[j];
        company_nameG[j] = temp_company;

        string temp_product = product_nameG[i];
        product_nameG[i] = product_nameG[j];
        product_nameG[j] = temp_product;

        float temp_discount = dis_price[i];
        dis_price[i] = dis_price[j];
        dis_price[j] = temp_discount;
      }
    }
  }

  cout << "------------    -----   ------- -------------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----   ------- -------------" << endl;
  cout << endl;
  for (int i = 0; i < count_product; i++)
  {
    cout << product_nameG[i] << " \t" << product_priceG[i] << " \t" << company_nameG[i] << " \t" << dis_price[i] << endl;
  }
}

bool deleteproduct(string product_nameE[], float product_priceE[], string company_nameE[], int count_product)
{
  string company;
  gotoxy(0, 7);
  cout << "Enter the Company name to delete the Product:";
  gotoxy(0, 8);
  cin >> company;
  bool flag = false;
  int index = -1;
  for (int i = 0; i < count_product; i++)
  {
    if (company == company_nameE[i])
    {
      gotoxy(14, 11);
      cout << "Found Company name." << endl;
      index = i;
      flag = true;
      break;
    }

    else
    {
      flag = false;
    }
  }

  if (flag == true)
  {

    for (int x = index; x < count_product - 1; x++)
    {
      company_nameE[x] = company_nameE[x + 1];
      product_nameE[x] = product_nameE[x + 1];
      product_priceE[x] = product_priceE[x + 1];
    }
    gotoxy(12, 13);
    cout << "The Product is deleted!!" << endl;
    return true;
  }
  return false;
}

void addNewUser(int REC, int usercounts, string usernameD[], string passwordD[], string rolesD[])
{
  string username;
  string password;
  string role;
  gotoxy(0, 8);
  cout << "Enter username........ ";
  gotoxy(30, 8);
  cout << "Enter password........ ";
  gotoxy(60, 8);
  cout << "Enter role........";
  gotoxy(0, 9);
  cin >> username;
  gotoxy(30, 9);
  cin >> password;
  
  while (true)
  {
    gotoxy(60, 8);
    cout << "Enter role........";
    gotoxy(60, 9);
    cin >> role;
    if (role != "CUSTOMER" && role != "EMPLOYER")
    {
      gotoxy(60,10);
      cout << "Again enter the Role." << endl;
    }
    else
    {
      break;
    }
  }
  
  addUser(username, password, role, REC, usercounts, usernameD, passwordD, rolesD);
}

void addEmployeUser(int REC, int usercounts, string usernameA[], string passwordA[], string rolesA[])
{
  string username;
  string password;
  string role;
  gotoxy(0, 8);
  cout << "Enter username........ ";
  gotoxy(30, 8);
  cout << "Enter password........ ";
  gotoxy(60, 8);
  cout << "Enter role........";
  gotoxy(0, 9);
  cin >> username;
  gotoxy(30, 9);
  cin >> password;

  while (true)
  {
    gotoxy(60, 8);
    cout << "Enter role........";
    gotoxy(60, 9);
    cin >> role;
    if (role== "ADMIN" || role == "EMPLOYER")
    {
      gotoxy(60,10);
      cout << "Again enter the Role." << endl;
    }
    else
    {
      break;
    }
  }
  
  addUser(username, password, role, REC, usercounts, usernameA, passwordA, rolesA);
}

int EmployerMenu()
{ // Employer or User Menu , what user can choose
  subMenu("Employer");
  cout << "Select one of the following options:" << endl;
  cout << "1. Records of all products." << endl;
  cout << "2. Rate list generator of services." << endl;
  cout << "3. Discounts and sorting." << endl;
  cout << "4. Add Customer." << endl;
  cout << "5. Booking of services." << endl;
  cout << "6. Calculate the bill." << endl;
  cout << "7. Add Customer Username and Password." << endl;
  cout << "8. Exit." << endl;
  // cout << "7.	Exit." << endl;

  int chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

int CustomerMenu()
{ //_________Customer or user menu, what user can choose_________
  subMenu("CUSTOMER");
  cout << "Select one of the following options:" << endl;
  cout << "1- View Your Profile " << endl;
  cout << "2- View all Products " << endl;
  cout << "3- Rate List Generator of All Services " << endl;
  cout << "4- Booking " << endl;
  cout << "5. Bill" << endl;
  cout << "6- Logout " << endl;

  int option;
  cout << " Choose Your Option : ";
  cin >> option;
  clearScreen();
  return option;
}

void updateproduct(string product_nameI[], float product_priceI[], string company_nameI[], int count_product, float discount_price[])
{
  string Update_company, new_product, new_company;
  bool flag = false;
  float new_price, dis, dprice;
  cout << "Enter name of the Company you want to update:  ";
  cin >> Update_company;

  for (int i = 0; i < count_product; i++)
  {
    if (company_nameI[i] == Update_company)
    {
      gotoxy(0, 11);
      cout << "Enter new name of Product:";
      gotoxy(33, 11);
      cout << "Enter new price of Product:";
      gotoxy(65, 11);
      cout << "Enter new name of Company:";

      gotoxy(0, 12);
      cin >> new_product;
      gotoxy(33, 12);
      cin >> new_price;
      if (new_price > 1500)
      {
        dis = new_price * 10 / 100;
        dprice = new_price - dis;
      }
      gotoxy(65, 12);
      cin >> new_company;
      cout << endl;

      gotoxy(0, 14);
      cout << "Your product has been updated successfully!!" << endl;

      product_nameI[i] = new_product;
      product_priceI[i] = new_price;
      company_nameI[i] = new_company;
      discount_price[i] = dprice;
      flag = true;
    }
    else
    {
      flag = false;
    }
  }

  if (flag == false)
  {
    cout << "Invalid Company Name." << endl;
  }
}

void addbooking(int c_booking, char bookingC[])
{
  char b;
  cout << "Booking(Press Y for Yes or N for No for Booking):";
  cin >> b;

  addBookingIntoArray(b, c_booking, bookingC);
}

void addBookingIntoArray(char book, int count_booking, char bookingB[])
{
  bookingB[count_booking] = book;
}

void calculateBill(string productA[],int count_product,string company_nameA[],float product_priceA[],float discount[],float discount_price[],string product_nameA[],int count_customer,string customerA[],int date[],string nameA[],string modelA[],int cwp,int bwp)
{
    string customername,product;
    gotoxy(0,9);
    cout <<"1. Customer Name: ";
    gotoxy(22,9);
    cin >> customername;
    for(int x=0; x<count_customer; x++)
    {
      if( customerA[x] == customername)
      {
        gotoxy(0,10);
        cout << "2. Date: " ;
        gotoxy(22,10);
        cout << date[x] << endl;
        gotoxy(0,11);
        cout << "3. Car/Bike Service: ";
        gotoxy(22,11);
        cout << nameA[x] << endl;
        if(nameA[x] == "car")
        {
          gotoxy(0,12);
          cout << "4. Price of Service: ";
          gotoxy(22,12);
          cout << cwp << endl;
        }
        else
        {
          gotoxy(0,12);
          cout << "4. Price of Service: ";
          gotoxy(22,12);
          cout << bwp << endl;
        }
        gotoxy(0,13);
        cout << "5. Car/Bike Model: ";
        gotoxy(22,13);
        cout << modelA[x] << endl;
        gotoxy(0,14);
        cout << "6. Product Name: ";
        gotoxy(22,14);
        cout << productA[x] << endl;
        product = productA[x];
        cout << endl;
      }

    }

    int f;
    for(int i=0; i<count_product; i++)
    {
        if(company_nameA[i] == product)
        {
            f=i;
            break;
        }   
        
    }

    if (product_priceA[f] < 1500)
    {
        discount[f] = product_priceA[f] * 5 / 100;
        discount_price[f] = product_priceA[f] - discount[f];
    }

    else
    {
        discount[f] = product_priceA[f] * 10 / 100;
        discount_price[f] = product_priceA[f] - discount[f];
    }

    cout << "------------    -----   ------- -------------" << endl;
    cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
    cout << "------------    -----   ------- -------------" << endl;
    cout << product_nameA[f] << " \t" << product_priceA[f] << " \t" << company_nameA[f] << " \t" << discount_price[f] << endl;
    
    
}

void addcustomerIntoArray(string customer,int datte, string modell, string namee, string productt, int count_customer, string customerC[],int date[], string modelC[], string nameC[], string productC[], int CUSTOMER)
{
  if (count_customer <= CUSTOMER)
  {
    customerC[count_customer] = customer;
    date[count_customer] = datte;
    modelC[count_customer] = modell;
    nameC[count_customer] = namee;
    productC[count_customer] = productt;
  }
}

void addcustomer(string customerA[],int date[],string modelA[],string nameA[],string productA[],int count_customer,int CUSTOMER)
{
    string customername,mod,nam,pro;
    int datee;
    gotoxy(0,9);
    cout << "Enter the name of Customer: ";
    gotoxy(35,9);
    cout << "Date: ";
    gotoxy(62,9);
    cout << "Car/Bike Service: ";
    gotoxy(0,10);
    gotoxy(0,13);
    cout << "Car/Bike Model: ";
    gotoxy(35,13);
    cout << "Product Name: ";
    gotoxy(0,10);
    cin >> customername;
    while (true)
    {
      gotoxy(35,9);
      cout << "Date: ";
      gotoxy(35,10);
      cin >> datee;
      if (datee < 0 || datee >= 32)
      {
        gotoxy(35,11);
        cout << "Again enter the date." << endl;
      }
      else
      {
        break;
      }
        
    }
    // cout << "Enter the date:";
    // cin >> datee;
    
    gotoxy(62,10);
    cin >> nam;
    
    gotoxy(0,14);
    cin >> mod;
    
    gotoxy(35,14);
    cin >> pro;
     
    addcustomerIntoArray(customername,datee,mod,nam,pro,count_customer,customerA,date,modelA,nameA,productA,CUSTOMER);
}

void addAmountIntoArray(float tamount, float AmountB[], int count_amount, int CUSTOMER)
{
  if (count_amount <= CUSTOMER)
  {
    AmountB[count_amount] = tamount;
  }
}

void addamount(float AmountC[], int count_amount, int CUSTOMER)
{
  float num1, num2, amount;
  gotoxy(0,21);
  cout << "7. Price of Service: ";
  gotoxy(22,21);
  cin >> num1;
  gotoxy(0,22);
  cout << "8. Price of Product: ";
  gotoxy(22,22);
  cin >> num2;
  amount = num1 + num2;
  gotoxy(0,23);
  cout << "9. Amount: ";

  addAmountIntoArray(amount, AmountC, count_amount, CUSTOMER);
  gotoxy(22,23);
  cout << amount << endl;
}

void customerBill(int count_customer, string customerA[], string loginusername, string nameA[], string modelA[], int cwp, int bwp, string productA[], int count_amount, float AmountA[], string usernameA[], int usercount)
{ //______Customer bill___________
  mainHeader();
  subMenu("CUSTOMER BILL");
  for (int x = 0; x < count_customer; x++)
  {
    for (int y = 0; y < usercount; y++)
    {
      if (customerA[x] == usernameA[y])
      {
        gotoxy(0,9);
        cout << "1.Customer name:" << customerA[x] << endl;
        gotoxy(0,10);
        cout << "2.Car/bike Service:" << nameA[x] << endl;
        gotoxy(0,11);
        cout << "3.Car/Bike model:" << modelA[x] << endl;

        if (nameA[x] == "car")
        {
          gotoxy(0,12);
          cout << "4.Price of Service:" << cwp << endl;
        }
        else
        {
          gotoxy(0,12);
          cout << "4.Price of Service:" << bwp << endl;
        }
        gotoxy(0,13);
        cout << "5.Product:" << productA[x] << endl;
      }

      for (int x = 0; x < count_amount; x++)
      {
        for(int y=0; y < usercount; y++)
        if (customerA[x] == usernameA[y])
        {
          cout << "6.Amount:" << AmountA[x] << endl;
        }
      }

      clearScreen();
    }
  }
}

void store(string product_nameA[], float product_priceA[], string company_nameA[], int count_product)
{ //___________FIlehandlinng store data
  fstream myfile;
  myfile.open("data.txt", ios::out);
  for (int x = 0; x < count_product; x++)
  {
    myfile << product_nameA[x] << "," << product_priceA[x] << "," << company_nameA[x] << endl;
  }
  myfile.close();
}

int load(string product_nameA[], float product_priceA[], string company_nameA[], int count_product)
{ //________File handling load data
  string data;
  int x = 0;
  fstream myfile;
  
  myfile.open("data.txt", ios::in);
  while (!(myfile.eof()))
  {
    getline(myfile, data);
    if (data != "")
    {
      product_nameA[x] = parsedata(data, 1);
     // cout << parsedata(data, 2) << endl;
      product_priceA[x] = stoi(parsedata(data, 2));
      company_nameA[x] = parsedata(data, 3);
     // cout << product_nameA[x] << product_priceA[x] << company_nameA[x] << endl;
      x++;
      
    }
  }
  //count_product = x - 1;
  myfile.close();
  return x;
}

string parsedata(string s, int field)
{
  string item;
  int comma = 1;
  for (int x = 0; x < s[x] != '\0'; x++)
  {
    if (s[x] == ',')
    {
      comma++;
    }
    else if (comma == field)
    {
      item = item + s[x];
    }
  }
  return item;
}