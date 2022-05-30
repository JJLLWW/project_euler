#include "euler.hpp"
#include <fmt/core.h>
#include <vector>

namespace peuler {
    // seriously think about how to do this in a general way when get on to harder problems.
    
    // shouldn't need a different kind of struct/class for each problem.
    struct prob_1_test_case {
        ull expect;
        ull N;
        ull M1;
        ull M2;
    };

    // hard-code test cases as necessary.
    std::vector<prob_1_test_case> prob_1_cases = {{23, 10, 3, 5}};

    // Now need to generalise this to not need to repeat for each problem.
    void test_prob1() {
        bool success = true;
        for(int i=0; i<prob_1_cases.size(); i++) {
            prob_1_test_case test_case = prob_1_cases[i];
            ull res = solve_prob1(test_case.N, test_case.M1, test_case.M2);
            if(res != test_case.expect) {
                fmt::print("Test Case #{}: Expected {}, got {}", i+1, test_case.expect, res);
                success = false;
                break;
            }
        }
        if(success) {
            fmt::print("Success (!)");
        }
    }
} // namespace peuler