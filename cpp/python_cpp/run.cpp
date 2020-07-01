#include<iostream>
#include<python3.6/Python.h>

using namespace std;

int main()
{
	wchar_t *program = Py_DecodeLocale("/usr/bin/python3.6", NULL);
	Py_Initialize();
	Py_SetProgramName(program);
	FILE *file = _Py_fopen( "tmp.py", "r+" ); 
	int x = 0;
	if( file != NULL)
		x = PyRun_SimpleFile(file, "tmp.py");
	else 
		cout << " null file  " << endl;
	cout << " x " << x << endl;
	Py_Finalize();
	return 0;
}
