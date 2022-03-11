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