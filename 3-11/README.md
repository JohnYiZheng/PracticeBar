# 千里之行始于足下
目的：学习如何在QT中嵌入PCL  
背景：之前在调研KITTI数据集的时候，发现官方案例了一款基于QT，PCL的可视化工具。准备学习一下。  
网址：https://github.com/MarkMuth/QtKittiVisualizer  
在kitti-devkit-raw/readme.txt中有kitti数据集的解释文件  
编译源码问题：  
- find_package(VTK)，从源码安装VTK，要求安装GLVND，ubuntu安装GLVND命令：sudo apt install libglvnd-dev  
点开VTK_WRAP_PYTHON，发现Could NOT find Python3 (missing: Python3_INCLUDE_DIRS Development.Module) 遗留  
sudo apt-get install doxygen  
降级vtk -> 8.2  
取消选择VTK_WITH_DOCUMENTATION  
点选 VTK_GROUP_QT
sudo apt-get install libqt5x11extras5-dev  
遗留问题：VTK的qt版本加载不出来  
boost1.76.0安装的时候没安装include？？？  
找到问题了，是因为之前把boost1.76.0安装到系统的时候，没有删除/usr/lib/cmake下的config文件，导致所有依赖boost的第三方库cmake环节都使用的是1.76.0残留的配置文件，查找到一堆不存在的.so文件。删除遗留config文件得到解决。  
sudo apt-get install cmake libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev  

依赖链条太难解决了 直接sudo apt install libpcl-dev  
安装pcl出现无法访问apt服务器的问题，换源：

\# 添加阿里源
deb http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse  
deb-src http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse  
deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse  
deb-src http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse  
deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse  
deb-src http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse  
deb http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse  
deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse  
#添加清华源
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse  
\# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse  
\# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse  
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse  
\# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse  
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse  
\# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse multiverse  

