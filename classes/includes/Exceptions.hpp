/*
*** vadee_s
*/

#ifndef EXCEPTIONS_HH_
# define EXCEPTIONS_HH_

# include <exception>
# include <string>
# include <stdio.h>
# include <string.h>
# include <errno.h>

namespace	BombermanError
{

class		ShaderBuildingFailure : public std::exception
  {
  public :
    ShaderBuildingFailure(std::string const& message) throw()
      : _message(message) {}
    virtual ~ShaderBuildingFailure() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(_message);

      return _message.c_str();
    }
  private :
    std::string	_message;
  };

class		SubAnimFailure : public std::exception
  {
  public :
    SubAnimFailure(std::string const& message) throw()
      : _message(message) {}
    virtual ~SubAnimFailure() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(_message);

      return _message.c_str();
    }
  private :
    std::string	_message;
  };

class		ModelLoadFailure : public std::exception
  {
  public :
    ModelLoadFailure(std::string const& message) throw()
      : _message(message) {}
    virtual ~ModelLoadFailure() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(_message);

      return _message.c_str();
    }
  private :
    std::string	_message;
  };

class		TextureLoadFailure : public std::exception
  {
  public :
    TextureLoadFailure(std::string const& message) throw()
      : _message(message) {}
    virtual ~TextureLoadFailure() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(_message);

      return _message.c_str();
    }
  private :
    std::string	_message;
  };

class		MapSizeFailure : public std::exception
  {
  public :
    MapSizeFailure(std::string const& message) throw()
      : _message(message) {}
    virtual ~MapSizeFailure() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(_message);

      return _message.c_str();
    }
  private :
    std::string	_message;
  };

class		CharacterUnknown : public std::exception
  {
  public :
    CharacterUnknown(std::string const& message) throw()
      : _message(message) {}
    virtual ~CharacterUnknown() throw() {}
    virtual const char*	what() const throw()
    {
      std::string	tmp(_message);

      return _message.c_str();
    }
  private :
    std::string	_message;
  };

class		FileError : public std::exception
{
public :
  FileError(int error, std::string const& message) throw()
    : _error(error), _message(message) {}
  virtual ~FileError() throw() {}
  virtual const char*	what() const throw()
  {
    std::string	tmp(strerror(_error));

    tmp += _message;
    return _message.c_str();
  }
private :
  int		_error;
  std::string	_message;
};

};

#endif /* !EXCEPTIONS_HH_ */
