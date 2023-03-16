<div align="center">
  <img src="https://github.com/LumosNet/Lumos/blob/master/img/Lumos.png">
</div>

# Lumos

### 简介

[Lumos](https://gitee.com/lumos-net/lumos)是一个以个人学习为目的而开发的深度学习框架，以darknet框架作为主要参考。Lumos框架以C语言为主要开发语言，gcc作为主要编译器，当然该框架也可以轻松的在Windows上进行开发。

Lumos一词来源《哈利波特》中的咒语荧光闪烁，该框架旨在提供一个简洁的轻量级深度学习框架，帮助学习、研究深度学习算法和底层实现的学者和爱好者更容易学习相关内容，希望该框架是你学习过程中指引你的荧光。

Lumos的目标从来不是为了比肩TensorFlow或者Pytorch这样的顶级开源框架，而是希望更好的展现底层算法实现，提供给使用者更灵活的使用体验。同时希望有更多的人不止能在上层框架构建成熟应用，更能对底层算法原理和实现技巧有更多的关注。



### 开发状况

当前Lumos提供基础的全连接神经网络和卷积神经网络基本组件，使用配置文件的方式提供快速构建神经网络的方法。如果你有Darknet框架的使用经验，那么你可以快速上手Lumos。

Lumos框架现在只提供了最基本的网络组件，对于一些特定算法的处理方法会在后续开发继续完善。

当前该框架还未能提供GPU加速，你所构建的所有内容都将在CPU上进行计算。



### 安装

当前Lumos只支持Ubuntu操作系统

**Ubuntu：**
Ubuntu：

首先您需要相关的编译工具，gcc编译器和make工具是您必须安装的工具

```shell
$ sudo apt update
$ sudo apt install build-essential
```

下载我们的安装包

最新安装包为：[lumos-v0.4a.run](https://github.com/LumosNet/Lumos-Build/raw/main/lumos-v0.4a.run)

如果需要更早版本的安装包，请到[lumos-build](https://github.com/LumosNet/Lumos-Build)下自行查找

下载完成安装包后，使用如下命令安装

```shell
$ sudo sh lumos-v0.4a.run
```

添加环境变量，在用户目录下~/.bashrc文件末尾添加如下语句

```
export PATH=$PATH:/usr/local/lumos/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lumos/lib
export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/lumos/lib
```

添加完成后，在命令行运行

```shell
source ~/.bashrc
```

来激活相关设置，此时您已经完成lumos的安装

通过命令行验证安装

```shell
lumos --version
```

若出现以下版本信息，则您已经安装好了lumos

```shell
Lumos version: v0.4-a
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

我们提供了丰富的用例demo，您可以尝试运行这些demo，来开启您的lumos之旅

以xor用例为例，调用如下命令

```shell
sudo lumos --demo xor
```

开始xor示例模型的训练和测试

lumos会打印网络结构

```shell
[Lumos]                     Inputs         Outputs
Im2col          Layer      2*  1*  1 ==>   1*  2*  1
Connect         Layer      1*  2*  1 ==>   1*  4*  1
Connect         Layer      1*  4*  1 ==>   1*  2*  1
Connect         Layer      1*  2*  1 ==>   1*  1*  1
Mse             Layer      1*  1*  1 ==>   1*  1*  1
```

经过训练和测试您将看到最终结果如下

```shell
Session Start To Detect Test Cases
Test Data Path: ./src/demo/xor/data/00.png
Label:   0
Truth:   0.000000
Predict: 0.189420
Loss:    0.035880

Test Data Path: ./src/demo/xor/data/01.png
Label:   1
Truth:   1.000000
Predict: 0.842445
Loss:    0.024823

Test Data Path: ./src/demo/xor/data/11.png
Label:   0
Truth:   0.000000
Predict: 0.135885
Loss:    0.018465

Test Data Path: ./src/demo/xor/data/10.png
Label:   1
Truth:   1.000000
Predict: 0.866493
Loss:    0.017824
```



**Windows：**

由于lumos支持CUDA加速，所以我们无法在windows上直接编译，我们推荐您使用wsl2，这是windows推出的Linux Subsystem，并且wsl2支持GPU，相关安装方法请参考[wsl文档](https://docs.microsoft.com/zh-cn/windows/wsl/)

如果您成功安装wsl2，那么请参考上文Linux下Lumos安装方法



**CUDA：**

Lumos支持cuda加速（虽然现在还没有^_^），如果您拥有支持cuda的GPU，并且希望使用GPU加速您的算法，那么请提前安装cuda，相关安装方法请参考[cuda文档](https://docs.nvidia.com/cuda/cuda-toolkit-release-notes/index.html)


### 使用
通过添加头文件: lumos.h
```
"lumos.h"
```
来调用我们提供的相关接口，接口详细信息请查看我们的接口描述文件
编译时请添加如下命令
链接动态库:
```shell
-llumgraph -llumops -llumos
```

头文件引用路径:
```shell
-I/usr/local/lumos/include/
```

编译时如果出现如下错误:
```shell
/usr/bin/ld: /usr/local/lumos/lib/../lib/liblumops.so: undefined reference to `omp_get_thread_num'
/usr/bin/ld: /usr/local/lumos/lib/../lib/liblumops.so: undefined reference to `omp_get_num_threads'
/usr/bin/ld: /usr/local/lumos/lib/../lib/liblumops.so: undefined reference to `GOMP_parallel'
collect2: error: ld returned 1 exit status
```

请添加如下编译参数:
```shell
-fopenmp
```

通常，正确的编译命令应该如下:
```shell
gcc -fopenmp main.c -I/usr/local/lumos/include/ -o main -llumgraph -llumops -llumos
```

### 发行版
**[v0.4-a](https://github.com/LumosNet/Lumos/tree/v0.4-a/)**：我们修复了卷积网络问题，可以保证基础全连接网络和卷积网络运行，并提供了LeNet5网络模型demo

**[v0.3-a](https://github.com/LumosNet/Lumos/tree/v0.3-a/)**：我们修复了梯度不收敛问题，可以保证全连接网络正确运行

**[v0.2-a](https://github.com/LumosNet/Lumos/tree/v0.2-a/)**：我们对lumos代码进行了全面重构，我们将在这个版本进行全面测试，我们已经提供了安装包，您可以参照上述安装步骤进行安装。我们不再建议您直接使用源码，虽然也可以。当前版本并非正式发行版本，如果您依然愿意使用，我们将非常感激，如果遇到任何问题，请通过邮件知会我们，我们将及时处理

**[v0.1-a](https://github.com/LumosNet/Lumos/tree/v0.1-a/)**：Lumos第一个测试版本，主要对基本网络框架进行测试，若无必要，请不要使用该版本。当前我们推荐您直接使用master分支的最新提交版本

联系我们：
    邮箱：yuzhuoandlb@foxmail.com
    