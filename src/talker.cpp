#include "ros/ros.h"
#include "std_msgs/Float32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  
  ros::Publisher pub = n.advertise<std_msgs::Float32>("chatter", 100);
  
  ros::Rate loop_rate(100); // 100 Hz

  while (ros::ok())
  {
    std_msgs::Float32 msg;
    msg.data = 0.001;

    ROS_INFO("%f", msg.data);

    pub.publish(msg);

    ros::spin();
    loop_rate.sleep();
  }

  return 0;
}