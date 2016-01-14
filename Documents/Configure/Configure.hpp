#ifndef __CONFIGURE_HPP__
#define __CONFIGURE_HPP__

#include "def.hpp"

namespace DECS{
  namespace common{

    class Configure{
    private:
      static const std::string COMMENT_STR;
      static const std::string DELIM_STR;
      static const std::string MULTI_DELIM_STR;
      
      STRMAP param_;
      STRVECMAP vParam_;

    protected:
      Configure(){}
      Configure(Configure &obj){}
    public:
      static const std::string VARNAME_CFPATH;
      Configure(PATH ConfFilePath);
      ~Configure();

      void parse();
      
      std::string param(std::string verName);
      std::string param(std::string verName, int index);
    };
  }
}

#endif // __CONFIGURE_HPP__
