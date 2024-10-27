#include "../include/main.h"

namespace po = boost::program_options;
int main(int ac, char* av[]){
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("input,i", po::value<std::string>(), "set input string")
    ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);    
    
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }
    
    if (vm.count("input")) {
        std::cout << "Input string was set to " << vm["input"].as<std::string>() << ".\n";
    } else {
        std::cout << "Input string was not set.\n";
    }

}
