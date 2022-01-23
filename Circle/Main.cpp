#include <GLFW/glfw3.h>
#include <iostream>

void DrawCircle()
{
	glBegin(GL_POLYGON);                        // Middle circle
	double radius = 0.4;
	double ori_x = 0.0;                         // the origin or center of circle
	double ori_y = 0.0;
	for (int i = 0; i <= 600; i++) {
		double angle = 2 * 3.14 * i / 600;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(ori_x + x, ori_y + y);
	}
	glEnd();
}

int main()
{
	glfwInit();

	// Window creation and error checking
	GLFWwindow* window = glfwCreateWindow(800, 600, "Circle", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Viewport set up and callback
	glViewport(0, 0, 800, 600);

	// Setting colors in window
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw Something
		DrawCircle();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}