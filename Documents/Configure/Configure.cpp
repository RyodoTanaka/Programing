#include <fstream>

#include <iostream>

#include <boost/tokenizer.hpp>
#include <boost/xpressive/xpressive.hpp>

#include "Configure.hpp"

const std::string DECS::common::Configure::VARNAME_CFPATH("ConfFilePath");
const std::string DECS::common::Configure::COMMENT_STR("#");
const std::string DECS::common::Configure::DELIM_STR("=");
const std::string DECS::common::Configure::MULTI_DELIM_STR(",");

DECS::common::Configure::Configure(PATH ConfFilePath)
{
  std::string nativePath = ConfFilePath.native_file_string();
  this->param_[this->VARNAME_CFPATH] = nativePath;
}

DECS::common::Configure::~Configure()
{
}

void DECS::common::Configure::parse()
{
  namespace XPR = boost::xpressive;

  typedef boost::char_separator<char> CSEP;
  typedef boost::tokenizer<CSEP> TOKEN;  

  //Definition of separator between the configure file entry and its comment.
  CSEP cmtSep(this->COMMENT_STR.c_str(), ""); 
  //Definition of separator for the array variable.
  CSEP eqSep(this->DELIM_STR.c_str(), "", boost::keep_empty_tokens);

  //Definition of the regular expression for deleting white spaces around separators.
  XPR::sregex eqRex = (*XPR::_s) >> this->DELIM_STR >> (*XPR::_s);
  XPR::sregex varRex = (*XPR::_s) >> this->MULTI_DELIM_STR >> (*XPR::_s);

  std::string line;
  std::ifstream inConfFile((this->param(this->VARNAME_CFPATH)).c_str());  
  while(getline(inConfFile, line)){
    if(line.c_str()[0] != this->COMMENT_STR.c_str()[0]){ //For line comment out
      line = XPR::regex_replace(line, eqRex, this->DELIM_STR);
      TOKEN cmtToken(line, cmtSep);
      line = *(cmtToken.begin()); //Deleting comment
      TOKEN eqToken(line, eqSep); //Separating between the variabl name and its value.
      TOKEN::iterator eqIter = eqToken.begin();
      std::string varName = *eqIter++;
      XPR::smatch m;
      if(XPR::regex_search(*eqIter, m, varRex)){ //Switching single or multi value
	std::string varStr =
	  XPR::regex_replace(*eqIter, varRex, this->MULTI_DELIM_STR);
	CSEP varSep(this->MULTI_DELIM_STR.c_str(), "", boost::keep_empty_tokens);
	TOKEN varToken(varStr, varSep); //Separating multi value to single values.
	for(TOKEN::iterator varIter = varToken.begin();
	    varIter != varToken.end();
	    ++varIter){
	  this->vParam_[varName].push_back(*varIter);
	}
      }
      else{
	this->param_[varName] = *eqIter;
      }
    }
  }
  inConfFile.close();
}
      
std::string DECS::common::Configure::param(std::string verName)
{
  return this->param_[verName];
}
std::string DECS::common::Configure::param(std::string verName, int index)
{
  return this->vParam_[verName][index];
}
