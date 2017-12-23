#include "highguiMouse.hpp"

/*
** This program allows the user to drag the mouse from the center to a point on the circumference to create a circle on 
** the image.
*/

Point g_center, g_circumference;						// Center of the circle and point on the circumference
Mat g_src;									// Source image


void drawCircle(int action, int x, int y, int flags, void* userdata)
{
	/* This is callback function when the left mouse button is pressed.*/

	// Action when the left mouse button is pressed
	if(action == EVENT_LBUTTONDOWN){
		g_center = Point(x, y);
		circle(g_src, g_center, 1, Scalar(255, 255, 0), 2, CV_AA);
	}
	// Action when the left mouse button is released
	if(action == EVENT_LBUTTONUP){
		g_circumference = Point(x, y);
		// Calculate radius of circle
		float radius = sqrt(pow(g_center.x - g_center.y, 2) -
					pow(g_center.y - g_center.y, 2));
		// Draw the circle
		circle(g_src, g_center, radius, Scalar(0, 255, 0), 2, CV_AA);
		imshow("Window", g_src);
	}
}

int highguiMouse(char* name)
{
	g_src = imread(name, 1);

	if(g_src.empty()){
		return EXIT_FAILURE;
	}

	// This dummy image will be useful to clear the drawing
	Mat dummy = g_src.clone();
	namedWindow("Window", WINDOW_NORMAL);

	// Set mouse event handler
	setMouseCallback("Window", drawCircle);

	int k = 0;

	while(k != 27){
		imshow("Window", g_src);
		putText(g_src, 
			"Choose center and drag, press escape to exit and c" \
				" to clear", 
			Point(10,30), FONT_HERSHEY_SIMPLEX, 0.7, 
			Scalar(255,255,255), 2 );
		k = waitKey(20) & 0xFF;
		if(k == 99){
			dummy.copyTo(g_src);					// Another way to copy
		}
	}
	return EXIT_SUCCESS;
}
