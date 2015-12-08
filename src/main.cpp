/**
 * IMS
 * Simulace dopravního uzlu
 * - Brno Hlavní nádraží
 * 
 * David Balvín (xbalvi00)
 * Drahoslav Bednář (xbedna55)
 */

#include "simlib/simlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "schedule.h"

using namespace std;


Histogram Table("Table",0,60,24);
Store mainStation("main station", 10);


////////////////////////////
/// DECLARATIONS

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
		Table(Time);
		Enter(mainStation, 1);
		// mainStation.Enter(this,1);

		// switch(type){
		// 	case TYPE_START:
				Wait(10);
		// 		break;
		// 	case TYPE_END:
		// 		Wait(5);
		// 		break;
		// 	case TYPE_PASS:
		// 		Wait(5);
		// 		break;
		// }
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
	TrainType type;

public:

	Generator(vector<ScheduleRecord> records, TrainType type) {
		schedule = records;
		// sort(schedule.begin(), schedule.end());
		scheduleIndex = 0;
		this->type = type;
	}

	void Activate(){
		Event::Activate(schedule[scheduleIndex++].time);
	}

	void Behavior(){
		(new Train(type))->Activate();
		if(scheduleIndex >= schedule.size()){
			return;
		}

		Event::Activate(schedule[scheduleIndex++].time);

	}
};

//////////////////////////////////////
// GLOBALS:



Generator startingTrainsGen(scheduleStart, TYPE_START);
Generator passingTrainsGen(schedulePass, TYPE_PASS);
Generator endingTrainsGen(scheduleEnd, TYPE_END);


/** Hlavní nádraží **/

/** MAIN **/
int main(int argc, char const *argv[])
{
	Print("Model dopravniho uzlu\n");
	SetOutput("model.out");
	Init(0, TIME(23,59));        // whole day
	startingTrainsGen.Activate();
	// passingTrainsGen.Activate();
	// endingTrainsGen.Activate();
	Run();                     // simulation
	// Box.Output();              // print of results
	Table.Output();
	return 0;
}