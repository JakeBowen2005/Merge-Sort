//
//  main.cpp
//  merge_sort_search
//
//  Created by Jake Bowen on 10/20/24.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>
using namespace std;

void merge(vector<int>& v, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;
    vector<int> nv(r-l+1);
    
    while (i <= m && j <= r) {
        if (v[i] <= v[j]) {
            nv[k] = v[i];
            i++;
        } else {
            nv[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= m) {
        nv[k] = v[i];
        i++;
        k++;
    }
    while (j <= r) {
        nv[k] = v[j];
        j++;
        k++;
    }
    for (int p = 0; p < nv.size(); p++) {
        v[l + p]= nv[p];
    }
}


void merge_sort(vector<int>& v, int l, int r) {
    if (l < r) {
        int m = ((l + r) / 2);
        merge_sort(v, l, m);
        merge_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int b_search(vector<int>& v, int value) {
    int l = 0;
    int r = static_cast<int>(v.size()) - 1;
    
    while(l <= r) {
        int q = (l + r) / 2;
        if (v[q] == value) {
            return q;
        } else if (v[q] < value) {
            l = q + 1;
        } else {
            r = q - 1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::random_device rd;  // Seed source for randomness (usually based on hardware)
    std::mt19937 gen(rd()); // Mersenne Twister RNG engine, seeded with random device
    srand (time_t(NULL));
    vector<int> nums;
    
    cout << "Generate random numbers 0 - : ";
    int max_num;
    cin >> max_num;
    uniform_int_distribution<> dist(1, max_num);
    for (int i = 0; i < max_num;i++) {
        nums.push_back(dist(gen));
    }
    cout << "Sorting now..." << endl;
    cout << endl;
    merge_sort(nums, 0, static_cast<int>(nums.size() - 1));
    cout << endl;
   /* for (int i = 0; i <nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;*/
    int value;
    std::cout << "What value would you like to find in the random numbers: ";
    std::cin >> value;
    
    if(b_search(nums, value) > -1) {
        std::cout << "Number found at postion " << b_search(nums, value) << std::endl;
    } else {
        std::cout << "Number not found sorry!!" << std::endl;
    }
    return 0;
}
