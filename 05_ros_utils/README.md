# ROS 记录
> ROS版本：Ubuntu 18.04, melodic

里面主要包含学习**ros**的记录，分别有以下内容：
- `pub_sub_test`: 展示了从`int`，`string`，`array`，`poseStamped`等数据的收发，以及在类（**class**）内收发的例程
- `read_param_test`: 则是读取参数的测试，包括读取常用的`string`和`int`等，以及如何从`yaml`文件读取。
- `learn_rviz_tf`: 从`rviz`中，读取并显示`tf`树的变化。
- `msgs_test`: 表示消息机制的例程，如果需要自己定义消息机制的话。
- `python3_test`: 表示ROS环境下如何使用python3。虽然Ubuntu20下已经是python3了，但是现在还是有很多东西没有跟上。但是深度学习很多都是在用python3，所以这里需要测试。详细查看：ROS使用python3
 
## 创建新的功能包
在`src`文件夹下，使用`catkin_create_pkg xxx(name) rospy roscpp std_msgs`等，进行创建。


### ROS使用python3
1. 安装python3的依赖和ROS包
   
   首先安装依赖
   ```bash
   sudo apt update
   sudo apt install -y python3 python3-dev python3-pip build-essential
   ```
   利用pip安装ROS相关包
   ```bash
   pip3 install rosdep rospkg rosinstall_generator rosinstall wstool vcstools catkin_tools catkin_pkg
   ```
   可能需要sudo权限。
2. 初始化ROS，使用如下命令：
   
   ```bash
   sudo rosdep init
   rosdep update
   ```
   如果第一步提示有相关文件存在，则使用`sudo删除相关文件`即可
3. 创建工作空间
   
   ```bash
   mkdir catkin_ws/src
   cd src 
   catkin_init_workspace
   ```
   在此之前，需要将opencv的部分重新编译：如下所示

    1. 初始化cv_bridge_ws编译工作空间
    ```bash
    mkdir -p cv_bridge_ws/src && cd cv_bridge_ws/src
    catkin_init_workspace
    ```
    2. 将cv_bridge源码拉取到本地
    ```bash
    git clone https://github.com.cnpmjs.org/ros-perception/vision_opencv.git
    ```
    3. 编译
    ```bash
    cd ../
    catkin_make install -DPYTHON_EXECUTABLE=/usr/bin/python3
    ```
    注意，这里使用的是python3编译，防止后续出现错误。
4. 基于python3的图像ros节点
   
   在3中的catkin_ws中，创建功能包：
   ```bash
   catkin_create_pkg py3_demo rospy rosmsg roscpp
   ```
   编写python3的图像收发节点及代码
   ```bash
    cd py3_demo && mkdir scripts
    cd scripts && touch camera.py img_process.py
    chmod +x camera.py
    chmod +x img_process.py
   ```
   代码部分如下`camera.py`
```python3
#!/usr/bin/env python3
# coding:utf-8

import cv2
import numpy as np
import rospy
from std_msgs.msg import Header
from sensor_msgs.msg import Image
from cv_bridge import CvBridge , CvBridgeError
import time

if __name__=="__main__":
    import sys 
    print(sys.version) # 查看python版本
    capture = cv2.VideoCapture(0) # 定义摄像头
    rospy.init_node('camera_node', anonymous=True) #定义节点
    image_pub=rospy.Publisher('/image_view/image_raw', Image, queue_size = 1) #定义话题

    while not rospy.is_shutdown():    # Ctrl C正常退出，如果异常退出会报错device busy！
        start = time.time()
        ret, frame = capture.read()
        if ret: # 如果有画面再执行
            # frame = cv2.flip(frame,0)   #垂直镜像操作
            frame = cv2.flip(frame,1)   #水平镜像操作   
    
            ros_frame = Image()
            header = Header(stamp = rospy.Time.now())
            header.frame_id = "Camera"
            ros_frame.header=header
            ros_frame.width = 640
            ros_frame.height = 480
            ros_frame.encoding = "bgr8"
            # ros_frame.step = 1920
            ros_frame.data = np.array(frame).tostring() #图片格式转换
            image_pub.publish(ros_frame) #发布消息
            end = time.time()  
            print("cost time:", end-start ) # 看一下每一帧的执行时间，从而确定合适的rate
            rate = rospy.Rate(25) # 10hz 

    capture.release()
    cv2.destroyAllWindows() 
    print("quit successfully!")
```

接收topic的代码：
```bash
#!/usr/bin/env python3
# coding:utf-8

import rospy
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
 
def callback(data):
    global bridge
    cv_img = bridge.imgmsg_to_cv2(data, "bgr8")
    cv2.imshow("frame" , cv_img)
    cv2.waitKey(1)

if __name__ == '__main__':
    import sys 
    print(sys.version) # 查看python版本
    
    rospy.init_node('img_process_node', anonymous=True)
    bridge = CvBridge()
    rospy.Subscriber('/image_view/image_raw', Image, callback)
    rospy.spin()
```
5. 编译，编译时也是记得使用python3进行编译
   
```bash
cd ../../..
catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3
```

之后source就可以运行了。

----
# Q&A
1. python中出现错误：![](https://raw.githubusercontent.com/zhuhu00/img/master/20211228150204.png)，这是由于创建后并没有给对应的权限，需要给运行权限。`chmod +x xxx.py`