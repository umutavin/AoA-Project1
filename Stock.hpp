//
//  Stock.hpp
//  project1
//
//  Created by Umut Avin on 27.10.2018.
//  Copyright © 2018 avin. All rights reserved.
//

#ifndef Stock_hpp
#define Stock_hpp

#include <iostream>
#include <string>
#include <vector>
#include "StockData.cpp"
#include <fstream>


using namespace std;

class Stock{
private:
    vector<StockData> stock_data;
    int row;
public:
    Stock(){};
    void newStock(StockData &new_stock) {stock_data.push_back(new_stock);};
    void StockWriter(const string fileName);
    void mergeSort(int low_index, int high_index, string sortFeature);
    void merge(int low_index, int mid, int high_index, string sortFeature);
    void insertionSort(int size, string sortFeature);
};

#endif /* Stock_hpp */
