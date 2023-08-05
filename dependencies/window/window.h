#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

class Window
{
public:
    GLFWwindow *window = NULL;
    Window(int width, int height, const char *title);
};

// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
