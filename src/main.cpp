/**
 * IMS
 * Simulace dopravního uzlu
 * - Brno Hlavní nádraží
 * 
 * David Balvín (xbalvi00)
 * Drahoslav Bednář (xbedna55)
 */

#include "simlib.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "schedule.h"

using namespace std;


Histogram Table("Table",0,60,24);
Store mainStation("main station", 10);


////////////////////////////
/// DECLARATIONS


class Train : public Process {
public:
	// TrainType type;
	t_time waitTime;
	TrainType type;

	Train(t_time waitTime,	TrainType type){
		this->waitTime = waitTime;
		this->type = type;
	}

	void Behavior(){
		Table(Time);
		Enter(mainStation, 1);
		// mainStation.Enter(this,1);

		Wait(waitTime);
		
		// Wait(10);

		Leave(mainStation, 1);
		// mainStation.Leave(1);

	};
};


class Station : public Store {
public:
	// Station(const char* name, int n) : Store(name, n) {
	// }

};


class Generator : public Event {

private:
	int scheduleIndex;
	vector<ScheduleRecord> schedule;
	// TrainType type;

public:

	Generator(vector<ScheduleRecord> records) {
		schedule = records;
		sort(schedule.begin(), schedule.end());
		scheduleIndex = 0;
		// this->type = type;
	}

	void Activate(){
		Event::Activate(schedule[scheduleIndex].time);
	}

	void Behavior(){
		(new Train(schedule[scheduleIndex].waitTime, schedule[scheduleIndex].type))->Activate();
		scheduleIndex++;
		if(scheduleIndex >= schedule.size()){
			return;
		}

		Event::Activate(schedule[scheduleIndex].time);

	}
};

//////////////////////////////////////
// GLOBALS:





/** Hlavní nádraží **/

/** MAIN **/
int main(int argc, char const *argv[])
{
	DebugON();

	std::vector<Generator*> generators;

	for(auto &line : schedule) {
		generators.push_back(new Generator(line.second));
	}


	Print("Model dopravniho uzlu\n");
	SetOutput("model.out");
	Init(0, TIME(23,59));        // whole day

	for(auto &generator : generators) {
		generator->Activate();
	}

	// startingTrainsGen.Activate();
	// passingTrainsGen.Activate();
	// endingTrainsGen.Activate();
	Run();                     // simulation
	// Box.Output();              // print of results
	Table.Output();
	return 0;
}