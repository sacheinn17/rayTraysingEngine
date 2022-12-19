#ifndef INDEX_BUFFER_CLASS
#define INDEX_BUFFER_CLASS

#include "glad/glad.h"
#include "GLFW/glfw3.h"



class indexBuffer{

private:
    unsigned int ID;
    unsigned int dataCount;
public:
    indexBuffer(const unsigned int* data, unsigned int count,unsigned int usage);
    ~indexBuffer();

    void Bind() const;
    unsigned int getCount()const{return dataCount;}
    void Unbind() const;
    void Delete() const;

};


#endif