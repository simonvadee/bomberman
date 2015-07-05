//
// Way.hh for bomber in /home/ngo-va_a/rendu/bomberman/classes
//
// Made by Arthur Ngo Van
// Login   <ngo-va_a@epitech.net>
//
// Started on  Thu May  7 11:57:13 2015 Arthur Ngo Van
// Last update Thu May  7 18:03:25 2015 Arthur Ngo Van
//

#ifndef WAY_HH_
# define WAY_HH_

# include <deque>

class					Way
{
private:
  int					_weight;

public:
  Way(std::pair<int,int> const& pos);
  ~Way();
  Way&					operator+(std::pair<int,int>& add);

  std::deque<std::pair<int,int> >	_way;

  float					getWeight() const;
  std::deque<std::pair<int,int> >&	getWay();
  void					push(std::pair<int,int>& pos);
  void					pop();
  void					setWeight(int weight);
  void					dump();
  bool					isStraight();
};

#endif /* WAY_HH_ */
