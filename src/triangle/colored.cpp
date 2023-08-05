#include <GLAD/GLAD.h>
#include <GLFW/glfw3.h>
#include <shader/shader.h>
#include <window/window.h>
#include <iostream>

using namespace std;

void processInput(GLFWwindow *window);

// 스크린 크기
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float vertices[] = {
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f};

int main()
{
    Window windowObj = Window(SCR_WIDTH, SCR_HEIGHT, "Learn OpenGL");
    GLFWwindow *window = windowObj.window;
    if (!window)
        return -1;

    Shader shader = Shader("shaders/color/vertex-shader.glsl", "shaders/color/fragment-shader.glsl");

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        // 입력 처리
        processInput(window);

        // 버퍼 초기화
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        shader.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // 버퍼 출력
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}