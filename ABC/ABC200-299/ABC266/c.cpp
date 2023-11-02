#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <complex>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

using Point = complex<double>;

inline bool equal(const double &a, const double &b)
{
    return fabs(a - b) < EPS;
}

// 単位ベクトル(unit vector)を求める
Point unitVector(const Point &a) { return a / abs(a); }

// 法線ベクトル(normal vector)を求める
// 90度回転した単位ベクトルをかける
// -90度がよければPoint(0, -1)をかける
Point normalVector(const Point &a) { return a * Point(0, 1); }

// 内積(dot product) : a・b = |a||b|cosΘ
double dot(const Point &a, const Point &b)
{
    return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積(cross product) : a×b = |a||b|sinΘ
double cross(const Point &a, const Point &b)
{
    return (a.real() * b.imag() - a.imag() * b.real());
}

// 点pを反時計回りにtheta度回転
Point rotate(const Point &p, const double &theta)
{
    return Point(cos(theta) * p.real() - sin(theta) * p.imag(),
                 sin(theta) * p.real() + cos(theta) * p.imag());
}

// ラジアン->度
double radianToDegree(const double &radian) { return radian * 180.0 / PI; }

// 度->ラジアン
double degreeToRadian(const double &degree) { return degree * PI / 180.0; }

// Line : 直線を表す構造体
// b - a で直線・線分を表せる
struct Line
{
    Point a, b;
    Line() = default;
    Line(Point a, Point b) : a(a), b(b) {}
    // Ax+By=C
    Line(double A, double B, double C)
    {
        if (equal(A, 0))
        {
            a = Point(0, C / B), b = Point(1, C / B);
        }
        else if (equal(B, 0))
        {
            b = Point(C / A, 0), b = Point(C / A, 1);
        }
        else
        {
            a = Point(0, C / B), b = Point(C / A, 0);
        }
    }
};

// Segment : 線分を表す構造体
// Lineと同じ
struct Segment : Line
{
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};

// Circle : 円を表す構造体
// pが中心の位置ベクトル、rは半径
struct Circle
{
    Point p;
    double r;

    Circle() = default;

    Circle(Point p, double r) : p(p), r(r) {}
};

// 射影(projection)
// 直線(線分)lに点pから引いた垂線の足を求める
Point projection(const Line &l, const Point &p)
{
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p)
{
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

// 点の回転方向
// 点a, b, cの位置関係について(aが基準点)
int ccw(const Point &a, Point b, Point c)
{
    b -= a, c -= a;
    // 点a, b, c が
    // 反時計回りの時、
    if (cross(b, c) > EPS)
    {
        return 1;
    }
    // 時計回りの時、
    if (cross(b, c) < -EPS)
    {
        return -1;
    }
    // c, a, bがこの順番で同一直線上にある時、
    if (dot(b, c) < 0)
    {
        return 2;
    }
    // a, b, cがこの順番で同一直線上にある場合、
    if (norm(b) < norm(c))
    {
        return -2;
    }
    // cが線分ab上にある場合、
    return 0;
}

// 線分sと線分tが交差しているかどうか
bool isIntersect(const Segment &s, const Segment &t)
{
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
           ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

int main(void)
{
}