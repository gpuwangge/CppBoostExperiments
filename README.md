# CppBoostExperiments

# Build Instruction
> mkdir build  
> cd build  
> cmake -G "MinGW Makefiles" ..  
> make -j 


# Introduction
Boost是基于C++标准的库，创建于1998年  
Boost源码允许任何人自由使用、修改和分发  

# Setup
有一些简单的功能可以仅包含头文件。但是大多数功能比如program_options需要编译成dll/lib使用  

在下面网站下载Version x.xx.x  
www.boost.org  
本处测试使用Version 1.86.0 for windows:  
boost_1_86_0.zip  
解压缩后，将boost_x_xx_x拷贝至需要的位置(比如：C:\boost_1_86_0)   
boost_x_xx_x/boost其实就是头文件。但zip中不含有编译后的文件  
编译过程如下：  
1、进入boost_1_86_0.zip目录，如果使用mingw编译器，使用用如下指令：  
> bootstrap.bat gcc  

(如果直接运行bootstrap.bat，会使用默认的msvc(cl编译器)而不是mingw)  
(如果遇到mutex error，是因为编译器没有使用posix的缘故。解决办法是下载posix版本的mingw64)  
结果是几分钟后，会在当前目录下生成b2.exe  
2、运行b2.exe  
这一步会持续十几分钟  
生成的库文件位于stage/lib/文件夹下  
每一个boost功能都会被编译成单独的库文件，所以此文件夹下会有很多文件，可以选取需要的文件link，比如：  
libboost_program_options-mgw8-mt-x64-1_86.a  
3、将该位置添加至环境变量  
include就是C:\boost_1_86_0  
lib就是C:\boost_1_86_0\stage\lib  
4、配置CMakeLists.txt，包含Include Dir, Link Dir, 就是上一步设置的path  
之后Link需要的Libs，比如boost_program_options-mgw8-mt-x64-1_86  
5、在源文件中include需要的头文件  
比如#include <boost/program_options.hpp>  

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
