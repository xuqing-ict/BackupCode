#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

static const char *opt_str = "1:2:t:";

int main(int argc , char **argv)
{
	pid_t status;
	string command = "./test.sh";
	string read_file_name1, read_file_name2, training;

	int opt;
	opt = getopt(argc, argv, opt_str);
	while(opt != -1)
	{
		switch(opt)
		{
			case '1':
				read_file_name1 = optarg;
				break;
			case '2':
				read_file_name2 = optarg;
				break;
			case 't':
				training = optarg;
				break;
			default:
				cout << "Invalid parameter" << endl;
				exit(1);
		}
		opt = getopt(argc, argv, opt_str);
	}
	command += " -1 ";
	command += read_file_name1;
	command += " -2 ";
	command += read_file_name2;
	command += " -t ";
	command += training;
	cout << "command " << command << endl;
	
	status = system(command.c_str());
	if (-1 == status)
	{
		cout << "system error!!" << endl;
		exit(1);
	}
	else
	{
		printf("exit status value = [0x%x]\n" , status);
		if (WIFEXITED(status))
		{
			if (0 == WEXITSTATUS(status))
			{
				printf("run shell for PerM successfully..\n");
			}
			else
			{
				printf("runt shell for PerM failed, script exit code : %d\n", status);
			}
		}
		else
		{
			printf("exit status = [%d]\n",WEXITSTATUS(status));
		}
	}

	for(int i = 0 ; i < 10 ; ++i)
		cout << i << endl;
	return 0;
}
