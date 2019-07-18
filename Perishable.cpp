#include <iostream>
#include "Perishable.h"
#include "Date.h"
using namespace std;
namespace sict {
	//done
	Perishable::Perishable() : NonPerishable('P') {
		expiry_date = Date();
	}
	//done
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		NonPerishable::store(file,false);
		if (file.is_open()) {
			file << ",";
			file << expiry_date;
			if (newLine == true) {
				file << endl;
			}
		}
		return file;
	}

	//done
	std::fstream& Perishable::load(std::fstream& file) {
		NonPerishable::load(file);

		file >> expiry_date;

		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		NonPerishable::write(os, linear);

		if (isEmpty() == false && isCLear()==true) {
			if (linear == true) {
				expiry_date.write(os);
			}
			else {
				os << '\n';
				os << "Expiry date: " << expiry_date;
			}
		}
		
		return os;
	}

	std::istream & Perishable::read(std::istream & is)
	{
		NonPerishable::read(is);
		if (is.fail()==false) {
			
			std::cout << "Expiry date (YYYY/MM/DD): ";
			Date temp;
			temp.Date::read(is);
			if (temp.Date::bad()==true) { // checking error state
				is.setstate(ios::failbit);
				if (temp.errCode() == YEAR_ERROR) {
					NonPerishable::message("Invalid Year in Date Entry");
				}
				if (temp.errCode() == MON_ERROR) {
					NonPerishable::message("Invalid Month in Date Entry");
				}
				if (temp.errCode() == DAY_ERROR) {
					NonPerishable::message("Invalid Day in Date Entry");
				}
				if (temp.errCode() == CIN_FAILED) {
					NonPerishable::message("Invalid Date Entry");
				}
			}
			if (is.fail()==false) {
				expiry_date = temp;
			}
		}
		return is;
	}

	const Date& Perishable::expiry() const {
		return expiry_date;
	}

	//helper function
	Product* CreatePerishable() {
		Product*  new_obj = new Perishable;
		return new_obj;

	}




}