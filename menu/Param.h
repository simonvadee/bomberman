#ifndef PARAM_H
#define PARAM_H
#include <fstream>

class Param
{
public:
    Param();
    ~Param();

private:
    bool        isMulti;
    bool        isSaveMap;
    bool        isRandom;
    int         nbIa;
    int         x;
    int         y;
    std::string mapPath;

public:
    bool            getIsMulti() const;
    bool            getIsSaveMap() const;
    bool            getIsRandom() const;
    std::string     getMapPath() const;
    int             getNbIa() const;
    int             getX() const;
    int             getY() const;

    void            setIsMulti(bool multi);
    void            setIsSaveMap(bool saveMap);
    void            setIsRandom(bool rando);
    void            setMapPath(std::string path);
    void            setNbIa(int ia);
    void            setX(int _x);
    void            setY(int _y);
};

#endif // PARAM_H
