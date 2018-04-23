#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTextStream>
#include <QStringList>
#include "FileCount.h"
#include <QDebug>

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   QCoreApplication::setApplicationName("my-counter-program");
   QCoreApplication::setApplicationVersion("1.0");

   QCommandLineParser parser;
   parser.setApplicationDescription("Word, line, or character counter");
   parser.addHelpOption();
   parser.addVersionOption();
   parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));

   // A boolean option with multiple names (-w, --words)
   QCommandLineOption words(QStringList() << "w" << "words",
           QCoreApplication::translate("main", "Count of words."));
   parser.addOption(words);

   // A boolean option with multiple names (-l, --lines)
   QCommandLineOption lines(QStringList() << "l" << "lines",
           QCoreApplication::translate("main", "Count of lines."));
   parser.addOption(lines);

   // A boolean option with multiple names (-c, --characters)
   QCommandLineOption characters(QStringList() << "c" << "characters",
           QCoreApplication::translate("main", "Count of characters."));
   parser.addOption(characters);

   // A boolean option with multiple names (-m, --monitor)
   QCommandLineOption monitor(QStringList() << "m" << "monitor",
           QCoreApplication::translate("main", "Monitor the file."));
   parser.addOption(monitor);

   // Process the actual command line arguments given by the user
   parser.process(a);

    const QStringList args = parser.positionalArguments();
    // source is args.at(0), destination is args.at(1)
    if(args.empty())
    {
        //No file name argument
        QTextStream(stdout) << "\nNo file name provided\n";
        return 1;
    }

    //FileCount is the helper function
    FileCount *fc = new FileCount(QCoreApplication::instance());
    fc->setFileName(args.at(0));
    fc->setCharacters(parser.isSet(characters));
    fc->setLines(parser.isSet(lines));
    fc->setWords(parser.isSet(words));

    //output of FileCount::getCounts is a displayable list of strings
    QStringList *displayOut = fc->getCounts();
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

    //monitor is setting for continuous monitoring of file
    if(parser.isSet(monitor))
    {
        fc->setFileMonitor();
//        qDebug() << "Setting monitor";
        return a.exec();
    }
    else
    {
//        qDebug() << "Passing once";
        return 0;
    }
}
