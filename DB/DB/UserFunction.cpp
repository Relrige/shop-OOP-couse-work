#include "UserFunction.h"

/// <summary>
/// menu for user
/// </summary>
void UserFunction::menu(){
	std::vector<std::string> list{"Show category","Exit"};
	while (true) {
		size_t achion = 0;
		int a = 0;
		while (a != 13) {
			system("cls");
			for (int i = 0; i < list.size(); i++) {
				if (i == achion) {
					Login::SetColor(0, 14);
				}
				if (i != achion) {
					Login::SetColor(0, 15);
				}
				std::cout << (*(list.begin() + i)) << std::endl;
				Login::SetColor(0, 15);
			}
			a = _getch();
			if (a == 119) {
				achion--;
				if (achion < 0) {
					achion = list.size();
				}
			}

			else if (a == 115) {
				achion++;
				if (achion > list.size()) {
					achion = 0;
				}
			}
		}
		if (achion == 0) {
			BaseFunctionForUsers::showCategory(1);
		}
		else {
			Login::menu();
		}
	}
}

	
