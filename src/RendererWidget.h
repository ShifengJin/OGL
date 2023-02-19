#ifndef _RENDERERWIDGET_H_
#define _RENDERERWIDGET_H_

#include <QMouseEvent>
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

    virtual void drawTargets() override;

private:
    float m_viewMatrix[16];
    
    bool m_leftMousePressed = false;
    float m_xStart, m_yStart, m_xCur, m_yCur;
};

#endif