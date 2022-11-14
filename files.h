#pragma once
#include<QStringList>
class Files
{
public:
    Files();
    void setExtensions(const QString&extensions);
    void openFile(const QString&fullPath);

    QString nextFile();
    QString previousFile();

    bool hasNextFile();
    bool hasPreviousFile();

    QString getCurrentFilename();

private:
    QStringList fileNamesIncCurrentPath;
    QString currentFilePath;
    QString currentFileName;

    bool hasNext=false;
    bool hasPrevious=false;

    QStringList supportedExtensions;

};

