/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLineEdit>
#include <QSlider>
#include <QAbstractButton>
#include <QLabel>
#include <QVideoWidget>


class VideoPlayer : public QWidget
{
    Q_OBJECT
public:
    VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

    /**
     * \brief Modifie l'adresse du fichier a lire.
     * \param url QString avec l'adresse du fichier.
     */
    void setUrl(const QUrl &url);

public slots:
    /**
     * \brief Action du bouton Play.
     * \details Si le player est en pause, lance la lecture.
     * Sinon met le player en pause.
     */
    void play();

private slots:

    /**
     * \brief Change l'icone selon l'etat du player (play/pause).
     * \param state Etat du player.
     */
    void mediaStateChanged(QMediaPlayer::State state);

    /**
     * \brief Change l'emplacement de la barre de progression selon l'avancee de la video.
     * \param position Emplacement dans la video.
     */
    void positionChanged(qint64 position);

    /**
     * \brief Change l'etendu du slider de position en fonction de la duree de la video
     * \param duration Duree de la video.
     */
    void durationChanged(qint64 duration);

    /**
     * \brief Change l'avancement de la video
     * \param position Position a laquelle on veut mettre la video.
     */
    void setPosition(int position);

signals:

private:

    /**
     * \brief Player multimedia.
     */
    QMediaPlayer mediaPlayer;

    /**
     * \brief Bouton play.
     */
    QAbstractButton *playButton;

    /**
     * \brief Slider d'avancement de lecture du mediaPlayer.
     */
    QSlider *positionSlider;
};

#endif // PLAYER_H
