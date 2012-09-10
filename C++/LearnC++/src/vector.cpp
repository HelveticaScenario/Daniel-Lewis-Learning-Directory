#include "vector.h"
#include <cmath>
//Its all become rather convoluted and it doesn't work.


// using namespace custom_vector;

//-------CONSTRUCTORS-------//

vec2::vec2(float x, float y){
	vec2::set(x, _x);
	vec2::set(y, _y);
	vec2::set(sqrt(pow(vec2::get_x(), 2.0) + pow(vec2::get_y(), 2.0)), _mag);
	vec2::eval_unit();
}

//-------GETTERS--------//

float vec2::get(float &var){
	return var;
}

float vec2::get_x(){
	return vec2::get(_x);
}

float vec2::get_y(){
	return vec2::get(_y);
}

float vec2::get_unit_x(){
	return vec2::get(_unit_x);
}

float vec2::get_unit_y(){
	return vec2::get(_unit_y);
}
float vec2::get_mag(){
	return vec2::get(_mag);
}

//-------SETTERS--------//

void vec2::set(float val, float &var){
	var = val;
}

void vec2::set_x(float val){
	vec2::set(val, _x);
	vec2::eval_mag();

}

void vec2::set_y(float val){
	vec2::set(val, _y);
	vec2::eval_mag();

}

void vec2::set_x_y(float x, float y){
	vec2::set(x, _x);
	vec2::set(y, _y);
	vec2::eval_mag();

}

void vec2::set_unit_x(float val){
	vec2::set(val, _unit_x);
}

void vec2::set_unit_y(float val){
	vec2::set(val, _unit_y);
}
void vec2::set_mag(float val){
	float old_mag = _mag;
	vec2::set(val, _mag);
	vec2::eval_x_y(old_mag);
}

//-------EVALS--------//

void vec2::eval_mag(){
	// float x_squared = pow(_x, 2.0);
	// float y_squared = pow(_y, 2.0);
	// float combined = x_squared + y_squared;
	// float root = sqrt(combined);
	// vec2::set_mag(combined);
	if (vec2::get_x() != 0.0 || vec2::get_y() != 0.0)
	{
		vec2::set_mag(sqrt(pow(vec2::get_x(), 2.0) + pow(vec2::get_y(), 2.0)));
	}
	else vec2::set_mag(0.0);
}

void vec2::eval_x_y(float old_mag){
	if (old_mag != 0.0)
	{
		float difference = vec2::get_mag() / old_mag ;
		vec2::set_x_y(vec2::get_x() * difference, vec2::get_y() * difference);
		vec2::set(vec2::get_x() * difference, _x);
		vec2::set(vec2::get_y() * difference, _y);
		vec2::eval_unit();
	}
	else
	{
		vec2::set(vec2::get_unit_x() * vec2::get_mag(), _x);
		vec2::set(vec2::get_unit_y() * vec2::get_mag(), _y);
		vec2::eval_unit();
	}
}

void vec2::eval_unit(){
	if (vec2::get_mag() == 0.0)
	{
		return;
	}
	vec2::set_unit_x(vec2::get_x() / vec2::get_mag());
	vec2::set_unit_y(vec2::get_y() / vec2::get_mag());
} 