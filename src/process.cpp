#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {};

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { 

    // total time CPU has been busy with this process
    float process_totaltime = (float) LinuxParser::ActiveJiffies(pid_) / (float) sysconf(_SC_CLK_TCK);

    // start time of the process in seconds
    float process_startime = (float) LinuxParser::UpTime(pid_); 

    // uptime of the system in seconds
    float system_uptime = (float) LinuxParser::UpTime(); 
    float process_uptime = system_uptime - process_startime;
    
    float cpu_load = process_totaltime/process_uptime*100;
    return cpu_load;
 
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    if (CpuUtilization() < a.CpuUtilization()){
        return true;
    } else {
        return false;
    }
}