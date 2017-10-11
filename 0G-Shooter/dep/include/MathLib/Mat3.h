#pragma once

//NO INCLUDES IN THE HEADER WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
union vec3;

class Mat3
{
public:
	Mat3();
	~Mat3();

	float m[9];

	float& operator[](const int i);
	const float& operator[](const int i) const;
};



Mat3 operator+(const Mat3& lhs, const Mat3& rhs);
Mat3 operator-(const Mat3& lhs, const Mat3& rhs);
Mat3 operator-(const Mat3& lhs);
Mat3 operator*(const Mat3& lhs, const float& rhs);
Mat3 operator*(const float& lhs, const Mat3& rhs);
Mat3 operator*(const Mat3& lhs, const Mat3& rhs);
vec3 operator*(const Mat3& lhs, const vec3& rhs);
vec3 operator*(const vec3& lhs, const Mat3& rhs);
