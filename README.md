# Collision-Detection
Problem statement
Assume we have two objects in 2D plane and we have there initial position and velocity (magnitude and direction)
Determine if they would collide.
If they would collide determine the actual time and position of collide.  
pseudo code
get user input for object A 
get user input for object B 
assume object B is stationery
calculate object A relative velocity relative to object B 
relative velocity = A.velocity – B.velocity 
calculate the distance between the two objects 
calculate the time to travel between the two objects using the relative speed
find the final position of the first object after moving with the relative velocity for the time we calculated 
if the fined position equals the position of the second object calculate the collision point which is the final position of the first object after moving with it’s real velocity and the calculated time 
return true ;
tell the user that the two objects will collide and print the collision time and position 
else 
return false ;
tell the user that the two objects will never collide 
