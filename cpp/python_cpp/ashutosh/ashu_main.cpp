#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>

using namespace std;

int
main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    if (argc < 3) {
        cout << "Usage: call pythonfile funcname [args]" << endl;
        return 1;
    }

    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("."));

    pName = PyUnicode_DecodeFSDefault(argv[1]);
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, argv[2]);
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(argc - 3);
            for (i = 0; i < argc - 3; ++i) {
                //pValue = PyLong_FromLong(atoi(argv[i + 3]));
                pValue = PyUnicode_FromString(argv[i + 3]);
cout << "pValue = " << pValue <<  " i = " << i << " argv[3] = " << argv[3] << endl;
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    cout << "Cannot convert argument" << endl;
                    return 1;
                }
                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, i, pValue);
                //PyTuple_SetItem(pArgs, i, PyUnicode_FromString(argv[i +3]));
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                //cout << "Result of call: " << PyLong_AsLong(pValue) << endl;
                cout << "Result of call: " << PyBytes_AsString(pValue) << endl;
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                cout << "Call failed" << endl;
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            cout << "Cannot find function " <<  argv[2] << endl;
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        cout << "Failed to load " <<  argv[1] << endl;
        return 1;
    }
    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}
