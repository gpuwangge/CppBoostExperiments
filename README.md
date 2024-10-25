# CppBoostExperiments

# Build Instruction
> mkdir build  
> cd build  
> cmake -G "MinGW Makefiles" ..  
> make  


# Introduction
Boost是基于C++标准的库，创建于1998年  
Boost源码允许任何人自由使用、修改和分发  

# Setup
有一些简单的功能可以仅包含头文件。但是大多数功能比如program_options需要编译成dll/lib使用  

在下面网站下载Version x.xx.x
www.boost.org  
本处测试使用Version 1.86.0 for windows:  
boost_1_86_0.zip  
解压缩后，将boost_x_xx_x拷贝至需要的位置，将该位置添加至环境变量  
boost_x_xx_x/boost其实就是头文件。但zip中不含有编译后的文件  
编译过程如下：  
1、双击bootstrap.bat 
(应该使用mingw而不是默认的cl)  
此过程会使用默认的cl编译器
结果会生成b2.exe
2、双击b2.exe文件
这一步会持续比较长的时间  
生成的dll/lib位于stage/文件夹下
3、配置CMakeLists.txt，包含Include Dir, Link Dir, Link Libs
4、在源文件中include需要的头文件
  

# Boost库
## Boost.Program_options
```c++
#include <boost/program_options.hpp>
namespace po = boost::program_options;
int main(int ac, char* av[]){
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("compression", po::value<int>(), "set compression level")
    ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);    
    
    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
    
    if (vm.count("compression")) {
        cout << "Compression level was set to " << vm["compression"].as<int>() << ".\n";
    } else {
        cout << "Compression level was not set.\n";
    }

}
```


## Boost.Serialization
WIP  

# Reference
www.boost.org  
https://www.boost.org/doc/libs/1_39_0/doc/html/program_options/tutorial.html#id2891824  
http://zh.highscore.de/cpp/boost/introduction.html  
