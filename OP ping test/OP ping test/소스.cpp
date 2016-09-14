#include <ctime>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <string>
#include <stdlib.h>     /* atoi */

using namespace std;

string fileName;

string getFileName() {
	time_t currentTime;
	struct tm *localTime;

	time(&currentTime);                   // Get the current time
	localTime = localtime(&currentTime);  // Convert the current time to the local time

	int Day = localTime->tm_mday;
	int Month = localTime->tm_mon + 1;
	int Year = localTime->tm_year + 1900;
	int Hour = localTime->tm_hour;
	int Min = localTime->tm_min;
	int Sec = localTime->tm_sec;

	string fileName = "";
	fileName += to_string(Month) + "월" + to_string(Day) + "일" + to_string(Hour) + "시" + to_string(Min) + "분.txt";

	return fileName;
}

void main()
{
	while(true) {
		cout << getFileName() << endl;
		
		string cmd = "(ping 165.246.255.90 & ping 165.246.255.1 & ping 165.246.255.2 & ping 165.246.48.1 & ping 165.246.100.1 & ping 165.246.12.1 & 	ping 165.246.150.1  & ping 165.246.136.1 & ping 165.246.255.194  & ping 165.246.170.1 & ping 165.246.68.1 & ping 165.246.186.1 & ping 165.246.255.18 & ping 165.246.196.1 & ping 165.246.112.1 & ping 165.246.210.1 & ping 221.154.15.250  & ping 165.246.12.10  & ping 165.246.12.11 & ping 165.246.5.25 & ping 165.246.255.132 & ping 165.246.255.133 & ping 165.246.255.229 & ping 165.246.5.20 & ping 165.246.2.25 & ping 165.246.12.12 & ping 165.246.12.13 & ping 165.246.12.21 & ping 165.246.12.14 & ping 165.246.12.15 & ping 165.246.19.162 & ping 165.246.16.8 & ping 165.246.16.9 & ping 165.246.17.28 & ping 165.246.255.125 & nslookup www.inha.ac.kr & nslookup www.kreonet.re.kr)";
		cmd += " > " + getFileName();
		system(cmd.c_str());

		std::this_thread::sleep_for(std::chrono::seconds(60 * 60));
	}
}
