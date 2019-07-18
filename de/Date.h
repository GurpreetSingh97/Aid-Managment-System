// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
// Revision History
// -----------------------------------------------------------
// Name:Gurpreet Singh     Date:26 November 2017     Reason: -
/////////////////////////////////////////////////////////////////
#include <iostream>
#ifndef SICT_DATE_H
#define SICT_DATE_H

namespace sict {

	#define NO_ERROR 0
	#define CIN_FAILED 1
	#define YEAR_ERROR 2
	#define MON_ERROR 3
	#define DAY_ERROR 4


	//pre defined constants
	const int min_year = 2000;
	const int  max_year = 2030;


  class Date {
 
	  int year;
	  int month;
	  int day;

	  int comparator;
	  int error_state;

	  int mdays(int, int)const;
	 void errCode(int errorCode);
 
  public:
	  Date();
	  Date(int p_year,int p_month ,int p_day);
	  
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	   //Queries and modifier
	  int errCode() const;
	  bool bad() const;
	 
	 
	 
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;

  };

 //HELPER FUNCTION
  std::ostream& operator<<(std::ostream& ostr, const Date& date);
  std::istream& operator>>(std::istream& istr, Date& date);


}
#endif
