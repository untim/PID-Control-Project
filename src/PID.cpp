#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	//setting coeffiecients of from arguments
	this -> Kp = Kp;
	this -> Ki = Ki;
	this -> Kd = Kd;

	p_error = 0;
	i_error = 0;
	d_error = 0;
}

void PID::UpdateError(double cte) {
	i_error += cte;
	d_error = cte - p_error;
	p_error = cte;
}

double PID::TotalError() {
	double steering_angle = -Kp*p_error - Ki*i_error - Kd*d_error;
	cout<< steering_angle<<endl;
	return steering_angle;
}