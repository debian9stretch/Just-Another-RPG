#include <iostream>
#include "level.hpp"

Area::Area() {

}

Area::Area(int x) {
	areaBase = x;
}



int Area::getAreaBase() {
	return areaBase + 1;
}