TUIO in a Qt project
=====

I have succesfully compiled after:

1. installing the SDL libraries in my mac.
2. much effort
3. removing the glut calls in the program

To compile please use:

```
qmake -spec macx-xcode project.pro
make
```

.. otherwise, the linker does not find certain XCode libraries that 
are needed for the SDLmain library.


## Newer version

I made some changes to the Makefile.xcode. Compile with

    make -f Makefile.xcode demo

If you made changes to the *.h you must create the moc, using
```
/Developer/Tools/Qt/moc -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/usr/local/Qt4.7/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/usr/include -I. -I. -F/Library/Frameworks -D__APPLE__ -D__GNUC__ MainWindow.h -o moc_mainwindow.cpp
```

It is now working with Qt.
