// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description

// Revision History
// -----------------------------------------------------------
// Name:Gurpreet Singh      Date 26 November 2017      Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace sict {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

  void Date::errCode(int errorCode) {
	  error_state = errorCode;
  }

  Date::Date() {
	  year = 0;
	  month = 0;
	  day = 0;
	  error_state = NO_ERROR;
	  comparator = 0;
  }

  Date::Date(int p_year, int p_month, int p_day) {
	  year = p_year;
	  month = p_month;
	  day = p_day;
	  comparator = p_year * 372 + p_month * 13 + p_day;
	  if (year > min_year && year < max_year) {
		  if (p_month >= 1 && p_month <= 12) {
			  int m_days = mdays(p_month, p_year);
			  if (p_day >= 0 && p_day <= m_days) {
				  error_state = NO_ERROR;
			  }
			  else {
				  error_state = DAY_ERROR;
				  year = 0;
				  month = 0;
				  day = 0;
				  comparator = 0;
			  }
		  }
		  else {
			  error_state = MON_ERROR;
			  year = 0;
			  month = 0;
			  day = 0;
			  comparator = 0;
		  }
	  }
	  else {
		  error_state = YEAR_ERROR;
		  year = 0;
		  month = 0;
		  day = 0;  
		  comparator = 0;
	  }

  }


  bool Date::operator==(const Date& rhs) const {
	  int answer;
	  if (comparator == rhs.comparator) {
		  answer = true;
	  }
	  else {
		  answer = false;
	  }
	  return answer;
  }

   



  bool Date::operator!=(const Date& rhs) const {
	  int answer;
	  if (comparator != rhs.comparator) {
		  answer = true;
	  }
	  else {
		  answer = false;
	  }
	  return answer;
  }

  bool Date::operator<(const Date& rhs) const {
	  int answer;
	  if (comparator < rhs.comparator) {
		  answer = true;
	  }
	  else {
		  answer = false;
	  }
	  return answer;
  }

  bool Date::operator>(const Date& rhs) const {
	  int answer;
	  if (comparator > rhs.comparator) {
		  answer = true;
	  }
	  else {
		  answer = false;
	  }
	  return answer;
  }
 

  bool Date::operator<=(const Date& rhs) const {
	  int answer;
	  if (comparator <= rhs.comparator) {
		  answer = true;
	  }
	  else {
		  answer = false;
	  }
	  return answer;
  }

  bool Date::operator>=(const Date& rhs) const {
	  int answer;
	  if (comparator >= rhs.comparator) {
		  answer = true;
	  }
	  else {
		  answer = false;
	  }
	  return answer;
  }

  int Date::errCode() const {
	  return  error_state;
	  
  }

  bool Date::bad() const {
	  bool answer;
	  if (error_state != NO_ERROR) {
		  answer = true;
	}
	  else {
		  answer = false;
	  }
	  return answer;
  }

  std::istream& Date::read(std::istream& istr) {
	  // ignore function as a buffer clear
	  istr >> year;
	  istr.ignore();
	  istr >> month;
	  istr.ignore();
	  istr >> day;

	  if (!(istr.fail())) {
		  if (!(year >= min_year && year <= max_year)) {

			  year = 0;
			  month = 0;
			  day = 0;
			  error_state = YEAR_ERROR;
		  }

		  else if (!(month > 0 && month <= 12)) {
			  year = 0;
			  month = 0;
			  day = 0;
			  error_state = MON_ERROR;
		  }

		  else if (!(day > 0 && day <= mdays(month, year))) {
			  year = 0;
			  month = 0;
			  day = 0;
			  error_state = DAY_ERROR;
		  }

		  else {
			  error_state = NO_ERROR;
		  }
	  }

	  else {
		  error_state = CIN_FAILED;
	  }

	  return istr;
  }

  std::ostream& Date::write(std::ostream& ostr) const {

	  ostr << year << "/";

	  if (month <= 9) {  
		  ostr << "0";
	  }

	  ostr << month << "/";

	  if (day <=9) {
		  ostr << "0";
	  }

	  ostr << day;
	  return ostr;
  }



  //HELPER FUNCTIONS 
  std::ostream& operator<<(std::ostream& ostr, const Date& date) {
	  return date.write(ostr);
  }
  std::istream& operator>>(std::istream& istr, Date& date) {
	  return date.read(istr);
  }


  //SICT ENDS HERE
}
