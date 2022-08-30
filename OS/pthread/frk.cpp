#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	int pid;
	cout << " parent pid " << getpid() << endl;
	pid = fork();
	if (pid == 0)
	{
		cout << "\Process id : " 
			<< getpid() << endl;
		cout << "\nChild Process with parent id : " 
			<< getppid() << endl;
	}
	return 0;
}
