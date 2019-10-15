#include "abm.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    ABM w;
    w.show();    
    return a.exec();
}
