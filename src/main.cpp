/**
 * @file main.cpp
 * @brief This is a programs that checks amount of options to be expired and optimizes the poroflio by average amount of contracts to expire.
 * @author Addis Bogale and Bona Tufa
 * @date 04/21/2021
 * 
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class options{
public:
    vector<string> check;
    map<string, int> Porfolio;  
    map<string, int> values;
    map<string, int> stock;
       

    options(){

        // Porfolio Data 

        Porfolio["APPL"] = 999997;
        Porfolio["MSFT"] = 5230000;
        Porfolio["BKB.A"] = 20000;
        Porfolio["AMZN"] = 53000;
        Porfolio["NVDA"] = 335000;



        // Values Data 

        values["APPL"] = 300000;
        values["TSLA"] = 500000;
        values["MSFT"] =  458900;
        values["AMD"] = 234000;
        values["COIN"] = 543200;
        values["GOOGL"] = 980889;
        values["FB"] = 234312;
        values["NVDA"] = 2884003;
        values["SPY"] = 2000;
        values["P"] = 5432090;
        values["BKB.A"] = 9809;
        values["BKB.B"] = 234312;
        values["G"] = 213131;
        values["AMZN"] = 2300;
        values["ALP"] = 54300;
        values["N"] = 9808;
        values["BK"] = 23492;
        values["B"] = 21312;

    }

map<string, int> checker(){
    int val;
    string key;
    map<string, int>::iterator j;
    
    for(j=Porfolio.begin(); j != Porfolio.end();j++){
        key = j->first;
        if(values.find(key) != values.end()){
                //Add it to the stock map both the key and value
                val = values[key]; 
                stock[key] = val;
        }
    }
    return stock;
}

int total(){
    map<string, int> data; //map assigned for the returned value of checker function
    map<string, int>::iterator i;
    int count = 1;
    data = checker();
    int total = 0; 
    
    //calculating total contracts to be expired.
    for(i = stock.begin(); i != stock.end();i++){
        total += data[i->first];
    } 

    return total;
   
}

int average(){
    int average;
    int amount = total();
    average = amount/stock.size();

    return average;
}

void stockprint(){
    map<string, int>::iterator k; 
    map<string, int>::iterator i;
    int count = 0;
    int avg = average();

    cout << "List of stocks in porfolio and amount of contracts held" << endl;

    for(i = Porfolio.begin(); i != Porfolio.end();i++){
        cout << ++count << "." <<" " << i->first << " " << "=" << " " << Porfolio[i->first] << "." << endl;
    }

    cout << "List of stocks to expire and amount of contracts" << endl; 
    
    count = 0;
    for(k = stock.begin(); k != stock.end();k++){
        cout << ++count << "." <<" " << k->first << " " << "=" << " " << stock[k->first] << "." << endl;
    }

    cout << "The following stocks in your porfolio have higher amount of contracts than the average amount of contracts to expire" << endl;
    
    count = 0;
    for(k = Porfolio.begin(); k != Porfolio.end();k++){
        if(avg < Porfolio[k->first]){
            cout <<  ++count << ". " << k->first <<endl;
            check.push_back(k->first);
    
        }
    }

    cout << "Enter the ticker of which stock you want to sell: " << endl; 

    
}



void user(string ticker){
    
    map<string, int>::iterator k;
    int sell; 
    int count = 1;
    int avg = average();
    int left;

    //checking for input errors
    for(int i = 0; i<check.size(); i++){
        if(!Porfolio[ticker]){
            cout << "Invalid value" << endl;
            break;
        }else{
            cout << "calculating the average differences... " << endl;
    
            //calculating differences between the average contracts to be expired and currently owned contracts of each stock in porfolio.
            for(k = Porfolio.begin(); k != Porfolio.end();k++){
                if(avg < Porfolio[ticker]){
                    sell = Porfolio[ticker] - avg;
                    left = Porfolio[ticker] - sell;
                    cout << count++ << ". " << sell << " amount of " << ticker << " has been sold." << endl;
                    cout << "You have " << left << " contracts left of stock " << ticker << endl;
                    break;
                }
            } 
        break;
        }
    }    
}
};




int main(int, char**) {
    string input;
    
    options test;
    test.checker(); 
    test.stockprint();
    cin >> input;
    test.user(input);

}