#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QMainWindow>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPen pen;
    QBrush brush;
    QPixmap pixmap;
};

#endif // RENDERAREA_H
