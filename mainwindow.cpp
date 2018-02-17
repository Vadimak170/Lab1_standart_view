#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QTime>
#include <QDebug>
struct city{
    std::string name;
    int humans;
    int year;
};
void generator(int* arr, int* arr2,int* arr3,int* arr4, int n)
{
   srand(time(NULL));
   for (int i(0); i<n; i++){
    arr[i]=0+rand()%10;
    arr2[i]=arr[i];
    arr3[i]=arr[i];
    arr4[i]=arr[i];}

}
void selectionSort_sruct(city *arr, int n)
{
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].humans < arr[min_idx].humans)
            min_idx = j;




            city temp;
            temp=arr[min_idx];
            arr[min_idx]=arr[i];
            arr[i]=temp;

    }
}
     void GnomeSort_struct(city *A, int N) {
    int i = 0;
    while(i < N) {
        if(i == 0 || A[i - 1].humans <= A[i].humans) ++i;
        else {
            city Temp = A[i];
            A[i] = A[i - 1];
            A[i - 1] = Temp;
            --i;
        }
    }
}
void insertion_sort_struct (city *arr, int length){
        int j;
        city temp;
    for (int i = 0; i < length; i++){
        j = i;

        while (j > 0 && arr[j].humans < arr[j-1].humans){
              temp = arr[j];
              arr[j] = arr[j-1];
              arr[j-1] = temp;
              j--;
              }
        }
}

int BinarySearch_struct (city *a, int low, int high, int key)
{
    int mid;

    if (low == high)
        return low;

    mid = low + ((high - low) / 2);

    if (key > a[mid].humans)
        return BinarySearch_struct(a, mid + 1, high, key);
    else if (key < a[mid].humans)
        return BinarySearch_struct(a, low, mid, key);

    return mid;
}
void BinaryInsertionSort_struct (city *a, int n)
{
    int ins, i, j;
    city tmp;

    for (i = 1; i < n; i++) {
        ins = BinarySearch_struct(a, 0, i, a[i].humans);
        tmp = a[i];
        for (j = i - 1; j >= ins; j--)
            a[j + 1] = a[j];
        a[ins] = tmp;
    }
}
void GnomeSort(int *A, int N) {
    int i = 0;
    while(i < N) {
        if(i == 0 || A[i - 1] <= A[i]) ++i;
        else {
            int Temp = A[i];
            A[i] = A[i - 1];
            A[i - 1] = Temp;
            --i;
        }
    }
}





void selectionSort(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;


        swap(&arr[min_idx], &arr[i]);
    }
}





void insertionSort(int *arr, int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}





int BinarySearch (int *a, int low, int high, int key)
{
    int mid;

    if (low == high)
        return low;

    mid = low + ((high - low) / 2);

    if (key > a[mid])
        return BinarySearch (a, mid + 1, high, key);
    else if (key < a[mid])
        return BinarySearch (a, low, mid, key);

    return mid;
}

void BinaryInsertionSort (int *a, int n)
{
    int ins, i, j;
    int tmp;

    for (i = 1; i < n; i++) {
        ins = BinarySearch (a, 0, i, a[i]);
        tmp = a[i];
        for (j = i - 1; j >= ins; j--)
            a[j + 1] = a[j];
        a[ins] = tmp;
    }
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Сортировка сгенерированного массива", QVariant(1));
    ui->comboBox->addItem("Сортировка по ключу из файла", QVariant(2));
    ui->comboBox_2->addItem("Количество населения", QVariant(1));
    ui->comboBox_2->addItem("Год основания", QVariant(2));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   QTime start = QTime::currentTime();
    ui->statusBar->showMessage("Идет считывание");
    std::ifstream in("in.txt");
    if (!in) {QMessageBox::warning(this,"Ошибка!","Не удалось открыть файл"); QApplication::quit(); }
    std::string test, temp;
    int i=0,j=0,k=0;
    city a[600];
    while(std::getline(in,test))
    {
        while(test[i]!=',')
            i++;
            a[j].name.append(test,0,i);
        i++;k=i;
        while(test[i]!=',')
            i++;
        temp.append(test,k,i-k);
        a[j].humans=atoi(temp.c_str());
        temp.clear();
        i++;k=i;
         while(test[i]!=',')
            i++;
        temp.append(test,k,i-k);
        a[j].year=atoi(temp.c_str());
        temp.clear();
        j++;
        i=0;
    }
 //   QString s=QString::number(t.elapsed());
   // ui->statusBar->showMessage(s);
   //  qDebug() << "прошло " << start.elapsed() << " милисекунд";
    QString s=QString::number(start.elapsed());
     ui->timeSelection->setText(s);
}
