TEMPLATE = app
TARGET = PluriNotes

QT += core \
      xml \
      multimedia \
      multimediawidgets \
      widgets \
      gui
HEADERS += Article.h \
    ArticleEditeur.h \
    NoteEditeur.h \
    NoteManager.h \
    Notes.h \
    nouvellenote.h \
    PluriNotes.h \
    Media.h \
    MediaEditeur.h \
    player.h \
    playercontrols.h \
    playlistmodel.h \
    videowidget.h
SOURCES += Article.cpp \
    ArticleEditeur.cpp \
    main.cpp \
    NoteEditeur.cpp \
    NoteManager.cpp \
    Notes.cpp \
    nouvellenote.cpp \
    PluriNotes.cpp \
    Media.cpp \
    MediaEditeur.cpp \
    player.cpp \
    playercontrols.cpp \
    playlistmodel.cpp \
    videowidget.cpp
FORMS += PluriNotes.ui \
    nouvellenote.ui

