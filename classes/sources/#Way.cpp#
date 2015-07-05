//
// Way.cpp for bomber in /home/ngo-va_a/rendu/bomberman/classes
//
// Made by Arthur Ngo Van
// Login   <ngo-va_a@epitech.net>
//
// Started on  Thu May  7 12:57:22 2015 Arthur Ngo Van
// Last update Fri May  8 15:39:16 2015 Arthur Ngo Van
//

#include <iostream>

#include "Way.hh"

Way::Way(std::pair<int,int> const& pos)
  : _weight(0)
{
  _way.push_front(pos);
}

Way::~Way()
{

}

bool					Way::isStraight()
{
  if (_way.front().first == _way.back().first)
    {
      int				tmp = _way.front().first;

      for (std::deque<std::pair<int,int> >::iterator it = _way.begin(); it != _way.end(); ++it)
	{
	  if (tmp != it->first)
	    return (false);
	}
      return (true);
    }
  if (_way.front().second == _way.back().second)
    {
      int				tmp = _way.front().second;

      for (std::deque<std::pair<int,int> >::iterator it = _way.begin(); it != _way.end(); ++it)
	{
	  if (tmp != it->second)
	    return (false);
	}
      return (true);
    }
  return (false);
}

float					Way::getWeight() const
{
  if (_way.empty())
    return (0);
  return (static_cast<float>(_weight) / static_cast<float>(_way.size()));
}

std::deque<std::pair<int,int> >&	Way::getWay()
{
  return _way;
}

void					Way::push(std::pair<int,int>& pos)
{
  _way.push_front(pos);
}

void					Way::pop()
{
  _way.pop_front();
}

void					Way::setWeight(int weight)
{
  _weight = weight;
}

Way&					Way::operator+(std::pair<int,int>& add)
{
  push(add);
  return (*this);
}

void					Way::dump()
{
  std::cout << "dump : " << std::endl;
  for (std::deque<std::pair<int,int> >::iterator it = _way.begin(); it != _way.end(); ++it)
    std::cout << it->first << " | " << it->second << std::endl;
}
