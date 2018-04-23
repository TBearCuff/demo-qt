#ifndef FILECOUNT_H
#define FILECOUNT_H

#include <QObject>
#include <QFile>
#include <QFileSystemWatcher>

class FileCount : public QObject
{
    Q_OBJECT
    QString m_FileName;
    bool m_bWords;
    bool m_bLines;
    bool m_bCharacters;
    QFileSystemWatcher *m_FileToWatch;
public:
    explicit FileCount(QObject *parent = nullptr);
    FileCount(QString fileName, bool bWords, bool bLines, bool bCharacters);
    void setFileName(QString fileName) {m_FileName = fileName; }
    void setWords(bool bWords) {m_bWords = bWords; }
    void setLines(bool bLines) { m_bLines = bLines; }
    void setCharacters(bool bCharacters) { m_bCharacters = bCharacters; }
    QStringList *getCounts();
    void setFileMonitor();

signals:

public slots:
    void aFileChanged(QString filePath);
};

#endif // FILECOUNT_H
