

/*

const string TRANSACTIONS_FILE = "SalesTransactions.txt";                    // Tested!
// const string TRANSACTIONS_FILE = "SalesTransactions.blank";               // Tested!
// const string TRANSACTIONS_FILE = "SalesTransactions.bad";                 // Tested!
// const string TRANSACTIONS_FILE = "SalesTransactions.missing";             // Tested!

const int ERROR_FILE_MISSING = -1;
const int ERROR_FILE_CORRUPT = -2;
const int ERROR_FILE_BLANK = -3;



// Assignment Functions

const double SALES_TAX_RATE = 0.09265;

double calculateOrderAmount(double p, int q = 0);                // Default value for quantity.
double salesTaxAmount(double a, double r = SALES_TAX_RATE);      // Default value for tax rate.

string formatNameLastFirst(string f, string l, string d = ", "); // Default value for delimeter.

void GenerateInventoryErrorMessage(int rc);                      // ** Should b integrated into a try/catch structure **

// main() Program Loop

int main()
{
    int rc = 0; // Pass any error codes to this variable before dropping out.
    
    int quantity = 0, counter = 0;
    
    bool fileOkay = true;
    
    double orderSubTotal, orderSalesTax, orderTotal, price = 0;
    
    string lastName, firstName, lastFirstName;
    
    ifstream transactionsFile(TRANSACTIONS_FILE);
    
    if (transactionsFile.fail())
    {
        rc = ERROR_FILE_MISSING;
    }
    
    else
    {
        // Print Header
        
        // There is apparently no header required in this assignment.
        
        // Loop Through The File and Print Data
        
        do
        {
            if (rc) { break; }                                                    // An error was thrown. 
            
            // n.b. I am simulating try/catch with these complex if/then structures. There are easier and more 
            //      appropriate ways of doing this mess. However, I am just trying to get this done and move on :-)
            
            if (transactionsFile.eof()) { break; } // Last record .. time to exit loop.
            
            transactionsFile >> lastName >> firstName >> quantity >> price;
            
            if (price <= 0 || quantity <= 0 || firstName == "" || lastName == "") // Data Is Corrupt
            {
                rc = (counter > 0 ? ERROR_FILE_CORRUPT : ERROR_FILE_BLANK); // If first time ... blank file ... else corrupt file.
                break;
            }
            
            counter++;
            
            lastFirstName = formatNameLastFirst(firstName, lastName);
            
            orderSubTotal = calculateOrderAmount(price, quantity);
            
            orderSalesTax = salesTaxAmount(orderSubTotal);
            
            orderTotal = orderSubTotal + orderSalesTax;
            
            cout << AL_PE_WI(true, 0, 32) << lastFirstName;
            cout << AL_PE_WI(false, 2, 10) << orderSubTotal;
            cout << AL_PE_WI(false, 2, 12) << orderSalesTax;
            
            cout << endl;
            
        } while (true);
        
        cout << endl;
        
        transactionsFile.close();
    }
    
    if (counter == 0 && rc == 0) { rc = -3; } // No records read and error code is "blank file"
    
    if (rc) { GenerateInventoryErrorMessage(rc); }
    
    //----------------------------------------------------

    #ifdef _WIN32
    system("pause");
    #endif
    
    #ifdef __unix
    system("read -r -p \"Press <Enter> to continue...\" key");
    #endif

    return rc;
}

double calculateOrderAmount(double p, int q)
{
    double rc = p * q;
    
    return rc;
}

double salesTaxAmount(double a, double r)
{
    double rc = a * r;
    
    return rc;
}

string formatNameLastFirst(string f, string l, string d)
{
    string rc = l + d + f;
    
    return rc;
}


void GenerateInventoryErrorMessage(int rc)
{
    switch (rc)
    {
        case ERROR_FILE_MISSING:
        
        cout << "The file you are trying to open does not exist. (" << rc << ")\n";
        
        break;
    
        case ERROR_FILE_CORRUPT:
    
        cout << "The file is corrupt at the above point in the output. (" << rc << ")\n";
        
        break;
    
        case ERROR_FILE_BLANK:
    
        cout << "The file is blank. (" << rc << ")\n";
        
        break;
    }
    
    return;
}


int GetInteger(string q)
{
    int returnCode;
    
    do
    {
        cout << q;
        
        if (cin >> returnCode) break;
        
        cin.clear();
        cin.ignore();
        
    } while (true);
    
    return returnCode;
}



int GetIntegerRange(string prompt, int lowNumber, int highNumber)
{
    int inputNumber;
    
    do
    {
        inputNumber = GetInteger(prompt);
        
        cout << "Broken Do Not Use";
        
        if (inputNumber < lowNumber || inputNumber > highNumber )
        {
            cout << "**** INVALID Number: Must be >= " << lowNumber;
            cout << " and <= " << highNumber << "!\n";
        }
        
        else
        { 
            cout << endl;
            break;
        }
        
    } while (true);
}

string str_repeat(string s, int n)
{
    string rc = "";
    
    for (int i=0; i<n; i++)
    {
        rc += s;
    }
    
    return rc;
}

string str_reverse(string s)
{
    string rc = "";
    
    for (int i=s.length(); i>=0; i--)
    {
        rc += s[i];
    }
    
    return rc;
}

string str_replace(string s, char a, char b)
{
    replace( s.begin(), s.end(), a, b);
    
    return s;
}

string str_toupper(string s)
{
    transform( s.begin(),
               s.end(),
               s.begin(),
               
               [](unsigned char c){ return toupper(c); }
               
               );
    return s;
}

string str_tolower(string s)
{
    transform( s.begin(),
               s.end(),
               s.begin(),
               
               [](unsigned char c){ return tolower(c); }
               
               );
    return s;
}

string int_toBinary(int i, int b)
{
    string r = "";
    
    if (i>0)
    {
        while (i>0)
        {
            r = ((i % 2) == 0 ? "0" : "1" ) + r;
            i /= 2;
        }
    }
    
    r = string(b, '0') + r;
    r = r.substr(r.length() - b);

    return r;
}

bool isLeapYear(int year)
{
    bool returnCode = false;
    
    if (year == -1)
    {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        
        year = timePtr->tm_year;
    }
    
    returnCode = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    
    return returnCode;
}

int WaitForUserToPressKey(int errorCode, char waitKey, string message)
{
    // If the waitKey is $ then any key will work and it overrides the default message.
    
	char c;
	
	if (waitKey == '$')
	{
	    message = "Press any key to continue . . . ";
	}
	
	cout << "\n" << message;
	
	do
	{
	    c = getchar();
	    
	    if (c == waitKey || waitKey == '$') { break; }
	    
	} while (true);

	if (errorCode < 0 || errorCode > 0)
	{
	    cout << "\n\n" << "An error was passed to the exit routine. The error code is (" << errorCode << ")\n\n";
	    cout << "Note that an error code of -1 in the program will yield a 255 (invalid error code) upon exit.\n\n";
	}
	
	return errorCode;
}




*/