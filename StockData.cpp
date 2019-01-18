//
//  StockData.cpp
//  project1
//
//  Created by Umut Avin on 23.10.2018.
//  Copyright © 2018 avin. All rights reserved.
//

#include "StockData.hpp"

using namespace std;

StockData::StockData(string time_stamp, string ins_token, double last_price, vector<string>&other_cols){
    timestamp = time_stamp;
    lastprice = last_price;
    instoken = ins_token;
    otherColumns = other_cols;
}

bool StockData::compareVectors(StockData &data, string feature){
    if(feature == "t"){
        if(this->timestamp.compare(data.timestamp)==1)
            return 1;
        else
            return 0;
    }
    else if(feature == "p"){
        if(this->lastprice > data.lastprice)
            return 1;
        else
            return 0;
    }
    else{
        cout << "Enter valid arguements" << endl;
        return 0;
    }
    
}



