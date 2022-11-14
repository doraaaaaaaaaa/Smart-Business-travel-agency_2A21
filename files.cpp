#include "files.h"
#include<QString>
#include<QFileInfo>
#include<QDir>
#include<QStringList>
Files::Files()
{

}

void setExtensions(const QString&extensions)
{
    supportedExtensions=extensions;
}
void openFile(const QString&fullPath)
{
    QFileInfo current(fullPath);
    Dir dir=current.absoluteDir();
    currentFilePath=fullPath;
    currentFileName=current.fileName();
    FilesNamesInCurrentPath.indexOf(currentFileName);
}
QString nextFile()
{

}
QString previousFile()
{

}

bool hasNextFile()
{

}
bool hasPreviousFile()
{

}

QString getCurrentFilename()
{

}
