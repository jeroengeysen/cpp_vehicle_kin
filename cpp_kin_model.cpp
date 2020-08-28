#include <iostream>
#include <cmath>

using std::cout;

float x_dot = 0;
float y_dot = 0;
float teta_dot =0;
float L = 2;
float v = 10;
float delta = 0;
float dt = 0.01;
float x = 0;
float y = 0;
float teta = 0.2;


struct Derivatives {float x_dot; float y_dot;float teta_dot;};
struct Positions {float x; float y;float teta;};

Derivatives kinematic_eq(float &delta,float &teta, float &v, Derivatives &derivatives)
{
	//calculate derivatives
	derivatives.x_dot = v * cos(delta + teta);
	derivatives.y_dot = v * sin(delta + teta);
	derivatives.teta_dot = v * sin(delta)/L;

	
	//derivatives = (Derivatives){x_dot, y_dot, teta_dot};
	return derivatives; 
}

Positions integration(Derivatives &derivatives,Positions &positions)
{
	positions.x = positions.x + derivatives.x_dot*dt;
	positions.y = positions.y + derivatives.y_dot*dt;
	positions.teta = positions.teta + derivatives.teta_dot*dt;
	
	//positions = (Positions){x, y, teta};
	return positions;
}



int main()
{
	//initial positions
	Derivatives derivatives = {x_dot, y_dot, teta_dot};
	Positions positions = {x, y, teta};
	
	//auto positions = get_initial_positions(x,y,teta);

	for (int i=0;i<100;i++)
	{
	
		//obtain derivatives
		kinematic_eq(delta, teta, v, derivatives);
		
		//time integration
		integration(derivatives, positions);

		
		//cout << "step: " << i << std::endl;
		cout << "\t" << positions.x << "\t" << positions.y << std::endl;
	}



return 0;
}


