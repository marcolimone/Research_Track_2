#include "ros/ros.h"
#include "mode_srv/Mode.h"

int mode1=0;
int mode2=0;
int mode3=0;

bool mymode (mode_srv::Mode::Request &req, mode_srv::Mode::Response &res){
        
     if (req.type == 1)
     {   
        if (req.in_mode == 1)
        {
          mode1= 1 ;
          mode2= 0 ;
          mode3= 0 ;
        }
        else if (req.in_mode == 2)
        {
          mode1= 0 ;
          mode2= 1 ;
          mode3= 0 ;        
        }
        else if (req.in_mode == 3)
        {
          mode1= 0 ;
          mode2= 0 ;
          mode3= 1 ;                
        }
     } 
     else if (req.type == 2)
     {  
        res.out_mode1= mode1;
        res.out_mode2=mode2;
        res.out_mode3=mode3;
     }  
     
        return true;
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "server1");
   ros::NodeHandle n3;
   ros::ServiceServer service= n3.advertiseService("/mode", mymode);
   ros::spin();
   return 0;
   }
