#include<iostream>
#include <python3.6/Python.h>
#include <wchar.h>

using namespace std;

#if 0
wchar_t *nstrws_convert(char *raw) {
	wchar_t *rtn = (wchar_t *) calloc(1, (sizeof(wchar_t) * (strlen(raw) + 1)));
	setlocale(LC_ALL,"en_US.UTF-8"); // Unless you do this python 3 crashes.
	mbstowcs(rtn, raw, strlen(raw));
	return rtn;
}

/** Dispose of an array of wchar_t * */
void nstrws_dispose(int count, wchar_t ** values) {
	for (int i = 0; i < count; i++) {
		free(values[i]);
	}
	free(values);
}

/** Convert an array of strings to wchar_t * all at once. */
wchar_t **nstrws_array(int argc, char *argv[]) {
	wchar_t **rtn = (wchar_t **) calloc(argc, sizeof(wchar_t *));
	for (int i = 0; i < argc; i++) {
		rtn[i] = nstrws_convert(argv[i]);
	}
	return rtn;
}

#endif

int main(int argc, char *argv[])
{

	/* These have to be wchar_t */
//	char *str_program_name = argv[0];


#if 0
	wchar_t **_argv = nstrws_array(argc, str_argv);
	wchar_t *_program_name = nstrws_convert(str_program_name);
#endif
	wchar_t** _argv = (wchar_t**) PyMem_Malloc(sizeof(wchar_t*)*argc);
	for (int i=0; i < argc; i++) {
		wchar_t* arg = Py_DecodeLocale(argv[i], NULL);
		  _argv[i] = arg;
	}

	for (int i = 0; i < argc ; i++)
	{
		cout <<  "argv  i  " << i <<  " " << argv[i] << " _argv " << *_argv[i] << endl;
	}
	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	Py_SetProgramName(program);
	Py_Initialize();
	PySys_SetArgv(argc, _argv);

	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyBytes_FromString("."));
	PyList_Append(path, PyBytes_FromString("lib"));

	int rtn = Py_Main(argc, _argv); // <-- Notice the command line arguments.
	Py_Finalize();

	return 0;
}
