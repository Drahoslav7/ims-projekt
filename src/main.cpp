/**
 * IMS
 * David Balvín (xbalvi00)
 * Drahoslav Bednář (xbedna55)
 */

#include "simlib/simlib.h"
#include <string>
#include <vector>
#include <algorithm>
#include "schedule.h"

using namespace std;

enum TrainType : int {
	TYPE_START,
	TYPE_PASS,
	TYPE_END,
};


class Train : public Process {
public:
	TrainType type;

	Train(TrainType t){
		type = t;
	}

	void Behavior(){

	}
};


class Station : public Facility {
public:
	int numberOftracks;

	Station(const char* name, int n) : Facility(name) {
		numberOftracks = n;
	}

};


class Generator : public Event {
public:
	vector<ScheduleRecord> schedule;
	int scheduleIndex;
	TrainType type;

	Generator(vector<ScheduleRecord> records, TrainType type) {
		schedule = records;
		sort(schedule.begin(), schedule.end());
		scheduleIndex = 0;
		this->type = type;
	}

	void Behavior(){
		(new Train(type))->Activate();
		if(scheduleIndex >= schedule.size()){
			return;
		}
		Activate(schedule[scheduleIndex].time);
		scheduleIndex++;
	}
};

// GLOBALS:

Generator startG(scheduleStart, TYPE_START);
Generator passG(schedulePass, TYPE_PASS);
Generator endG(scheduleEnd, TYPE_END);


/** Hlavní nádraží **/
Station mainStation("main station", 10);

/** MAIN **/
int main(int argc, char const *argv[])
{
	
	return 0;
}