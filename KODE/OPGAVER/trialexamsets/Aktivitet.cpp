#include "Aktivitet.h"
#include <vector>
Aktivitet::Aktivitet() {}

Aktivitet::Aktivitet(int e, string t, int d)
{
	event = e;
	task = t;
	duration = d;
}

int Aktivitet::getEvent()
{
	return event;
}

string Aktivitet::getTask()
{
	return task;
}

int Aktivitet::getDuration()
{
	return duration;
}

//#include <vector>


/*
int Aktivitet::largestSlack(vector<Aktivitet> slackTable){
	int biggestSlack = 0;
	int currentEventDuration = 0;
	for (int i = 0; i < slackTable.size(); i++)
		biggestSlack(getSlack slackTable[i].getDuration());
}
		*/