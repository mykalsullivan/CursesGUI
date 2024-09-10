//
// Created by msullivan on 9/9/24.
//

#pragma once

class CPoint {
public:
    CPoint() = default;
    CPoint(int xpos, int ypos);

public:
    bool isNull() const;
    int manhattanLength() const;
    int &rx();
    int &ry();
    void setX(int x);
    void setY(int y);
    CPoint transposed() const;
    int x() const;
    int y() const;
    CPoint &operator*=(float factor);
    CPoint &operator*=(double factor);
    CPoint &operator*=(int factor);
    CPoint &operator+=(const CPoint &point);
    CPoint &operator-=(const CPoint &point);
    CPoint &operator/=(float divisor);
    CPoint &operator/=(double divisor);
    CPoint &operator/=(int divisor);

    static int dotProduct(const CPoint &p1, const CPoint &p2);
};