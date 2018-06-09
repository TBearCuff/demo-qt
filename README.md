#### Qt demos

A repository of Qt demos. I created this repository to share some of my samples of Qt.

## Word Count

Word Count is similar to linux wc. Its primary usage was to learn about QCommandLineParser. Pass in a filename for a text file and some flags: -w for #words, -l for #lines, -c for #characters, and -m if you want to monitor the changes in the text file (Ctrl-C) to stop the process.

## Slots and signals

It really doesn't show slots and signals. The text box is bound to the slider so (behind the scenes) as the slider position is updated the value that is displayed in the text field is updated. QML bindings made this demo real light work.


