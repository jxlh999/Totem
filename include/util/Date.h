/*
 * Date.h
 *
 *  Created on: Sep 18, 2011
 *      Author: xiaolei
 */

#ifndef DATE_H_
#define DATE_H_

#include "Object.h"

namespace util {

class Date: public lang::Object {
public:
	Date();
	virtual ~Date();
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
private:
	int mYear;
	int mMonth;
	int mDay;
	int mHour;
	int mMinute;
	int mSecond;
};

}

#endif /* DATE_H_ */
