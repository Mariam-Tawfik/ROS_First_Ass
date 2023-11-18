#include "ros/ros.h"
#include "std_msgs/Int32.h"


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "publisher");

  
  ros::NodeHandle n;

 
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);

  ros::Rate loop_rate(10);

  int count = 20;
  while (count!=101)
  {
   
    std_msgs::Int32 msg;

   
   
    msg.data = count;


   
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}