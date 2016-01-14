#ifndef __DEF_HPP__
#define __DEF_HPP__

#include <vector>
#include <string>
#include <map>

#include <boost/filesystem/path.hpp>

typedef std::vector<int> INTVEC;
typedef std::vector<double> DBLVEC;
typedef std::vector<std::string> STRVEC;
typedef std::map<std::string, std::string> STRMAP;
typedef std::map<std::string, STRVEC> STRVECMAP;

typedef boost::filesystem::path PATH;

#endif //__DEF_HPP__
