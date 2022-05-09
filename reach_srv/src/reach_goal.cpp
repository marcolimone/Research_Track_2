#include "ros/ros.h"
#include "reach_srv/Reach.h"

int count_reach=0;
int tot_goal=0;


bool goalClk (reach_srv::Reach::Request &req, reach_srv::Reach::Response &res){

     if(req.mode == 1)
     {
       tot_goal=req.n_goal;
       count_reach = req.reach_goal;
     }
     else if(req.mode == 2)
     {
       res.goals=tot_goal;
       res.reached=count_reach;
     }

     return true;

}


int main(int argc, char **argv)
{
   ros::init(argc, argv, "server4");
   ros::NodeHandle n4;
   ros::ServiceServer service= n4.advertiseService("/reach_goal", goalClk);
   ros::spin();
   return 0;
   }
