/*
*
* @file: ApplicationParameters.cc
* @author: Jiejing Shan
* @comments: Define Command line process paramter set.
* @date: 18-07-05
*
*/

#include "ApplicationParameters.h"

namespace com {
namespace shjj {
namespace cppkit {

	ApplicationParameters::ApplicationParameters(IN std::string keystring,
		IN int argc, IN char* argv[]): mKeyStateMap(),mKeyValueMap() {
		if (0 == keystring.size()) return;
		parseKeyString(keystring);
		if (0 != argc && nullptr != argv) {
			parse(argc, argv);
		}
	}

	ApplicationParameters::~ApplicationParameters() {
		mKeyShortMap.reset();
		mKeyValueMap.reset();
	}

	int ApplicationParameters::parseKeyString(IN std::string keystring) {
		char c = '\0';
		int i = 0;

		for (i = 0; i < keystring.size(); i++) {
			c = keystring[i];
			if (isalpha(c)) {
				KeyState state;
				state.mShortCommand = c;
				if ((i != (keystring.size() -1)) && (keystring[i] == ':')) {
					state.mNeedParam = true;
					i++;
				}
				this->mKeyStateMap[c] = state;
			} else if (c == '{') {
				std::string shortstr;
				std::string longstr;
				int index = 0;
				int j  = 0;
				for (j = i + 1; j < keystring.size(); j ++) {
					if (isalpha(keystring[j])) {
						if (0 == index) {
							shortstr += keystring[j];
						} else {
							longstr += keystring[j];
						}
						continue;
					} else if ('|' == keystring[j]) {
						if (j == (i + 1)) {
							this->mErrorState = true;
							return -1;
						}
						index = j;
					} else if ('}' == keystring[j]) {
						if (j == (i + 1)) {
							this->mErrorState = true;
							return -1;
						}
						break;
					}
					this->mErrorState = true;
					return -1;
				}
				if (j == keystring.size()) {
					this->mErrorState = true;
					return -1;
				}
				i = j;
				KeyState state;
				state.mShortCommand = shortstr;
				state.mLongCommand = longstr;
				if ((i != (keystring.size() -1)) && (keystring[i] == ':')) {
					state.mNeedParam = tree;
					i++;
				}
				this->mKeyStateMap[state.mShortCommand] = state;
				if (0 != state.mLongCommand.size()) {
					this->mKeyStateMap[state.mLongCommand] = state;
				}
			} else {
				this->mErrorState = true;
				return -1;
			}
		}
		
		this->mErrorState = false;
		return 0;
	}

int ApplicationParameters::parse(IN int argc, IN char* argv[]) {
	if (0 == argc || nullptr == argv) {
		this->mErrorState = true;
		return -1;
	}

	int i = 0;
	const char* pstr = nullptr;
	std::string cmd;

	for (i = 0; i < argc; i++) {
		pstr = argv[i];
		if ('-' != *pstr) {
			goto error;
		}

		if ('-' != pstr[1]) {
			cmd = std::string(&p[1]);
		} else {
			cmd = std::string(&p[2]);
		}
		const auto iter = this->mKeyStateMap.find(cmd);
		if (this->mKeyStateMap.end() == iter) {
			goto error;
		}

		std::string argument("");
		if (iter->second.mNeedParam) {
			pstr = argv[i + 1];
			if (nullptr == pstr || '-' == *pstr) {
				goto error;
			}
			argument = std::string(argv[++i]);
		}
		this->mKeyValueMap[iter->second.mShortCommand] = argument;
	}

	return 0;
error:
	this->mErrorState = true;
	return -1;
}


bool ApplicationParameters::has(IN std::string key) {
	const auto iter = this->mKeyValueMap.find(key);
	if (this->mKeyValueMap.end() == iter) return false;
	return true;
}

std::string ApplicationParameters::operator[](IN std::string key) {
	if (!has(key)) return "";
	const auto iter = this->mKeyValueMap.find(key);
	return iter->second;
}

}
}
}