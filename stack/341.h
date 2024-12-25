//
// Created by QinJM on 2023/11/4.
//

#ifndef LEETCODE_341_H
#define LEETCODE_341_H
#include <vector>
#include <stack>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
     // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

/*class NestedInteger {
//total memory:32 bytes
private:
    bool isInt;    //true for intager, false for vector
    int intValue;    //offset:4
    vector<NestedInteger> *vecValues = nullptr;    //offset:8
public:
    NestedInteger(int value): isInt(true), intValue(value) {}
    NestedInteger(vector<NestedInteger> &value): isInt(false), vecValues(&value) {}
    bool isInteger() const { return isInt; }
    int getInteger() const { return intValue; }
    const vector<NestedInteger>& getList() const { return *vecValues; }
};*/
class NestedIterator {
private:
    vector<int> output;
    int counter;
    void func(vector<NestedInteger> nestedList, vector<int> &output){
        for(int i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger())
                output.push_back(nestedList[i].getInteger());
            else
                func(nestedList[i].getList(), output);
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        counter = 0;
        func(nestedList, output);
    }

    int next() {
        return output[counter++];
    }

    bool hasNext() {
        return counter==output.size();
    }
};

#endif //LEETCODE_341_H
