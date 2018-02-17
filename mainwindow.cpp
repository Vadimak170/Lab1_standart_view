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
void selectionSort_sruct(city *arr, int n,int key)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
            if(key==1) {
          if (arr[j].humans < arr[min_idx].humans)
            min_idx = j;}

        if(key==2) {
      if (arr[j].year < arr[min_idx].year)
        min_idx = j;}


            city temp;
            temp=arr[min_idx];
            arr[min_idx]=arr[i];
            arr[i]=temp;

    }
}
void GnomeSort_struct(city *A, int N,int key) {
   int i = 0;
   if(key==1){
   while(i < N) {
       if(i == 0 || A[i - 1].humans <= A[i].humans) ++i;
       else {
           city Temp = A[i];
           A[i] = A[i - 1];
           A[i - 1] = Temp;
           --i;
       }
   }}
   if(key==2){
   while(i < N) {
       if(i == 0 || A[i - 1].year <= A[i].year) ++i;
       else {
           city Temp = A[i];
           A[i] = A[i - 1];
           A[i - 1] = Temp;
           --i;
       }
   }}
}
void insertion_sort_struct (city *arr, int length,int key){
        int j;
        city temp;
    for (int i = 0; i < length; i++){
        j = i;
        if(key==1){
        while (j > 0 && arr[j].humans < arr[j-1].humans){
              temp = arr[j];
              arr[j] = arr[j-1];
              arr[j-1] = temp;
              j--;
        }}
        if(key==2){
        while (j > 0 && arr[j].year < arr[j-1].year){
              temp = arr[j];
              arr[j] = arr[j-1];
              arr[j-1] = temp;
              j--;
        }}
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
void BinaryInsertionSort_struct (city *a, int n, int key)
{
    int ins, i, j;
    city tmp;

    for (i = 1; i < n; i++) { if(key==1){
        ins = BinarySearch_struct(a, 0, i, a[i].humans);}
        if(key==2){
                ins = BinarySearch_struct(a, 0, i, a[i].year);}
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


void selectionSort(int *arr, int n)
{
    int i, j, min_idx,temp;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;



        temp=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;
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
    ui->comboBox_2->setVisible(0);
    ui->label_2->setVisible(0);
    ui->groupBox_3->setVisible(0);
    ui->comboBox->addItem("Сортировка сгенерированного массива", QVariant(1));
    ui->comboBox->addItem("Сортировка по ключу из файла", QVariant(2));
    ui->comboBox_2->addItem("Количество населения", QVariant(1));
    ui->comboBox_2->addItem("Год основания", QVariant(2));
    ui->label_3->setVisible(0);
    ui->label_7->setVisible(0);
ui->label_4->setVisible(0);
ui->label_5->setVisible(0);
ui->label_6->setVisible(0);
ui->label_8->setVisible(0);
ui->label_9->setVisible(0);
ui->label_10->setVisible(0);
ui->checkSelection->setChecked(1);
ui->checkGnome->setChecked(1);
ui->checkinsert->setChecked(1);
ui->checkBoxBinary->setChecked(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   static int opened;
    int value = ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt();
    int key = ui->comboBox_2->itemData(ui->comboBox_2->currentIndex()).toInt();
    if (value==2){
    ui->statusBar->showMessage("Идет считывание");
    std::ifstream in("in.txt");
    if (!in) {QMessageBox::warning(this,"Ошибка!","Не удалось открыть файл"); QApplication::quit(); }
    std::string test, temp;
    int i=0,j=0,k=0;
    city a[600];
    if(opened>0) { for(int z(0);z<500;z++) a[z].name.clear();}
        opened++;
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
    }  ui->statusBar->showMessage("Файл прочитан"); in.close();
    bool err;
    QTime start = QTime::currentTime();
    if(ui->radioInsert->isChecked()) {insertion_sort_struct(a,j,key);} else
        if(ui->radioSelection->isChecked()) {selectionSort_sruct(a,j,key);} else
            if(ui->radioGnome->isChecked()) {GnomeSort_struct(a,j,key);} else
                if(ui->radioBinary->isChecked()) {BinaryInsertionSort_struct(a,j,key);}
        else { QMessageBox::warning(this,"Ошибка","Не выбран вид сортировки");  err=1;}
   if(!err) {QString s=QString::number(start.elapsed());
     ui->timeStruct->setText(s);
     std::ofstream out("out.txt");
     for(int k(0);k<j;k++)
         out<<a[k].name<<" "<<a[k].humans<<" "<<a[k].year<<std::endl;
     out.close();
     QMessageBox::information(this,"Успешно!","Результы выведены в файл");}

    }else if (value==1)
    { QTime start;
        QString s;
        int n;
            n=ui->size->text().toInt();
            int *arr = new int[n];
                   int *arr2 = new int[n];
                    int *arr3 = new int[n];
                   int *arr4 = new int[n];
                   ui->statusBar->showMessage("Идет генерация данных");
                generator(arr,arr2,arr3,arr4,n);
                 ui->statusBar->showMessage("Идет сортировка");
                if(ui->checkinsert->isChecked()){ start = QTime::currentTime();
                insertionSort(arr,n);
                 s=QString::number(start.elapsed());
                     ui->timeInsert->setText(s);}
                    if (ui->checkGnome->isChecked()){ start = QTime::currentTime();
                     GnomeSort(arr2,n);
                      s=QString::number(start.elapsed());
                          ui->timeGnome->setText(s);}
                        if(ui->checkBoxBinary->isChecked()){ start = QTime::currentTime();
                BinaryInsertionSort(arr3,n);
                s=QString::number(start.elapsed());
                    ui->timeBinary->setText(s);}
                    if (ui->checkSelection->isChecked()){ start = QTime::currentTime();
                selectionSort(arr4,n);
                s=QString::number(start.elapsed());
                    ui->timeSelection->setText(s);}
                ui->statusBar->showMessage("Сортировка окончена");
                delete [] arr;
                 delete [] arr2;
                 delete [] arr3;
                 delete [] arr4;

    }

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int value = ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt();
    if(value==2) { ui->mas->setVisible(0);
        ui->size->setVisible(0);
        ui->comboBox_2->setVisible(1);
        ui->comboBox_2->raise();
        ui->label_2->setVisible(1);
        ui->groupBox->setVisible(0);
        ui->groupBox_2->setVisible(0);
        ui->groupBox_3->setVisible(1);
        ui->groupBox_3->raise();
    } else{
        ui->comboBox_2->setVisible(0);
        ui->label_2->setVisible(0);
        ui->groupBox->setVisible(1);
        ui->groupBox_2->setVisible(1);
        ui->groupBox_3->setVisible(0);
        ui->groupBox_2->raise();
        ui->mas->setVisible(1);
                ui->size->setVisible(1);
                ui->size->raise();
    }
}

void MainWindow::on_checkinsert_stateChanged(int arg1)
{ static int open=1;
    if(open%2==1){
        ui->timeInsert->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_7->setVisible(1);} else {
        ui->label_3->setVisible(0);
        ui->label_7->setVisible(0);
         ui->timeInsert->setVisible(0);
    }
    open++;
}

void MainWindow::on_checkGnome_stateChanged(int arg1)
{
    static int open2=1;
        if(open2%2==1){
             ui->timeGnome->setVisible(1);
        ui->label_4->setVisible(1);
        ui->label_8->setVisible(1);} else {
            ui->label_4->setVisible(0);
            ui->label_8->setVisible(0);
             ui->timeGnome->setVisible(0);
        }
        open2++;
}

void MainWindow::on_checkBoxBinary_stateChanged(int arg1)
{
    static int open3=1;
        if(open3%2==1){ ui->timeBinary->setVisible(1);
        ui->label_5->setVisible(1);
        ui->label_9->setVisible(1);} else {
            ui->label_5->setVisible(0);
            ui->label_9->setVisible(0);
             ui->timeBinary->setVisible(0);
        }
        open3++;
}

void MainWindow::on_checkSelection_stateChanged(int arg1)
{
    static int open4=1;
        if(open4%2==1){
             ui->timeSelection->setVisible(1);
        ui->label_6->setVisible(1);
        ui->label_10->setVisible(1);} else {
             ui->timeSelection->setVisible(0);
            ui->label_6->setVisible(0);
            ui->label_10->setVisible(0);
        }
        open4++;
}
