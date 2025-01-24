#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

// Agregar esta línea para definir la variable globalmente
turtlesim::Pose pose_turtle;

void poseCallback(const turtlesim::Pose::ConstPtr& msg){
  pose_turtle.x = msg->x;
  pose_turtle.y = msg->y;

  ROS_INFO("Se recibio una posicion de la tortuga: x = [%.3f] y = [%.3f]",pose_turtle.x,pose_turtle.y);
}

int main(int argc, char **argv){

  ros::init(argc, argv, "nodo_suscriptor"); /*nombre del publicador*/

  ROS_INFO("Se inicializo el nodo suscriptor");
  ros::NodeHandle n;
  //declaracion de publocadores y suscriptores
  ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);
  ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);//10

  //loop rate
  ros::Rate loop_rate(10);

  //insertar una velocidad
  geometry_msgs::Twist cmd_vel_msg;

  cmd_vel_msg.linear.x = 0.5;
  cmd_vel_msg.angular.z = 0.5;

  int count = 0;
  while (ros::ok())
  {
    ROS_INFO("Publicando velocidad");
    std::cout<< "Publicando velocidad en tortuga" <<  std::endl;
    //cmd_vel_pub.publish(cmd_vel_pub);
    cmd_vel_pub.publish(cmd_vel_msg);
    
    //reevisar si hay alguna suscripcion disponible y en base a eso ejecuta la funcion poseCallback
    ros::spinOnce();
    loop_rate.sleep();//duerme el hilo las dos lineas de arriba
    
  }

//
  ros::spin();
  ROS_INFO("Despues del spin");


  return 0;
}
