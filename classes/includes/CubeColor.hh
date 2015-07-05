/*
** ngo-va_a
*/

#ifndef CUBECOLOR_HH_
# define CUBECOLOR_HH_

class		CubeColor
{
private:
  float		_red;
  float		_green;
  float		_blue;
  float		_alpha;
  float		_gradient;

public:
  CubeColor(float red, float green, float blue, float alpha);
  ~CubeColor();

  float		getRed(int faceNumber) const;
  float		getGreen(int faceNumber) const;
  float		getBlue(int faceNumber) const;
  float		getAlpha() const;
};

#endif /* CUBECOLOR_HH_ */
