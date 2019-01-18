//
//  Stock.hpp
//  project1
//
//  Created by Umut Avin on 23.10.2018.
//  Copyright © 2018 avin. All rights reserved.
//

#ifndef StockData_hpp
#define StockData_hpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class StockData{
private:
    string timestamp, instoken;
public:
    vector<string>otherColumns;
    double lastprice;
    StockData(){};
    StockData(string time_stamp, string ins_token, double last_price, vector<string>&other_cols);
    bool compareVectors(StockData &data, string feature);
    string getTime(){ return timestamp; };
    string insToken(){ return instoken; };
    double getPrice(){ return lastprice; };
    vector<string> getCols(){ return otherColumns; };
};
    
#endif /* Stock_hpp */
