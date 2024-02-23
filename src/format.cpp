#include <string>
#include <cstdlib>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    long hh, mm, ss, tmp;
    string time;
    
    auto divisor = std::div(seconds, (long) 60);
    ss = divisor.rem;
    tmp = divisor.quot;
    divisor = std::div(tmp, (long) 60);
    mm = divisor.rem;
    hh = divisor.quot;

    time = std::to_string(hh) + ":" + std::to_string(mm) + ":" + std::to_string(ss);

    return time;
}