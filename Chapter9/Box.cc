#include "Chapter9.h"

bool Box::above(const Box &boxBottom) const{
    if(height<boxBottom.height && width<boxBottom.width && depth<boxBottom.depth)
	return true;
    return false;
}
