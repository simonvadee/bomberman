/*
** ngo-va_a
*/

#include "CubeColor.hh"

CubeColor::CubeColor(float red, float green, float blue, float alpha)
  : _red(red), _green(green), _blue(blue), _alpha(alpha), _gradient(0.1)
{
}

CubeColor::~CubeColor()
{  
}

float		CubeColor::getRed(int faceNumber) const
{
  return (_red - faceNumber * _gradient > 0 ? _red - faceNumber * _gradient : 0);
}

float		CubeColor::getGreen(int faceNumber) const
{
  return (_green - faceNumber * _gradient > 0 ? _green - faceNumber * _gradient : 0);
}

float		CubeColor::getBlue(int faceNumber) const
{
  return (_blue - faceNumber * _gradient > 0 ? _blue - faceNumber * _gradient : 0);
}

float		CubeColor::getAlpha() const
{
  return (_alpha);
}
