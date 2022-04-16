#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>
#include <vector>
#include "../../gen-cpp/BeveragePreferenceService.h"
#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{
	class BeveragePreferenceHandler : public BeveragePreferenceServiceIf {
		public:
			BeveragePreferenceHandler();
			~BeveragePreferenceHandler() override=default;
			void getBeverage(std::string& _return, const BeverageType::type bevType) override;
	};
	
	BeveragePreferenceHandler::BeveragePreferenceHandler() {

	}

	void BeveragePreferenceHandler::getBeverage(std::string& _return, const BeverageType::type bevType) {
		
		std::vector <std::string> hotDrinks {"Cappuccino", "Latte", "Espresso"};
		std::vector <std::string> coldDrinks {"Lemonade", "Ice tea", "Soda"};
		std::string emptyString ="";

		if(bevType == BeverageType::type::COLD){
			emptyString = coldDrinks[rand() % 3];
			_return = "Cold Beverage";
		}else{
			emptyString = hotDrinks[rand() % 3];
			_return = "Hot Beverage";
		}

		_return =  emptyString;

	}

}
#endif
