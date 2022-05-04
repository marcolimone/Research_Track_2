# Assignment_1 RT2 Marco Limone

This first assignment is basically divided into 3 parts:
- 1) compilation of a documentation related to the third assignment of the RT1 course through the use of Doxygen or Sphinx
- 2) creation of a user interface in jupyter, which can replace the user interface of the third assignment of the RT1 course
- 3) statistical analysis made by comparing the rabot made by me for the first assignment of the RT1 course and a robot given by the professor

## First part

Personally I had to change a lot in the third assignment because I didn't have a real user interface separate from the core of the program, so I create a python script that is only a user interface. This user interface communicates with the main core through services (the main core would be the same script I already had previously where I removed the user interactions and added the communication with the services in their place).
Having said that, to do the documentation I used Sphinx, in particular for the core of the program which is written in C ++ I used the JAVADOC style, while for the user interface written in python I used Google Docstrings.

## Second part

For the second part I created a user interface in jupyter based broadly on the user interface written in python with the addition of some graphs referring to the trajectory of the robot, the number of goals achieved, and the laser display.
In particular, I used a cell for each task to try to make the user interface clearer. The description of the individual cells is sent specifically to the notebook where the functionality of the code cells has been described through markdown cells.

### How to run all
To run the robot the user have to download the repository : https://github.com/marcolimone/Research_Track_2.git
We need to launch the simulation with the followings commmands:
-roslaunch final_assignment final_assignment.launch -> it launch the simulation and the core (my_global_user_interface.cpp)
-rosrun mode_srv servermode_node -> to run the service for the chose of the mode
-rosrun first_mode_srv firstmode_node -> to run the service for the set of the goals 
-rosrun controller_srv controll_node -> to run the service for the controll of the robot in mode 2 and 3
-rosrun reach_srv goal_node -> to run the service for the number of total sends goals and reached one
-in the repository there is the notebook where there is the userinterface made with jupyter, after running all the previous step, the user can open and run the nootebook to interact with the simulation.

## Third part

As for the third part, in the repository there is a file containing a report relating to the statistical analysis that was carried out, with all the indications


## PSEUDO-CODE

### Core (my_global_user_interface.cpp)
include all type og messages we need
declaretion of publishers
initializate global variables 


void currentStatus(:MoveBaseActionFeedback msg)  {      
if (variable id != from the actual goal ID) {
        
        set id equal to actual ID;                                                   
    }

}

void clbk_laser(LaserScan msg){                        
    geometry_msgs::Twist vel;
    
    float rright = 30.0;
    float fright = 30.0;
    float front = 30.0;
    float fleft = 30.0;
    float lleft = 30.0;   
    
    search the min value for every sector of the laser scan 
    
    drive assistance of mode 3
    if (mode_3 is active){
        cancel last goal
        if (one of the min value is minor than 0,5){
           if (front < 1.0 ){
           robot does not go on;
           }
           else if (rright < 0.5){                                                                     
           turn in order to not crash
           }
           else if (lleft < 0.5){                                                                     
           turn in order to not crash
           }
        }
        command to drive the robot, same as mode 2
        else {
        recall the service /controller to know the chosen command 
        if (command == 1){
           set linear and angular velocity to go on;
           }
        else if (command == 2){
           set linear and angular velocity to stop;
           }
        else if (command == 3){
           set linear and angular velocity to turn right;
           }
        else if (command == 4){
           set linear and angular velocity to turn left;
           }
        else if (command == 5){                   
           set current mode variable to 0 and mode 1 variable to 1 to change mode;
           } 
        else if (command == 6){                   
           set current mode variable to 0 and mode 3 variable to 1 to change mode;
           } 
           publish velocity;     
           }
     }
    return;
    }


void userCallback(Odometry msg)

{        

 geometry_msgs::Twist my_vel; 
 move_base_msgs::MoveBaseActionGoal coordinates;
 actionlib_msgs::GoalID canc_goal;
 
 float x;
 float y;
 recall service /mode to know the chosen mode
 
 //MODE 1 
 
 if (mode_1 == 1){
    
    recall the service /firstmode to receive the goal coordinates
    put the coordinates in x and y varables
    publish the insert position
    
  count of sended goal and reached goal
  if (actual send goal is different from the previous) 
       set the past goal variables to the new goal
       increase the counter of total send goals
  take the position between the robot and the actual goal
  if(the dstance is lower than a threshold)
          increase the reached goal counter
  recall the service /reach_goal to set the number of sended goals and the reached one        
}


//MODE 2 

else if (mode_2 == 1){

        recall the service /controller to know which command elaborate
        if (comm == 1){
           set linear and angular velocity
           }
        else if (comm == 2){             
           set linear and angular velocity
           }
        else if (comm == 3){              
           set linear and angular velocity
           }
        else if (comm == 4){              
           set linear and angular velocity 
           }
        else if (comm == 5){              
           set current mode variable to 0 and mode 1 variable to 1 to change mode
           }
        else if (comm == 6){              
           set current mode variable to 0 and mode 3 variable to 1 to change mode
           }
        publish velocity;
       }     
}

int main (int argc, char **argv):

{

 Initialize the nodes 
 
   
  Define the subscribers with their callback    
  
     
  Define the publishers  
   
   
  start Multi-threading
  ros::AsyncSpinner spinner(3); 
  spinner.start();
  ros::waitForShutdown();
   
   

}
