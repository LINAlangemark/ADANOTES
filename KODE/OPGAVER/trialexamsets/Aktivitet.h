#pragma once
#include <iostream>
using namespace std;
#include <vector>
class Aktivitet
{
public:
	Aktivitet();
	Aktivitet(int, string, int);
	int getEvent();
	string getTask();
	int getDuration();
	//int getSlack(int eventDuration, int activityDuration);
	//int largestSlack(vector<Aktivitet> slackTable);
private:
	int event;
	string task;
	int duration;
};

