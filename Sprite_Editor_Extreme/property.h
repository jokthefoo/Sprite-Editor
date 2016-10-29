#ifndef PROPERTY_H
#define PROPERTY_H
#include <QString>

class Property
{
public:
    Property();
    Property(QString);
    ~Property();
     QString name;
    std::vector<int> values;
    void addValue(int);
};

#endif // PROPERTY_H
