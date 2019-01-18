//
//  Stock.cpp
//  project1
//
//  Created by Umut Avin on 27.10.2018.
//  Copyright © 2018 avin. All rights reserved.
//

#include "Stock.hpp"

using namespace std;

void Stock::StockWriter(const string fileName){
    ofstream outputFile(fileName, ofstream::out);
    outputFile << "timestamp" << ';' << "instrument_token" << ';' << "last_price" << ';' << "volume"<< ';' << "sell_quantity"<< ';' << "last_quantity"<< ';' << "change"<< ';' << "average_price"<< ';' << "open"<< ';' << "high"<< ';' << "low"<< ';' << "close"<< ';' << "depth_buy_price_0"<< ';' << "depth_buy_orders_0"<< ';' << "depth_buy_quantity_0"<< ';' << "depth_sell_price_0" << ';' << "depth_sell_orders_0" << ';' << "depth_sell_quantity_0" << ';' << "depth_buy_price_1"<< ';' << "depth_buy_orders_1"<< ';' << "depth_buy_quantity_1"<< ';' << "depth_sell_price_1" << ';' << "depth_sell_orders_1" << ';' << "depth_sell_quantity_1" << ';' << "depth_buy_price_2"<< ';' << "depth_buy_orders_2"<< ';' << "depth_buy_quantity_2"<< ';' << "depth_sell_price_2" << ';' << "depth_sell_orders_2" << ';' << "depth_sell_quantity_2" << ';' << "depth_buy_price_3"<< ';' << "depth_buy_orders_3"<< ';' << "depth_buy_quantity_3"<< ';' << "depth_sell_price_3" << ';' << "depth_sell_orders_3" << ';' << "depth_sell_quantity_3" << "depth_buy_price_4"<< ';' << "depth_buy_orders_4"<< ';' << "depth_buy_quantity_4"<< ';' << "depth_sell_price_4" << ';' << "depth_sell_orders_4" << ';' << "depth_sell_quantity_4";
    outputFile << endl;
    for(int i=0; i<stock_data.size(); i++){
        outputFile << stock_data[i].getTime() << ';' << stock_data[i].insToken() << ';' << stock_data[i].getPrice();
        for(int j=0; j<39; j++){
            outputFile << ';' << stock_data[i].getCols()[j] ;
        }
        outputFile << endl;
    }
    outputFile.close();
}

void Stock::mergeSort(int low_index, int high_index, string sortFeature){
    if (low_index < high_index) {
        int mid = (low_index + high_index) / 2;
        mergeSort(low_index, mid, sortFeature);
        mergeSort(mid+1, high_index, sortFeature);
        merge(low_index, mid, high_index, sortFeature);
    }
}

void Stock::merge(int low_index, int mid, int high_index, string sortFeature){
    int leftSize = (mid - low_index) + 1;
    int rightSize = (high_index - mid);
    
    Stock left;
    Stock right;
    
    left.stock_data.resize(leftSize*sizeof(StockData));
    right.stock_data.resize(rightSize*sizeof(StockData));
    
    int i,j;
    for(i = 0; i < leftSize; i++) {
        left.stock_data[i] = stock_data[low_index+i];
        for(int colCount=0; colCount<39; colCount++){
            left.stock_data[i].otherColumns[colCount] = stock_data[low_index+i].otherColumns[colCount];
        }
    }
    
    for(j = 0; j < rightSize; j++) {
        right.stock_data[j] = stock_data[mid+j+1];
        for(int colCount=0; colCount<39; colCount++){
            left.stock_data[j].otherColumns[colCount] = stock_data[low_index+j].otherColumns[colCount];
        }
    }
    
    i=0;
    j=0;
    int k;
    if(sortFeature == "t"){
        for(k=low_index; k < high_index; k++) {
            if ((i >= leftSize) || (j >= rightSize))
                break;
            
            if (left.stock_data[i].compareVectors((right.stock_data[j]),sortFeature)== 1) {
                stock_data[k] = left.stock_data[i];
                for(int colCount=0; colCount<39; colCount++){
                    stock_data[k].otherColumns[colCount] = left.stock_data[i].otherColumns[colCount];
                }
                i++;
            }
            else {
                stock_data[k] = right.stock_data[j];
                for(int colCount=0; colCount<39; colCount++){
                    stock_data[k].otherColumns[colCount] = right.stock_data[j].otherColumns[colCount];
                }
                j++;
            }
        }
        
        while(i < leftSize) {
            stock_data[k] = left.stock_data[i];
            for(int colCount=0; colCount<39; colCount++){
                stock_data[k].otherColumns[colCount] = left.stock_data[i].otherColumns[colCount];
            }
            i++;
            k++;
        }
        
        while(j < rightSize) {
            stock_data[k] = right.stock_data[j];
            for(int colCount=0; colCount<39; colCount++){
                stock_data[k].otherColumns[colCount] = right.stock_data[j].otherColumns[colCount];
            }
            j++;
            k++;
        }
    }
    
    else{
        for(k=low_index; k < high_index; k++) {
            if ((i >= leftSize) || (j >= rightSize))
                break;
            
            if (left.stock_data[i].compareVectors((right.stock_data[j]),sortFeature)== 1) {
                stock_data[k] = left.stock_data[i];
                for(int colCount=0; colCount<39; colCount++){
                    stock_data[k].otherColumns[colCount] = left.stock_data[i].otherColumns[colCount];
                }
                i++;
            }
            else {
                stock_data[k] = right.stock_data[j];
                for(int colCount=0; colCount<39; colCount++){
                    stock_data[k].otherColumns[colCount] = right.stock_data[j].otherColumns[colCount];
                }
                j++;
            }
        }
        
        while(i < leftSize) {
            stock_data[k] = left.stock_data[i];
            for(int colCount=0; colCount<39; colCount++){
                stock_data[k].otherColumns[colCount] = left.stock_data[i].otherColumns[colCount];
            }
            i++;
            k++;
        }
        
        while(j < rightSize) {
            stock_data[k] = right.stock_data[j];
            for(int colCount=0; colCount<39; colCount++){
                stock_data[k].otherColumns[colCount] = right.stock_data[j].otherColumns[colCount];
            }
            j++;
            k++;
        }
        
    }
}

void Stock::insertionSort(int size, string sortFeature){
    StockData data;
    int i, j;
    if(sortFeature == "f"){
        for (j=1; j < size; j++) {
            data = stock_data[j];
            i = j - 1;
            while ((i >= 0) && (data.compareVectors(stock_data[i], sortFeature) == 1)) {
                stock_data[i+1] = stock_data[i];
                i--;
            }
            stock_data[i+1] = data;
        }
    }
    else if(sortFeature == "p"){
        for (j=1; j < size; j++) {
            data = stock_data[j];
            i = j - 1;
            while ((i >= 0) && (data.compareVectors(stock_data[i], sortFeature) == 1)) {
                stock_data[i+1] = stock_data[i];
                i--;
            }
            stock_data[i+1] = data;
        }
    }
};
