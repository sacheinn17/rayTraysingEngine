#include "renderer.hpp"

void renderer::clear(float red,float green,float blue,float alpha)
{
    glClearColor(red,green,blue,alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}

void renderer::draw(unsigned int MODE,const vertexArray &va, const indexBuffer &ib, const shaderProgram &shader) const
{
    shader.use(); 
    va.bind();
    ib.Bind();

    glDrawElements(MODE,ib.getCount(),GL_UNSIGNED_INT,0);

}