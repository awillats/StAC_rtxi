//
//  hmm_fs.hpp
//  hmm_tests
//
//  Created by Adam Willats on 8/16/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//

#ifndef hmm_fs_hpp
#define hmm_fs_hpp

#include <stdio.h>
#include <cassert>
#include <iostream>
#include <cmath>
#include <cfloat>

#include <vector>
#include <algorithm>




struct HMM {
    int states, events;
    double **A, **B;
    double *PI;
    
    //https://stackoverflow.com/questions/18795776/error-no-matching-function-for-call-to-when-constructing-an-unintialized-stru
    HMM(): states(2), events(2) { ;}; 


    HMM(int states, int events, double **A, double **B, double *PI):
    states(states), events(events), A(A), B(B), PI(PI) {
        assert(states > 0); assert(events > 0);
        assert(A != NULL); assert(B != NULL); assert(PI != NULL);
    }

   friend std::vector<int> genStates(HMM const& hmm);
   friend int* viterbi(HMM const& hmm, const int observed[], const int n); 
};




#endif /* hmm_fs_hpp */
