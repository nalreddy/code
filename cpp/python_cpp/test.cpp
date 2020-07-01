#include<iostream>
#include <python2.7/Python.h>

int main()
{
//    PyObject* pInt;

    Py_Initialize();

    PyRun_SimpleString("print('Hello World from Embedded Python!!!')");

    Py_Finalize();

    return 0;
}
