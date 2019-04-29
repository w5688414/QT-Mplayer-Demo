#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QIcon>
#include <QProcess>


class QPushButton;
class QSlider;
class QTextEdit;
class QTimer;
class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum PlayState{Playing, Paused, Stopped};
    void closeEvent(QCloseEvent *event);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void openFile();
        void startPlay();
        void stopPlay();
        void playOrPause();
        void slowSpeed();
        void highSpeed();
        void frameStep();
        void mute();
        void setVolume(int volume);
        void seekSliderChanged(int pos);
        void pollCurrentTime();
        void mplayerEnded(int exitCode, QProcess::ExitStatus exitStatus);
        void messageProcessing();

private:
    Ui::MainWindow *ui;
    QWidget *videoWidget;
    QWidget *widget;
        QPushButton *openButton;
        QPushButton *playButton;
        QIcon playIcon;
        QIcon pauseIcon;
        QPushButton *stopButton;
        QPushButton *slowSpeedButton;
        QPushButton *highSpeedButton;
        QPushButton *frameStepButton;
        QPushButton *muteButton;
        QSlider *volumeSlider;
        QSlider *seekSlider;
        QProcess *process;
        QTimer *poller;
        QLabel *timeLabel;


        PlayState playState;
        QTextEdit *outEdit;
        float m_speed;
        bool m_bMute;
        bool m_bFrameStep;
        float m_maxTime;
        float m_curTime;
        QString m_fileName;
        int m_volume;

        QString m_stotalTime;
        QString m_scurTime;

        void updateUi();
        QString convertToTime(int secs);
};

#endif // MAINWINDOW_H
