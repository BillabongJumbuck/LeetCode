//
// Created by QinJM on 2024/1/2.
//

#ifndef LEETCODE_912_H
#define LEETCODE_912_H
#include <vector>
using namespace std;
class Solution {
private:
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
public:
    vector<int> sortArray(vector<int>& nums) {

    }
};

/*
 *  快速排序, 基准采用左中右选中值的方式。
class Solution {
private:
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int Median3(vector<int>& nums, int low, int high) {
        int center = (low + high) / 2;
        if(nums[low] > nums[center])
            swap(nums[low], nums[center]);
        if(nums[low] > nums[high])
            swap(nums[low], nums[high]);
        if(nums[center] > nums[high])
            swap(nums[center], nums[high]);

        swap(nums[low], nums[center]);
        return nums[low];

    }
    int Partition(vector<int>& nums, int low, int high){
        int pivot = Median3(nums, low, high);
        while(low<high){
            while(low<high && nums[high]>=pivot)
                high--;
            nums[low] = nums[high];
            while(low<high && nums[low]<=pivot)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
    void QuickSort(vector<int>& nums, int low, int high){
        if(low<high){
            int pivotpos = Partition(nums, low, high);
            QuickSort(nums, low, pivotpos-1);
            QuickSort(nums, pivotpos+1, high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
};*/

/*
 * 堆排序
class Solution {
private:
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void PercDown(vector<int>& nums, int i, int n){
        int parent, child;
        int x = nums[i];
        for(parent = i;parent*2+1<=n;parent=child){
            child = parent*2+1;
            if(child+1 <= n && nums[child+1]>nums[child])
                child++;
            if(x > nums[child])
                break;
            else
                nums[parent] = nums[child];
        }
        nums[parent] = x;
    }
    void HeapSort(vector<int>& nums){
        for(int i=nums.size()/2-1;i>=0;i--)
            PercDown(nums, i, nums.size()-1);

        for(int i=nums.size()-1;i>0;i--){
            swap(nums[0], nums[i]);
            PercDown(nums, 0, i-1);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        HeapSort(nums);
        return nums;
    }
};*/

/*
 * 归并排序
class Solution {
private:
    void Merge(vector<int>& nums, vector<int>& tmp, int left, int right, int right_end){
        int left_end = right - 1;
        int index = left;
        int num_of_elem = right_end - left + 1;

        while(left<=left_end && right<=right_end){
            if(nums[left]<=nums[right]){
                tmp[index] = nums[left];
                left++;
            }else{
                tmp[index] = nums[right];
                right++;
            }
            index++;
        }
        while(left<=left_end){
            tmp[index] = nums[left];
            index++;
            left++;
        }
        while(right<=right_end){
            tmp[index] = nums[right];
            index++;
            right++;
        }

        for(int i=0;i<num_of_elem;i++){
            nums[right_end-i] = tmp[right_end-i];
        }
    }
    void MergeSort(vector<int>& nums, vector<int>& tmp, int left, int right_end){
        if(left<right_end){
            int center = (left+right_end)/2;
            MergeSort(nums, tmp, left, center);
            MergeSort(nums, tmp, center+1, right_end);
            Merge(nums, tmp, left, center+1, right_end);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        MergeSort(nums, tmp, 0, nums.size()-1);
        return nums;
    }
};*/

/*
 * 希尔排序, 采用的间距为Sedgewick = {929, 505, 209, 109, 41, 19, 5, 1, 0};
class Solution {
private:
    void Swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void ShellSort(vector<int>& nums){
        vector<int> Sedgewick = {929, 505, 209, 109, 41, 19, 5, 1, 0};
        int Si = 0;
        while(Sedgewick[Si] >= nums.size())
            Si++;

        for(int i=Sedgewick[Si];i>0;i=Sedgewick[++Si]){
            for(int j=i;j<nums.size();j++){
                int tmp = nums[j];
                int k = j;
                for(;k>=i&&nums[k-i]>tmp;k-=i)
                    nums[k] = nums[k-i];
                nums[k] = tmp;
            }
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        ShellSort(nums);
        return nums;
    }
};*/
#endif //LEETCODE_912_H
