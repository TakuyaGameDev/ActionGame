#pragma once
// ﾃﾝﾌﾟﾚｰﾄ使用
// float,intなにが来ても使用可能なように
template<typename T>
struct Vector2
{
	Vector2() :x(0), y(0) {};
	Vector2(T inx, T iny) :x(inx), y(iny) {};
	T x, y;

	void operator+=(const Vector2<T>& vec)
	{
		x += vec.x;
		y += vec.y;
	}
	void operator-=(const Vector2<T>& vec)
	{
		x -= vec.x;
		y -= vec.y;
	}
	void operator*=(int scale)
	{
		x *= scale;
		y *= scale;
	}
	Vector2<T> operator/(const Vector2<T>& vec) const
	{
		return Vector2<T>(x / vec.x, y / vec.y);
	}

	Vector2<T> operator*(int scale) const
	{
		return Vector2<T>(x * scale, y * scale);
	}

	Vector2<T> operator-(void) const
	{
		return Vector2<T>(-x, -y);
	}
};
template<typename T>
bool operator!=(const Vector2<T>& vec1, const Vector2<T>& vec2)
{
	return (((vec1.x != vec2.x) && (vec1.y != vec2.y)));
}
template<typename T>
Vector2<T> operator+(const Vector2<T>& vec1, const Vector2<T>& vec2)
{
	return Vector2<T>((vec1.x + vec2.x), (vec1.y + vec2.y));
}
template<typename T>
Vector2<T> operator-(const Vector2<T>& vec1, const Vector2<T>& vec2)
{
	return Vector2<T>((vec1.x - vec2.x), (vec1.y - vec2.y));
}

using Vector2I = Vector2<int>;
using Vector2F = Vector2<float>;

