#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace {

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

void error_callback(int error, const char* description) {
  std::cerr << "GLFW Error: " << description << std::endl;
}

}  // namespace

int main() {
  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    std::cout << "GLFW failed to initialize. Exiting" << std::endl;
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Context", NULL, NULL);
  if (!window) {
    std::cout << "GLFW failed to create a window. Exiting" << std::endl;
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  glewInit();
  std::cout << "Using OpenGL version: " << glGetString(GL_VERSION) << std::endl;

  while (!glfwWindowShouldClose(window)) {
    // render logic here...

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  exit(EXIT_SUCCESS);
}
