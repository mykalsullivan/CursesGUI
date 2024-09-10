//
// Created by msullivan on 9/6/24.
//

#pragma once
#include "cobject.h"
#include "clist.h"

// Forward declaration(s)
class CLayout;
enum class CColorAttribute;
using CColor = int;

class CWidget : public CObject {
public:
    explicit CWidget(CWidget *parent = nullptr);
    ~CWidget() override;

    CWidget &operator=(const CWidget &);
    CWidget &operator=(CWidget &&);

protected:
    CWidget *m_Parent;
    CLayout *m_Layout;

private:
    void init() override;

public:
    virtual void show();
    virtual void hide();
    virtual void pause();
    virtual void unpause();
    virtual bool lockHeight();
    virtual bool lockWidth();
    virtual int lockResize();
    virtual bool unlockHeight();
    virtual bool unlockWidth();
    virtual int unlockResize();
    [[nodiscard]] virtual bool isHidden();
    [[nodiscard]] virtual bool isPaused();
    [[nodiscard]] virtual bool hasLockedHeight();
    [[nodiscard]] virtual bool hasLockedWidth();
    [[nodiscard]] virtual bool hasUnlockableHeight();
    [[nodiscard]] virtual bool hasUnlockableWidth();
    [[nodiscard]] virtual bool isMoveable();
    [[nodiscard]] virtual bool isResizeable();

    // Layout
    virtual CLayout* layout() { return m_Layout; }
    virtual CList<CObject *> &children() { return m_Children; }

    // Colors
    virtual void setForegroundColor(CColor);
    virtual void setBackgroundColor(CColor);
    virtual void setColor(CColor foreground, CColor background);
    virtual void setColorAttribute(CColorAttribute, bool);
    virtual void resetColorAttributes();
    [[nodiscard]] virtual CColor getForegroundColor();
    [[nodiscard]] virtual CColor getBackgroundColor();
    [[nodiscard]] virtual bool hasColorAttribute(CColorAttribute);

    // Dimensions
    virtual bool setHeight(int);
    virtual bool setWidth(int);
    virtual int setDimensions(int h, int w);
    virtual bool setMinimumHeight(int);
    virtual bool setMinimumWidth(int);
    virtual int setMinimumDimensions(int h, int w);
    virtual bool setMaximumHeight(int);
    virtual bool setMaximumWidth(int);
    virtual int setMaximumDimensions(int h, int w);

    [[nodiscard]] virtual int getHeight();
    [[nodiscard]] virtual int getWidth();
    [[nodiscard]] virtual int getMinimumHeight();
    [[nodiscard]] virtual int getMinimumWidth();
    [[nodiscard]] virtual int getMaximumHeight();
    [[nodiscard]] virtual int getMaximumWidth();

    virtual bool extendTop(int);
    virtual bool extendRight(int);
    virtual bool extendBottom(int);
    virtual bool extendLeft(int);
    virtual int extendVertical(int);
    virtual int extendHorizontal(int);
    virtual int extendTopLeft(int h, int w);
    virtual int extendTopRight(int h, int w);
    virtual int extendBottomLeft(int h, int w);
    virtual int extendBottomRight(int h, int w);

    // Info
    [[nodiscard]] virtual long getFrameCount();

    // Movement
    virtual bool moveUp(int);
    virtual bool moveRight(int);
    virtual bool moveDown(int);
    virtual bool moveLeft(int);
    virtual int moveVertical(int);
    virtual int moveHorizontal(int);
    virtual int move(int y, int x);

    // Position
    virtual bool setY(int);
    virtual bool setX(int);
    virtual int setPosition(int y, int x);

    [[nodiscard]] virtual int getY();
    [[nodiscard]] virtual int getX();
    [[nodiscard]] virtual int getTopBorder();
    [[nodiscard]] virtual int getLeftBorder();
    [[nodiscard]] virtual int getBottomBorder();
    [[nodiscard]] virtual int getRightBorder();

    [[nodiscard]] virtual int getTopLeftEdgeY();
    [[nodiscard]] virtual int getTopLeftEdgeX();
    [[nodiscard]] virtual int getTopRightEdgeY();
    [[nodiscard]] virtual int getTopRightEdgeX();
    [[nodiscard]] virtual int getBottomLeftEdgeY();
    [[nodiscard]] virtual int getBottomLeftEdgeX();
    [[nodiscard]] virtual int getBottomRightEdgeY();
    [[nodiscard]] virtual int getBottomRightEdgeX();

    [[nodiscard]] virtual bool inYAxis(int);
    [[nodiscard]] virtual bool inXAxis(int);
    [[nodiscard]] virtual bool inElement(int y, int x);
};
