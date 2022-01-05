# 学习ROS的记录
> ROS版本：Ubuntu 18.04, melodic

里面主要包含学习**ros**的记录，分别有以下内容：
- `pub_sub_test`: 展示了从`int`，`string`，`array`，`poseStamped`等数据的收发，以及在类（**class**）内收发的例程
- `read_param_test`: 则是读取参数的测试，包括读取常用的`string`和`int`等，以及如何从`yaml`文件读取。
- `learn_rviz_tf`: 从`rviz`中，读取并显示`tf`树的变化。
- `msgs_test`: 表示消息机制的例程，如果需要自己定义消息机制的话。
- `python3_test`: 表示ROS环境下如何使用python3。虽然Ubuntu20下已经是python3了，但是现在还是有很多东西没有跟上。但是深度学习很多都是在用python3，所以这里需要测试。
 
## 创建新的功能包
在`src`文件夹下，使用`catkin_create_pkg xxx(name) rospy roscpp std_msgs`等，进行创建。



----
# Q&A
1. python中出现错误：![](https://raw.githubusercontent.com/zhuhu00/img/master/20211228150204.png)，这是由于创建后并没有给对应的权限，需要给运行权限。`chmod +x xxx.py`