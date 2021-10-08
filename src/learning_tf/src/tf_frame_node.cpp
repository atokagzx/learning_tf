#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
float R = 1, V = 4;
int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(30.0);
  
  while (node.ok()){
    node.getParam("/radius", R);
    node.getParam("/speed", V);
    transform.setOrigin( tf::Vector3(R * sin(ros::Time::now().toSec() * V), R * cos(ros::Time::now().toSec() * V), 0.0) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "turtle1", "carrot1"));
    rate.sleep();
  }
  return 0;
};