#!/home/roma/miniconda3/envs/yolact-env/bin/python3
#-*-coding:utf-8-*-
# 注意这里import的顺序
import numpy
import rospy
from sensor_msgs.msg import Image
import sys
sys.path.remove('/opt/ros/melodic/lib/python2.7/dist-packages')
import cv2


def shutdown():
    print("shut down!")


def publisher():
    rospy.init_node("image_publisher", anonymous=True)
    if len(sys.argv)<2:
        rospy.loginfo("There should be a parameter follow the %s, such as 0 or 1.", sys.argv[0])
        rospy.on_shutdown(shutdown)
        return
    capture=cv2.VideoCapture(int(sys.argv[1]))
    imgPub=rospy.Publisher('/camera/image_raw',Image,queue_size=1)
    rospy.loginfo("I am publishing an image...")
    rate = rospy.Rate(30)
    
    while not rospy.is_shutdown():
        ref,frame=capture.read()
        image=Image()
        image.encoding='bgr8'
        image.height=frame.shape[0]
        image.width=frame.shape[1]
        image.step=frame.shape[1]*frame.shape[2]
        image.data=numpy.array(frame).tostring()
        image.header.stamp=rospy.Time.now()
        imgPub.publish(image)
        rate.sleep()


if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass