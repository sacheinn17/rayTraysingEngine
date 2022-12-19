#include "glad/glad.h" 
#include "GLFW/glfw3.h"

#include "shaderClass.hpp"
#include "indexBuffer.hpp"
#include "vertexBuffer.hpp"
#include "vertexArray.hpp"
#include "renderer.hpp"

#include <iostream>

void renderPlayer(GLFWwindow* window);

float px,py,a;

int mapx = 8, mapy=8,maps=64;

int map[] = {

    1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,0,1,0,1,
    1,1,1,1,1,1,1,1,

};

bool wallPresent = false;

void drawMap();
int main()
{
    px = 0.1f;
    py = 0.2f;
    a = 0.05f;

    float positions[] = {
        px-(a/2.0f) , py-(a/2.0f) , 0,
        px-(a/2.0f) , py+(a/2.0f) , 0,
        px+(a/2.0f) , py-(a/2.0f) , 0,
        px+(a/2.0f) , py+(a/2.0f),  0,

        0.5f+px-(a/2.0f) , 0.5f+py-(a/2.0f) , 0,
        0.5f+px-(a/2.0f) , 0.5f+py+(a/2.0f) , 0,
        0.5f+px+(a/2.0f) , 0.5f+py-(a/2.0f) , 0,
        0.5f+px+(a/2.0f) , 0.5f+py+(a/2.0f),  0
        };
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Raycast3D", NULL, NULL);
   
    glfwMakeContextCurrent(window);
    
    float color[] = {
        1.0f, 0.5f, 0.2f,1.0f
    };

    unsigned int indices [] = {
        0,1,2,
        1,3,2
    };

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 800);
    
    shaderProgram shader("dependences/shaders/vertexShader.glsl","dependences/shaders/fragmentShader.glsl");
    shader.use();
    shader.setfloat4("aColor",color);

    vertexArray va;
    vertexArray va2;
    va.bind();
    
    vertexBuffer vb;
    
    indexBuffer ib(indices,6,GL_STATIC_DRAW);
    ib.Bind();

    vb.addData(positions,sizeof(positions),GL_STATIC_DRAW);
    va.addBuffer(vb,0,3,GL_FLOAT,GL_FALSE,0);
    va2.addBuffer(vb,0,3,GL_FLOAT,GL_FALSE,3*sizeof(float));
    


    vb.unBind();
    ib.Unbind();
    renderer renderer;

    while (!glfwWindowShouldClose(window))
    {
        renderPlayer(window);

        renderer.clear(0.3f,0.3f,0.3f,1.0f);

        float translation[] = {px, py};

        shader.setfloat4("translation",translation);
        renderer.draw(GL_TRIANGLES,va,ib,shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    va.deleteVao();
    ib.Delete();
    vb.Delete();
}

void renderPlayer(GLFWwindow * window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_RIGHT)==GLFW_PRESS)
        px+=0.01f;

    if(glfwGetKey(window, GLFW_KEY_LEFT)==GLFW_PRESS)
        px-=0.01f;

    if(glfwGetKey(window, GLFW_KEY_UP)==GLFW_PRESS)
        py+=0.01f;

    if(glfwGetKey(window, GLFW_KEY_DOWN)==GLFW_PRESS)
        py-=0.01f;
}

