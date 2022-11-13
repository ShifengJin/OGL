#include <sstream>
#include "Common.h"

namespace  DarkerOGL{

std::string FloatToString(float value)
{
    std::stringstream buf;
    buf.precision(3);
    buf.setf(std::ios::fixed);
    buf << value;
    std::string ans = buf.str();
    return ans;
}

}
