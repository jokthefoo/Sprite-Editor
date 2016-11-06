#ifndef HISTORY_H
#define HISTORY_H
#include <QImage>
#include <QStack>
#include <grid.h>
#include <QHash>

class History
{
private:
    QHash<unsigned int,QStack<Grid>> before;
    QHash<unsigned int,QStack<Grid>> after;
    QHash<unsigned int,Grid> current;
    unsigned int currentFrame;

public:
    History();
    void addEdit(QImage * image);
    Grid& getCurrent();
    ~History();
    Grid back();
    Grid foward();
    void changeFrame(unsigned int);
};

#endif // HISTORY_H
