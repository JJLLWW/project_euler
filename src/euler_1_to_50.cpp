#include "euler.hpp"
#include <stdexcept>
// lcm, gcd 
#include <numeric>
// sqrt
#include <cmath>

namespace peuler {
    // get the number of multiples of A which are less than N. (should this be templated?)
    ull get_nmult_less(ull A, ull N) {
        if(A >= N) {
            return 0;
        }
        ll nmult_A_le = N/A;
        // reduce to a ternary operator? return (N%A == 0) ? nmult_A_le - 1 : nmult_A_le
        if(N%A == 0) {
            return nmult_A_le - 1;
        }
        else {
            return nmult_A_le;
        }
    }

    // get the sum of the first n multiples of k
    ull sum_first_n_multk(ull n, ull k) {
        return k*(n*(n+1)/2);
    }

    // We want the sum of all natural numbers n with 0 < n < N, where n is a multiple
    // of A or B.
    ull solve_prob1(ull N, ull A, ull B) {
        if(N == 0 || A == 0 || B == 0) {
            throw std::invalid_argument("got zero argument in solve_prob1");
        }
        ull nmult_A = get_nmult_less(A, N);
        ull nmult_B = get_nmult_less(B, N);
        ull LCM_AB = std::lcm(A,B);
        ull nmult_A_and_B = get_nmult_less(LCM_AB, N);
        // inclusion-exclusion on the multiples.
        ull sum_A = sum_first_n_multk(nmult_A, A);
        ull sum_B = sum_first_n_multk(nmult_B, B);
        ull sum_A_and_B = sum_first_n_multk(nmult_A_and_B, LCM_AB);
        ull sum_A_or_B = sum_A + sum_B - sum_A_and_B;
        return sum_A_or_B;
    }

    // index of greatest member of the fibonacci sequence <= N.

    double geom_series(double A, double n) {
        return (1-std::pow(A,n+1))/(1-A);
    }
    // know from calculation that the 33rd term is the last one we care about.
    double solve_prob2() {
        // even terms indeces are given by 2 + 3*i with 0<=i<=10. Using formula for 
        // fibonaci numbers + geometric series.
        double A = (1 + std::sqrt(5))/2;
        double B = (1 - std::sqrt(5))/2;
        double ans = (std::pow(A,2)*geom_series(A,10) + std::pow(B,2)*geom_series(B,10))/std::sqrt(5);
        return ans;
    }
} // namespace peuler