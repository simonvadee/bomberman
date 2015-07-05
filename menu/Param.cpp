#include "Param.h"

Param::Param()
{
    isMulti = false;
    isSaveMap = false;
    isRandom = true;
    nbIa = 0;
    x = 19;
    y = 19;
}

Param::~Param()
{

}

bool            Param::getIsMulti() const
{
        return (isMulti);
}

bool            Param::getIsSaveMap() const
{
    return (isSaveMap);
}

bool            Param::getIsRandom() const
{
    return (isRandom);
}

std::string     Param::getMapPath() const
{
    return (mapPath);
}

int             Param::getNbIa() const
{
    return (nbIa);
}

void            Param::setIsMulti(bool multi)
{
    this->isMulti = multi;
}

void            Param::setIsSaveMap(bool saveMap)
{
    this->isSaveMap = saveMap;
}

void            Param::setIsRandom(bool rando)
{
    this->isRandom = rando;
}

void            Param::setMapPath(std::string path)
{
    this->mapPath = path;
}

void            Param::setNbIa(int ia)
{
    this->nbIa = ia;
}

int            Param::getX() const
{
    return (this->x);
}

int            Param::getY() const
{
    return (this->y);
}

void            Param::setX(int _x)
{
    this->x = _x;
}

void            Param::setY(int _y)
{
    this->y = _y;
}
