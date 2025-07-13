// simulating work of a printer

#include <bits/stdc++.h>
using namespace std;

// creating class for printer
class Printer{
    int paper;
    string name;
    
    public:
        // constructor
        Printer(string name, int paper){
            this->name = name;
            this->paper = paper;
        }
        // print fn will receive txtDoc 
        void print(string txtDoc,int pages){
            if(pages > this->paper){
                // throwing an text exception
                throw "not enough papers"; 
                // throwing int exception 
                // throw 101;
                
                // throwing an text exception comes using const char* types of exceptions
                // throw will break out the fn like break or return 
                // basically throw keyword crashes the app 
                // we need to try and catch exceptions
                // we put the code that we expect to create exception inside a try catch block 
            }
            
            cout << "printing " << txtDoc <<endl;
        }
        
};

int main(){
    // handling errors
    // try - catch - throw 
    
    Printer myPrinter("HP DeskJet",10);
    try{
        // try this code which might create an exception
        myPrinter.print("hello my name is yash",21);
        // catch that thrown exception 
    }catch(const char* txtException){
        // handle that thrown exception inside this block 
        // txtException contains - that error which we've thrown as an exception
        // printing the text associated with that exception
        cout << "exception occured : " << txtException <<  endl;
    }catch(int exceptionCode){
        cout << "error code : " << exceptionCode << endl;
        // using default error handler 
    }catch(...){
        // ... are called ellipses
        // this means this catch block will handle all & anytype of exception 
        cout << "Something Went Wrong" << endl;
        // although errors are taken care of sequencially, therefore catch block to catch all types of error which execute at the end;
        // defualt handler can't be put before other error and exception handling catch blocks, it will throw error : default handler masking other explicitly mentioned exception handler.
    }
    // this will throw error 
    // myPrinter.print(123,1);
    
}
