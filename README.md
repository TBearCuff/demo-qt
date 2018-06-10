# Qt demos

A repository of Qt demos. I created this repository to share some of my samples of Qt.

## Word Count

Word Count is similar to linux wc. Its primary usage was to learn about QCommandLineParser. Pass in a filename for a text file and some flags: -w for #words, -l for #lines, -c for #characters, and -m if you want to monitor the changes in the text file (Ctrl-C) to stop the process.

## Signals and slots

It really doesn't show signals and slotss. The text box is bound to the slider so (behind the scenes) as the slider position is updated the value that is displayed in the text field is updated. QML bindings made this demo real light work. The project only works to be deployed to an embedded Linux.

## Nested Items Lab

This lab was from a class on Qt and QML. Its objective was to recreate a screen provided by the instructor using QML Rectangles.

## Ball Animation

The ball animation is a QML animation demonstration. It runs on both desktop and Embedded Linux. Click or touch the ball and it rises up. After peaking it will fall and hit the 'ground' with a little bounce. It will roll right and then roll left. Clicking or touching it and it will repeat.

## Anchors

Demonstrates a log in screen (no supporting business logic) with buttons and images. With some business logic, the act of 'pushing buttons' can create a login event.

