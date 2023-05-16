#ifndef _RENDERERWIDGET_H_
#define _RENDERERWIDGET_H_

#include <QMouseEvent>
#include <QWheelEvent>
#include "RenderedBaseWidget.h"

class RendererWidget : public RenderedBaseWidget {
    Q_OBJECT

public:
    RendererWidget(QWidget* parent = Q_NULLPTR);
    ~RendererWidget();    
protected:
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void wheelEvent(QWheelEvent* e);

    virtual void drawTargets() override;

private:
    float m_xStart, m_yStart, m_xCur, m_yCur;
    float m_right_xStart, m_right_yStart, m_right_xCur, m_right_yCur;
};

#endif