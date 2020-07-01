#include<iostream>
#include <python3.6/Python.h>

using namespace std;

int main(int argc, char *argv[])
{
	PyObject *pName, *pModule, *pFunc;
	PyObject *pArgs, *pValue;
	int i = 0;

	if (argc < 3) {
		fprintf(stderr,"Usage: call pythonfile funcname [args]\n");
		return 1;
	}

	cout << " arg0 " << argv[0] << "   arg1 " << argv[1] << " arg2 " << argv[2] << endl;
	Py_Initialize();
	PyRun_SimpleString("import os");
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append(os.getcwd())");
	pName = PyUnicode_DecodeFSDefault(argv[1]);
	/* Error checking of pName left out */

	pModule = PyImport_Import(pName);
	Py_DECREF(pName);

	if (pModule != NULL) {
		pFunc = PyObject_GetAttrString(pModule, argv[2]);

		if (pFunc && PyCallable_Check(pFunc) && argc > 3) {

			pArgs = PyTuple_New(2);
			for (i = 0; i < 2; i++)
			{
				int k = atoi(argv[i + 3]);
				cout << " i " << i + 3 << " K " << k << endl;
				pValue = PyLong_FromLong(k);
				if (!pValue)
				{
					PyErr_Print();
					return 1;
				}
				PyTuple_SetItem(pArgs, i, pValue);
			}

			pValue = PyObject_CallObject(pFunc, pArgs);


			if (pArgs != NULL)
			{
				Py_DECREF(pArgs);
			} else {
				cout << " Args null "<< endl;
			}

			if (pValue != NULL) 
			{
			//	cout << "Return val " << PyLong_AsLong(pValue) << endl;
				cout << "Return val " << endl;
				Py_DECREF(pValue);
			} else {

				cout << " pvalue  null " << endl;
			}

			Py_DECREF(pFunc);
			Py_DECREF(pModule);
			Py_FinalizeEx();
		} else 
		{ 
			cout << " func null " << endl;
		}
	} else  {

		cout << " Module null " << endl;
	}


	return 0;
}
