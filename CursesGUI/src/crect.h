//
// Created by msullivan on 9/9/24.
//

#pragma once

// Forward declaration(s)
class CPoint;
class CSize;
class CMargins;

class CRect {
public:
    CRect() = default;
    CRect(const CPoint &topLeft, const CPoint &bottomRight);
    CRect(const CPoint &topLeft, const CSize &size);
    CRect(int x, int y, int width, int height);

public:
    void adjust(int dx1, int dy1, int dx2, int dy2);
    CRect adjusted(int dx1, int dy1, int dx2, int dy2);
    int bottom() const;
    CPoint bottomLeft() const;
    CPoint bottomRight() const;
    CPoint center() const;
    bool contains(const CPoint &point, bool proper = false) const;
    bool contains(const CRect &rectangle, bool proper = false) const;
    bool contains(int x, int y) const;
    bool contains(int x, int y, bool proper) const;
    void getCoords(int *x1, int *y1, int *x2, int *y2) const;
    void getRect(int *x, int *y, int *width, int *height) const;
    int height() const;
    CRect intersected(const CRect &rectangle) const;
    bool intersects(const CRect &rectangle) const;
    bool isEmpty() const;
    bool isNull() const;
    bool isValid() const;
    int left() const;
    CRect marginsAdded(const CMargins &margins) const;
    CRect marginsRemoved(const CMargins &margins) const;
    void moveBottom(int y);
    void moveBottomLeft(const CPoint &position);
    void moveBottomRight(const CPoint &position);
    void moveCenter(const CPoint &position);
    void moveLeft(int x);
    void moveRight(int x);
    void moveTo(int x, int y);
    void moveTo(const CPoint &position);
    void moveTop(int y);
    void moveTopLeft(const CPoint &position);
    void moveTopRight(const CPoint &position);
    CRect normalized() const;
    int right() const;
    void setBottom(int y);
    void setBottomLeft(const CPoint &position);
    void setBottomRight(const CPoint &position);
    void setCoords(int x1, int y1, int x2, int y2);
    void setHeight(int height);
    void setLeft(int x);
    void setRect(int x, int y, int width, int height);
    void setRight(int x);
    void setSize(const CSize &size);
    void setTop(int y);
    void setTopLeft(const CPoint &position);
    void setTopRight(const CPoint &position);
    void setWidth(int width);
    void setX(int x);
    void setY(int y);
    CSize size() const;
    int top() const;
    CPoint topLeft() const;
    CPoint topRight() const;
    void translate(int dx, int dy);
    void translate(const CPoint &offset);
    CRect translated(int dx, int dy) const;
    CRect translated(const CPoint &offset) const;
    CRect transposed() const;
    CRect united(const CRect &rectangle) const;
    int width();
    int x() const;
    int y() const;
    CRect operator&(const CRect &rectangle) const;
    CRect &operator&=(const CRect &rectangle);
    CRect &operator+=(const CMargins &margins);
    CRect &operator-=(const CMargins &margins);
    CRect operator|(const CRect &rectangle) const;
    CRect &operator|=(const CRect &rectangle);

    static CRect span(const CPoint &p1, const CPoint &p2);
};