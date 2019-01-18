//  Umut Cem Avin
//  150140018
//  Copyright © 2018 avin. All rights reserved.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Stock.cpp"
#include <vector>
#include <stdlib.h>


using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 7) {
        cout << endl << "ERROR: Some arguements are missing!" << endl;
        //return 0;
    }
    
    int size;
    string feature, algo;
    /*if(strcmp(argv[1],"-algo")==1) algo = string(argv[2]);
    if(strcmp(argv[3],"-algo")==1) algo = string(argv[4]);
    if(strcmp(argv[5],"-algo")==1) algo = string(argv[6]);
    if(strcmp(argv[1],"-feature")==1) feature = string(argv[2]);
    if(strcmp(argv[3],"-feature")==1) feature = string(argv[4]);
    if(strcmp(argv[5],"-feature")==1) feature = string(argv[6]);
    if(strcmp(argv[1],"-size")==1) size = atoi(argv[2]);
    if(strcmp(argv[3],"-size")==1) size = atoi(argv[4]);
    if(strcmp(argv[5],"-size")==1) size = atoi(argv[6]);
    */
    algo = string(argv[2]);
    size = atoi(argv[6]);
    feature = string(argv[4]);
    
     
    Stock stock;
    StockData stockData;
    vector<string>others;
    
    ifstream inputFile("log_inf.csv", ifstream::in);
    
    if (!inputFile.is_open()) {
        cout << endl << "File cannot be loaded!" << endl;
        return 0;
    }
    
    string line,date,time;
    getline(inputFile, line);//first row skipper
    
    for(int i=0; i<size; i++){
        getline(inputFile, line);
        stringstream ss(line);
        string time_stamp,ins_token,lprice;
        getline(ss, time_stamp, ',');
        getline(ss, ins_token, ',');
        getline(ss, lprice, ',');
        double last_price = atof(lprice.c_str());
        for(int colCounter=0; colCounter<39; colCounter++){
            string tmp;
            getline(ss, tmp, ',');
            others.push_back(tmp);
            
        }
        StockData stockData(time_stamp, ins_token, last_price, others);
        stock.newStock(stockData);
        if(line.empty() || inputFile.eof() ) break;
        others.clear();
        
    }
    if (algo == "m"){
        stock.mergeSort(0,size-1,feature);
        stock.StockWriter("sorted.csv");
        
    }
   else if (algo == "i"){
       stock.insertionSort(size, feature);
       stock.StockWriter("sorted.csv");
    }
    
    return 0;
    
}


