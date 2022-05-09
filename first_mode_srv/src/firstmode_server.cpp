#include "ros/ros.h"
#include "first_mode_srv/Firstmode.h"

float x;
float y;


bool firstmode (first_mode_srv::Firstmode::Request &req, first_mode_srv::Firstmode::Response &res){
       
        if (req.typereq == 1)
        {
          x = req.x_in;
          y = req.y_in;
        }
        else if (req.typereq == 2)
        {
         res.x_out = x;
         res.y_out = y;        
        }
  
        
        return true;
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "server2");
   ros::NodeHandle n4;
   ros::ServiceServer service= n4.advertiseService("/first_mode", firstmode);
   ros::spin();
   return 0;
   }
