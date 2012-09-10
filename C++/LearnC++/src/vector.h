#ifndef VEC
#define VEC VEC
#include <iostream>
// namespace custom_vector{
	class vec2{
		private:
			float _x;
			float _y;
			float _unit_x;
			float _unit_y;
			float _mag;
			void set_unit_x(float);
			void set_unit_y(float);
		protected:
			float get(float&);
			void set(float, float&);
			void eval_mag();
			void eval_x_y(float);
			void eval_unit();
		public:
			vec2(float, float);
			// ~vec2();
			float get_x();
			float get_y();
			float get_unit_x();
			float get_unit_y();
			float get_mag();
			void set_x(float);
			void set_y(float);
			void set_x_y(float, float);
			void set_mag(float);
	};
// }

#endif