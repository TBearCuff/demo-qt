#include "FileCount.h"
#include <QDebug>
#include <QTextStream>
#include <QFileInfo>

FileCount::FileCount(QObject *parent) : QObject(parent)
{

}

FileCount::FileCount(QString fileName, bool bWords, bool bLines, bool bCharacters)
    : m_bWords(bWords), m_bLines(bLines), m_bCharacters(bCharacters), m_FileToWatch(NULL)
{
    m_FileName = fileName;
}

QStringList* FileCount::getCounts()
{
    int lines = 0;
    int words = 0;
    int characters = 0;

    QString text;
    QStringList* outString = new QStringList;

    //Get the text file
    QFile file(m_FileName);

    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            text = stream.readLine();
            if(m_bLines)
            {
                lines++;
            }

            if(m_bWords)
            {
                QRegExp rew("(\\W|\\n|\\r)+");
                words += text.split(rew, QString::SkipEmptyParts).count();

            }

            if(m_bCharacters)
            {
                characters += text.length();
            }
        }
    }
    if(m_bLines)
    {
        outString->append(QString("Number of lines: %1").arg(lines));
    }
    if(m_bWords)
    {
        outString->append(QString("Number of words: %1").arg(words));
    }

    if(m_bCharacters)
    {
        outString->append(QString("Number of characters: %1").arg(characters));
    }


    return outString;
}

void FileCount::setFileMonitor()
{
    QFileInfo file(m_FileName);
    QString filePath = file.absoluteFilePath();
    m_FileToWatch = new QFileSystemWatcher(this);
    m_FileToWatch->addPath(filePath);
    connect(m_FileToWatch, &QFileSystemWatcher::fileChanged, this, &FileCount::aFileChanged);
}

void FileCount::aFileChanged(QString filePath)
{
    QFileInfo file(m_FileName);
    if(filePath == file.absoluteFilePath())
    {
        QStringList *displayOut = getCounts();
        QTextStream(stdout) << "\033[3A";
        if(displayOut->empty())
        {
            QTextStream(stdout) << "\nFile not found\n";
        }
        else
        {
            QStringList::const_iterator it;
            for(it = (*displayOut).constBegin(); it != (*displayOut).constEnd(); ++it)
            {
                QTextStream(stdout) << (*it).toLocal8Bit().constData() << endl;
            }
        }
    }
    else
    {
        //Not my file
    }
//    qDebug() << "I reached the end of the call";
}

