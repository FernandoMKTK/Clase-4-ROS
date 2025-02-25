#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv){

  ros::init(argc, argv, "nodo_publicado"); /*nombre del publicador*/

  ros::NodeHandle n;

  ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

  ros::Rate loop_rate(10);

  //geometry_msgs::msg::Twist cmd_vel_msg;
  geometry_msgs::Twist cmd_vel_msg;

  cmd_vel_msg.linear.x = 0.5;
  cmd_vel_msg.angular.z = 0.5;

  
  int count = 0;
  while (ros::ok())
  {
    std::cout<< "Publicando velocidad en tortuga" <<  std::endl;
    //cmd_vel_pub.publish(cmd_vel_pub);
    cmd_vel_pub.publish(cmd_vel_msg);
    loop_rate.sleep();//duerme el hilo las dos lineas de arriba
    
  }
  return 0;
}
