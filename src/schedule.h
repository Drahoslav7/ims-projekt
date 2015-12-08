
#define TIME(h,m) ((60*(h))+(m))

typedef double t_time;

struct ScheduleRecord
{
	t_time time;
	int line;

	friend bool operator<(const ScheduleRecord& x, const ScheduleRecord& y){
		return (x.time < y.time);
	}
};


const std::vector<ScheduleRecord> scheduleEnd = {
	// TIME(),
};



const std::vector<ScheduleRecord> scheduleStart = {
	// 340:
	{TIME(0,35), 340},
	{TIME(4,25), 340},
	{TIME(5,12), 340},
	{TIME(6,11), 340},
	{TIME(7,35), 340},
	{TIME(8,12), 340},
	{TIME(9,28), 340},
	{TIME(10,15), 340},
	{TIME(11,28), 340},
	{TIME(12,15), 340},
	{TIME(12,49), 340},
	{TIME(13,28), 340},
	{TIME(13,48), 340},
	{TIME(14,14), 340},
	{TIME(14,47), 340},
	{TIME(15,28), 340},
	{TIME(15,48), 340},
	{TIME(16,14), 340},
	{TIME(16,47), 340},
	{TIME(17,28), 340},
	{TIME(17,48), 340},
	{TIME(18,15), 340},
	{TIME(18,48), 340},
	{TIME(19,28), 340},
	{TIME(20,15), 340},
	{TIME(21,28), 340},
	{TIME(22,48), 340},

};

const std::vector<ScheduleRecord> schedulePass = {

	// TIME(),	
	// TIME(),
	// TIME(),
	// TIME(),

};