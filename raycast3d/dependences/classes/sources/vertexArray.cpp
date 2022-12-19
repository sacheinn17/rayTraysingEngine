#include "vertexArray.hpp"


vertexArray::vertexArray()
{
    glGenVertexArrays(1,&ID);
}

void vertexArray::addBuffer(vertexBuffer vb, unsigned int layout,unsigned int count, unsigned int TYPE, unsigned int NORMALIZED,unsigned int offset)
{
        vb.bind();

        glVertexAttribPointer(layout,count,TYPE,NORMALIZED,count*sizeof(float),(void*)offset);
        glEnableVertexAttribArray(layout);
        glBindVertexArray(0);

        vb.unBind();
}

void vertexArray::bind() const
{
    glBindVertexArray(ID);
}

void vertexArray::unbind() const
{
    glBindVertexArray(0);
}

void vertexArray::deleteVao() const
{
    glDeleteVertexArrays(1,&ID);
}

vertexArray::~vertexArray()
{
    glDeleteVertexArrays(1,&ID);
}