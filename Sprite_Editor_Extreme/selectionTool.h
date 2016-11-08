#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H

#include <grid.h>
#include <QPoint>
#include <tool.h>
#include <vector>
#include <QRubberBand>
#include <QClipboard>
#include <QApplication>

class SelectionTool : public Tool
{
public:
    SelectionTool();
    ~SelectionTool();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int, Project*) override;

    bool drawing;
private:
    QPoint origin;
};

#endif // SELECTIONTOOL_H
