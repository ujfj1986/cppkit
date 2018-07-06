/*
 *
 * @file: to_string.h
 * @author: Jiejing Shan
 * @comments: on some platform, there is no to_string function. Define it on here.
 * @date: 18-07-03
 *
*/

#ifndef _COM_SHJJ_CPPKIT_TO_STRING_H_
#define _COM_SHJJ_CPPKIT_TO_STRING_H_

#include <string>
#include <sstream>

namespace com {
namespace shjj {
namespace cppkit {
    
template <typename T>
std::string to_string(T value) {
       std::ostringstream os;
       os <<value;
       return os.str();
}

} // cppkit
} //  shjj
} // com

#endif /* end of include guard: _COM_SHJJ_CPPKIT_TO_STRING_H_ */




