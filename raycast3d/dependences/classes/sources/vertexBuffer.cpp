#include "vertexBuffer.hpp"


vertexBuffer::vertexBuffer()
{
    glGenBuffers(1, &ID);
}

vertexBuffer::~vertexBuffer()
{
    glDeleteBuffers(1, &ID);

}

void vertexBuffer::addData(const void* data,unsigned int size, unsigned int usage) const
{
    glBindBuffer(GL_ARRAY_BUFFER,ID);
    glBufferData(GL_ARRAY_BUFFER,size,data,usage);
}

void vertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER,ID);
}

void vertexBuffer::unBind() const
{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
 
void vertexBuffer::Delete() const
{
    glDeleteBuffers(1,&ID);
}