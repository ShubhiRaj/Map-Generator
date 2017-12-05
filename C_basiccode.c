#include <stdio.h>
#include <math.h>

int main(){
  
  //assign angle in degrees from gps to theta
  double theta;
  theta=(3.14/180)*32.5;
  
  double d1,d2,d3,d4,d5;
  //take sensor 1's angle to the theta1
  d1=3.2; 

  /*get cordinates of reference point by getting distance of corner from current location, ie. r. Angle is tan-1(3/4). 
   * refx= Gpsposition.x - rsin(angle);
   * refy= Gpsposition.y + rcos(angle);
   */
  
  double Gpsposition_x= 50.4567, Gpsposition_y=60.7657, refx,refy, x0, y0;
  refx=Gpsposition_x-d1*(3/5);
  refy=Gpsposition_y+d1*(4/5);
  x0=Gpsposition_x-refx;
  y0=Gpsposition_y-refy;

  //now we need to turn

  d1=2.6; d2=2.4; d3=2.7; d4=3.4; d5=3.1;
  
  double theta1;
  // getting this from the GPS
  //do theta1=theta1 - theta - tan-1(3/4)
  theta1=(3.14/180)*62;
  theta1=theta1-theta-atan(3/4);
  
  double theta2=theta1+(3.14/180)*72, theta3=theta1+(3.14/180)*2*72, theta4=theta1+(3.14/180)*3*72, theta5=theta1+(3.14/180)*4*72;
  
  double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
  x1=x0+d1*sin(theta1);
  y1=y0+d1*cos(theta1);
  
  x2=x0+d2*sin(theta2);
  y2=y0+d2*cos(theta2);
  
  x3=x0+d3*sin(theta3);
  y3=y0+d3*cos(theta3);
  
  x4=x0+d4*sin(theta4);
  y4=y0+d4*cos(theta4);
 
  x5=x0+d5*sin(theta5);
  y5=y0+d5*cos(theta5);

  x1=floor(x1+0.5);  y1=floor(y1+0.5);
  x2=floor(x2+0.5);  y2=floor(y2+0.5);
  x3=floor(x3+0.5);  y3=floor(y3+0.5);
  x4=floor(x4+0.5);  y4=floor(y4+0.5);
  x5=floor(x5+0.5);  y5=floor(y5+0.5); 

  printf("x0=%d y0=%d\n",x0,y0);
  printf("x1=%d y1=%d\n",x1,y1);
  printf("x2=%d y2=%d\n",x2,y2);
  printf("x3=%d y3=%d\n",x3,y3);
  printf("x4=%d y4=%d\n",x4,y4);
  printf("x5=%d y5=%d\n",x5,y5);
  return 0;
}  