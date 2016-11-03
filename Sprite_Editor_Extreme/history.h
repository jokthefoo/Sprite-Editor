#ifndef HISTORY_H
#define HISTORY_H
#include <QStack>
#include <grid.h>


class History
{
private:
    QStack<Grid> stacka;
    QStack<Grid> stackb;
    Grid * current;

public:
    ~History();
    History(Grid * grid);
    bool forwards();
    bool backwards();
    Grid * getCurrent();
    void addEdit(Grid grid);

};

#endif // HISTORY_H
