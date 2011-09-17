#include <iostream.h>

namespace util {
class Date: public Object {
public:
	void SetDate(Date date);
	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);
	void SetHour(int hour);
	void SetMinute(int minute);
	void SetSecond(int second);

	Date GetDate();
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMinute();
	int GetSecond();
	~Date();
private:
	Date();
}

}
