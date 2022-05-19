#! /usr/bin/env python

# import ros stuff
import rospy
from move_base_msgs.msg import MoveBaseActionGoal
from nav_msgs.msg import Odometry



pub = rospy.Publisher("/move_base/goal", MoveBaseActionGoal, queue_size = 10)


def userCallback(msg):
    print("Target reached! Please insert a new position")
   
    #rospy.loginfo("Turtle subscriber @[%f, %f, %f]", msg.x, msg.y, msg.theta);
    coordinates = MoveBaseActionGoal()
    x = float(input("new x position:"))
    y = float(input("new y position:"))
    
    coordinates.goal.target_pose.header.frame_id = 'map'
    coordinates.goal.target_pose.pose.position.x = x
    coordinates.goal.target_pose.pose.position.y = y
    coordinates.goal.target_pose.pose.orientation.w = 1.0
    pub.publish(coordinates)
   
    print("Thanks! Let's reach the next position")
    return []


def main():
    rospy.init_node('user_interface')

    sub_odom = rospy.Subscriber('/odom', Odometry, userCallback)
    rospy.spin()



if __name__ == '__main__':
    main()
