#include "abm.h"
#include "ui_abm.h"
#include <pthread.h>
#include <unistd.h>

int firstValue = 0;
int secondValue = 0;

void *augmentNumber(void *data)
{
    int *n = (int *)data;
    while(1)
    {
        *n += 1;
        sleep(2);
        if( *n == 100)
        {
            *n=0;
        }
    }
}

void *augmentOtherValue(void *data)
{
    int *n = (int *)data;
    while(1)
    {
        *n+=2;
        sleep(1);
        if(*n == 100)
        {
            *n = 0;
        }
    }

}


ABM::ABM(QWidget *parent) : QMainWindow(parent), ui(new Ui::ABM)
{
    pthread_t lcd1;
    pthread_t lcd2;
    if(pthread_create(&lcd1, NULL, &augmentNumber,&firstValue))
    {
        printf("Failed to create the thread");
    }
    if(pthread_create(&lcd2,NULL,&augmentOtherValue,&secondValue))
    {
        printf("Errod creating second thread");
    }
    ui->setupUi(this);
}


ABM::~ABM()
{
    delete ui;
}

void ABM::updateValue(void *val)
{
    int *x = (int *)val;
    ui->progressBar->setValue(*x);
}

void ABM::on_pushButton_clicked()
{
    ui->lcdNumber->display(firstValue);
    printf("%d \n",firstValue);
}

void ABM::on_toolButton_clicked()
{
    ui->lcdNumber_2->display(secondValue);
    printf("%d \n", secondValue);
}

void ABM::on_pushButton_2_clicked()
{
    ui->lcdNumber->display(firstValue);
    ui->lcdNumber_2->display(secondValue);
}
