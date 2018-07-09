/*
 *
 * @file: ApplicationParameters.h
 * @author: Jiejing Shan
 * @comments: Define Command line process arguments set.
 * Command arguments use the key string to define. The Command arguments must start by "-" or "--".
 * The Key string includes all the arguments 
 * Key string example:
 *     "a:b{c|client}:de{fg}"
 * This key string defines the arguments:
 *     '-a [parem] -b -c{--client} [param] -d -e -fg'
 * @date: 18-07-05
 *
*/
#ifndef _COM_SHJJ_CPPKIT_APPLICATION_PARAMETERS_H_
#define _COM_SHJJ_CPPKIT_APPLICATION_PARAMETERS_H_

#include "util.h"

#include <string>
#include <map>

namespace com {
namespace shjj {
namespace cppkit {


class ApplicationParameters {
public: 
    //explicit Parameters(std::string key);
    explicit ApplicationParameters(IN std::string keystring, IN int argc = 0, IN char* argv[] = nullptr );
    ~ApplicationParameters();

    std::string operator[](IN std::string key);
	bool has(IN std::string key);

    int parse(IN int argc, IN char* argv[]);

	bool isErrorState() const { return this->mErrorState;}

private:
	int parseKeyString(IN std::string keystring);

	typedef struct KeyState {
		KeyState():mNeedParam(false), mLongCommand(), mShortCommand() {}
		bool mNeedParam;
		std::string mLongCommand;
		std::string mShortCommand;
	}KeyState;

#if 0
	typedef struct ValueState {
		ValueState(): mIsConfig(false), mArgument() {}
		bool mIsConfig;
		std::string mArgument;
	} ValueState;
#endif

	PropertyBuilderByName_NGS(bool, ErrorState, private)
    PropertyBuilderByName_NGS(std::map<std::string, KeyState>, KeyStateMap, private)
    PropertyBuilderByName_NGS(std::map<std::string, std::string>, KeyValueMap, private)
};

}
}
}
#endif /* end of include guard: _COM_SHJJ_CPPKIT_APPLICATION_PARAMETERS_H_ */
