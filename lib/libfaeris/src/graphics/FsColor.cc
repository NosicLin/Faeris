#include "FsColor.h"

NS_FS_BEGIN

Color Color::DEFAULT_COLOR=Color(255,255,255,255);
Color Color::RED=Color(255,0,0,255);
Color Color::BLUE=Color(0,0,255,255);
Color Color::GREEN=Color(0,255,0,255);
Color Color::WHITE=Color(255,255,255,255);
Color Color::BLACK=Color(0,0,0,255);


Color Color::operator+(Color right)
{
	int red=r+right.r;
	int green=g+right.g;
	int blue=b+right.b;
	int alpha=a+right.a;

	if(red>255) red=255;
	if(green>255) green=255;
	if(blue>255) blue=255;
	if(alpha>255) alpha=255;

	return Color(red,green,blue,alpha);
}

Color Color::operator-(Color right)
{
	int red=r-right.r;
	int green=g-right.g;
	int blue=b-right.b;
	int alpha=a-right.a;

	if(red<0) red=0;
	if(green<0) green=0;
	if(blue<0) blue=0;
	if(alpha<0) alpha=0;

	return Color(red,green,blue,alpha);
}

Color Color::operator*(float s)
{
	int red=(int)(r*s);
	int green=(int)(g*s);
	int blue=(int)(b*s);
	int alpha=(int)(a*s);

	if(red<0) red=0;
	if(red>255) red=255;

	if(green<0)  green=0;
	if(green>255) green=255;

	if(blue<0) blue=0;
	if(blue>255) blue=255;

	if(alpha<0) alpha=0;
	if(alpha>255) alpha=255;


	return Color(red,green,blue,alpha);
}

NS_FS_END

