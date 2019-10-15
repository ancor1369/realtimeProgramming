#ifndef ABM_H
#define ABM_H

#include <QMainWindow>



namespace Ui {
class ABM;
}

class ABM : public QMainWindow
{
    Q_OBJECT

public:
    explicit ABM(QWidget *parent = 0);
    void updateValue(void *val);
    int value;
    ~ABM();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ABM *ui;
};

#endif // ABM_H
