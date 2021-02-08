#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <iostream>
#include <QVariant>
#include <QtSql/QSqlRecord>
#include <QString>
#include <iomanip>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QSqlDatabase db;
db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("First db");
if(!db.open())
{
return 0;
}
std::string input1;
std::cout << "Enter the command" << std::endl;
std::cout.flush();
std::getline(std::cin, input1);
QString input = QString::fromStdString(input1.c_str());
QSqlQuery MyQ(db);
while(input1 != "STOP PROGRAMM")
{
if(!MyQ.exec(input))
{
std::cout << MyQ.lastError().text().toStdString() << std::endl;
}
else
{
std::cout << "OK"<< std::endl;
if(input1.substr(0,6) == "SELECT")
{
QSqlRecord rec;
bool b = 0;
while(MyQ.next())
{
rec = MyQ.record();
int count = rec.count();
if(!b)
{
for(int i=0;i<count;i++)
{
std::cout << rec.fieldName(i).toStdString();
if((i+1) != count)
{
std::cout << std::setw(30);
}
}
std::cout << std::endl;
}
b = true;
for(int i = 0;i<count;i++)
{
std::cout << rec.value(i).toString().toStdString();
if((i+1) != count)
{
std::cout << std::setw(30);
}
}
std::cout << std::endl;
}
}
}
std::cout << "Enter the command" << std::endl;
std::cout.flush();
std::getline(std::cin, input1);
input = QString::fromStdString(input1.c_str());
}
db.close();
return 0;
}
