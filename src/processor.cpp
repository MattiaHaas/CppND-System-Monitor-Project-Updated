#include "processor.h"
#include "linux_parser.h"
#include <vector>
#include <string>

using std::vector;
using std::string;


// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 

    vector<string> ticks = LinuxParser::CpuUtilization();
    vector<float> values;
    
    // Convert strings to floats
    for (string& tick : ticks){
        values.push_back(std::stof(tick));
    }

    float idle = values[3] + values[4];
    float non_idle = values[0] + values[1] + values[2] + values[5] + values[6] + values[7];

    float total = idle + non_idle;

    return (total - idle)/total;
}