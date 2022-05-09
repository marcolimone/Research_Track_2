#include "ros/ros.h"
#include "controller_srv/Controller.h"

int command;



bool controllercall (controller_srv::Controller::Request &req, controller_srv::Controller::Response &res){
        
        if (req.command == 1)
        {
          command = req.direction_in;
        }
        else if (req.command == 2)
        {
          res.direction_out = command;        
        }
        
        return true;
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "server3");
   ros::NodeHandle n5;
   ros::ServiceServer service= n5.advertiseService("/controller", controllercall);
   ros::spin();
   return 0;
   }
