﻿//----------------------------------------------------------------------------
// MainWnd.h : メインウィンドウの作成・管理を行う
//----------------------------------------------------------------------------
#ifndef MainWndH
#define MainWndH

class CApp;
class CPlayListView_MainWnd;
class QTimer;
class QUrl;
#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>
#include <QList>
#include <QMainWindow>
#include "../Common/Define.h"
#include "EQLabel_MainWnd.h"
#include "EQSlider_MainWnd.h"
#include "FreqLabel_MainWnd.h"
#include "FreqSlider_MainWnd.h"
#include "Menu_MainWnd.h"
#include "PanLabel_MainWnd.h"
#include "PanSlider_MainWnd.h"
#include "PitchLabel_MainWnd.h"
#include "PitchSlider_MainWnd.h"
#include "Sound.h"
#include "SpeedLabel_MainWnd.h"
#include "SpeedSlider_MainWnd.h"
#include "TimeLabel_MainWnd.h"
#include "TimeSlider_MainWnd.h"
#include "ToolBar_MainWnd.h"
#include "VolumeLabel_MainWnd.h"
#include "VolumeSlider_MainWnd.h"
#include "ui_MainWnd.h"
//----------------------------------------------------------------------------
// メインウィンドウの作成・管理を行うクラス
//----------------------------------------------------------------------------
class CMainWnd : public QMainWindow, public Ui::MainWnd
{
	Q_OBJECT

public: // 関数

	CMainWnd(CApp & app): m_rApp(app), m_menu(*this), m_toolBar(*this),
		m_timeLabel(*this), m_timeSlider(*this), m_speedLabel(*this),
		m_speedSlider(*this), m_freqLabel(*this), m_freqSlider(*this),
		m_pitchLabel(*this), m_pitchSlider(*this), m_volumeLabel(*this),
		m_volumeSlider(*this), m_panLabel(*this), m_panSlider(*this),
		m_eq20Label(*this), m_eq20Slider(*this),
		m_eq25Label(*this), m_eq25Slider(*this),
		m_eq31_5Label(*this), m_eq31_5Slider(*this),
		m_eq40Label(*this), m_eq40Slider(*this),
		m_eq50Label(*this), m_eq50Slider(*this),
		m_eq63Label(*this), m_eq63Slider(*this),
		m_eq80Label(*this), m_eq80Slider(*this),
		m_eq100Label(*this), m_eq100Slider(*this),
		m_eq125Label(*this), m_eq125Slider(*this),
		m_eq160Label(*this), m_eq160Slider(*this),
		m_eq200Label(*this), m_eq200Slider(*this),
		m_eq250Label(*this), m_eq250Slider(*this),
		m_eq315Label(*this), m_eq315Slider(*this),
		m_eq400Label(*this), m_eq400Slider(*this),
		m_eq500Label(*this), m_eq500Slider(*this),
		m_eq630Label(*this), m_eq630Slider(*this),
		m_eq800Label(*this), m_eq800Slider(*this),
		m_eq1kLabel(*this), m_eq1kSlider(*this),
		m_eq1_25kLabel(*this), m_eq1_25kSlider(*this),
		m_eq1_6kLabel(*this), m_eq1_6kSlider(*this),
		m_eq2kLabel(*this), m_eq2kSlider(*this),
		m_eq2_5kLabel(*this), m_eq2_5kSlider(*this),
		m_eq3_15kLabel(*this), m_eq3_15kSlider(*this),
		m_eq4kLabel(*this), m_eq4kSlider(*this),
		m_eq5kLabel(*this), m_eq5kSlider(*this),
		m_eq6_3kLabel(*this), m_eq6_3kSlider(*this),
		m_eq8kLabel(*this), m_eq8kSlider(*this),
		m_eq10kLabel(*this), m_eq10kSlider(*this),
		m_eq12_5kLabel(*this), m_eq12_5kSlider(*this),
		m_eq16kLabel(*this), m_eq16kSlider(*this),
		m_eq20kLabel(*this), m_eq20kSlider(*this),
		m_sound(*this), isInitFileRead(FALSE), m_bFinish(FALSE), nCurPlayTab(0),
		m_timeThreadRunning(false), m_bForwarding(false), m_bRewinding(false) { }
	virtual ~CMainWnd();

	virtual void AddDropFiles(const QList<QUrl> & urls, BOOL bClear);
	virtual BOOL Create() { return OnCreate(); }
	virtual BOOL CreateControls();
	virtual void DownFreq(double freq);
	virtual void DownPitch(double pitch);
	virtual void DownSpeed(double speed);
	virtual void Forward();
	virtual void Head();
	virtual BOOL OpenFile(const QString & lpszFilePath, int nCount = 1);
	virtual void OpenInitFile();
	virtual void OpenInitFileAfterShow();
	virtual BOOL OpenNext();
	virtual BOOL OpenPrevious();
	virtual BOOL OpenRandom();
	virtual void Pause();
	virtual BOOL Play();
	virtual void PlayNext(BOOL bPlay, BOOL bFadeoutCancel);
	virtual void PlayPrevious();
	virtual void ResetFreq();
	virtual void ResetPitch();
	virtual void ResetSpeed();
	virtual void ResetVolume();
	virtual void Rewind();
	virtual void SetABLoopA();
	virtual void SetABLoopA_Sec(double dTime);
	virtual void SetABLoopB();
	virtual void SetABLoopB_Sec(double dTime);
	virtual void SetABLoopASetting();
	virtual void SetABLoopBSetting();
	virtual void SetAllLoop(bool bAllLoop);
	virtual void SetAllEffects();
	virtual void SetContinue(bool bContinue);
	virtual void SetSpeedVisible(bool bSpeedVisible);
	virtual void SetFreqVisible(bool bFreqVisible);
	virtual void SetPitchVisible(bool bPitchVisible);
	virtual void SetVolumeVisible(bool bVolumeVisible);
	virtual void SetPanVisible(bool bPanVisible);
	virtual void SetEQ20(LONG lEQ20);
	virtual void SetEQ25(LONG lEQ25);
	virtual void SetEQ31_5(LONG lEQ31_5);
	virtual void SetEQ40(LONG lEQ40);
	virtual void SetEQ50(LONG lEQ50);
	virtual void SetEQ63(LONG lEQ63);
	virtual void SetEQ80(LONG lEQ80);
	virtual void SetEQ100(LONG lEQ100);
	virtual void SetEQ125(LONG lEQ125);
	virtual void SetEQ160(LONG lEQ160);
	virtual void SetEQ200(LONG lEQ200);
	virtual void SetEQ250(LONG lEQ250);
	virtual void SetEQ315(LONG lEQ315);
	virtual void SetEQ400(LONG lEQ400);
	virtual void SetEQ500(LONG lEQ500);
	virtual void SetEQ630(LONG lEQ630);
	virtual void SetEQ800(LONG lEQ800);
	virtual void SetEQ1K(LONG lEQ1K);
	virtual void SetEQ1_25K(LONG lEQ1_25K);
	virtual void SetEQ1_6K(LONG lEQ1_6K);
	virtual void SetEQ2K(LONG lEQ2K);
	virtual void SetEQ2_5K(LONG lEQ2_5K);
	virtual void SetEQ3_15K(LONG lEQ3_15K);
	virtual void SetEQ4K(LONG lEQ4K);
	virtual void SetEQ5K(LONG lEQ5K);
	virtual void SetEQ6_3K(LONG lEQ6_3K);
	virtual void SetEQ8K(LONG lEQ8K);
	virtual void SetEQ10K(LONG lEQ10K);
	virtual void SetEQ12_5K(LONG lEQ12_5K);
	virtual void SetEQ16K(LONG lEQ16K);
	virtual void SetEQ20K(LONG lEQ20K);
	virtual void SetEQVisible(bool bEQVisible);
	virtual void SetPreviousNextMenuState();
	virtual void SetRandom(bool bRandom);
	virtual void SetSingleLoop();
	virtual void SetSpeed(double dSpeed);
	virtual void SetFreq(double dFreq);
	virtual void SetPitch(double dPitch);
	virtual void SetVolume(double nVolume);
	virtual void SetTime(QWORD qwTime, BOOL bReset = TRUE);
	virtual void SetPan(int nPan);
	virtual void ShowTime(BOOL bReset = TRUE);
	virtual void StartRewind();
	virtual void StartForward();
	virtual void StopRewind();
	virtual void StopForward();
	virtual void Stop(BOOL bForce = TRUE);
	virtual void UpFreq(double freq);
	virtual void UpPitch(double pitch);
	virtual void UpSpeed(double speed);
	virtual void WriteInitFile();

	// メッセージ
	virtual void OnClose();
	virtual LRESULT OnCreate();
	virtual void OnTimer(UINT id);

	static void UpdateTimeThreadProc(void * pParam);

protected: // メンバ変数

	CApp & m_rApp;
	CMenu_MainWnd m_menu;
	CToolBar_MainWnd m_toolBar;
	CTimeLabel_MainWnd m_timeLabel;
	CTimeSlider_MainWnd m_timeSlider;
	CSpeedLabel_MainWnd m_speedLabel;
	CSpeedSlider_MainWnd m_speedSlider;
	CFreqLabel_MainWnd m_freqLabel;
	CFreqSlider_MainWnd m_freqSlider;
	CPitchLabel_MainWnd m_pitchLabel;
	CPitchSlider_MainWnd m_pitchSlider;
	CVolumeLabel_MainWnd m_volumeLabel;
	CVolumeSlider_MainWnd m_volumeSlider;
	CPanLabel_MainWnd m_panLabel;
	CPanSlider_MainWnd m_panSlider;
	CEQLabel_MainWnd m_eq20Label;
	CEQSlider_MainWnd m_eq20Slider;
	CEQLabel_MainWnd m_eq25Label;
	CEQSlider_MainWnd m_eq25Slider;
	CEQLabel_MainWnd m_eq31_5Label;
	CEQSlider_MainWnd m_eq31_5Slider;
	CEQLabel_MainWnd m_eq40Label;
	CEQSlider_MainWnd m_eq40Slider;
	CEQLabel_MainWnd m_eq50Label;
	CEQSlider_MainWnd m_eq50Slider;
	CEQLabel_MainWnd m_eq63Label;
	CEQSlider_MainWnd m_eq63Slider;
	CEQLabel_MainWnd m_eq80Label;
	CEQSlider_MainWnd m_eq80Slider;
	CEQLabel_MainWnd m_eq100Label;
	CEQSlider_MainWnd m_eq100Slider;
	CEQLabel_MainWnd m_eq125Label;
	CEQSlider_MainWnd m_eq125Slider;
	CEQLabel_MainWnd m_eq160Label;
	CEQSlider_MainWnd m_eq160Slider;
	CEQLabel_MainWnd m_eq200Label;
	CEQSlider_MainWnd m_eq200Slider;
	CEQLabel_MainWnd m_eq250Label;
	CEQSlider_MainWnd m_eq250Slider;
	CEQLabel_MainWnd m_eq315Label;
	CEQSlider_MainWnd m_eq315Slider;
	CEQLabel_MainWnd m_eq400Label;
	CEQSlider_MainWnd m_eq400Slider;
	CEQLabel_MainWnd m_eq500Label;
	CEQSlider_MainWnd m_eq500Slider;
	CEQLabel_MainWnd m_eq630Label;
	CEQSlider_MainWnd m_eq630Slider;
	CEQLabel_MainWnd m_eq800Label;
	CEQSlider_MainWnd m_eq800Slider;
	CEQLabel_MainWnd m_eq1kLabel;
	CEQSlider_MainWnd m_eq1kSlider;
	CEQLabel_MainWnd m_eq1_25kLabel;
	CEQSlider_MainWnd m_eq1_25kSlider;
	CEQLabel_MainWnd m_eq1_6kLabel;
	CEQSlider_MainWnd m_eq1_6kSlider;
	CEQLabel_MainWnd m_eq2kLabel;
	CEQSlider_MainWnd m_eq2kSlider;
	CEQLabel_MainWnd m_eq2_5kLabel;
	CEQSlider_MainWnd m_eq2_5kSlider;
	CEQLabel_MainWnd m_eq3_15kLabel;
	CEQSlider_MainWnd m_eq3_15kSlider;
	CEQLabel_MainWnd m_eq4kLabel;
	CEQSlider_MainWnd m_eq4kSlider;
	CEQLabel_MainWnd m_eq5kLabel;
	CEQSlider_MainWnd m_eq5kSlider;
	CEQLabel_MainWnd m_eq6_3kLabel;
	CEQSlider_MainWnd m_eq6_3kSlider;
	CEQLabel_MainWnd m_eq8kLabel;
	CEQSlider_MainWnd m_eq8kSlider;
	CEQLabel_MainWnd m_eq10kLabel;
	CEQSlider_MainWnd m_eq10kSlider;
	CEQLabel_MainWnd m_eq12_5kLabel;
	CEQSlider_MainWnd m_eq12_5kSlider;
	CEQLabel_MainWnd m_eq16kLabel;
	CEQSlider_MainWnd m_eq16kSlider;
	CEQLabel_MainWnd m_eq20kLabel;
	CEQSlider_MainWnd m_eq20kSlider;
	std::vector<CPlayListView_MainWnd*> m_arrayList;

	CSound m_sound;

	BOOL isInitFileRead; // INI ファイルがすでに読み込まれたかどうか
	BOOL m_bFinish; // 再生が完了したかどうか
	int nCurPlayTab; // 現在再生中のファイルが存在しているタブ
	std::unique_ptr<std::thread> m_timeThread;
	bool m_timeThreadRunning;
	bool m_bForwarding;
	bool m_bRewinding;

public: // 定数

	// タイマー ID
	enum {
		IDT_TIME = 11,
		IDT_REWIND,
		IDT_FORWARD,
	};

public: // メンバ変数の取得・設定

	CMenu_MainWnd & GetMenu() { return m_menu; }
	CSpeedLabel_MainWnd & GetSpeedLabel() { return m_speedLabel; }
	CSpeedSlider_MainWnd & GetSpeedSlider() { return m_speedSlider; }
	CFreqLabel_MainWnd & GetFreqLabel() { return m_freqLabel; }
	CFreqSlider_MainWnd & GetFreqSlider() {
		return m_freqSlider;
	}
	CPitchLabel_MainWnd & GetPitchLabel() { return m_pitchLabel; }
	CPitchSlider_MainWnd & GetPitchSlider() { return m_pitchSlider; }
	CVolumeLabel_MainWnd & GetVolumeLabel() { return m_volumeLabel; }
	CVolumeSlider_MainWnd & GetVolumeSlider() { return m_volumeSlider; }
	CPanLabel_MainWnd & GetPanLabel() { return m_panLabel; }
	CPanSlider_MainWnd & GetPanSlider() { return m_panSlider; }
	CPlayListView_MainWnd & GetPlayList() {
		int nSelect = m_tab->GetCurrentFocus();
		return *m_arrayList[nSelect];
	}
	CPlayListView_MainWnd & GetCurPlayList() {
		return *m_arrayList[nCurPlayTab];
	}
	CSound & GetSound() { return m_sound; }
 	void SetFinish(BOOL bFinish) { m_bFinish = bFinish; }

private:

	struct EQItem {
		QString title;
		CEQLabel_MainWnd & label;
		CEQSlider_MainWnd & slider;
		UINT menuId;
		void (CMainWnd::*setEQ)(LONG);
	};

	void SetContextMenus();
	void ShowContextMenu(QWidget * widget, QMenu * menu,
											 QAction * visibilityAction, const QString &title,
											 void (CMainWnd::*callback)(bool visible),
											 const QPoint & pos);
	void closeEvent(QCloseEvent *event) final;
	void dragEnterEvent(QDragEnterEvent * e) final;
	void dropEvent(QDropEvent * e) final;
	// Qtのラッパー
	virtual void KillTimer(UINT_PTR nIDEvent);
	virtual void SetCaption(const QString & lpWindowName);
	virtual void SetTimer(UINT_PTR nIDEvent, UINT nElapse);

	std::unordered_map<UINT_PTR, QTimer *> m_timers;
	std::vector<EQItem> m_eqItems;
};
//----------------------------------------------------------------------------

#endif
